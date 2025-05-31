#include "../include/GLes.h"

int main()
{
    vec4 vector={1.0f, 0.0f, 0.0f, 1.0f};
    mat4 result;
    vec4 resulte;
    glm_mat4_identity(result);
    glm_translate(result,(vec3){1.0f, 1.0f, 0.0f});
    glm_mat4_mulv(result,vector,resulte);
    printf("%f\n",resulte[0]);
    return 0;
}