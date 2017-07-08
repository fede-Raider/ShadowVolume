#version 430

uniform sampler2D DiffSpecTex;
layout( location = 0 ) out vec4 FragColor;

void main() {
  vec4 diffSpec = texelFetch(DiffSpecTex, ivec2(gl_FragCoord), 0);

  FragColor = vec4(diffSpec.xyz, 1);
}