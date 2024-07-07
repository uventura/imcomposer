package(default_visibility = ["//imcomposer:__subpackages__"])

cc_library(
    name = "environment",
    srcs = ["imcomposer_environment.cpp"],
    hdrs = ["imcomposer_environment.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "imcomposer",
    srcs = [
        "imcomposer.cpp",
    ],
    hdrs = [
        "imcomposer.hpp",
    ],
    deps = [
        "//imcomposer/core/window",
        "//imcomposer/core/imgui",
        "//imcomposer/core/imgui:docking",
        ":environment",
        "//imcomposer/ui",
    ]
)

cc_binary(
    name = "application",
    deps = [":imcomposer"],
    srcs = [
        "main.cpp"
    ],
)
