load("//third_party/glfw:glfw.bzl", "glfw")
load("//third_party/imgui:imgui.bzl", "imgui")
load("//third_party/hermetic_cc_toolchain:hermetic_cc_toolchain.bzl", "hermetic_cc_toolchain")
load("//third_party/nlohmann:nlohmann.bzl", "nlohmann")

def dependencies():
    glfw()
    imgui()
    hermetic_cc_toolchain()
    nlohmann()
