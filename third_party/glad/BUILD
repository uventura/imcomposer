cc_library(
    name = "glad",
    srcs = [
        "src/gl.c",
    ],
    hdrs = [
        "include/GL/gl.h",
        "include/glad/gl.h",
        "include/KHR/khrplatform.h"
    ],
    visibility = ["//visibility:public"],
    strip_include_prefix = "include",
    linkopts = select({
        "//conditions:default": [],
        "@bazel_tools//src/conditions:windows": [],
        "@bazel_tools//src/conditions:linux": [
            "-ldl",
            # "-lpthread",
            # "-fpic",
            # "-fPIC",
            # "-m64",
        ],
    }),
    copts = select({
        "//conditions:default": [],
        "@bazel_tools//src/conditions:windows": [],
        "@bazel_tools//src/conditions:linux": [
            "-ldl",
            # "-lpthread",
            # "-fpic",
            # "-fPIC",
            # "-m64"
        ],
    }),
)
