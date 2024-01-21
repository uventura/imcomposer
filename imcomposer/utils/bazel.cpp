#include "imcomposer/utils/bazel.h"

#include "tools/cpp/runfiles/runfiles.h"
using bazelRunfiles = bazel::tools::cpp::runfiles::Runfiles;

std::string ImComposer::Utils::Bazel::getFullPath(std::string applicationPath, std::string relativePath)
{
    std::string error;
    std::unique_ptr<bazelRunfiles> runfiles(
        bazelRunfiles::Create(applicationPath, &error)
    );

    if(runfiles == nullptr)
    {
        return error;
    }

    return runfiles->Rlocation(relativePath);
}
