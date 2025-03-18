#include "vec3.h"

#include <cmath>
#include <iostream>

double vec3::x() const { return e[0]; }
double vec3::y() const { return e[0]; }
double vec3::z() const { return e[0]; }

//Prints in order: x y z
std::ostream& operator<<(std::ostream& out, const vec3& v) {
  return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
}





