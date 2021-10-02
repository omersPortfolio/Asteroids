
-----------------------------------------------------
-- Workspace
-----------------------------------------------------
workspace "Project"
	architecture "x86_64"
	configurations	{ "Debug", "Release" }
	platforms		{ "x64" }
	dependson { "ZERO_CHECK" }
	startproject	"Game"
	language "C++"
	cppdialect	"C++17"

	targetdir "%{wks.location}/Build/%{prj.name}/%{cfg.buildcfg}_%{cfg.platform}/"
	objdir "%{wks.location}/Intermediate/%{prj.name}/%{cfg.buildcfg}_%{cfg.platform}/"

	disablewarnings { "26812" }

	filter "Debug"
		defines { "_DEBUG", "T_DEBUG", "T_ENABLE_ASSERTS" }
		optimize "Off"
		runtime "Debug"
		symbols "On"
	filter "Release"
		defines { "NDEBUG", "T_RELEASE" }
		optimize "Speed"
		runtime "Release"
		symbols "Off"
	filter {} -- disable the filter


	files 
	{ 
		"%{wks.location}/Code/%{prj.name}/%{prj.name}/**.h",
		"%{wks.location}/Code/%{prj.name}/%{prj.name}/**.cpp",
		"%{wks.location}/Code/%{prj.name}/%{prj.name}/**.inl",
		"%{wks.location}/Code/%{prj.name}/premake5.*",
	}

	vpaths 
	{ 
		{ ["/"] = { "**premake5.lua" } },
	}

	filter "files:%{wks.location}/3rdParty/**.cpp"
		flags { "NoPCH" }

	include "Code/Framework/premake5.lua"
	include "Code/Core/premake5.lua"
	include "Code/ImGui/premake5.lua"
	include "Code/Game/premake5.lua"

	group "ut"
		include "Code/Core_ut/premake5.lua"
		include "Code/Framework_ut/premake5.lua"
	group ""

project "ZERO_CHECK"
	kind "ConsoleApp"
	language "C++"
	location "%{wks.location}/Projects/ZERO_CHECK"
	files { "%{wks.location}/premake5.lua" }

	-- fix the path
	buildcommands { "cd D:/Dev/MyFramework & call GenerateProjectFiles.bat" }
	buildoutputs { "unused.txt" }