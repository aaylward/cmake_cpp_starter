#if !defined(QWK_ARGS_H)
#define QWK_ARGS_H

#include <cstdint>
#include <memory>
#include <string>

namespace qwk {
  struct options {
    uint8_t standard;
    bool parser;
    bool debug;
    std::string boost_version;
    std::string project;
  };

  [[nodiscard]] std::unique_ptr<options> get_options(int ac, char** av);
}


#endif // QWK_ARGS_H
