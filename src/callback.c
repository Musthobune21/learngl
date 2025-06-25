#include "../include/learngl.h"
bool keys[1024];
GLfloat DeltaTime=0.0f;
GLfloat LastFrame=0.0f;
void key_callback(GLFWwindow* win,int key,int scancode,int action,int mode)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(win, GL_TRUE);
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            keys[key] = true;
        else if (action == GLFW_RELEASE)
            keys[key] = false;
    }
}
void framebuffersize_callback(GLFWwindow* win,int width,int height)
{
    glfwGetFramebufferSize(win,&width,&height);
    glViewport(0,0,width,height);
}
void do_movement()
{
    GLfloat CurrentFrame=glfwGetTime();
    DeltaTime=CurrentFrame - LastFrame;
    LastFrame=CurrentFrame;
    GLfloat speed = 5.0f * DeltaTime;
    vec3 right;
    glm_cross(cFront,wUp,right);
    glm_normalize(right);
    if(keys[GLFW_KEY_W]) 
        glm_vec3_muladds(cFront,speed,cPOS);
    if(keys[GLFW_KEY_S]) 
        glm_vec3_mulsubs(cFront,speed,cPOS);
    if(keys[GLFW_KEY_A])
        glm_vec3_mulsubs(right,speed,cPOS);
    if(keys[GLFW_KEY_D])
        glm_vec3_muladds(right,speed,cPOS);
}
