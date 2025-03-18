#ifndef VEC3_H_
#define VEC3_H_

#include <cmath>
#include <iostream>

class vec3 {
 public:
  // store coords
  // can we make this private
  // TODO: figure out why this is public not private
  double e[3];

  // constructors
  // TODO: find out what this constructor type is called again. i fogor
  vec3() : e{0, 0, 0} {}
  vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

  // coordinates
  double x() const;
  double y() const;
  double z() const;

  vec3 operator-() const;  // TODO: figure out why this is NOT inlined

  // Element Access
  double operator[](int i) const;
  double& operator[](int i);

  double length() const;
  double length_squared() const;

  // Assign ops
  vec3& operator+=(const vec3& v);
  vec3& operator*=(double t);
  vec3& operator/=(double t);
};

using point3 = vec3;  //interesting placement for this alias

// It took me some time to understand why inlining is a thing here
// Apparently its not lazy, its to tell the compiler "hey. optimize me in
// particular" which would be important for calcuating hundreds of thousands of
// vectors. RTiW doesn't mention this... neither has any of my classes.
//
// TODO: Find out a way to do this but have a seperate declaration for the class
// declaration. I'd like to put all methods into the .cpp for uniformity.
//
// Apparently the Google C++ style guide says to put inline defs into the header
// Leaving as is

inline vec3 operator+(const vec3& u, const vec3& v) {
  return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
  return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
  return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v) {
  return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) { return t * v; }

inline vec3 operator/(const vec3& v, double t) { return (1 / t) * v; }

inline double dot(const vec3& u, const vec3& v) {
  return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
  return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
              u.e[2] * v.e[0] - u.e[0] * v.e[2],
              u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) { return v / v.length(); }

// Prints in order: x y z
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
  return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
}
#endif  // VEC3_H_