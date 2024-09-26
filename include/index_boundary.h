#pragma once

#include "index_edge.h"
#include <deque>
#include <vector>

class IndexBoundary {
public:
  IndexBoundary(){};

  const std::pair<int, IndexPoint> searchConnectedPoint(IndexEdge &edge);

  const bool addEdge(IndexEdge &edge, const bool &ignore_point = true);

  const std::vector<float> toPointVec();

  const bool outputBoundaryIdxs(const int &info_level = 0,
                                const int &single_line_idx_num = 10);
  const bool outputInfo(const int &info_level = 0);

public:
  std::deque<IndexPoint> points;
};
