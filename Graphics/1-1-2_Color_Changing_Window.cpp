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

    glfwInit();//��ʼ��glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//��һЩ������ֵ, �൱������, ��һ�к���һ�����õĶ��� API �汾, Ҳ���� glfw3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//ģʽΪ����ģʽ

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL); // �����Ƿ�װ��glfw�е�һ������, ����һ������, ��¼����ָ���Ա��������, ǰ���������Ǵ��ڴ�С (����Ϊ��λ), �����������Ǵ��ڱ���
    if (window == NULL) { // �½�����ʧ��, ����, ��ֹ���� Bug
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);//���õ�ǰ������Ϊ��ǰ����
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//����ע��ǰ�������Ļص�����, ʹ��ÿ���޸Ĵ��ڴ�Сʱ����

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {//glad ������ȡ�Կ������е� OpenGL ����, �����ǳ�ʼ��, ���жϳɹ����
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {//��Ⱦѭ��, Ҳ�������һ֡���һ֡�Ĺ���, Windows Should Close ���ص��Ǵ����Ƿ񱻹ر�, �����ʱ��ס��, �ⲿ�ر�����Ч��Ҳ����Ϊ���ԭ��
        processInput(window);//������һ���û��Ĳ���
        glClearColor(ColorR += 0.01, ColorG -= 0.01, ColorB, 1.0);  // ������ɫ, �����ҷֱ����ĸ� [0, 1] ��ʵ����ʾ R, G, B �� Alpha ͨ��
        printf("%f %f %f\n", ColorR, ColorG, ColorB);   // ����̨��Ϣ
        if (ColorR > 1) break;  // ����
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);//����֮��֡��ʾ����, ʵ�������滻����Ļ������
        glfwPollEvents();//�����û��Ĳ���
    }
    glfwTerminate();//�ͷ��������Դ (Terminate: ��ֹ)
    return 0;
}

void processInput(GLFWwindow* window) {//��������
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);//��ǰֻ�ܴ����˳�����, Ҳ���� "ESC" ������
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {//����ص�����
    glViewport(0, 0, width, height);//ǰ�������������½�����, ���������ӿڴ�С (����)
}