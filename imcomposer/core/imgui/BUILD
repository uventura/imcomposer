cc_library(
    name = "imgui",
    srcs = [
        "imgui.cpp",
    ],
    hdrs = [
        "imgui.hpp",
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
    hdrs = ["docking.hpp"],
    deps = [":imgui"],
    visibility = ["//imcomposer:__subpackages__"],
)
