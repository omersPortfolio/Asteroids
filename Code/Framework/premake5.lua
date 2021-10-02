
-----------------------------------------------------
-- Framework
-----------------------------------------------------
project "Framework"
	kind		"StaticLib"
	dependson { "Core", "Imgui" }
	location	"%{wks.location}/Projects/Framework"
	pchheader "FrameworkPCH.h"
	pchsource "Framework/FrameworkPCH.cpp"

	vpaths 
	{ 
		{ ["Source/*"] = {  
			"Framework/**.h", 
			"Framework/**.cpp", 
			"Framework/**.inl" } },
	}

	includedirs {
		"%{wks.location}/Code/Framework/",
		"%{wks.location}/Code/Core/",
		"%{wks.location}/3rdParty/",
		"%{wks.location}/3rdParty/SFML/Include/",
		"%{wks.location}/3rdParty/glfw/3.3.4/Include/",
		"%{wks.location}/3rdParty/ImGui/",
		"%{wks.location}/3rdParty/imgui-sfml/",
		"%{wks.location}/3rdParty/entt/include/",
		"%{wks.location}/3rdParty/spdlog/include/",
	}

	libdirs
	{
		"%{wks.location}/Build/Core/%{cfg.buildcfg}_%{cfg.platform}/",
		"%{wks.location}/3rdParty/glfw/3.3.4/Library/",
	}

	links {
		"Core.lib",
		"glfw3.lib",
	}
	