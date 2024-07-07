cc_library(
    name = "imgui",
    srcs = [
        "imgui.cpp",
    ],
    hdrs = [
        "imgui.h",
    ],
    deps = [
        "//third_party/imgui",
        "//data/fonts",
        "//imcomposer/utils:bazel",
        "//imcomposer/core/fonts:font_loader",
    ],
    visibility = ["//imcomposer:__subpackages__",],
)

cc_library(
    name = "docking",
    srcs = ["docking.cpp"],
    hdrs = ["docking.h"],
    deps = [":imgui"],
    visibility = ["//imcomposer:__subpackages__"],
)
