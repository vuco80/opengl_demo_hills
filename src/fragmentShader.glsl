#version 440 core

layout(location = 0) out vec4 outputColor;
smooth in vec3 vColor;
smooth in vec3 outNormalVector;

uniform vec3 ambientLight;

void main() {
	vec3 diffuseColor = vec3(0.8, 0.8, 0.8);
	vec3 diffuseDirection = normalize(vec3(-10, -50, -100));
	float intensity = max(0.0, dot(outNormalVector, -diffuseDirection));
	intensity = clamp(intensity, 0.0, 1.0);
	vec3 lightFactor = diffuseColor * intensity;
	outputColor = vec4(vColor, 1.0) * (vec4(ambientLight, 1.0) + vec4(lightFactor, 1.0));
}