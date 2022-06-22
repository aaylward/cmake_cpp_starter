#include "args.h"
#include <cstdint>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>


namespace cs = cpp_starter;

std::string make_contents(const cs::options* o) {
  std::string contents = "cmake_minimum_required(VERSION 3.20)\n\n";
  contents += "project(" + o->project + " VERSION 0.1 LANGUAGES CXX)\n\n";

  contents += "set(CMAKE_CXX_STANDARD " + std::to_string(o->standard) + ")\n";
  contents += "set(CMAKE_CXX_STANDARD_REQUIRED True)\n\n";

  contents += "file(GLOB SOURCES \"src/*.cpp\")\n\n";
  contents += "add_executable(" + o->project + " ${SOURCES})\n";
  contents += "add_compile_options(-Wall -Wextra -Werror -fsanitize=address)\n";
  contents += "add_link_options(-fsanitize=address)\n";

  if (o->parser) {
    contents += "find_package(Boost " + o->boost_version + " COMPONENTS program_options REQUIRED)\n\n";
    contents += "target_link_libraries(" + o->project + " Boost::program_options)\n\n";
  }

  return contents;
}

int write_contents(std::string &contents, std::unique_ptr<cs::options> o) {
  namespace fs = std::filesystem;

  if (o->debug) {
    std::cout << contents << std::endl;
    return 0;
  }

  if (!fs::create_directories(o->project + "/src")) {
    std::cout << "failed to create project directories!" << std::endl;
    return 1;
  }
  std::ofstream c(o->project + "/CMakeLists.txt");
  c << contents;

  std::ofstream b(o->project + "/build.sh");
  b << "#/usr/bin/env bash\n\nmkdir build\ncd build\ncmake ..\nmake\n";
  b.close();

  fs::permissions(o->project + "/build.sh", fs::perms::owner_exec, fs::perm_options::add);

  std::ofstream f(o->project + "/src/" + o->project + ".cpp");
  f << "#include <iostream>\n\nint main() {\n  std::cout << \"sup.\" << std::endl;\n}" << std::endl;

  return 0;
}

int main(int ac, char** av) {
  auto o = cs::get_options(ac, av);
  if (o->project.empty()) {
    std::cout << "--project is required" << std::endl;
    return 1;
  }
  std::string contents = make_contents(o.get());
  return write_contents(contents, std::move(o));
}
