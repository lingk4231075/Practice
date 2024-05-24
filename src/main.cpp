#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
int main() {
    SPDLOG_INFO("Start program");
    SPDLOG_INFO("Initialize glfw");

    if (!glfwInit()) { //initialize
        const char *description = nullptr;
        glfwGetError(&description); 
        SPDLOG_ERROR("failed to initialize glfw: {}", description); // {} == %, 타입 지정을 하지 않아도 됨
        return -1;
    }

    SPDLOG_INFO("Create glfw window");
    auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr); // 
    if (!window) {
        SPDLOG_ERROR("failed to create glfw window");
        glfwTerminate();
        return -1;
    }
    SPDLOG_INFO("Start main loop");

    while (!glfwWindowShouldClose(window)) { // 루프
        glfwPollEvents(); // 
    }

    glfwTerminate();

    return 0;
}