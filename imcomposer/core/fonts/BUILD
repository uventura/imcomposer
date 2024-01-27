cc_library(
    name = "font_data",
    srcs = ["font_data.h"],
    deps = ["//data/fonts"],
    visibility = ["//imcomposer:__subpackages__"],
)

cc_library(
    name = "font_loader",
    srcs = ["font_loader.cpp"],
    hdrs = ["font_loader.h"],
    deps = [
        ":font_data",
        "//third_party/imgui",
        "//imcomposer/application:environment",
        "//data/fonts",
        "//imcomposer/utils:bazel",
    ],
    data = [],
    visibility = ["//imcomposer:__subpackages__"],
)

cc_library(
    name = "fonts",
    srcs = ["fonts.h"],
    deps = ["//data/fonts"],
    visibility = ["//imcomposer:__subpackages__"],
)
