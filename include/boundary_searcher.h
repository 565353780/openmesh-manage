#pragma once

#include "index_edge.h"
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <string>

typedef OpenMesh::TriMesh_ArrayKernelT<> TriMesh;

class BoundarySearcher {
public:
  BoundarySearcher(){};

  const bool toBoundaryEdgeVec(const std::string &mesh_file_path,
                               std::vector<IndexEdge> &boundary_edge_vec);

  const bool toOrderedBoundaryPointIdxVec(
      const std::vector<std::pair<int, int>> &boundary_edge_idx_pair_vec,
      std::vector<int> boundary_point_idx_vec);
};
