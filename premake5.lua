workspace "Appler"
	architecture "x64"
	startproject "Appler"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}"

IncludeDir = {}
IncludeDir["GLFW"] = "Appler/Vendor/GLFW/include"
IncludeDir["GLAD"] = "Appler/Vendor/GLAD/include"
IncludeDir["GLM"] = "Appler/Vendor/GLM"
IncludeDir["ImGUI"] = "Appler/Vendor/ImGUI"
IncludeDir["ImGUIZMO"] = "Appler/Vendor/ImGUIZMO"
IncludeDir["STB_IMAGE"] = "Appler/Vendor/STB_IMAGE"

include "Appler/Vendor/GLFW"
include "Appler/Vendor/ImGUI"
	
project "Appler"
	location "Appler/Source"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "arpch.h"
	pchsource "Appler/Source/arpch.cpp"
	
	files
	{
		"Appler/Source/**.h",
		"Appler/Source/**.cpp",
		"Appler/Vendor/GLAD/**.c",
		"Appler/Vendor/STB_IMAGE/stb_image.h",
		"Appler/Vendor/ImGUIZMO/ImGuizmo.h",
		"Appler/Vendor/ImGUIZMO/ImGuizmo.cpp"
		
	}
	
	includedirs
	{
		"Appler/Source",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.GLM}",
		"%{IncludeDir.STB_IMAGE}",
		"%{IncludeDir.ImGUI}",
		"%{IncludeDir.ImGUIZMO}",
	}
	
	links
	{
		"GLFW",
		"ImGUI",
		"opengl32.lib"
	}
	
	filter "files:Appler/Vendor/**.c"
		flags { "NoPCH" }
		
	filter "files:Appler/Vendor/**.cpp"
		flags { "NoPCH" }
		
	filter "files:Appler/Source/stb_image.cpp"
		flags { "NoPCH" }
	
	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"APPLER_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "AR_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "AR_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "AR_DIST"
		optimize "On"