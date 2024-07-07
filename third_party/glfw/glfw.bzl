load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

def glfw():
    new_git_repository(
        name = "glfw",
        remote = "https://github.com/glfw/glfw",
        # tag = "3.3.8",
        commit = "7b6aead9fb88b3623e3b3725ebb42670cbe4c579",
        build_file = "@//third_party/glfw:glfw.BUILD"
    )
