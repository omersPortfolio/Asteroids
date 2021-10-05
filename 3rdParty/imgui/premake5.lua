project "ImGui"
	kind "StaticLib"
	language "C++"
    cppdialect "C++17"

	files
	{
		"imconfig.h",
		"imgui.h",
		"imgui.cpp",
		"imgui_draw.cpp",
		"imgui_internal.h",
		"imgui_widgets.cpp",
		"imstb_rectpack.h",
		"imstb_textedit.h",
		"imstb_truetype.h",
		"imgui_demo.cpp",
		"%{wks.location}/3rdParty/imgui-sfml/*.cpp",
		"%{wks.location}/3rdParty/imgui-sfml/*.h",
		"%{wks.location}/3rdParty/imgui/premake5.*"
	}

	includedirs 
	{ 
		"%{wks.location}/3rdParty/",
		"%{wks.location}/3rdParty/imgui/",
		"%{wks.location}/3rdParty/imgui-sfml/",
		"%{wks.location}/3rdParty/SFML/Include/",
	}