#version 440 core

uniform mat4 projectionMat;
uniform mat4 viewMat;
uniform mat4 modelMat;
uniform mat4 normalMat;

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec3 normalVector;

smooth out vec3 vColor;
smooth out vec3 outNormalVector;

void main() {
	mat4 mvpMat = projectionMat * viewMat * modelMat;
	gl_Position = mvpMat * vec4(vertexPosition, 1.0);

	vColor = inColor;

	vec4 normalTransform = normalMat * vec4(normalVector, 1.0);
	outNormalVector = normalize(vec3(normalTransform.x, normalTransform.y, normalTransform.z));
}
