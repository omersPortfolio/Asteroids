#include "SazPCH.h"
#include "LevelSystem.h"

#include "Saz/RenderSystem.h"
#include "Saz/ResourceManager.h"
#include "Saz/SpriteComponent.h"
#include "Saz/TransformComponent.h"
#include "Saz/LevelComponent.h"

#include <entt/entt.hpp>
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include "NameComponent.h"
#include "FileHelpers.h"
#include "InputComponent.h"

namespace ecs
{	
	LevelSystem::LevelSystem(Saz::ResourceManager& resourceManager)
		: m_ResourceManager(resourceManager)
	{

	}

	LevelSystem::~LevelSystem()
	{

	}

	void LevelSystem::Init()
	{

	}

	void LevelSystem::Update()
	{

	}

	bool LevelSystem::LoadFromFile(const FilePath& path)
	{
		const char* jsonSceneFile = Saz::LoadCompleteFile(path.u8string().c_str(), nullptr);
		if (!jsonSceneFile)
			return false;

		rapidjson::Document loadedScene;
		rapidjson::ParseResult ok = loadedScene.Parse(jsonSceneFile);
		delete[] jsonSceneFile;

		if (!ok)
			return false;

		for (rapidjson::Value& obj : loadedScene["Entities"].GetArray())
		{
			const ecs::Entity entity = m_World->CreateEntity();

			{
				component::LevelComponent& levelComponent = m_World->AddComponent<component::LevelComponent>(entity);
				levelComponent.m_Name = path.stem().string();
				levelComponent.m_Path = path.string();
			}

			{
				component::NameComponent& nameComp = m_World->AddComponent<component::NameComponent>(entity);
				const String& entityName = obj["Name"].GetString();
				nameComp.m_Name = !entityName.empty() ? entityName : "InvalidName";
			}

			if (obj.HasMember("IsPlayer"))
			{
				if (obj["IsPlayer"].GetBool() == true)
				{
					component::InputComponent& inputComponent = m_World->AddComponent<component::InputComponent>(entity);
				}
			}
		
			if (obj.HasMember("Components"))
			{
				for (rapidjson::Value& component : obj["Components"].GetArray())
				{
					const String& componentType = component["Type"].GetString();
					if (componentType == "TransformComponent")
					{
						component::TransformComponent& transformComponent = m_World->AddComponent<component::TransformComponent>(entity);
						if (component.HasMember("Pos"))
						{
							const float x = component["Pos"][0].GetFloat();
							const float y = component["Pos"][1].GetFloat();
							transformComponent.m_Position = vec2(x, y);
						}
						if (component.HasMember("Scale"))
						{
							const float x = component["Scale"][0].GetFloat();
							const float y = component["Scale"][1].GetFloat();
							transformComponent.m_Scale = vec2(x, y);
						}
					}
					if (componentType == "SpriteComponent")
					{
						component::SpriteComponent& spriteComponent = m_World->AddComponent<component::SpriteComponent>(entity);
						const String& textureName = component["TextureName"].GetString();
						spriteComponent.m_Texture = m_ResourceManager.GetTexture(textureName);
					}
				}
			}		
		}

		return true;
	}

}
