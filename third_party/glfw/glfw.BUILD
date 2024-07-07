# https://github.com/pbellis/bazel-glfw/blob/master/glfw.BUILD

WIN32_DEFINES = [
    "_GLFW_WIN32",
    "GLFW_INVALID_CODEPOINT"
]

WIN32_HDRS = [
    "src/win32_joystick.h",
    "src/win32_platform.h",
    "src/win32_thread.h",
    "src/win32_time.h",
    "src/init.c",
]

WIN32_SRCS = [
    "src/glx_context.c",
    "src/win32_init.c",
    "src/win32_joystick.c",
    "src/win32_monitor.c",
    "src/win32_thread.c",
    "src/win32_time.c",
    "src/win32_window.c",
    "src/win32_module.c",
    "src/wgl_context.c",
]

WIN32_LINKOPTS = [
    "-DEFAULTLIB:user32.lib",
    "-DEFAULTLIB:gdi32.lib",
    "-DEFAULTLIB:shell32.lib",
]

LINUX_DEFINES = [
    "_GLFW_HAS_XF86VM",
    "_GLFW_X11",
]

LINUX_HDRS = [
    "src/linux_joystick.h",
    "src/posix_thread.h",
    "src/posix_time.h",
    "src/posix_poll.h",
    "src/x11_platform.h",
]

LINUX_SRCS = [
    "src/glx_context.c",
    "src/linux_joystick.c",
    "src/posix_thread.c",
    "src/posix_time.c",
    "src/posix_poll.c",
    "src/posix_module.c",
    "src/x11_init.c",
    "src/x11_monitor.c",
    "src/x11_window.c",
]

LINUX_LINKOPTS = []

LINUX_DEPS = [
    "@//third_party/x11"
]

SRCS = [
    "src/context.c",
    "src/egl_context.c",
    "src/init.c",
    "src/input.c",
    "src/osmesa_context.c",
    "src/monitor.c",
    "src/vulkan.c",
    "src/window.c",
    "src/xkb_unicode.c",
    "src/platform.c",
    "src/null_window.c",
    "src/null_init.c",
    "src/null_monitor.c",
    "src/null_joystick.c",
]

HDRS = [
    "include/GLFW/glfw3.h",
    "include/GLFW/glfw3native.h",
    "src/internal.h",
    "src/mappings.h",
    "src/xkb_unicode.h",
    "src/platform.h",
    "src/null_platform.h",
    "src/null_joystick.h",
]

cc_library(
    name = "glfw_src",
    hdrs = HDRS + select({
		"@bazel_tools//src/conditions:windows": WIN32_HDRS,
		"@bazel_tools//src/conditions:linux_x86_64": LINUX_HDRS,
	}),
    srcs = SRCS + select({
		"@bazel_tools//src/conditions:windows": WIN32_SRCS,
		"@bazel_tools//src/conditions:linux_x86_64": LINUX_SRCS,
	}),
    defines = select({
		"@bazel_tools//src/conditions:windows": WIN32_DEFINES,
		"@bazel_tools//src/conditions:linux_x86_64": LINUX_DEFINES,
	}),
    deps = [
        "@//third_party/glad",
    ] + select({
		"@bazel_tools//src/conditions:windows": [],
		"@bazel_tools//src/conditions:linux_x86_64": LINUX_DEPS,
	}),
    linkopts = select({
        "//conditions:default": [],
        "@bazel_tools//src/conditions:windows": ["-lGdi32"],
        "@bazel_tools//src/conditions:linux": [],
    }),
)

cc_library(
    name = "glfw",
    hdrs = [
        "include/GLFW/glfw3.h",
        "include/GLFW/glfw3native.h",
    ],
    linkopts = select({
		"@bazel_tools//src/conditions:windows": WIN32_LINKOPTS,
		"@bazel_tools//src/conditions:linux_x86_64": LINUX_LINKOPTS,
	}),
    deps = [
        ":glfw_src",
        "@//third_party/glad",
    ],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)
