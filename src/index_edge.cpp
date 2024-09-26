#include "index_edge.h"
#include <iostream>
#include <string>

IndexEdge::IndexEdge(const IndexPoint &start_point,
                     const IndexPoint &end_point) {
  start_point_ = start_point;
  end_point_ = end_point;
}

const bool IndexEdge::outputInfo(const int &info_level) {
  std::string line_start = "";
  for (int i = 0; i < info_level; ++i) {
    line_start += "\t";
  }

  std::cout << line_start << "[INFO][IndexEdge::outputInfo]" << std::endl;
  std::cout << line_start << "\t start_point: " << std::endl;
  start_point_.outputInfo(info_level + 1);
  std::cout << line_start << "\t end_point: " << std::endl;
  end_point_.outputInfo(info_level + 1);

  return true;
}
