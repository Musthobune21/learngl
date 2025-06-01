#include "../include/GLes.h"
int main(int argc,char *argv[])
{   //GLinit
    glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_TRUE);
	GLFWwindow* win=glfwCreateWindow(640,480,"GLTEST",NULL,NULL);
	if(win==NULL){
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
	    1.0f,1.0f,0.0f,1.0f,1.0f,//0
	    1.0f,-1.0f,0.0f,1.0f,-1.0f,//1
	    -1.0f,-1.0f,0.0f,-1.0f,-1.0f,//2
	    -1.0f,1.0f,0.0f,-1.0f,1.0f//3
	};
	GLuint indwedr[]=
	{
	    0,1,3,
	    1,2,3
	};
GLuint VertexID,FragmentID,PID;
shader_compile(&VertexID,GL_VERTEX_SHADER,"./glsl/vertex.glsl");
shader_compile(&FragmentID,GL_FRAGMENT_SHADER,"./glsl/fragment.glsl");
PID=shader_link(VertexID,FragmentID);
	//Elements
	GLuint vbo,vao,ebo,tex;
	glGenBuffers(1,&vbo);
	glGenBuffers(1,&ebo);
	glGenTextures(1,&tex);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
	glBindTexture(GL_TEXTURE_2D,tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    load_texture2d("./grass.png",true);
	glBufferData(GL_ARRAY_BUFFER,sizeof vertatri,vertatri,GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof indwedr,indwedr,GL_STATIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat), (GLvoid*)0);
	glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat),(GLvoid*)(3*sizeof(GLfloat)));
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
		glBindTexture(GL_TEXTURE_2D,tex);
		glBindVertexArray(vao);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		mat4 transform;
		glm_mat4_identity(transform);
		glm_scale(transform,(vec3){0.5f, 0.5f, 0.5f});
		GLint transformLoc = glGetUniformLocation(PID,"transform");
        glUniformMatrix4fv(transformLoc,1,GL_FALSE,(const GLfloat *)transform);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(win);
	}
	glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1,&ebo);
	glfwTerminate();//End
	return 0;
}