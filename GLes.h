#ifndef _GLES_H_
#define _GLES_H_
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
//variables and functions
extern int width,height;
extern const GLchar *VSSource,*FSSource;
void framebuffersize_callback(GLFWwindow* win,int width,int height);
void key_callback(GLFWwindow* win,int key,int scancode,int action,int mode);
#endif