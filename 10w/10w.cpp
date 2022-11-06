#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include "MusoenMath.h"

using namespace std;

void mat3::printmat3()

{
    cout << "----------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << m[i][j] << " " ;
        cout << endl;
    }
    cout << "----------------" << endl;
    cout << endl;

}
void vec3::printvec3()

{
    cout << "----------------" << endl;
    for (int i = 0; i < 3; i++)
        cout << v[i] << " " ;

        cout << endl;
        cout << "----------------" << endl;
        cout << endl;  
}
void posMath::printPmat3()

{
    cout << "----------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << pm[i][j] << " ";
        cout << endl;
    }
    cout << "----------------" << endl;
    cout << endl;
}

void posMath::printPvec3()

{
    cout << "----------------" << endl;
    for (int i = 0; i < 3; i++)
        cout << pv[i] << " ";

    cout << endl;
    cout << "----------------" << endl;
    cout << endl;
}

void posMath::vec3Set(float a, float b, float c)
{
    pv[0] = a;
    pv[1] = b;
    pv[2] = c;
}
void posMath::mat3Set(float a, float b, float c, float d, float e, float f, float g, float h, float i)
{
    pm[0][0] = a;
    pm[0][1] = b;
    pm[0][2] = c;
    pm[1][0] = d;
    pm[1][1] = e;
    pm[1][2] = f;
    pm[2][0] = g;
    pm[2][1] = h;
    pm[2][2] = i;
}


void main()
{

    posMath v;
    posMath finalR,finalR2;
    posMath FR;
    FR.vec3Set(1, 1, 1);
    v.vec3Set(1, 1, 1);
    
    posMath Tr;
    Tr.mat3Set(1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        3.0, 5.0, 1.0);

    posMath Ro;
    Ro.mat3Set(cos(30), -sin(30), 0.0,
        sin(30), cos(30), 0.0,
        0.0, 0.0, 1.0);
    posMath Sc;
    Sc.mat3Set(2.0, 0.0, 0.0,
        0.0, 2.0, 0.0,
        0.0, 0.0, 1.0);
    Tr.printPmat3();
    Ro.printPmat3();
    Sc.printPmat3();
    mat3 test1 = mat3(1, 0, 0,
        0, 1, 0,
        0, 0, 1);
    mat3 test2 = mat3(5, 0, 0,
        0, 5, 0,
        0, 0, 5);
    mat3 test3;
    test3 = test1 * test2;

    test3.printmat3();

    FR = v * Tr * Ro * Sc;

    cout << endl;

    cout << "(" << FR.pv[0] << " " << FR.pv[1] << " " << FR.pv[2]<< ")" << endl;

}