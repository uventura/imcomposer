load("//third_party/glfw:glfw.bzl", "glfw")
load("//third_party/imgui:imgui.bzl", "imgui")
load("//third_party/hermetic_cc_toolchain:hermetic_cc_toolchain.bzl", "hermetic_cc_toolchain")

def dependencies():
    hermetic_cc_toolchain()
    glfw()
    imgui()
