#include "font.hpp"
#include <GLFW/glfw3.h>
#include <jstl/opengl/camera.hpp>
#include <jstl/opengl/window.hpp>

int main(int argc, char *argv[]) {
	jstl::opengl::Window window("Font renderer");
	FontRenderer fontRenderer{};
	
	while (!glfwWindowShouldClose(window.window)) {
		fontRenderer.setViewport(window.resolution);
		fontRenderer.renderText("Hello!", window.resolution.x / 2 - 48, window.resolution.y / 2, 1.0, glm::vec4(1.0));
		
		glfwPollEvents();
		glfwSwapBuffers(window.window);
	}
	
	return 0;
}