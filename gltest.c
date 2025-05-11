#include "GLes.h"

int main(int argc,char *argv[])
{   //GLinit
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_TRUE);
	GLFWwindow* win=glfwCreateWindow(640,480,"GLTEST",NULL,NULL);
	if(win==NULL)
	{
		printf("unable to create window!\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(win);
	glfwSetKeyCallback(win, key_callback);
	glfwSetFramebufferSizeCallback(win,framebuffersize_callback);
	glewExperimental=GL_TRUE;
	glewInit();
	//shaders
	GLfloat vertatri[]=
	{
		-0.5f,-0.5f,0.0f,1.0f,0.0f,0.0f
		0.5f,-0.5f,0.0f,0.0f,1.0f,0.0f
		0.0f,0.5f,0.0f,0.0f,0.0f,1.0f
	};
GLuint VertexID,FragmentID,PID;
shader_compile(&VertexID,GL_VERTEX_SHADER,"./vertex.glsl");
shader_compile(&FragmentID,GL_FRAGMENT_SHADER,"./fragment.glsl");
PID=shader_link(VertexID,FragmentID);
	//Elements
	GLuint vbo,vao;
	glGenBuffers(1,&vbo);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof vertatri,vertatri,GL_STATIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(GLfloat), (GLvoid*)0);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(GLfloat),(GLvoid*)3*sizeof(GLfloat));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
    //Events
	while(!glfwWindowShouldClose(win))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(PID);
		/*GLfloat TimeValue=glfwGetTime();
	    GLfloat UpdateValue=(sin(TimeValue)/2.0f) + 0.5f;
		GLint WhereUniform=glGetUniformLocation(Use.PID,"transcolor");
		glUniform4f(WhereUniform,0.0f,UpdateValue,0.0f,1.0f);
		*/
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
