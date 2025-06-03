#ifndef _SHADER_H_
#define _SHADER_H_
char* shader_file_reader(const char* filename);
void shader_compile(GLuint *name,GLenum shaderType,const char* path);
GLuint shader_link(GLuint ifvert,GLuint iffrag);
void set_mat4(const char *uniform_var,const GLfloat *array,GLuint prog);
#endif