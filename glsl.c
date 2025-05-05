#include "GLes.h"
const GLchar* VSSource="#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
    "}\0";
const GLchar* FSSource="#version 330 core\n"
    "out vec4 color;\n"
    "uniform vec4 transcolor;\n"
    "void main()\n"
    "{\n"
    "color = transcolor;\n"
    "}\0";