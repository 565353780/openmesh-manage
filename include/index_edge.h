#pragma once

#include "index_point.h"

class IndexEdge {
public:
  IndexEdge(){};
  IndexEdge(const IndexPoint &start_point, const IndexPoint &end_point);

  const bool outputInfo(const int &info_level = 0);

  IndexPoint start_point() { return start_point_; }
  IndexPoint end_point() { return end_point_; }

private:
  IndexPoint start_point_;
  IndexPoint end_point_;
};
