#ifndef _GLES_H_
#define _GLES_H_
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
//variables and functions
extern int width,height;
void framebuffersize_callback(GLFWwindow* win,int width,int height);
void key_callback(GLFWwindow* win,int key,int scancode,int action,int mode);
int byte(FILE *fp);
void GLSLFileReader(char *GLSLfile,char buffer[]);//buffer must have a length
GLuint GLSLShaderCompiler(const GLchar *verSource,const GLchar *fragSource);
typedef struct
{
    static char *fvert;
    static char *ffrag;
    bool setfile;
    char BUFF[];
    char BUFF2[];
    GLuint PID;
    bool ifuse;
}Use;
Use Use;
#endif