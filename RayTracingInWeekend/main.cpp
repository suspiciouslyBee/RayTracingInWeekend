#include <iostream>

#include "color.h"
#include "vec3.h"
#include "ray.h"

//TODO: Why here?
color ray_color(const ray& r) { 
  vec3 unit_direction = unit_vector(r.direction());
  auto a = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main() {
  int image_width = 400;
  auto aspect_ratio = 16.0 / 9.0;

  int image_height = int(image_width / aspect_ratio);
  image_height = (image_height < 1) ? 1 : image_height;

  //Camera
  //TODO: What happens if I mess with these values?
  auto focal_length = 1.0;
  auto viewport_height = 2.0;
  auto viewport_width = viewport_height * (double(image_width) / image_height);
  auto camera_center = point3(0, 0, 0);

  
  auto viewport_u = vec3(viewport_width, 0, 0);
  auto viewport_v = vec3(0, -viewport_height, 0);
  
  //Where the probe for each pixel is taken from
  auto pixel_delta_u = viewport_u / image_width;
  auto pixel_delta_v = viewport_v / image_width;

  //Locates the upper left pixel in the 3D space with respect to camera
  //So that the view port, as a plane, is offset from camera center 
  // by -focal length, and the upper left most pixel in the fourth quadrant in
  //the viewport grid
  auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) -
                             viewport_u / 2 - viewport_v / 2;
  auto pixel00_loc =
      viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    std::clog << "\rScanlines remaining: " << (image_height - j) << std::flush;
    for (int i = 0; i < image_width; i++) {
      auto pixel_center =
          pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
      auto ray_direction = pixel_center - camera_center;
      ray r(camera_center, ray_direction);
      color pixel_color = ray_color(r);
      write_color(std::cout, pixel_color);
    }
  }
  std::clog << "\rDone.                    \n";
}
