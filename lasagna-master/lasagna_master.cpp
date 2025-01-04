#include "lasagna_master.h"

namespace lasagna_master {

int preparationTime(std::vector<std::string> layers) {
  int num = 2;
  int counting = 0;
  for (unsigned long int i = 0; i < layers.size(); i++) {

    counting++;
  }

  return counting * num;
}

int preparationTime(std::vector<std::string> layers, int num) {
  int counting = 0;
  for (unsigned long int i = 0; i < layers.size(); i++) {
    counting++;
  }
  return counting * num;
}

} // namespace lasagna_master
