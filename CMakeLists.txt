# CMakeList.txt : CMake project for imgui_template, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("imgui_template")


# Libraries
find_package(Vulkan REQUIRED)
#find_library(VULKAN_LIBRARY
  #NAMES vulkan vulkan-1)
#set(LIBRARIES "glfw;${VULKAN_LIBRARY}")
set(LIBRARIES "glfw;Vulkan::Vulkan")

# Add source to this project's executable.
add_executable (imgui_template "imgui_template.cpp" "imgui_template.h")

# TODO: Add tests and install targets if needed.
