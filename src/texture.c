#include "../include/GLes.h"
void load_texture2d(char const *image_path,_Bool ycoord)
{
    int Channels,tex_width,tex_height;
    unsigned char *tex_data;
    if(ycoord==true)
        stbi_set_flip_vertically_on_load(true);
    tex_data=stbi_load(image_path,&tex_width,&tex_height,&Channels,0);
    if(!*tex_data){ 
        printf("failed to load texture");
    }else{
        printf("loading… success!\n");
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,tex_width,tex_height,0,GL_RGBA, GL_UNSIGNED_BYTE,tex_data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    stbi_image_free(tex_data);
    return;
}