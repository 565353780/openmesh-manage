#include "index_edge.h"
#include <iostream>
#include <string>

IndexEdge::IndexEdge(const IndexPoint &new_start_point,
                     const IndexPoint &new_end_point) {
  start_point = new_start_point;
  end_point = new_end_point;
}

const bool IndexEdge::isPoint() { return start_point.idx == end_point.idx; }

const int IndexEdge::searchIdx(const int &idx) {
  if (start_point.idx == idx) {
    return 0;
  }

  if (end_point.idx == idx) {
    return 1;
  }

  return -1;
}

const int IndexEdge::searchIdx(const IndexPoint &point) {
  return searchIdx(point.idx);
}

const IndexPoint IndexEdge::point(const int &idx) {
  if (idx == 0) {
    return start_point;
  } else {
    return end_point;
  }
}

const bool IndexEdge::outputInfo(const int &info_level) {
  std::string line_start = "";
  for (int i = 0; i < info_level; ++i) {
    line_start += "\t";
  }

  std::cout << line_start << "[INFO][IndexEdge::outputInfo]" << std::endl;
  std::cout << line_start << "\t start_point: " << std::endl;
  start_point.outputInfo(info_level + 1);
  std::cout << line_start << "\t end_point: " << std::endl;
  end_point.outputInfo(info_level + 1);

  return true;
}
