package(default_visibility = ["//imcomposer:__subpackages__"])

cc_library(
    name = "imcomposer",
    srcs = [
        "imcomposer.cpp",
    ],
    hdrs = [
        "imcomposer.hpp"
    ],
    deps = [
        "//imcomposer/core/window",
        "//imcomposer/core/imgui",
        "//imcomposer/components/docking",
    ]
)

cc_binary(
    name = "main",
    deps = [":imcomposer"],
    srcs = [
        "main.cpp"
    ],
)
