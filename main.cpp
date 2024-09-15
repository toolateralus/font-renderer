#include "font.hpp"
#include <GLFW/glfw3.h>
#include <jstl/opengl/camera.hpp>
#include <jstl/opengl/window.hpp>

using namespace jstl::opengl::font;

int main(int argc, char *argv[]) {
	
	Window window("Font renderer");
	FontRenderer fontRenderer{};
	
	fontRenderer.setViewport(window.resolution);
	
	auto pos = glm::vec2(window.resolution.x / 2 - 48, window.resolution.y / 2);
	
	window.setClearColor(glm::vec4(0.0, 0.0, 0.0, 1.0));
	
	glfwSwapInterval(1);
	
	while (!glfwWindowShouldClose(window.window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		std::string text = "Hello, Font!";
		
		fontRenderer.renderText(text, pos - (MeasureText(Font::defaultFont(), text, 1.0) / 2.0f), 1.0, glm::vec4(1.0));
		static float angle = 0.0f;
		float radius = 100.0f;
		pos.x = window.resolution.x / 2 + radius * cos(angle);
		pos.y = window.resolution.y / 2 - radius * sin(angle);
		angle += 0.01f;
		
		glfwPollEvents();
		glfwSwapBuffers(window.window);
	}
	
	return 0;
}