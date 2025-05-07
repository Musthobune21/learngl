#include "GLes.h"
void GLSLFileReader(char *vertfile,char *fragfile,char buffer[],char buffer2[])
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
	glShaderSource(fragOBJ,1,&fragSource,NULL);
	glCompileShader(fragOBJ);
	
	Program=glCreateProgram();
	glAttachShader(Program,verOBJ);
	glAttachShader(Program,fragOBJ);
	glLinkProgram(Program);
	glDeleteShader(verOBJ);
	glDeleteShader(fragOBJ);
	
	return Program;
}

if(use.ifuse == true) glUseProgram(use.PID);

if(use.setfile == true){
    GLSLFileReader(use.fvert,use.ffrag,use.BUFF,use.BUFF2);
    const GLchar *VSSource=&use.BUFF;
    const GLchar *FSSource=&use.BUFF2;
    use.PID = GLSLShaderCompiler(VSSource,FSSource);
}