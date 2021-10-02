project "Framework_ut"
	kind "ConsoleApp"
	dependson { "Core", "Framework" }
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
		"%{wks.location}/Code/Core/",
		"%{wks.location}/Code/Framework/",
	}

	libdirs 
	{ 
		"%{wks.location}/Build/Core/%{cfg.buildcfg}_%{cfg.platform}/",
		"%{wks.location}/Build/Framework/%{cfg.buildcfg}_%{cfg.platform}/"
	}
	
	links 
	{ 
		"Framework.lib",
	}