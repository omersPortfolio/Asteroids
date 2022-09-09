#include "SazPCH.h"

#include "Saz/CameraComponent.h"
#include "Saz/Systems/RenderSystem.h"
#include "Saz/RenderComponents.h"
#include "Saz/Screen.h"
#include "Saz/TransformComponent.h"

#include "Saz/Core/WindowBase.h"

#include <entt/entt.hpp>
#include "InputComponent.h"
#include "Rendering/Renderer2D.h"
#include "Rendering/RenderCommand.h"
#include "Platform/OpenGL/OpenGLFrameBuffer.h"
#include "imgui.h"
#include "Core/Application.h"
#include "glm/gtc/type_ptr.inl"

namespace ecs
{
	RenderSystem::RenderSystem(Saz::WindowBase& window)
		: m_Window(window)
		, m_CameraController(1280.0f / 720.0f, true)
	{
		
	}

	RenderSystem::~RenderSystem()
	{
		
	}

	void RenderSystem::Init()
	{
		Entity m_FrameBufferEntity = m_World->CreateEntity();
		auto& frameBufferComp = m_World->AddComponent<component::FrameBufferComponent>(m_FrameBufferEntity);
		Saz::FrameBufferSpecification fbSpec;
		fbSpec.Width = 1280;
		fbSpec.Height = 720;
		frameBufferComp.FrameBuffer = Saz::FrameBuffer::Create(fbSpec);
		m_FrameBuffer = frameBufferComp.FrameBuffer;


		m_SquareEntity = m_World->CreateEntity();
		m_World->AddComponent<component::TransformComponent>(m_SquareEntity);
		m_World->AddComponent<component::SpriteRendererComponent>(m_SquareEntity, glm::vec4{ 0.0f, 1.0f, 0.0f, 1.0f });
	}

	void RenderSystem::Update(const Saz::GameTime& gameTime)
	{
		auto& registry = m_World->m_Registry;

		const auto frameBufferView = registry.view<component::FrameBufferComponent>();
		for (const auto& frameBufferEntity : frameBufferView)
		{
			const auto& frameBufferComp = registry.get<component::FrameBufferComponent>(frameBufferEntity);

			if (Saz::FrameBufferSpecification spec = m_FrameBuffer->GetSpecification();
				m_SceneSize.x > 0.0f && m_SceneSize.y > 0.0f && // zero sized framebuffer is invalid
				(spec.Width != m_SceneSize.x || spec.Height != m_SceneSize.y))
			{
				m_FrameBuffer->Resize((uint32_t)m_SceneSize.x, (uint32_t)m_SceneSize.y);
				m_CameraController.ResizeBounds(m_SceneSize.x, m_SceneSize.y);
			}

			// Update
			if (m_ViewportFocused)
				m_CameraController.OnUpdate(gameTime);

			Saz::Renderer2D::ResetStats();
			// Render
			{
				frameBufferComp.FrameBuffer->Bind();
				SAZ_PROFILE_SCOPE("Renderer Prep");
				Saz::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
				Saz::RenderCommand::Clear();
			}

			{
				static float rotation = 0.0f;
				rotation += gameTime.GetDeltaTime() * 50.0f;

				SAZ_PROFILE_SCOPE("Renderer Draw");

				Saz::Renderer2D::BeginScene(m_CameraController.GetCamera());

				auto view = registry.view<component::TransformComponent, component::SpriteRendererComponent>();
				for (auto entity : view)
				{
					auto& [transform, sprite] = view.get<component::TransformComponent, component::SpriteRendererComponent>(entity);
					Saz::Renderer2D::DrawQuad(transform, sprite.Color);
				}

				Saz::Renderer2D::EndScene();
			}

			frameBufferComp.FrameBuffer->Unbind();
		}
	}

	void RenderSystem::ImGuiRender()
	{
		static bool dockingEnabled = true;

		static bool opt_fullscreen = true;
		static bool opt_padding = false;
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		if (opt_fullscreen)
		{
			const ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->WorkPos);
			ImGui::SetNextWindowSize(viewport->WorkSize);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		}
		else
		{
			dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
		}

		if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("DockSpace Demo", &dockingEnabled, window_flags);
		ImGui::PopStyleVar();

		if (opt_fullscreen)
			ImGui::PopStyleVar(2);

		// Submit the DockSpace
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Exit"))
				{
					Saz::Application::Get().Close();
				}

				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}

		ImGui::Begin("Profiler");
		auto stats = Saz::Renderer2D::GetStats();
		ImGui::Text("Renderer2D Stats: ");
		ImGui::Text("DrawCalls: %d ", stats.DrawCalls);
		ImGui::Text("Quads: %d", stats.QuadCount);
		ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
		ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

		auto& color = m_World->GetComponent<component::SpriteRendererComponent>(m_SquareEntity).Color;
		ImGui::ColorEdit4("Square Color", glm::value_ptr(color));


		static char str0[128] = "Hello, world!";
		ImGui::InputText("input text", str0, IM_ARRAYSIZE(str0));

		ImGui::End();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 0, 0 });

		ImGui::Begin("Scene");
		m_ViewportFocused = ImGui::IsWindowFocused();
		m_ViewPortHovered = ImGui::IsWindowHovered();
		// if viewport is not hovered and is not focused, block events, otherwise don't block events
		// if viewport is 
		Saz::Application::Get().GetImGuiLayer()->SetBlockEvents(!m_ViewPortHovered);

		ImVec2 scenePanelSize = ImGui::GetContentRegionAvail();
		if (m_SceneSize != *((glm::vec2*)&scenePanelSize))
		{
			m_SceneSize = { scenePanelSize.x, scenePanelSize.y };
		}

		uint32_t textureId = m_FrameBuffer->GetColorAttachmentRendererID();
		ImGui::Image((void*)textureId, ImVec2{ m_SceneSize.x, m_SceneSize.y }, ImVec2{ 0,1 }, ImVec2{ 1, 0 });

		ImGui::End();

		ImGui::PopStyleVar();

		ImGui::End();
	}

}
