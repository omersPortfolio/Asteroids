#pragma once

#include <Saz/System.h>

namespace Saz
{
	class ResourceManager;
}

namespace ecs 
{
	class SAZ_API LevelSystem final : public System
	{
	public:
		
		LevelSystem(Saz::ResourceManager& resourceManager);
		~LevelSystem();

		virtual void Init() override;
		virtual void Update() override;

		bool LoadFromFile(const FilePath& path);

	private:
		Saz::ResourceManager& m_ResourceManager;
	};
}
