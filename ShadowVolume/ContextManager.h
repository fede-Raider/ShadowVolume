#pragma once

#ifndef OPENGL_LAB_CONTEXTMANAGER_H
#define OPENGL_LAB_CONTEXTMANAGER_H

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW\glfw3.h>
#include <iostream>

#define WIDTH 800
#define HEIGHT 600

using namespace std;

typedef void(*keyCallback) (GLFWwindow* window, int key, int scancode, int action, int mode);
typedef void(*MouseButtonCallback) (GLFWwindow* window, double xpos, double ypos);

class ContextManager
{
public:
	ContextManager() {}

	virtual ~ContextManager() {}

	void initGLFW(GLuint minor = 3, GLuint major = 3, GLboolean resizer = GL_FALSE) {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, resizer);

		glfwWindowHint(GLFW_SAMPLES, 4);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_MULTISAMPLE);
	}
	void initWindow(GLuint width = WIDTH, GLuint height = HEIGHT) {
		window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
		//window = glfwCreateWindow(width, height, "LearnOpenGL", glfwGetPrimaryMonitor(), nullptr);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(window);
	}
	GLFWwindow* getWindow() {
		return window;
	}

	void initGLEW() {
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
		{
			std::cout << "Failed to initialize GLEW" << std::endl;
			return;
		}
	}
	void setKeyCallback(keyCallback cb) {
		glfwSetKeyCallback(getWindow(), cb);
	}

	void setMouseButtonCallback(MouseButtonCallback mc) {
		glfwSetInputMode(getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwSetCursorPosCallback(getWindow(), mc);
	}

	void exitContext() {
		glfwTerminate();
	}

private:
	GLFWwindow* window;
};

#endif //OPENGL_LAB_CONTEXTMANAGER_H
