#version 460

in vec2 o_TexCoords;
in vec2 o_LocalPos;

layout(location = 0) out vec4 Out;

uniform vec4 u_BackgroundColor; // RGBA
uniform vec4 u_BorderColor;     // RGBA
uniform float u_BorderThickness; // pixels
uniform sampler2D u_Texture;
uniform int u_UseTexture;       // 0 or 1
uniform int u_TextureHasRGB;    // 0 = font mask, 1 = full color image

uniform vec2 u_Size;    // widget size in pixels
uniform float u_Radius; // corner radius in pixels

void main() {
    vec2 p = o_LocalPos;
    vec2 s = u_Size;

    float r = u_Radius;
    float b = u_BorderThickness;

    // Rounded corner mask
    float mask = 1.0;
    if (r > 0.0) {
        vec2 cornerDist = min(p, s - p);
        float dist = length(cornerDist);
        if (dist > r) {
            float aa = clamp((r - dist) * 10.0, 0.0, 1.0);
            mask *= aa;
        }
    }

    // Border mask
    float borderMask = 0.0;
    if (b > 0.0) {
        vec2 innerDist = min(p - vec2(b), s - p - vec2(b));
        float distInner = length(innerDist);
        if (distInner > (r - b)) {
            borderMask = 1.0;
        }
    }

    // Sample texture
    vec4 texColor = vec4(1.0);
    if (u_UseTexture == 1) {
        texColor = texture(u_Texture, o_TexCoords);
    }

    vec4 baseColor = u_BackgroundColor;

    if (u_UseTexture == 1) {
        if (u_TextureHasRGB == 1) {
            // It's an image: use texture RGB, multiply by background as tint
            baseColor = vec4(texColor.rgb, 1.0) * u_BackgroundColor;
        } else {
            // It's a font mask: only use alpha
            baseColor.a *= texColor.a;
        }
    }

    vec4 borderColor = u_BorderColor;

    vec4 finalColor = mix(baseColor, borderColor, borderMask);

    finalColor.a *= mask;

    if (finalColor.a < 0.01) discard;

    Out = finalColor;
}