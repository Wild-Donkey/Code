#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float ColorR(0.0), ColorG(1.0), ColorB(0.5);

int main()
{

    glfwInit();//初始化glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//给一些参数赋值, 相当于设置, 这一行和下一行设置的都是 API 版本, 也就是 glfw3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//模式为核心模式

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL); // 窗口是封装在glfw中的一个对象, 生成一个窗口, 记录它的指针以便后续操作, 前两个参数是窗口大小 (像素为单位), 第三个参数是窗口标题
    if (window == NULL) { // 新建窗口失败, 跳出, 防止更大 Bug
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);//设置当前上下文为当前窗口
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//这里注册前面声明的回调函数, 使得每次修改窗口大小时调用

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {//glad 用来拉取显卡驱动中的 OpenGL 函数, 这里是初始化, 并判断成功与否
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {//渲染循环, 也就是算出一帧输出一帧的过程, Windows Should Close 返回的是窗口是否被关闭, 如果这时候卡住了, 外部关闭是无效的也是因为这个原因
        processInput(window);//处理上一轮用户的操作
        glClearColor(ColorR += 0.01, ColorG -= 0.01, ColorB, 1.0);  // 设置颜色, 从左到右分别是四个 [0, 1] 的实数表示 R, G, B 和 Alpha 通道
        printf("%f %f %f\n", ColorR, ColorG, ColorB);   // 控制台信息
        if (ColorR > 1) break;  // 跳出
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);//处理之后将帧显示出来, 实现上是替换了屏幕缓冲区
        glfwPollEvents();//接收用户的操作
    }
    glfwTerminate();//释放申请的资源 (Terminate: 终止)
    return 0;
}

void processInput(GLFWwindow* window) {//处理输入
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);//当前只能处理退出操作, 也就是 "ESC" 被按下
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {//定义回调函数
    glViewport(0, 0, width, height);//前两个参数是左下角坐标, 后两个是视口大小 (像素)
}