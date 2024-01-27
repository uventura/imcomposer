#ifndef IMCOMPOSER_UTILS_BAZEL
#define IMCOMPOSER_UTILS_BAZEL

#include <string>

namespace ImComposer
{
namespace Utils
{
namespace Bazel
{
    std::string getFullPath(std::string applicationPath, std::string relativePath);
}
}
}

#endif
