/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#version 130

uniform vec4 color;

out vec4 fragColor;

void main()
{
  fragColor = color;
}
