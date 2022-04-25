// imgui_template.cpp : Defines the entry point for the application.
//

#include "imgui_template.h"
#include "imgui/imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_vulkan.h"
#include <stdio.h>          // printf, fprintf
#include <stdlib.h>         // abort
#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
