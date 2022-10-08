workspace "Appler"
	architecture "x64"
	startproject "ApplerCore"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}"

IncludeDir = {}
IncludeDir["GLFW"] = "ApplerCore/Vendor/GLFW/include"
IncludeDir["GLAD"] = "ApplerCore/Vendor/GLAD/include"
IncludeDir["GLM"] = "ApplerCore/Vendor/GLM"
IncludeDir["ImGUI"] = "ApplerCore/Vendor/ImGUI"
IncludeDir["ImGUIZMO"] = "ApplerCore/Vendor/ImGUIZMO"
IncludeDir["STB_IMAGE"] = "ApplerCore/Vendor/STB_IMAGE"

include "ApplerCore/Vendor/GLFW"
include "ApplerCore/Vendor/ImGUI"
	
project "ApplerCore"
	location "ApplerCore/Source"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++latest"
	staticruntime "On"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "arpch.h"
	pchsource "ApplerCore/Source/arpch.cpp"
	
	files
	{
		"ApplerCore/Source/**.h",
		"ApplerCore/Source/**.cpp",
		"ApplerCore/Vendor/GLAD/**.c",
		"ApplerCore/Vendor/STB_IMAGE/stb_image.h",
		"ApplerCore/Vendor/ImGUIZMO/ImGuizmo.h",
		"ApplerCore/Vendor/ImGUIZMO/ImGuizmo.cpp"
		
	}
	
	includedirs
	{
		"ApplerCore/Source",
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
	
	filter "files:ApplerCore/Vendor/**.c"
		flags { "NoPCH" }
		
	filter "files:ApplerCore/Vendor/**.cpp"
		flags { "NoPCH" }
		
	filter "files:ApplerCore/Source/stb_image.cpp"
		flags { "NoPCH" }
	
	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"ApplerCore_PLATFORM_WINDOWS"
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