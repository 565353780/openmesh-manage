#include "boundary_searcher.h"
#include "index_boundary.h"
#include <string>

int main(int argc, char **argv) {
  const std::string mesh_file_path = "/home/chli/Downloads/bunny_pgr_crop.ply";

  BoundarySearcher boundary_searcher;

  std::vector<IndexBoundary> boundary_vec;
  if (!boundary_searcher.searchBoundaries(mesh_file_path, boundary_vec)) {
    std::cerr << "[ERROR][main]" << std::endl;
    std::cerr << "\t searchBoundaries failed!" << std::endl;
    return -1;
  }

  std::cout << "boundary num : " << boundary_vec.size() << std::endl;
  for (int i = 0; i < boundary_vec.size(); ++i) {
    std::cout << "boundary[" << i
              << "] size : " << boundary_vec[i].points.size() << std::endl;
    boundary_vec[i].outputBoundaryIdxs();
  }

  return 0;
}
