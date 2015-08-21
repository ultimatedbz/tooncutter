//Phong Reflection Model Vertex Shader
#version 120

varying vec3 vNormal;
varying vec3 vVertex;

void main(void)
{
  vVertex = gl_Vertex.xyz;
  vNormal = gl_Normal;
  gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
   //gl_FrontColor = gl_Color;
}
