#include "GLes.h"


void GLSLFileReader(char *vertfile,char fragfile,char buffer[],char buffer2[])
{
    FILE *ifvert,*iffrag;
    int lenv,lenf;
    ifvert=fopen(vertfile,"r");
    lenv=byte(ifvert);
    while(fgets(buffer,lenv,ifvert));
    fclose(ifvert);
    iffrag=fopen(fragfile,"r");
    lenf=byte(iffrag);
    while(fgets(buffer2,lenf,iffrag));
    fclose(iffrag);
}
int byte(FILE *fp)
{
    int length;
    fseek(fp, 0, SEEK_END);
    length=ftell(fp) + 1;
    fseek(fp,0,SEEK_SET);
    return length;
}
GLuint GLSLShaderCompiler(const GLchar *verSource,const GLchar *fragSource)
{
    GLuint verOBJ,fragOBJ,Program;
    verOBJ=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(verOBJ,1,&verSource,NULL);
    glCompileShader(verOBJ);
    
    fragOBJ=glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragOBJ,1,&FragSource,NULL);
	glCompileShader(fragOBJ);
	
	Program=glCreateProgram();
	glAttachShader(Program,verOBJ);
	glAttachShader(Program,fragOBJ);
	glLinkProgram(Program);
	glDeleteShader(verOBJ);
	glDeleteShader(fragOBJ);
	
	return Program;
}
if(Use.ifuse==true)
    glUseProgram(Use.PID);
if(Use.setfile==true)
{
    GLSLFileReader(Use.fvert,Use.ffrag,Use.Use.BUFF,Use.BUFF2);
    const GLchar *VSSource=&Use.BUFF;
    const GLchar *FSSource=&Use.BUFF;
    Use.PID = GLSLShaderCompiler(VSSource,FSSource);
}