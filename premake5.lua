
-----------------------------------------------------
-- Workspace
-----------------------------------------------------
workspace "Asteroids"
	configurations	{ "Debug", "Release" }
	platforms		{ "x64" }
	location		"build"
	characterset	"MBCS"
	startproject	"Asteroids"

	filter "configurations:Debug"
		symbols		"on"

-----------------------------------------------------
-- Asteroids Project
-----------------------------------------------------
project "Asteroids"
	kind		"WindowedApp"
	location	"build/Asteroids"
	cppdialect	"C++17"

	files {
		"Source/**.cpp",
		"Source/**.h",
		"premake5.lua",
		".gitignore",
		"GenerateProjectFiles.bat",
		"Libraries/SFML/include/**.hpp",
		"Libraries/SFML/include/**.inl",
		"Libraries/imgui/*.cpp",
		"Libraries/imgui/*.h",
		"Libraries/entt/include/entt.hpp",
		"Libraries/imgui-sfml/**.h"
	}

	includedirs {
		"Source",
		"Libraries",
		"Libraries/SFML/include",
		"Libraries/imgui-sfml",
		"Libraries/imgui",
		"Libraries/entt/include"
	}

	libdirs
	{
		"Libraries/SFML/lib"
	}

	links {
		"opengl32",
		"winmm",
		"gdi32"
	}

	defines
	{
		"SFML_STATIC"
	}

	filter "configurations:Debug"
		links {
			"sfml-window-s-d.lib",
			"sfml-audio-s-d.lib",
			"sfml-system-s-d.lib",
			"sfml-graphics-s-d.lib",
		}
	
	filter "configurations:Release"
		links {
			"sfml-window-s.lib",
			"sfml-audio-s.lib",
			"sfml-system-s.lib",
			"sfml-graphics-s.lib",
		}
	

	pchheader "GamePCH.h"
	pchsource "Source/WinMain.cpp"

	filter "files:Framework/Libraries/imgui/*.cpp"
		flags { "NoPCH" }