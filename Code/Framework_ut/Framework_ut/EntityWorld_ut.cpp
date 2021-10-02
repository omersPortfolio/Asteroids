#include <Framework/FrameworkPCH.h>
#include <Catch2/catch.hpp>
#include <Framework/EntityWorld.h>
#include <Framework/System.h>

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
			constexpr core::TypeId typeId = core::ToTypeId<Type>();
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
	SECTION("Components are registered")
	{
		TestWorld world;
		CHECK(!world.IsRegistered<ComponentA>());

		world.RegisterComponent<ComponentA>();
		CHECK(world.IsRegistered<ComponentA>());
	}
}
