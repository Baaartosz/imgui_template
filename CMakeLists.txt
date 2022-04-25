# CMakeList.txt : CMake project for imgui_template, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
project ("imgui_template" C CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DVK_PROTOTYPES")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_PROTOTYPES")


# GLFW
set(GLFW_DIR glfw/) # Set this to point to an up-to-date GLFW repo
option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)
option(GLFW_DOCUMENT_INTERNALS "Include internals in documentation" OFF)
add_subdirectory(${GLFW_DIR} binary_dir EXCLUDE_FROM_ALL)
include_directories(${GLFW_DIR}/include)

# Dead ImGUI
set(IMGUI_DIR imgui/)
include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends)

# Libraries
find_package(Vulkan REQUIRED)
#find_library(VULKAN_LIBRARY
  #NAMES vulkan vulkan-1)
#set(LIBRARIES "glfw;${VULKAN_LIBRARY}")
set(LIBRARIES "glfw;Vulkan::Vulkan")

file(GLOB sources *.cpp)

# Add source to this project's executable.
add_executable(imgui_template ${sources} ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp 
											  ${IMGUI_DIR}/backends/imgui_impl_vulkan.cpp
											  ${IMGUI_DIR}/imgui.cpp 
											  ${IMGUI_DIR}/imgui_draw.cpp 
											  ${IMGUI_DIR}/imgui_demo.cpp	
										      ${IMGUI_DIR}/imgui_tables.cpp
											  ${IMGUI_DIR}/imgui_widgets.cpp)

target_link_libraries(imgui_template ${LIBRARIES})
