#pragma once

#include "index_boundary.h"
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

  const bool toBoundaryVec(std::vector<IndexEdge> &boundary_edge_vec,
                           std::vector<IndexBoundary> &boundary_vec);
};
