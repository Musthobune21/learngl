#ifndef _LEARNGL_H_
#define _LEARNGL_H_
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cglm/cglm.h>
#include <stb/stb_image.h>
#include "shader.h"
#include "texture.h"
//variables and functions
extern int width,height;
void framebuffersize_callback(GLFWwindow* win,int width,int height);
void key_callback(GLFWwindow* win,int key,int scancode,int action,int mode);
#endif
