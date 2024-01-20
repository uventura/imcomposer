load("//third_party/glfw:glfw.bzl", "glfw")
load("//third_party/imgui:imgui.bzl", "imgui")

def dependencies():
    glfw()
    imgui()
