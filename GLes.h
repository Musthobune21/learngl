#ifndef _GLES_H_
#define _GLES_H_
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
#include <math.h>
//variables and functions
extern char *BUFF,*BUFF2;
extern int width,height;
void framebuffersize_callback(GLFWwindow* win,int width,int height);
void key_callback(GLFWwindow* win,int key,int scancode,int action,int mode);
char* shader_file_reader(const char* filename);
void shader_compile(GLuint *name,GLenum shaderType,const char* path);
GLuint shader_link(GLuint ifvert,GLuint iffrag);
/*
typedef struct{
    bool MakeSureGenProgram;
    bool MakeSureUseProgram;
    GLuint IDforVert;
    GLuint IDforFrag;
}Use;
Use *use;
*/
#endif