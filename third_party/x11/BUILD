cc_import(
    name = "x11_import",
    hdrs = glob([
        "includes/**/*.h"
    ]),
    shared_library = "src/libX11.so",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "x11",
    hdrs = glob([
        "includes/**/*.h",
    ]),
    strip_include_prefix = "includes",
    deps = [
        ":x11_import",
    ],
    visibility = ["//visibility:public"],
)
