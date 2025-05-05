#include "GLes.h"
void key_callback(GLFWwindow* win,int key,int scancode,int action,int mode)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(win, GL_TRUE);
}
void framebuffersize_callback(GLFWwindow* win,int width,int height)
{
    glfwGetFramebufferSize(win,&width,&height);
    glViewport(0,0,width,height);
}
