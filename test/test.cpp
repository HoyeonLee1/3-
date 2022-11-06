#include <iostream>
#include "MuSoenMath.h"

//vec3(float 3*1) -> 2차원좌표 + 동차좌표
//mat3(float 3*3) -> 2차원 행렬

int main() {
    vec3 v(1, 1, 1);

    mat3 Translate = mat3(vec3(1, 0, 0),
        vec3(0, 1, 0),
        vec3(3, 5, 1));

    mat3 Rotate = mat3(vec3(cos(30), -sin(30), 0),
        vec3(sin(30), cos(30), 0),
        vec3(0, 0, 1));

    mat3 Scale = mat3(vec3(2, 0, 0),
        vec3(0, 2, 0),
        vec3(0, 0, 1));

    vec3 p = v * Translate * Rotate * Scale;
    for (int i = 0; i < 3; i++) {
        std::cout << p.at(i) << " ";
    }
    return 0;
}