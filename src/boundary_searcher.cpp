#include "boundary_searcher.h"
#include "index_boundary.h"
#include "index_point.h"
#include <filesystem>

const bool
BoundarySearcher::toBoundaryEdgeVec(const std::string &mesh_file_path,
                                    std::vector<IndexEdge> &boundary_edge_vec) {
  if (!std::filesystem::exists(mesh_file_path)) {
    std::cerr << "[ERROR][BoundarySearcher::toBoundaryEdgeVec]" << std::endl;
    std::cerr << "\t mesh file not exist!" << std::endl;
    std::cerr << "\t mesh_file_path: " << mesh_file_path << std::endl;

    return false;
  }

  TriMesh mesh;

  if (!OpenMesh::IO::read_mesh(mesh, mesh_file_path)) {
    std::cerr << "[ERROR][BoundarySearcher::toBoundaryEdgeVec]" << std::endl;
    std::cerr << "\t read_mesh failed!" << std::endl;
    std::cerr << "\t mesh_file_path: " << mesh_file_path << std::endl;
    return false;
  }

  boundary_edge_vec.clear();

  // 遍历所有边，检查它们是否是边界边
  for (TriMesh::EdgeIter e_it = mesh.edges_begin(); e_it != mesh.edges_end();
       ++e_it) {
    if (mesh.is_boundary(*e_it)) {
      const TriMesh::HalfedgeHandle heh = mesh.halfedge_handle(*e_it, 0);
      const TriMesh::VertexHandle vh1 = mesh.to_vertex_handle(heh);
      const TriMesh::VertexHandle vh2 = mesh.from_vertex_handle(heh);

      const TriMesh::Point p1 = mesh.point(vh1);
      const TriMesh::Point p2 = mesh.point(vh2);

      // 将边界顶点插入集合
      boundary_edge_vec.emplace_back(
          IndexEdge(IndexPoint(vh1.idx(), p1[0], p1[1], p1[2]),
                    IndexPoint(vh2.idx(), p2[0], p2[1], p2[2])));
    }
  }

  return true;
}

const bool
BoundarySearcher::toBoundaryVec(std::vector<IndexEdge> &boundary_edge_vec,
                                std::vector<IndexBoundary> &boundary_vec) {
  boundary_vec.clear();

  const int boundary_edge_num = boundary_edge_vec.size();
  if (boundary_edge_num == 0) {
    return true;
  }

  if (boundary_edge_num == 1) {
    IndexBoundary boundary;
    boundary.addEdge(boundary_edge_vec[0]);

    boundary_vec.emplace_back(boundary);
    return true;
  }

  std::vector<int> remained_boundary_edge_idx_vec;
  remained_boundary_edge_idx_vec.reserve(boundary_edge_vec.size());
  for (int i = 0; i < boundary_edge_num; ++i) {
    remained_boundary_edge_idx_vec.emplace_back(i);
  }

  bool new_edge_added = false;

  while (remained_boundary_edge_idx_vec.size() > 0) {
    while (new_edge_added) {
      new_edge_added = false;

      for (int i = remained_boundary_edge_idx_vec.size() - 1; i >= 0; --i) {
        if (boundary_vec.back().addEdge(
                boundary_edge_vec[remained_boundary_edge_idx_vec[i]])) {
          new_edge_added = true;

          remained_boundary_edge_idx_vec.erase(
              remained_boundary_edge_idx_vec.begin() + i);

          break;
        }
      }
    }

    if (remained_boundary_edge_idx_vec.size() == 0) {
      break;
    }

    IndexBoundary new_boundary;
    new_boundary.addEdge(
        boundary_edge_vec[remained_boundary_edge_idx_vec.back()]);

    boundary_vec.emplace_back(new_boundary);

    remained_boundary_edge_idx_vec.pop_back();

    new_edge_added = true;
  }

  return true;
}

const bool
BoundarySearcher::searchBoundaries(const std::string &mesh_file_path,
                                   std::vector<IndexBoundary> &boundary_vec) {
  std::vector<IndexEdge> boundary_edge_vec;
  if (!toBoundaryEdgeVec(mesh_file_path, boundary_edge_vec)) {
    std::cerr << "[ERROR][BoundarySearcher::searchBoundaries]" << std::endl;
    std::cerr << "\t toBoundaryEdgeVec failed!" << std::endl;
    return false;
  }

  if (!toBoundaryVec(boundary_edge_vec, boundary_vec)) {
    std::cerr << "[ERROR][BoundarySearcher::searchBoundaries]" << std::endl;
    std::cerr << "\t toBoundaryVec failed!" << std::endl;
    return false;
  }

  return true;
}
