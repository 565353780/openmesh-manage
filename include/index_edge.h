#pragma once

#include "index_point.h"

class IndexEdge {
public:
  IndexEdge(){};
  IndexEdge(const IndexPoint &new_start_point, const IndexPoint &new_end_point);

  const bool isPoint();

  const int searchIdx(const int &idx);
  const int searchIdx(const IndexPoint &point);

  const IndexPoint point(const int &idx);

  const bool outputInfo(const int &info_level = 0);

public:
  IndexPoint start_point;
  IndexPoint end_point;
};
