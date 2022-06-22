#if !defined(CPP_STARTER_ARGS_H)
#define CPP_STARTER_ARGS_H

#include <cstdint>
#include <string>

namespace cpp_starter {
  struct options {
    uint8_t standard;
    bool parser;
    bool debug;
    std::string boost_version;
    std::string project;
  };

  [[nodiscard]] std::unique_ptr<options> get_options(int ac, char** av);
}


#endif // CPP_STARTER_ARGS_H
