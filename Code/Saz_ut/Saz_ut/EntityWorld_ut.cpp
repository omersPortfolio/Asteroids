#include <Saz/SazPCH.h>
#include <Catch2/catch.hpp>

#include <Saz/EntityWorld.h>
#include <Saz/System.h>

namespace 
{
	struct ComponentA
	{
		bool m_Bool = true;
	};

	class SystemA : public ecs::System
	{
	};

	class TestWorld : public ecs::EntityWorld
	{
	public:
		template<typename Type>
		bool IsRegistered()
		{
			constexpr Saz::TypeId typeId = Saz::ToTypeId<Type>();
			if constexpr (std::is_base_of<ecs::System, Type>::value)
			{
				auto result = std::find_if(m_SystemEntries.begin(), m_SystemEntries.end(),
					[&typeId](const ecs::SystemEntry& entry)
					{
						return entry.m_TypeId == typeId;
					});

				return result != m_SystemEntries.end();
			}
			else
			{
				auto result = std::find_if(m_ComponentEntries.begin(), m_ComponentEntries.end(),
					[&typeId](const ecs::ComponentEntry& entry)
					{
						return entry.m_TypeId == typeId;
					});

				return result != m_ComponentEntries.end();
			}
		}
	};
}
TEST_CASE("EntityWorld")
{
	TestWorld world;

	SECTION("Systems and Components are properly registered")
	{
		CHECK(!world.IsRegistered<ComponentA>());
		CHECK(!world.IsRegistered<SystemA>());

		world.RegisterComponent<ComponentA>();
		CHECK(world.IsRegistered<ComponentA>());

		world.RegisterSystem<SystemA>();
		CHECK(world.IsRegistered<SystemA>());
	}

	SECTION("Components are added / removed properly")
	{
		auto entity = world.CreateEntity();
		REQUIRE(world.IsAlive(entity));
		REQUIRE(!world.HasComponent<ComponentA>(entity));

		world.AddComponent<ComponentA>(entity);
		CHECK(world.HasComponent<ComponentA>(entity));

		world.RemoveComponent<ComponentA>(entity);
		CHECK(!world.HasComponent<ComponentA>(entity));
	}
}
