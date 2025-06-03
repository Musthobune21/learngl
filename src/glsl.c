#include "../include/GLes.h"
char* shader_file_reader(const char* filename)
{
    FILE *fp;
    char* content;
    long size;
    fp=fopen(filename,"rb");
    if(fp==NULL) return "";
    fseek(fp,0L,SEEK_END);
    size=ftell(fp)+1;
    fclose(fp);
    fp=fopen(filename,"r");
    content=(char*)calloc(size,1);
    fread(content, 1, size-1, fp);
    fclose(fp);
    return content;
}
void shader_compile(GLuint *name,GLenum shaderType,const char* path)
{
    GLint ifCompiled;
    const GLchar* itsSource=shader_file_reader(path);
    *name=glCreateShader(shaderType);
    if(*name == 0) 
        printf("COULD NOT LOAD SHADER: %s!\n", path);
    glShaderSource(*name,1,(const GLchar**)&itsSource,NULL);
    glCompileShader(*name);
    //checkerror
    glGetShaderiv(*name,GL_COMPILE_STATUS,&ifCompiled);
    if(ifCompiled==GL_FALSE){
        printf("Shader Compile Error: %s!\n", path);
        glDeleteShader(*name);
        return;
    }
        
    free((void *)itsSource);
}
GLuint shader_link(GLuint ifvert,GLuint iffrag)
{
    GLint ifLinked;
    GLuint Program = glCreateProgram();
    glAttachShader(Program,ifvert);
	glAttachShader(Program,iffrag);
	glLinkProgram(Program);
	//checkerror
	glGetProgramiv(Program,GL_LINK_STATUS,&ifLinked);
    if(ifLinked==GL_FALSE) {
        printf("Shader Program Link Error\n");
        glDeleteShader(ifvert);
        glDeleteShader(iffrag);
        return 1u;
    }
	glDeleteShader(ifvert);
	glDeleteShader(iffrag);
	return Program;
}
