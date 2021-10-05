project "Saz_ut"
	kind "ConsoleApp"
	dependson { "Core", "Saz" }
	location "%{wks.location}/Projects/Framework_ut"

	defines { "T_UNIT_TEST" }

	vpaths 
	{ 
		{ ["Source/*"] = {  
			"Framework_ut/**.h", 
			"Framework_ut/**.cpp", 
			"Framework_ut/**.inl" } },
	}

	includedirs 
	{
		"%{wks.location}/3rdParty/",
		"%{wks.location}/3rdParty/spdlog/include/",
		"%{wks.location}/3rdParty/glad/include/",
		"%{wks.location}/3rdParty/glad/src/",
		"%{wks.location}/Code/Core/",
		"%{wks.location}/Code/Saz/",
		--"%{wks.location}/3rdParty/entt/include/",
	}

	libdirs
	{
		"%{wks.location}/3rdParty/",
		"%{wks.location}/Build/Saz/%{cfg.buildcfg}_%{cfg.platform}/",
		"%{wks.location}/3rdParty/SFML/Library/%{cfg.buildcfg}/",
	}

	links 
	{
		"Saz",
	}

	filter "Debug"
		links 
		{ 
			"sfml-audio-d.lib",
			"sfml-graphics-d.lib",
			"sfml-main-d.lib",
			"sfml-network-d.lib",
			"sfml-system-d.lib",
			"sfml-window-d.lib",
		}
	filter "Release"
		links 
		{ 
			"sfml-audio.lib",
			"sfml-graphics.lib",
			"sfml-main.lib",
			"sfml-network.lib",
			"sfml-system.lib",
			"sfml-window.lib",
		}
	filter {} -- disable the filter

	postbuildcommands 
	{ 
		"{COPY} %{wks.location}/3rdParty/*.dll $(OutDir)",
		"{COPY} %{wks.location}/3rdParty/SFML/Binary/%{cfg.buildcfg}/*.dll $(OutDir)",
	}


	filter "system:windows"
		systemversion "latest"
		defines
		{
			"SAZ_PLATFORM_WINDOWS"
		}