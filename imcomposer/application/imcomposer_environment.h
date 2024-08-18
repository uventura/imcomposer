// Bad Practice

#ifndef IMCOMPOSER_GLOBAL
#define IMCOMPOSER_GLOBAL

#include <string>

/*
Because the application is beeing used with
    bazel run ...
For execution mode, this variable is beeing
used.
*/

namespace ImComposer {
namespace Environment {
extern std::string applicationPath;
}
}  // namespace ImComposer

#endif
