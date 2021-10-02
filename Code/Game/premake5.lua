
-----------------------------------------------------
-- Game
-----------------------------------------------------
project "Game"
	kind		"ConsoleApp"
	dependson { "Core", "Framework", "ImGui" }
	location	"%{wks.location}/Projects/Game"
	pchheader "GamePCH.h"
	pchsource "Game/GamePCH.cpp"

	vpaths 
	{ 
		{ ["Source/*"] = {  
			"Game/**.h", 
			"Game/**.cpp", 
			"Game/**.inl" } },
	}

	includedirs {
		"%{wks.location}/Code/Game/",
		"%{wks.location}/Code/Framework/",
		"%{wks.location}/Code/Core/",
		"%{wks.location}/3rdParty/",
		"%{wks.location}/3rdParty/SFML/Include/",
		"%{wks.location}/3rdParty/entt/include/",
		"%{wks.location}/3rdParty/spdlog/include/",
	}

	libdirs
	{
		"%{wks.location}/3rdParty/",
		"%{wks.location}/3rdParty/SFML/Library/%{cfg.buildcfg}/",
		"%{wks.location}/3rdParty/glfw/3.3.4/Library/",
		"%{wks.location}/Build/Framework/%{cfg.buildcfg}_%{cfg.platform}/",
		"%{wks.location}/Build/Core/%{cfg.buildcfg}_%{cfg.platform}/",
		"%{wks.location}/Build/Imgui/%{cfg.buildcfg}_%{cfg.platform}/",
	}

	links {
		"Framework.lib",
		"Core.lib",
		"ImGui.lib",

		"glfw3.lib",

		"flac.lib",
		"freetype.lib",
		"gdi32.lib",
		"ogg.lib",
		"openal32.lib",
		"opengl32.lib",
		"vorbis.lib",
		"vorbisenc.lib",
		"vorbisfile.lib",
		"winmm.lib",
		"ws2_32.lib",
		"winmm.lib",
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

	