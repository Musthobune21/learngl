#version 330 core
out vec4 color;
in vec2 outcolor;
uniform sampler2D TexturePIC;
void main()
{
	color = texture(TexturePIC,outcolor);
}
