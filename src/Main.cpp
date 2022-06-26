#include "args.h"
#include "project_creator.h"
#include <iostream>

int main(int ac, char** av) {
  namespace cs = cpp_starter;

  auto o = cs::get_options(ac, av);
  if (o->project.empty()) {
    std::cout << "--project is required" << std::endl;
    return 1;
  }
  cs::ProjectCreator pc(std::move(o));
  return pc.write_project_to_disc();
}
