#include "boundary_searcher.h"
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
  std::cout << "Boundary vertices: " << std::endl;
  for (IndexEdge boundary_edge : boundary_edge_vec) {
    std::cout << boundary_edge.start_point().idx() << " -> "
              << boundary_edge.end_point().idx() << std::endl;
  }

  std::cout << boundary_edge_vec.size() << std::endl;
  boundary_edge_vec[0].outputInfo();

  std::vector<int> boundary_point_idx_vec;

  return 0;
}
