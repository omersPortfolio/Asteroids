-----------------------------------------------------
-- Workspace
-----------------------------------------------------
workspace "Saz"
	architecture "x64"
	configurations	{ "Debug", "Release" }
	platforms		{ "x64" }
	dependson { "ZERO_CHECK" }
	startproject	"Game"
	language "C++"
	cppdialect	"C++17"

	outputdir = "%{cfg.buildcfg}_%{cfg.platform}"
	
	targetdir ("%{wks.location}/Build/%{prj.name}/" .. outputdir )
	objdir ("%{wks.location}/Intermediate/%{prj.name}/" .. outputdir)
	
	disablewarnings { "26812" }

	filter "Debug"
		defines { "_DEBUG", "SAZ_DEBUG", "SAZ_ENABLE_ASSERTS" }
		optimize "Off"
		runtime "Debug"
		--buildoptions "/MDd"
		symbols "On"
	filter "Release"
		defines { "NDEBUG", "SAZ_RELEASE" }
		optimize "Speed"
		runtime "Release"
		--buildoptions "/MD"
		symbols "Off"
	filter {} -- disable the filter

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		
	}

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

	include "Code/Saz/premake5.lua"
	include "Code/Core/premake5.lua"
	include "Code/Game/premake5.lua"
	include "3rdParty/glad/premake5.lua"
	include "3rdParty/imgui/premake5.lua"
	include "3rdParty/GLFW/premake5.lua"

	group "ut"
		include "Code/Core_ut/premake5.lua"
		include "Code/Saz_ut/premake5.lua"
	group ""
	

project "ZERO_CHECK"
	kind "ConsoleApp"
	language "C++"
	location "%{wks.location}/Projects/ZERO_CHECK"
	files { "%{wks.location}/premake5.lua" }

	-- fix the path
	buildcommands { "cd %{wks.location} & call GenerateProjectFiles.bat" }
	buildoutputs { "unused.txt" }