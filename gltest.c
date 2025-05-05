#include "GLes.h"

int main(int argc,char *argv[])
{   //Windows&&GLEW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_TRUE);
	GLFWwindow* win=glfwCreateWindow(640,480,"GLTEST",NULL,NULL);
	if(win==NULL)
	{
		printf("an AMC duty!unable to create window!\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(win);
	glfwSetKeyCallback(win, key_callback);
	glfwSetFramebufferSizeCallback(win,framebuffersize_callback);
	glewExperimental=GL_TRUE;
	glewInit();
	//glfwGetFramebufferSize(win,&width,&height);
	//glViewport(0,0,width,height);
	//Shaders
	GLfloat vertatri[]=
	{
		-0.5f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		0.0f,0.5f,0.0f
	};
	GLuint vershader=glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vershader,1,&VSSource,NULL);
	glCompileShader(vershader);
	GLuint fragshader=glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragshader,1,&FSSource,NULL);
	glCompileShader(fragshader);
	GLuint shaderprogram=glCreateProgram();
	glAttachShader(shaderprogram,vershader);
	glAttachShader(shaderprogram,fragshader);
	glLinkProgram(shaderprogram);
	glDeleteShader(vershader);
	glDeleteShader(fragshader);
	//Elements
	GLuint vbo,vao;
	glGenBuffers(1,&vbo);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof vertatri,vertatri,GL_STATIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
    //Events
	while(!glfwWindowShouldClose(win))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderprogram);
		TimeValue=glfwGetTime();
		UpdateValue=(sin(TimeValue)/2.0f) + 0.5f;
		WhereUniform=glGetUniformLocation(shaderprogram,"transcolor");
		glUniform4f(WhereUniform,0.0f,UpdateValue,0.0f,1.0f);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		glfwSwapBuffers(win);
	}
	glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
	glfwTerminate();//End
	return 0;
}