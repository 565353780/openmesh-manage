#include "boundary_searcher.h"
#include "index_boundary.h"
#include <string>

// 主程序
int main(int argc, char **argv) {
  const std::string mesh_file_path = "/home/chli/Downloads/bunny_pgr_crop.ply";

  BoundarySearcher boundary_searcher;

  std::vector<IndexEdge> boundary_edge_vec;
  if (!boundary_searcher.toBoundaryEdgeVec(mesh_file_path, boundary_edge_vec)) {
    return -1;
  }

  // 输出边界顶点
  std::cout << "Boundary edges: " << std::endl;
  for (IndexEdge boundary_edge : boundary_edge_vec) {
    std::cout << boundary_edge.start_point.idx << " -> "
              << boundary_edge.end_point.idx << std::endl;
  }

  std::cout << boundary_edge_vec.size() << std::endl;
  boundary_edge_vec[0].outputInfo();

  std::vector<IndexBoundary> boundary_vec;
  if (!boundary_searcher.toBoundaryVec(boundary_edge_vec, boundary_vec)) {
    return -1;
  }

  std::cout << boundary_vec.size() << std::endl;
  for (int i = 0; i < boundary_vec.size(); ++i) {
    std::cout << "boundary " << i << " : " << boundary_vec[i].points.size()
              << std::endl;
    boundary_vec[i].outputBoundaryIdxs();
  }

  return 0;
}
