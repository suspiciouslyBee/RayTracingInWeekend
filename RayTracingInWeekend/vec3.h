#ifndef VEC3_H_
#define VEC3_H_

#include <cmath>
#include <iostream>

class vec3 {
 public:

  //store coords
  //can we make this private
  //TODO: figure out why this is public not private
  double e[3];

  //constructors
  vec3() : e{0, 0, 0} {}
  vec3(double e0, double e1, double e2) : e{0, 0, 0} {}

  //coordinates
  double x() const;
  double y() const;
  double z() const;
  
  vec3 operator-() const;

  //Element Access
  double operator[](int i) const;
  double& operator[](int i);

  double length() const;
  double length_squared() const;

  //Assign ops
  vec3& operator+=(const vec3& v);
  vec3& operator*=(double t);
  vec3& operator/=(double t);

};

// It took me some time to understand why inlining is a thing here
// Apparently its not lazy, its to tell the compiler "hey. optimize me in
// particular" which would be important for calcuating hundreds of thousands of
// vectors. RTiW doesn't mention this... neither has any of my classes.

// Apparently the Google C++ style guide says to put inline defs into the header
// Leaving as is

inline vec3 operator+(const vec3& u, const vec3& v) {
  return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

#endif  // VEC3_H_