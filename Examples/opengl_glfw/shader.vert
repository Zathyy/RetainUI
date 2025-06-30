#version 460

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texCoords;

out vec2 o_TexCoords;
out vec2 o_LocalPos;

uniform vec2 u_Translation;
uniform vec2 u_Size;        // pixel size

void main() {

    o_LocalPos = (position + vec2(0.5)) * u_Size;

    gl_position = vec4(position + u_Translation * vec2(2.0, -2.0), 0.0, 1.0);
    o_TexCoords = texcoords;
}