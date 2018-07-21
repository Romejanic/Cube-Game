#version 330 core

layout(location = 0) in vec3 vertex;
out vec3 v_color;

uniform mat4 projMat;
uniform mat4 viewMat;

void main() {
	gl_Position = projMat * viewMat * vec4(vertex, 1.);
	v_color = vertex * .5 + .5;
	
	gl_PointSize = 10.0;
}