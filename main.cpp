#include "font.hpp"
#include <GLFW/glfw3.h>
#include <jstl/opengl/camera.hpp>
#include <jstl/opengl/window.hpp>
#include <memory>

int main(int argc, char *argv[]) {
	jstl::opengl::Window window("Font renderer");
	FontRenderer fontRenderer{};
	std::unique_ptr<Camera> camera = std::make_unique<Camera>(window);
	
	while (!glfwWindowShouldClose(window.window)) {
		fontRenderer.renderText(Font::defaultFont(), "Hello!", window.resolution.x / 2, window.resolution.y / 2, 1.0, glm::vec4(1.0), camera);
		glfwPollEvents();
		glfwSwapBuffers(window.window);
	}
	
	return 0;
}