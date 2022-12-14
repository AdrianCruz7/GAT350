#version 430 core
 
in vec3 position;
in vec3 normal;
in vec2 texcoord;
 
out vec4 fcolor; //pixel to draw
 
struct Light
{
	vec3 ambient;
	vec3 color;
	vec4 position;
};

struct Material
{
	vec3 color;
	float shininess;
};

uniform Light light;
uniform Material material;

uniform sampler2D textureSampler;

layout (binding = 0) uniform sampler2D diffuseMap; 
layout (binding = 1) uniform sampler2D specularMap;
layout (binding = 2) uniform sampler2D emissiveMap;

void main()
{

	//AMBIENT
	vec3 ambient = light.ambient * material.color;

	//DIFFUSE
	//calculate light direction (unit vector)
	vec3 light_dir = normalize(vec3(light.position) - position);

	//calculate light intensity with dot product (normal * light direction)
	float intensity = max(dot(light_dir, normal), 0);

	//calculate diffuse color
	vec3 diffuse = light.color * material.color * intensity;

	//SPECULAR
	vec3 specular = vec3(0);

	if (intensity > 0)
	{
		vec3 reflection = reflect(-light_dir, normal);
		vec3 view_dir = normalize(-vec3(position));
		intensity = max(dot(reflection, view_dir), 0);
		intensity = pow(intensity, material.shininess);
		specular = light.color * material.color * intensity;
	}

	vec4 diffuseColor = texture(diffuseMap, texcoord);
	vec4 specularColor = texture(specularMap, texcoord);
	vec4 emissiveColor = texture(emissiveMap, texcoord);

	//color = ambient + diffuse + specular;

	fcolor = emissiveColor + vec4(ambient + diffuse, 1) * diffuseColor + (vec4(specular, 1) * specularColor);
}