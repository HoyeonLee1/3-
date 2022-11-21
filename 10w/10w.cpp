#include <iostream>
#include "Musoenmath.h"

using namespace std;

void mat3::printmat3()
{
    // mat3 출력용 함수 본문
    cout << "----------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << "----------------" << endl;
    cout << endl;
}
void vec3::printvec3()
{
    // vec3 출력용 함수 본문
    cout << "----------------" << endl;

    cout << x << " " << y << " " << z << " ";

    cout << endl;
    cout << "----------------" << endl;
    cout << endl;
}

//
int main()
{
    // 삼각함수 선언
    const float PI = 3.1415926;
    float a = sin(30 * PI / 180);
    float b = cos(30 * PI / 180);

    //좌표 초기값 (1,1,1) 초기화
    vec3 v = vec3(1, 1, 1);

    // (3,5) 이동행렬 초기화
    mat3 Tr = mat3(1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        3.0, 5.0, 1.0);
    // 30도 회전행렬 초기화
    mat3 Ro = mat3(b, -a, 0.0,
        a, b, 0.0,
        0.0, 0.0, 1.0);
    // 2배 확대 스케일 행렬 초기화
    mat3 Sc = mat3(2.0, 0.0, 0.0,
        0.0, 2.0, 0.0,
        0.0, 0.0, 1.0);

    // 행렬이 잘 초기화 되었는지 확인하는 출력문
    v.printvec3();
    Tr.printmat3();
    Ro.printmat3();
    Sc.printmat3();
    // 결과값 좌표 = 초기값 * 이동행렬 * 회전행렬 * 스케일행렬
    vec3 p = v * Tr * Ro * Sc;
    // 최종 좌표값 출력
    p.printvec3();
}