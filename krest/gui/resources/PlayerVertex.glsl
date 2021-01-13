/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#version 130

uniform mat4 transform;

in vec2 a_vertexCoords;
in vec2 a_textureCoords;

out vec2 v_textureCoords;

void main()
{
  gl_Position = transform * vec4(a_vertexCoords, 0.0, 1.0);
  v_textureCoords = a_textureCoords;
}
