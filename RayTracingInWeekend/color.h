#ifndef COLOR_H_
#define COLOR_H_

#include "vec3.h"

#include <iostream>

using color = vec3;
void write_color(std::ostream& out, const color& pixel_color);

#endif //COLOR_H_