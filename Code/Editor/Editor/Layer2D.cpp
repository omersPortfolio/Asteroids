#include "EditorPCH.h"
#include "Layer2D.h"
#include "Saz/Platform/OpenGL/OpenGLShader.h"
#include "Saz/Rendering/RenderCommand.h"
#include "Saz/Rendering/Renderer.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Saz/Rendering/SubTexture2D.h"

static const uint32_t s_MapWidth = 24;
static const char* s_MapTiles = 
"WWWWWWWWWWWWWWWWCWWWWWWW"
"WWWWWWWWDDDDDDWWWWWWWWWW"
"WWWWWWDDDDDDDDDDDWWWWWWW"
"WWWWDDDDDDDDDDDDDDDDDWWW"
"WWWDDDDDDDDDDDDDDDDDDDWW"
"WWDDDDDWWWDDDDDDDDDDDDWW"
"WWWDDDDWWWDDDDDDDDDDDWWW"
"WWWWDDDDDDDDDDDDDDDDWWWW"
"WWWWWDDDDDDDDDDDDDDWWWWW"
"WWWWWWDDDDDDDDDDDDWWWWWW"
"WWWWWWWDDDDDDDDDDWWWWWWW"
"WWWWWWWWDDDDDDDDWWWWWWWW"
"WWWWWWWWWDDDDDDWWWWWWWWW"
"WWWWWWWWWWWWWWWWWWWWWWWW";

Layer2D::Layer2D()
	: Layer("Layer2D")
	, m_CameraController(1280.0f / 720.0f, true)
{

}

void Layer2D::OnAttach()
{
	m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
	m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	m_Particle.SizeBegin = 0.1f;
	m_Particle.SizeVariation = 0.3f;
	m_Particle.SizeEnd = 0.0f;
	m_Particle.LifeTime = 1.0f;
	m_Particle.Velocity = { 0.0f, 0.0f };
	m_Particle.VelocityVariation = { 3.0f, 1.0f };
	m_Particle.Position = { 0.0f, 0.0f };

	m_Texture = Saz::Texture2D::Create("C:/Dev/SazEngine/Data/Textures/Checkerboard.png");
	m_SpriteSheet = Saz::Texture2D::Create("C:/Dev/SazEngine/Data/Textures/RPGPack.png");

	m_MapWidth = s_MapWidth;
	m_MapHeight = strlen(s_MapTiles) / s_MapWidth;

	m_TextureMap['D'] = Saz::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 6, 11 }, { 128, 128 });
	m_TextureMap['W'] = Saz::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 11, 11 }, { 128, 128 });
	m_TextureStairs = Saz::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 1, 3 }, { 128, 128 });

	m_CameraController.SetZoomLevel(5.0f);
}

void Layer2D::OnUpdate(const Saz::GameTime& gameTime)
{
	SAZ_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(gameTime);

	Saz::Renderer2D::ResetStats();
	// Render
	{
		SAZ_PROFILE_SCOPE("Renderer Prep");
		Saz::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Saz::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += gameTime.GetDeltaTime() * 50.0f;

		SAZ_PROFILE_SCOPE("Renderer Draw");

#if 0
		Saz::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Saz::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.75f, 0.75f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		Saz::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.5f, 0.75f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Saz::Renderer2D::DrawQuad({ 0.5f, -0.5f, 0.0f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Saz::Renderer2D::DrawQuad(glm::vec3(0.0f, 0.0f, -0.1f), { 20.0f, 20.0f }, m_Texture, 10.0f);
		Saz::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_Texture, 20.0f);
		Saz::Renderer2D::EndScene();

		Saz::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 1.0f };
				Saz::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}

		Saz::Renderer2D::EndScene();
#endif

		if (Saz::Input::IsMouseButtonPressed(Saz::Mouse::ButtonLeft))
		{
			auto [x, y] = Saz::Input::GetMousePosition();
			auto width = Saz::Application::Get().GetWindow().GetWidth();
			auto height = Saz::Application::Get().GetWindow().GetHeight();

			auto bounds = m_CameraController.GetBounds();
			auto pos = m_CameraController.GetCamera().GetPosition();
			x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
			y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
			m_Particle.Position = { x + pos.x, y + pos.y };
			for (int i = 0; i < 5; i++)
				m_ParticleSystem.Emit(m_Particle);
		}

		m_ParticleSystem.OnUpdate(gameTime);
		m_ParticleSystem.OnRender(m_CameraController.GetCamera());

		Saz::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (uint32_t y = 0; y < m_MapHeight; y++)
		{
			for (uint32_t x = 0; x < m_MapWidth; x++)
			{
				char tileType = s_MapTiles[x + y * m_MapWidth];

				Saz::Ref<Saz::SubTexture2D> texture;
				if (m_TextureMap.find(tileType) != m_TextureMap.end())
				{
					texture = m_TextureMap[tileType];
				}
				else
					texture = m_TextureStairs;

				Saz::Renderer2D::DrawQuad(glm::vec3(x - m_MapWidth / 2.0f, m_MapHeight - y - m_MapHeight / 2.0f, 0.5f), { 1.0f, 1.0f }, texture);
			}
		}

		Saz::Renderer2D::EndScene();
	}

}

void Layer2D::OnDetach()
{

}

void Layer2D::OnEvent(Saz::Event& event)
{
	m_CameraController.OnEvent(event);
}

void Layer2D::OnImGuiRender()
{
	static bool dockspaceOpen = true;
	static bool opt_fullscreen = true;
	static bool opt_padding = false;
	static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

	// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
	// because it would be confusing to have two docking targets within each others.
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

	// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
	// and handle the pass-thru hole, so we ask Begin() to not render a background.
	if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
		window_flags |= ImGuiWindowFlags_NoBackground;

	// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
	// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
	// all active windows docked into it will lose their parent and become undocked.
	// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
	// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
	if (!opt_padding)
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
	ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
	if (!opt_padding)
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

	ImGui::End();

	ImGui::Begin("Scene");
	uint32_t textureId = m_Texture->GetRendererID();
	ImGui::Image((void*)textureId, ImVec2{ 256.0f, 256.0f });
	ImGui::End();

	ImGui::End();
}
