#include "../include/learngl.h"

int main()
{
    //1:glm
    vec4 vector={1.0f, 0.0f, 0.0f, 1.0f};
    mat4 result;
    vec4 resulte;
    glm_mat4_identity(result);
    glm_translate(result,(vec3){1.0f, 1.0f, 0.0f});
    glm_mat4_mulv(result,vector,resulte);
    printf("%f\n",resulte[0]);
    return 0;
    //2:3d
    vec3 axis={0.0f,1.0f,0.0f};//y coord
		mat4 view,projection,model;
		glm_mat4_identity(view);
		glm_mat4_identity(projection);
		glm_mat4_identity(model);
		
		glm_normalize(axis);
		glm_rotate(model,45.0f,axis);
		glm_translate(view,(vec3){0.0f,0.0f,-3.0f});
		glm_perspective(glm_rad(45.0f), (GLfloat)640 / (GLfloat)480, 0.1f, 100.0f,projection);
        set_mat4("model",(const GLfloat *)model,PID);
        set_mat4("view",(const GLfloat *)view,PID);
        set_mat4("projection",(const GLfloat *)projection,PID);
}