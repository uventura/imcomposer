cc_library(
    name = "tinyfiledialogs",
    srcs = [
        "tinyfiledialogs.c",
    ],
    hdrs = [
        "tinyfiledialogs.h"
    ],
    linkopts = ["comdlg32.lib", "ole32.lib", "user32.lib", "shell32.lib"],
    visibility = ["//tools/booster/gui:__subpackages__"],
)
