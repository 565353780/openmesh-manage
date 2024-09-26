#include "index_boundary.h"
#include "index_point.h"
#include <iostream>
#include <string>

const std::pair<int, IndexPoint>
IndexBoundary::searchConnectedPoint(IndexEdge &edge) {
  if (points.size() == 0) {
    return std::pair<int, IndexPoint>(1, edge.start_point);
  }

  int search_point_idx = edge.searchIdx(points[0]);

  if (search_point_idx >= 0) {
    return std::pair<int, IndexPoint>(0, edge.point(1 - search_point_idx));
  }

  search_point_idx = edge.searchIdx(points[points.size() - 1]);

  if (search_point_idx >= 0) {
    return std::pair<int, IndexPoint>(1, edge.point(1 - search_point_idx));
  }

  return std::pair<int, IndexPoint>(-1, edge.start_point);
}

const bool IndexBoundary::addEdge(IndexEdge &edge, const bool &ignore_point) {
  if (ignore_point) {
    if (edge.isPoint()) {
      return false;
    }
  }

  if (points.size() == 0) {
    points.emplace_back(edge.start_point);
    points.emplace_back(edge.end_point);
    return true;
  }

  const std::pair<int, IndexPoint> search_connected_point_result =
      searchConnectedPoint(edge);

  const int connect_point_idx = search_connected_point_result.first;
  if (connect_point_idx == 0) {
    points.emplace_front(search_connected_point_result.second);
    return true;
  }

  if (connect_point_idx == 1) {
    points.emplace_back(search_connected_point_result.second);
    return true;
  }

  return false;
}

const std::vector<float> IndexBoundary::toPointVec() {
  std::vector<float> point_vec;
  point_vec.reserve(points.size() * 3);

  for (int i = 0; i < points.size(); ++i) {
    point_vec.emplace_back(points[i].x);
    point_vec.emplace_back(points[i].y);
    point_vec.emplace_back(points[i].z);
  }

  return point_vec;
}

const bool IndexBoundary::outputBoundaryIdxs(const int &info_level,
                                             const int &single_line_idx_num) {
  std::string line_start = "";
  for (int i = 0; i < info_level; ++i) {
    line_start += "\t";
  }

  std::cout << line_start << "[INFO][IndexBoundary::outputBoundary]";
  for (int i = 0; i < points.size(); ++i) {
    if (i % single_line_idx_num == 0) {
      std::cout << std::endl;
      std::cout << line_start << "\t";

      if (i != 0) {
        std::cout << " -> ";
      }
    }

    std::cout << points[i].idx;
    if (i != points.size() - 1) {
      std::cout << " -> ";
    } else {
      std::cout << std::endl;
    }
  }

  return true;
}

const bool IndexBoundary::outputInfo(const int &info_level) {
  std::string line_start = "";
  for (int i = 0; i < info_level; ++i) {
    line_start += "\t";
  }

  std::cout << line_start << "[INFO][IndexBoundary::outputInfo]" << std::endl;
  std::cout << line_start << "\t points: " << std::endl;
  for (int i = 0; i < points.size(); ++i) {
    std::cout << line_start << "\t" << i << std::endl;
    points[i].outputInfo(info_level + 1);
  }

  return true;
}
