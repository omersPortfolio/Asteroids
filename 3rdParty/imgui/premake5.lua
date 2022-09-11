project "ImGui"
	kind "StaticLib"
	language "C++"
    cppdialect "C++17"
    location	"%{wks.location}/Projects/ImGui"

	files
	{
		"*.cpp",
		"*.h",
		"%{wks.location}/3rdParty/imgui/premake5.*"
	}

	includedirs 
	{ 
		"%{wks.location}/3rdParty/",
		"%{wks.location}/3rdParty/imgui/imgui",
	}

    defines
    {
         "IMGUI_API=__declspec(dllexport)"
    }