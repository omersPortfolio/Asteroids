#pragma once

class Entity;


namespace fw
{
	class GameCore;
	class Level
	{
		friend class Entity;

	public:
		Level(GameCore* pGameCore);
		virtual ~Level();

	public:
		virtual void Init();

		virtual void Update(float delta);

		virtual void Draw(sf::RenderWindow* pWindow);

		Entity CreateEntity(const std::string& name = std::string());

		template<typename T>
		auto View()
		{
			return m_Registry.view<T>();
		}

		template<typename T1, typename T2>
		auto View()
		{
			return m_Registry.view<T1, T2>();
		}

		GameCore* GetGameCore() { return m_pGameCore; }

		void LoadFromFile(const std::string& filename);

	protected:
		entt::registry m_Registry;
		GameCore* m_pGameCore = nullptr;
	};
}
