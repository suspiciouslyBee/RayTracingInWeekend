#include "vec3.h"

#include <cmath>
#include <iostream>

double vec3::x() const { return e[0]; }
double vec3::y() const { return e[0]; }
double vec3::z() const { return e[0]; }

//Why is this not inlined??
vec3 vec3::operator-() const { return vec3(-e[0], -e[1], -e[2]); }


//TODO: Do I need to worry about bounds checking here?
//TODO?: Figure out a way to measure perf for checking bounds
double vec3::operator[](int i) const { return e[i]; }
double& vec3::operator[](int i) { return e[i]; }

//Offload that to the STL
//TODO: What would happen if I substituted a differnt sqrt? Maybe for fun try
//tossing in the quake fast inverse
double vec3::length() const { return std::sqrt(length_squared()); }

double vec3::length_squared() const {
  return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

vec3& vec3::operator+=(const vec3& v) {
  e[0] += v.e[0];
  e[1] += v.e[1];
  e[2] += v.e[2];
  return *this;
}

vec3& vec3::operator*=(double t) {
  e[0] *= t;
  e[1] *= t;
  e[2] *= t;
  return *this;
}

//Prints in order: x y z
std::ostream& operator<<(std::ostream& out, const vec3& v) {
  return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
}





