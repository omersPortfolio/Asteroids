#include "SazPCH.h"
#include "CameraSystem.h"

#include "Saz/GameTime.h"
#include "Saz/CameraComponent.h"
#include "Saz/InputComponent.h"
#include "Saz/MovementComponent.h"
#include "Saz/TransformComponent.h"

#include <entt/entt.hpp>

namespace
{
	constexpr float s_TranslateSpeed = 1000.f;
	constexpr float s_RotateSpeed = 250.0f;
}

namespace ecs
{	

	CameraSystem::CameraSystem()
	{
	}

	void CameraSystem::Update(const Saz::GameTime& gameTime)
	{
		auto& registry = m_World->m_Registry;
		const auto cameraView = registry.view<component::CameraComponent, component::TransformComponent, component::MovementComponent>();
		for (const auto& entity : cameraView)
		{
			const auto inputView = registry.view<component::InputComponent>();
			for (auto& inputEntity : inputView)
			{
				const auto& inputComponent = inputView.get<component::InputComponent>(inputEntity);

				component::CameraComponent& cameraComponent = cameraView.get<component::CameraComponent>(entity);
				component::TransformComponent& transformComponent = cameraView.get<component::TransformComponent>(entity);
				component::MovementComponent& movementComponent = cameraView.get<component::MovementComponent>(entity);

				float speed = movementComponent.m_Speed * gameTime.m_DeltaTime;

				vec3& position = transformComponent.m_Position;
				vec3& rotation = transformComponent.m_Rotation;	
				

				/*vec3 rot(0.0f);
				if (inputComponent.IsKeyHeld(Input::EKeyboard::J))
					rot.y += -1.0f;
				if (inputComponent.IsKeyHeld(Input::EKeyboard::L))
					rot.y += 1.0f;
				if (inputComponent.IsKeyHeld(Input::EKeyboard::I))
					rot.x += 1.0f;
				if (inputComponent.IsKeyHeld(Input::EKeyboard::K))
					rot.x += -1.0f;*/

				vec3 translateDir = vec3::Zero();

				if (inputComponent.IsKeyHeld(Input::EKeyboard::W))
					translateDir.z += 1.0f;
				if (inputComponent.IsKeyHeld(Input::EKeyboard::S))
					translateDir.z -= 1.0f;
				if (inputComponent.IsKeyHeld(Input::EKeyboard::A))
					translateDir.x -= 1.0f;
				if (inputComponent.IsKeyHeld(Input::EKeyboard::D))
					translateDir.x += 1.0f;
				if (inputComponent.IsKeyHeld(Input::EKeyboard::Q))
					translateDir.y -= 1.0f;
				if (inputComponent.IsKeyHeld(Input::EKeyboard::E))
					translateDir.y += 1.0f;
				
				if (inputComponent.IsKeyHeld(Input::EKeyboard::Shift_L))
					speed *= 3.f;

				translateDir.Normalize();
				position += (translateDir * speed) * Quaternion::FromRotator(rotation);

				if (inputComponent.IsKeyHeld(Input::EMouse::Right))
				{
					vec3 rotator = vec3::Zero();
					rotator.x = inputComponent.m_MouseDelta.y * s_RotateSpeed * gameTime.m_DeltaTime;
					rotator.y = -inputComponent.m_MouseDelta.x * s_RotateSpeed * gameTime.m_DeltaTime;

					rotation += rotator;

					//SAZ_CORE_INFO("CamRot: vec3({0},{1},{2})", rotation.x, rotation.y, rotation.z);
					SAZ_CORE_INFO("MouseDeltaX: {0}", inputComponent.m_MouseDelta.x);
				}
			}
		}
	}
}
