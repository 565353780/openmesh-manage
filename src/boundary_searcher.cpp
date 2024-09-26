#include "boundary_searcher.h"
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

const bool BoundarySearcher::toOrderedBoundaryPointIdxVec(
    const std::vector<std::pair<int, int>> &boundary_edge_idx_pair_vec,
    std::vector<int> boundary_point_idx_vec) {
  return true;
}
