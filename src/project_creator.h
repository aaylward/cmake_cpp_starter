#if !defined(CPP_STARTER_PROJECT_CREATOR_H)
#define CPP_STARTER_PROJECT_CREATOR_H

#include "args.h"
#include <string>

namespace cpp_starter {
  class ProjectCreator {
    private:
      std::unique_ptr<options> o;
    public:
      ProjectCreator(std::unique_ptr<options> _o) : o(std::move(_o)) {}

      std::string write_contents();
      bool write_project_to_disc();
  };
}


#endif // CPP_STARTER_PROJECT_CREATOR_H
