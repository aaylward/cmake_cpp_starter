#include "args.h"
#include "project_creator.h"
#include <cstdint>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>


namespace cs = cpp_starter;

int main(int ac, char** av) {
  auto o = cs::get_options(ac, av);
  if (o->project.empty()) {
    std::cout << "--project is required" << std::endl;
    return 1;
  }
  cs::ProjectCreator pc(std::move(o));
  return pc.write_project_to_disc();
}
