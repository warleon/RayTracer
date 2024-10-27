#include <Mesh.hpp>
#include <iostream>

using namespace war;
int main() {
  Mesh::Loader load;
  std::string name("../data/bunny.obj");
  load.OBJ(name);
  const auto mesh = load.getMesh();
  const auto grid = mesh->getGrid();
  const auto dim = grid->dimensions;
  size_t count=0;
  for (size_t i = 0; i < dim[0]; i++) {
    for (size_t j = 0; j < dim[1]; j++) {
      for (size_t k = 0; k < dim[2]; k++) {
   count 
        += (grid->operator[](Mesh::index_t(i, j, k))).size();
  
  //std::cout<<"grid["<<i<<", "<<j<<", "<<k<<"].size() = "<<count<<std::endl;
      }
    }
  }
  std::cout<<"count = "<<count<<std::endl;

  return 0;
}
