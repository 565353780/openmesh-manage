#pragma once

#include "index_boundary.h"
#include "index_edge.h"

#include <string>


class BoundarySearcher {
public:
  BoundarySearcher(){};

  const bool toBoundaryEdgeVec(const std::string &mesh_file_path,
                               std::vector<IndexEdge> &boundary_edge_vec);

  const bool toBoundaryVec(std::vector<IndexEdge> &boundary_edge_vec,
                           std::vector<IndexBoundary> &boundary_vec);

  const bool searchBoundaries(const std::string &mesh_file_path,
                              std::vector<IndexBoundary> &boundary_vec);
  const bool searchBoundaries(const std::string &mesh_file_path,
                              std::vector<std::vector<float>> &boundary_vec);
};
