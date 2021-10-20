
-----------------------------------------------------
-- Saz
-----------------------------------------------------

project "Saz"
	kind		"StaticLib"
	dependson { "Core", "Imgui", "GLFW", "Glad" }
	location	"%{wks.location}/Projects/Saz"
	pchheader "SazPCH.h"
	pchsource "Saz/SazPCH.cpp"

	vpaths 
	{ 
		{ ["Source/*"] = {  
			"Saz/**.h", 
			"Saz/**.cpp", 
			"Saz/**.inl" } },
	}

	flags
	{
		"MultiProcessorCompile"
	}

	IncludeDir = {}
	IncludeDir["GLFW"] = "%{wks.location}/3rdParty/GLFW/include"
	IncludeDir["glad"] = "%{wks.location}/3rdParty/glad/include"
	IncludeDir["ImGui"] = "%{wks.location}/3rdParty/imgui"
	IncludeDir["imguisfml"] = "%{wks.location}/3rdParty/imgui-sfml"
	IncludeDir["entt"] = "%{wks.location}/3rdParty/entt/include"
	IncludeDir["spdlog"] = "%{wks.location}/3rdParty/spdlog/include"
	IncludeDir["Vulkan"] = "%{wks.location}/3rdParty/Vulkan/Include/"

	includedirs {
		"%{wks.location}/Code/Core/",
		"%{wks.location}/3rdParty/",
		"%{wks.location}/3rdParty/SFML/Include/",
		"%{wks.location}/3rdParty/imgui-sfml/",
		"%{wks.location}/3rdParty/glm/",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Vulkan}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.imguisfml}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.spdlog}",
	}

	libdirs
	{
		"%{wks.location}/Build/Core/%{cfg.buildcfg}_%{cfg.platform}/",
		"%{wks.location}/Build/Glad/%{cfg.buildcfg}_%{cfg.platform}/",
		"%{wks.location}/3rdParty/Vulkan/Library/",
		"%{wks.location}/Build/ImGui/%{cfg.buildcfg}_%{cfg.platform}/",
		"%{wks.location}/Build/GLFW/%{cfg.buildcfg}_%{cfg.platform}/",
	}

	links {
		"Core",
		"GLFW",
		"Glad",
		"vulkan-1.lib",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines{
			"SAZ_PLATFORM_WINDOWS",
			"SAZ_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
			"VK_INSTANCE_LAYERS",
			"VK_LAYER_PATH",
		}


	filter "files:%{wks.location}/3rdParty/**.cpp"
		flags { "NoPCH" }