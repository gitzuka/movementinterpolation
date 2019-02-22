#version 330 core
// shadertype=<glsl>

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 MVP;
uniform mat4 projection;
uniform mat3 normalMat;
uniform vec3 lightPos; // we now define the uniform in the vertex shader and pass the 'view space' lightpos to the fragment shader. lightPos is currently in world space.

out vec3 vNormal;
out vec3 vFragPos;
out vec3 vColor;

//uniform vec3 lightPos;
//out vec4 v_Color;

//out vec4 vColor;



void main()
{
	vColor = color;
	vNormal = mat3(transpose(inverse(model))) * normal;
	vFragPos = vec3(model * vec4(position, 1.0));
	//mat3 normalM = transpose(inverse(mat3(view * model)));
	//vNormal = normalize(normalM * normal);
	//vEye = -(view * model * vec4(position, 1.0f));

	gl_Position = MVP * vec4(position, 1.0);
}
