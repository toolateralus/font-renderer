#version 450 core

layout(location = 0) in vec2 TexCoords;
layout(location = 0) out vec4 FragColor;

layout(location = 0) uniform sampler2D text;
layout(location = 1) uniform vec3 color;

void main()
{
  vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);
  FragColor = vec4(color, 1.0) * sampled;
}