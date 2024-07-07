load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

def imgui():
    new_git_repository(
        name = "imgui",
        remote = "https://github.com/ocornut/imgui",
        # branch = "docking",
        commit = "1db579d458da29fa43376af9d88d486910d9406a",
        build_file = "@//third_party/imgui:imgui.BUILD",
    )
