#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <GLFW/glfw3.h>
#include "Musoenmath.h"
#pragma comment(lib, "OpenGL32")

using namespace std;

vec3 star[5];                           //최초 별
vec3 transformedStar[5];                //업데이트 별
vec3 circle[360];                       //원
vec3 transformedCircle[360];            //업데이트 원
vec4 starColor[5];                      //별 색상
vec4 circleColor[360];                  //원 색상
vec4 transformedStarColor[5];           //업데이트 별 색상
vec4 transformedCircleColor[360];       //업데이트 원 색상

mat3 translate; //이동 행렬
mat3 scale;     //크기 변환 행렬
mat3 rotation;  //회전 행렬

float tx = 0.0f;  //위치 이동 변수
float r = 0.0f;   //각도 변수
float s = 1.0f;   //크기 변수
bool bR = true;   //크기 확대/축소 판단하는 변수
float PI = 3.1415926f; //원주율

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
        //별 그리기
        star[i].x[0][0] = -sin(theta * PI / 180) * 0.5f;
        star[i].x[1][0] = cos(theta * PI / 180) * 0.5f;
        star[i].x[2][0] = 1.0f;

        //별 색상 초기화
        starColor[i].x[0][0] = 0.3f;
        starColor[i].x[1][0] = 0.0f;
        starColor[i].x[2][0] = theta / 360.0f;
        starColor[i].x[3][0] = 0.7f;

        //업데이트 될 예정인 별도 동일하게 초기화
        transformedStar[i] = star[i];
        transformedStarColor[i] = starColor[i];

        i++;
    }

    for (int theta = 0; theta < 360; theta++)
    {
        //원 그리기
        circle[theta].x[0][0] = -sin((float)theta * PI / 180) * 0.5f;
        circle[theta].x[1][0] = cos((float)theta * PI / 180) * 0.5f;
        circle[theta].x[2][0] = 1.0f;

        //원 색상
        circleColor[theta].x[0][0] = 0.3f;
        circleColor[theta].x[1][0] = 0.0f;
        circleColor[theta].x[2][0] = (float)theta / 360.0f;
        circleColor[theta].x[3][0] = 0.7f;

        //업데이트 될 예정인 원도 동일하게 초기화
        transformedCircle[theta] = circle[theta];
        transformedCircleColor[theta] = circleColor[theta];
    }

}


void Update()
{
    while (!glfwWindowShouldClose(window))
    {
        //업데이트가 한 번 돌 때마다 0.001씩 증가
        tx += 0.001f;
        //시계방향으로 -1도씩 회전
        r -= 1.0f;
        //-360도가 되면 0과 같으므로 다시 0으로 초기화
        if (r == -360)
            r = 0;

        //이동 행렬, tx값이 업데이트 함수가 한 번 실행될 때마다
        //0.001씩 증가한 값을 초기화 받습니다
        translate = mat3(
            1, 0, tx,
            0, 1, 0,
            0, 0, 1
        );
        //회전 행렬, r값이 업데이트 함수가 한 번 실행될 때마다
        //-1씩 감소한 값을 초기화 받습니다
        rotation = mat3(
            cos(r * PI / 180), -sin(r * PI / 180), 0,
            sin(r * PI / 180), cos(r * PI / 180), 0,
            0, 0, 1
        );
        //크기 변환 행렬
       scale = mat3(
            s, 0, 0,
            0, s, 0,
            0, 0, 1
        );
       //bR이 true일 경우 확대 false일 경우 축소를 진행한다.
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

        //원 업데이트
        for (int i = 0; i < 360; i++)
        {
            transformedCircle[i] = translate * rotation * scale * circle[i];
        }

        //별 업데이트
        for (int i = 0; i < 5; i++)
        {
            transformedStar[i] =  translate * rotation * scale * star[i] ;
        }

        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        //별그리기
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

        //원 그리기
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

        //초당 프레임 수 출력
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
    Init(); //glfw창 생성, 원과 별의 최초 랜더링
    Update();//창을 닫을 때가지 반복
    Release();//glfw창 제거
    exit(EXIT_SUCCESS);
}