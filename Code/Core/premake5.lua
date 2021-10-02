
project "Core"
	kind		"StaticLib"
	location	"%{wks.location}/Projects/Core"

	vpaths 
	{ 
		{ ["Source/*"] = {  
			"Core/**.h", 
			"Core/**.cpp", 
			"Core/**.inl" } },
	}

	includedirs 
	{
		"%{wks.location}/Code/Core/",
	}
