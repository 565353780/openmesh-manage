#include "index_point.h"
#include <iostream>
#include <string>

IndexPoint::IndexPoint(const int &new_idx, const float &new_x,
                       const float &new_y, const float &new_z) {
  idx = new_idx;
  x = new_x;
  y = new_y;
  z = new_z;
}

const bool IndexPoint::outputInfo(const int &info_level) {
  std::string line_start = "";
  for (int i = 0; i < info_level; ++i) {
    line_start += "\t";
  }

  std::cout << line_start << "[INFO][IndexPoint::outputInfo]" << std::endl;
  std::cout << line_start << "\t idx: " << idx << std::endl;
  std::cout << line_start << "\t x: " << x << std::endl;
  std::cout << line_start << "\t y: " << y << std::endl;
  std::cout << line_start << "\t z: " << z << std::endl;

  return true;
}
