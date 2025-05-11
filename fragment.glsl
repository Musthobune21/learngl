#version 330 core
out vec4 color;
in vec3 outcolor
void main()
{
	color = vec4(outcolor,1.0f);
}
