workspace "Apollo"
   architecture "x64"

   configurations {"Debug", "Release", "Dist"}
   OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

   project "Apollo"
      location "Apollo"
      kind "SharedLib"
      language "c++"
      targetdir ("bin/"..OutputDir.."/%{prj.name}")
      objdir ("bin-int/"..OutputDir.."/%{prj.name}")
      files 
      {
          "%{prj.name/src/**.h",
          "%{prj.name/src/**.cpp"
            
      }
      includedirs
      {
          "dependencies/vendor/spdlog/include"

      }
      filter "system:windows"
          cppdialect   "c++17"
          staticruntime "on"
          systemversion "latest"
      defines 
      {
          "AP_PLATFORM_WINDOWS",
          "AP_BUILD_DLL"
          
      }
      postbuildcommands {
          ("{copy} %{cfg.buildtarget.relpath} ../bin/" .. OutputDir .."/SandBox")
      }
      filter "configurations:Debug"
           defines "AP_DEBUG"
           symbols "on"

      filter "configurations:Release"
           defines "AP_RELEASE"
           optimize "on"


      filter "configurations:Dist"
           defines "AP_DIST"
           optimize "on"

   project "SandBox"
      location "SandBox"
      kind "ConsoleApp"
      language "c++"

      targetdir ("bin/"..OutputDir.."/%{prj.name}")
      objdir ("bin-int/"..OutputDir.."/%{prj.name}")

      files 
      {
          "%{prj.name}/src/**.h",
          "%{prj.name}/src/**.cpp"
        
            
      }
      includedirs
      {
          "dependencies/vendor/spdlog/include",
          "Apollo/src"
      }
        filter "system:windows"
          cppdialect   "c++17"
          staticruntime "on"
          systemversion "latest"
      defines 
      {
          "AP_PLATFORM_WINDOWS",
      }
      links 
      {
          "Apollo"
      }
    
      filter "configurations:Debug"
           defines "AP_DEBUG"
           symbols "on"

      filter "configurations:Release"
           defines "AP_RELEASE"
           optimize "on"


      filter "configurations:Dist"
           defines "AP_DIST"
           optimize "on"


