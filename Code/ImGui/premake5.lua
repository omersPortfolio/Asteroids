project "Imgui"
	kind "StaticLib"
	location "%{wks.location}/Projects/Imgui"

	files 
	{
		"%{wks.location}/3rdParty/imgui/*.h",
		"%{wks.location}/3rdParty/imgui/*.cpp",
		"%{wks.location}/3rdParty/imgui/*.inl",
		"%{wks.location}/3rdParty/imgui-sfml/*.h",
		"%{wks.location}/3rdParty/imgui-sfml/*.cpp",
		"%{wks.location}/3rdParty/imgui-sfml/*.inl",
	}

	includedirs 
	{ 
		"%{wks.location}/3rdParty/",
		"%{wks.location}/3rdParty/imgui/",
		"%{wks.location}/3rdParty/imgui-sfml/",
		"%{wks.location}/3rdParty/SFML/Include/",
	}
