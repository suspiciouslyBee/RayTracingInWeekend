// RayTracingInWeekend.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

//Format
// image_width

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) { 

  if (!(argc == 2)) {
    
  }

  int image_width = 256;
  int image_height = 256;

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    for (int i = 0; i < image_height; i++) {
      auto r = double(i) / (image_width - 1);
      auto g = double(j) / (image_height - 1);
      auto b = 0.0;

      int ir = int(255.999 * r);
      int ig = int(255.999 * g);
      int ib = int(255.999 * b);

      std::cout << ir << ' ' << ig << ' ' << ib << '\n';
    }
  }
}
