#version 430 core 
 
in layout(location = 0) vec3 vposition;
in layout(location = 1) vec2 vtexcoord;
in layout(location = 1) vec3 vnormal;
 
out vec2 texcoord;
out vec3 color;
 
struct Light
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	vec4 position;
};

uniform Light light;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
 
void main()
{
	texcoord = vtexcoord;
 

	color = light.ambient;

	mat4 mvp = projection * view * model;
	gl_Position = mvp * vec4(vposition, 1.0);
}