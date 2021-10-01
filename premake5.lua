
-----------------------------------------------------
-- Workspace
-----------------------------------------------------
workspace "Project"
	configurations	{ "Debug", "Release" }
	platforms		{ "x64" }
	location		"build"
	characterset	"MBCS"
	startproject	"Game"

	filter "configurations:Debug"
		symbols		"on"

-----------------------------------------------------
-- Framework
-----------------------------------------------------
project "Framework"
	kind		"StaticLib"
	location	"build/Framework"
	cppdialect	"C++17"

	files {
		"Framework/Source/**.cpp",
		"Framework/Source/**.h",
		"Framework/Libraries/SFML/include/**.hpp",
		"Framework/Libraries/SFML/include/**.inl",
		"Framework/Libraries/imgui/*.cpp",
		"Framework/Libraries/imgui/*.h",
		"Framework/Libraries/entt/include/entt.hpp",
		"Framework/Libraries/imgui-sfml/**.h",
		"Framework/Libraries/rapidjson/include/rapidjson/**.h"
	}

	includedirs {
		"Framework/Source",
		"Framework/Libraries",
		"Framework/Libraries/SFML/include",
		"Framework/Libraries/imgui-sfml",
		"Framework/Libraries/imgui",
		"Framework/Libraries/entt/include",
	}

	libdirs
	{
		"Framework/Libraries/SFML/lib"
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

	pchheader "FrameworkPCH.h"
	pchsource "Framework/Source/Core/FWCore.cpp"

	filter "files:Framework/Libraries/imgui/*.cpp"
		flags { "NoPCH" }

	filter "files:Framework/Libraries/SFML/src/**.cpp"
		flags { "NoPCH" }

	filter "files:Framework/Source/imgui/*.cpp"
		flags { "NoPCH" }


-----------------------------------------------------
-- Game
-----------------------------------------------------
project "Game"
	kind		"WindowedApp"
	location	"build/Game"
	debugdir	"Game"
	cppdialect	"C++17"

	files {
		"Game/Source/**.cpp",
		"Game/Source/**.h",
		"premake5.lua",
		".gitignore",
		"GenerateProjectFiles.bat",
	}

	includedirs {
		"Game/Source",
		"Framework/Libraries",
		"Framework/Libraries/SFML/include",
		"Framework/Libraries/entt/include",
	}

	libdirs
	{
		"Framework/Libraries/SFML/lib"
	}

	links {
		"Framework"
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

	pchheader "GamePCH.h"
	pchsource "Game/Source/WinMain.cpp"

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



-----------------------------------------------------
-- UnitTest
-----------------------------------------------------
project "UnitTest"
	kind		"ConsoleApp"
	location	"build/UnitTest"
	cppdialect	"C++17"

	includedirs {
		"UnitTest/Libraries/Catch2/src",
		"Framework/Libraries",
		"Framework/Libraries/SFML/include",
		"Framework/Libraries/entt/include",
	}

	files {
		"UnitTest/Libraries/Catch2/src/**.cpp",
		"UnitTest/Libraries/Catch2/src/**.hpp",
		"UnitTest/Source/**.h",
		"UnitTest/Source/**.cpp",
	}


	links {
		"Framework"
	}

	pchheader "UnitTestPCH.h"
	pchsource "UnitTest/Source/Test.cpp"

	filter "files:UnitTest/Libraries/Catch2/**.cpp"
		flags { "NoPCH" }