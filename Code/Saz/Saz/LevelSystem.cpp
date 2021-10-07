#include "SazPCH.h"
#include "LevelSystem.h"

#include "Saz/RenderSystem.h"
#include "Saz/ResourceManager.h"
#include "Saz/RenderComponents.h"
#include "Saz/TransformComponent.h"
#include "Saz/LevelComponent.h"
#include "Saz/NameComponent.h"
#include "Saz/FileHelpers.h"
#include "Saz/InputComponent.h"

#include <entt/entt.hpp>

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

	bool LevelSystem::LoadFromFile(const String& filename)
	{
		FilePath relativePath = filename;
		const char* jsonSceneFile = Saz::file::LoadCompleteFile(relativePath.u8string().c_str(), nullptr);
		if (!jsonSceneFile)
		{
			SAZ_CORE_ERROR("File not found with path: {0}", relativePath.u8string());
			return false;
		}

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
				levelComponent.m_Name = relativePath.stem().string();
				levelComponent.m_Path = relativePath.string();
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
		
			// #todo: clean this up
			if (obj.HasMember("Components"))
			{
				for (rapidjson::Value& component : obj["Components"].GetArray())
				{
					const String& componentType = component["Type"].GetString();
					if (componentType == "TransformComponent")
					{
						component::TransformComponent& transformComponent = m_World->AddComponent<component::TransformComponent>(entity);
						if (component.HasMember("Pos"))
							Saz::file::JSONLoadVec2(component, "Pos", &transformComponent.m_Position);
						if (component.HasMember("Scale"))
							Saz::file::JSONLoadVec2(component, "Scale", &transformComponent.m_Scale);
					}
					if (componentType == "SpriteComponent")
					{
						component::SpriteComponent& spriteComponent = m_World->AddComponent<component::SpriteComponent>(entity);
						const String& textureName = component["TextureName"].GetString();
						spriteComponent.m_Texture = m_ResourceManager.GetTexture(textureName);
					}
					if (componentType == "RenderComponent")
					{
						component::RenderComponent& renderComp = m_World->AddComponent<component::RenderComponent>(entity);
						size_t b = sizeof(renderComp);
						StringView shapeType = component["ShapeType"].GetString();
						if (shapeType == "Rectangle")
						{
							if (component.HasMember("Size"))
							{
								float x = component["Size"][0].GetFloat();
								float y = component["Size"][1].GetFloat();

								renderComp.m_RectangleShape = m_ResourceManager.CreateRectangle("Rectangle", vec2(x, y));
								const String& textureName = component["TextureName"].GetString();
								renderComp.m_RectangleShape->setTexture(&m_ResourceManager.GetTexture(textureName));
							}							
						}
						else if (shapeType == "Circle")
						{
							const float radius = component["Radius"].GetFloat();
							const int pointCount = component["PointCount"].GetInt();
							const String& textureName = component["TextureName"].GetString();

							sf::CircleShape* circleShape = renderComp.m_CircleShape;
							circleShape = m_ResourceManager.CreateCircle("Circle", radius, pointCount);
							circleShape->setTexture(&m_ResourceManager.GetTexture(textureName));
							circleShape->setFillColor(sf::Color::Blue);
							circleShape->setOrigin(radius / 2, radius / 2);
						}
					}
				}
			}		
		}

		return true;
	}

}
