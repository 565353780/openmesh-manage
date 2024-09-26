#include "index_point.h"
#include <iostream>
#include <string>

IndexPoint::IndexPoint(const int &idx, const float &x, const float &y,
                       const float &z) {
  idx_ = idx;
  x_ = x;
  y_ = y;
  z_ = z;
}

const bool IndexPoint::outputInfo(const int &info_level) {
  std::string line_start = "";
  for (int i = 0; i < info_level; ++i) {
    line_start += "\t";
  }

  std::cout << line_start << "[INFO][IndexPoint::outputInfo]" << std::endl;
  std::cout << line_start << "\t idx: " << idx_ << std::endl;
  std::cout << line_start << "\t x: " << x_ << std::endl;
  std::cout << line_start << "\t y: " << y_ << std::endl;
  std::cout << line_start << "\t z: " << z_ << std::endl;

  return true;
}
