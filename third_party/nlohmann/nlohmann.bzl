load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

def nlohmann():
    new_git_repository(
        name = "nlohmann",
        remote = "https://github.com/nlohmann/json.git",
        # branch = "docking",
        commit = "9cca280a4d0ccf0c08f47a99aa71d1b0e52f8d03",
        build_file = "@//third_party/nlohmann:nlohmann.BUILD",
    )
