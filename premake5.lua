workspace "MythEngine"
  architecture "x64"
  startproject "Sandbox"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Myth"
  location "Myth"
  kind "SharedLib"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "%{prj.name}/src",
    "%{prj.name}/vendor/spdlog/include"
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "MYTH_PLATFORM_WINDOWS",
      "MYTH_BUILD_DLL"
    }

    postbuildcommands
    {
      ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

  filter "configurations:Debug"
    defines "MYTH_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "MYTH_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "MYTH_DIST"
    optimize "On"

project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "Myth/vendor/spdlog/include",
    "Myth/src"
  }

  links
  {
    "Myth"
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "MYTH_PLATFORM_WINDOWS"
    }

  filter "configurations:Debug"
    defines "MYTH_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "MYTH_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "MYTH_DIST"
    optimize "On"