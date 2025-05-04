#include "GLes.h"
void key_callback(GLFWwindow* win,int key,int scancode,int action,int mode)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(win, GL_TRUE);
}