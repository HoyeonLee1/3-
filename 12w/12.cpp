#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <GLFW/glfw3.h>
#include "Musoenmath.h"
#pragma comment(lib, "OpenGL32")

using namespace std;

vec3 star[5];                           //���� ��
vec3 transformedStar[5];                //������Ʈ ��
vec3 circle[360];                       //��
vec3 transformedCircle[360];            //������Ʈ ��
vec4 starColor[5];                      //�� ����
vec4 circleColor[360];                  //�� ����
vec4 transformedStarColor[5];           //������Ʈ �� ����
vec4 transformedCircleColor[360];       //������Ʈ �� ����

mat3 translate; //�̵� ���
mat3 scale;     //ũ�� ��ȯ ���
mat3 rotation;  //ȸ�� ���

float tx = 0.0f;  //��ġ �̵� ����
float r = 0.0f;   //���� ����
float s = 1.0f;   //ũ�� ����
bool bR = true;   //ũ�� Ȯ��/��� �Ǵ��ϴ� ����
float PI = 3.1415926f; //������

chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<float> renderDuration;

GLFWwindow* window;
bool isFirstFrame = true;
static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

void Init()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    startRenderTimePoint = chrono::system_clock::now();


    int i = 0;
    for (float theta = 0; theta < 360; theta += 72)
    {
        //�� �׸���
        star[i].x[0][0] = -sin(theta * PI / 180) * 0.5f;
        star[i].x[1][0] = cos(theta * PI / 180) * 0.5f;
        star[i].x[2][0] = 1.0f;

        //�� ���� �ʱ�ȭ
        starColor[i].x[0][0] = 0.3f;
        starColor[i].x[1][0] = 0.0f;
        starColor[i].x[2][0] = theta / 360.0f;
        starColor[i].x[3][0] = 0.7f;

        //������Ʈ �� ������ ���� �����ϰ� �ʱ�ȭ
        transformedStar[i] = star[i];
        transformedStarColor[i] = starColor[i];

        i++;
    }

    for (int theta = 0; theta < 360; theta++)
    {
        //�� �׸���
        circle[theta].x[0][0] = -sin((float)theta * PI / 180) * 0.5f;
        circle[theta].x[1][0] = cos((float)theta * PI / 180) * 0.5f;
        circle[theta].x[2][0] = 1.0f;

        //�� ����
        circleColor[theta].x[0][0] = 0.3f;
        circleColor[theta].x[1][0] = 0.0f;
        circleColor[theta].x[2][0] = (float)theta / 360.0f;
        circleColor[theta].x[3][0] = 0.7f;

        //������Ʈ �� ������ ���� �����ϰ� �ʱ�ȭ
        transformedCircle[theta] = circle[theta];
        transformedCircleColor[theta] = circleColor[theta];
    }

}


void Update()
{
    while (!glfwWindowShouldClose(window))
    {
        //������Ʈ�� �� �� �� ������ 0.001�� ����
        tx += 0.001f;
        //�ð�������� -1���� ȸ��
        r -= 1.0f;
        //-360���� �Ǹ� 0�� �����Ƿ� �ٽ� 0���� �ʱ�ȭ
        if (r == -360)
            r = 0;

        //�̵� ���, tx���� ������Ʈ �Լ��� �� �� ����� ������
        //0.001�� ������ ���� �ʱ�ȭ �޽��ϴ�
        translate = mat3(
            1, 0, tx,
            0, 1, 0,
            0, 0, 1
        );
        //ȸ�� ���, r���� ������Ʈ �Լ��� �� �� ����� ������
        //-1�� ������ ���� �ʱ�ȭ �޽��ϴ�
        rotation = mat3(
            cos(r * PI / 180), -sin(r * PI / 180), 0,
            sin(r * PI / 180), cos(r * PI / 180), 0,
            0, 0, 1
        );
        //ũ�� ��ȯ ���
       scale = mat3(
            s, 0, 0,
            0, s, 0,
            0, 0, 1
        );
       //bR�� true�� ��� Ȯ�� false�� ��� ��Ҹ� �����Ѵ�.
        if (bR == true) {
            s += 0.01f;
            if (s > 1.3f) {
                bR = false;
            }
        }
        else if (bR == false) {
            s -= 0.01f;
            if (s < 0.7f) {
                bR = true;
            }
        }

        //�� ������Ʈ
        for (int i = 0; i < 360; i++)
        {
            transformedCircle[i] = translate * rotation * scale * circle[i];
        }

        //�� ������Ʈ
        for (int i = 0; i < 5; i++)
        {
            transformedStar[i] =  translate * rotation * scale * star[i] ;
        }

        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        //���׸���
        glLineWidth(7.0f);
        glBegin(GL_LINE_STRIP);
        int a = 0;
        glColor4f(transformedStarColor[a].x[0][0], transformedStarColor[a].x[1][0],
            transformedStarColor[a].x[2][0], transformedStarColor[a].x[3][0]);
        glVertex3f(transformedStar[a].x[0][0], transformedStar[a].x[1][0], 0.0f);
        a = 3;
        glColor4f(transformedStarColor[a].x[0][0], transformedStarColor[a].x[1][0],
            transformedStarColor[a].x[2][0], transformedStarColor[a].x[3][0]);
        glVertex3f(transformedStar[a].x[0][0], transformedStar[a].x[1][0], 0.0f);
        a = 1;
        glColor4f(transformedStarColor[a].x[0][0], transformedStarColor[a].x[1][0], 
            transformedStarColor[a].x[2][0], transformedStarColor[a].x[3][0]);
        glVertex3f(transformedStar[a].x[0][0], transformedStar[a].x[1][0], 0.0f);
        a = 4;
        glColor4f(transformedStarColor[a].x[0][0], transformedStarColor[a].x[1][0],
            transformedStarColor[a].x[2][0], transformedStarColor[a].x[3][0]);
        glVertex3f(transformedStar[a].x[0][0], transformedStar[a].x[1][0], 0.0f);
        a = 2;
        glColor4f(transformedStarColor[a].x[0][0], transformedStarColor[a].x[1][0],
            transformedStarColor[a].x[2][0], transformedStarColor[a].x[3][0]);
        glVertex3f(transformedStar[a].x[0][0], transformedStar[a].x[1][0], 0.0f);
        a = 0;
        glColor4f(transformedStarColor[a].x[0][0], transformedStarColor[a].x[1][0],
            transformedStarColor[a].x[2][0], transformedStarColor[a].x[3][0]);
        glVertex3f(transformedStar[a].x[0][0], transformedStar[a].x[1][0], 0.0f);

        glEnd();

        //�� �׸���
        glBegin(GL_LINE_STRIP);
        for (int theta = 0; theta < 360; theta++)
        {
            glColor4f(transformedCircleColor[theta].x[0][0], transformedCircleColor[theta].x[1][0],
                transformedCircleColor[theta].x[2][0], transformedCircleColor[theta].x[3][0]);
            glVertex3f(transformedCircle[theta].x[0][0], transformedCircle[theta].x[1][0], 0.0f);
        }
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();

        //�ʴ� ������ �� ���
        renderDuration = chrono::system_clock::now() - startRenderTimePoint;
        startRenderTimePoint = chrono::system_clock::now();

        float fps = 1.0f / renderDuration.count();
        if (isFirstFrame == true)
        {
            isFirstFrame = false;
            continue;
        }
        if (renderDuration.count() < (1.0f / 60.0f))
            this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
        string fps_s = "FPS : " + to_string(fps);
        cout << fps_s << endl;
    }
}

void Release()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main() 
{
    Init(); //glfwâ ����, ���� ���� ���� ������
    Update();//â�� ���� ������ �ݺ�
    Release();//glfwâ ����
    exit(EXIT_SUCCESS);
}