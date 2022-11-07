#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include "Musoenmath.h"
using namespace std;
void mat3::printmat3()
{
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
    cout << "----------------" << endl;

    cout << x << " " << y << " " << z << " ";

    cout << endl;
    cout << "----------------" << endl;
    cout << endl;
}
int main()
{

    const float PI = 3.1415926;
    double a = sin(30 * PI / 180);
    double b = cos(30 * PI / 180);

    vec3 v = vec3(1, 1, 1);

    mat3 Tr = mat3(1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        3.0, 5.0, 1.0);

    mat3 Ro = mat3(b, -a, 0.0,
        a, b, 0.0,
        0.0, 0.0, 1.0);
    mat3 Sc = mat3(2.0, 0.0, 0.0,
        0.0, 2.0, 0.0,
        0.0, 0.0, 1.0);

    v.printvec3();
    Tr.printmat3();
    Ro.printmat3();
    Sc.printmat3();
    vec3 p = v * Tr * Ro * Sc;
    p.printvec3();

}