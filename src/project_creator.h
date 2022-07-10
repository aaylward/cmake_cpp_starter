#if !defined(QWK_PROJECT_CREATOR_H)
#define QWK_PROJECT_CREATOR_H

#include "args.h"
#include <memory>
#include <string>

namespace qwk {
  class ProjectCreator {
    private:
      std::unique_ptr<options> o;
    public:
      ProjectCreator(std::unique_ptr<options> _o) : o(std::move(_o)) {}

      std::string write_contents();
      bool write_project_to_disc();
  };
}


#endif // QWK_PROJECT_CREATOR_H
