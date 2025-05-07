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
void GLSLFileReader(char *vertfile,char *fragfile,char buffer[],char buffer2[]);
GLuint GLSLShaderCompiler(const GLchar *verSource,const GLchar *fragSource);
typedef struct
{
    char *fvert;
    char *ffrag;
    bool setfile;
    bool ifuse;
    GLuint PID;
    char BUFF[],BUFF2[];
}Use;
Use use;
#endif