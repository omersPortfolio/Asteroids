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

	links 
	{ 
		"Saz",
	}

	filter "system:windows"
		systemversion "latest"
		defines
		{
			"SAZ_PLATFORM_WINDOWS"
		}