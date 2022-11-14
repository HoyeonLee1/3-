#include <iostream>
#include "Musoenmath.h"

using namespace std;

//3x3 행렬 출력함수
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
//4x4 행렬 출력함수
void mat4::printmat4()
{
    cout << "----------------" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    cout << "----------------" << endl;
    cout << endl;
}

//1x3 벡터 출력 함수
void vec1x3::printvec1x3()
{
    cout << "----------------" << endl;
    cout << x[0][0] << " " << x[0][1] << " " << x[0][2] << " ";
    cout << endl;
    cout << "----------------" << endl;
    cout << endl;
}

//vec3 출력 함수
void vec3::printvec3()
{
    cout << "----------------" << endl;
    cout << "(" << x[0][0] << endl <<x[1][0] << endl << x[2][0] << ")";
    cout << endl;
    cout << "----------------" << endl;
    cout << endl;
}

//vec4 출력 함수
void vec4::printvec4()
{
    cout << "----------------" << endl;
    cout << "(" << x[0][0] << endl << x[1][0] << endl << x[2][0] << endl << x[3][0] << ")";
    cout << endl;
    cout << "----------------" << endl;
    cout << endl;
}
//vec4 출력 함수
void vec1x4::printvec1x4()
{
    cout << "----------------" << endl;
    cout << x[0][0] << " " << x[0][1] << " " << x[0][2] << " " << x[0][3];
    cout << endl;
    cout << "----------------" << endl;
    cout << endl;
}
//3x3 행렬을 단위행렬로 초기화하는 함수
void mat3::Mat3identity()
{
    a[0][0] = 1;
    a[0][1] = 0;
    a[0][2] = 0;

    a[1][0] = 0;
    a[1][1] = 1;
    a[1][2] = 0;

    a[2][0] = 0;
    a[2][1] = 0;
    a[2][2] = 1;
}
//4x4 행렬을 단위행렬로 초기화하는 함수
void mat4::Mat4Identity()
{
    b[0][0] = 1;
    b[0][1] = 0;
    b[0][2] = 0;
    b[0][3] = 0;

    b[1][0] = 0;
    b[1][1] = 1;
    b[1][2] = 0;
    b[1][3] = 0;

    b[2][0] = 0;
    b[2][1] = 0;
    b[2][2] = 1;
    b[2][3] = 0;
    
    b[3][0] = 0;
    b[3][1] = 0;
    b[3][2] = 0;
    b[3][3] = 1;
}
// 3x3행렬을 전치하는 함수
void mat3::Mat3Transpose()
{

    mat3 p; 

    for (int i = 0; i < 3; i++)

        for (int j = 0; j < 3; j++)

            p.a[i][j] = a[i][j];


    for (int i = 0; i < 3; i++)

        for (int j = 0; j < 3; j++)

            a[j][i] = p.a[i][j];
}
//4x4 행렬을 전치하는 함수
void mat4::Mat4Transpose()
{

    mat4 p;

    for (int i = 0; i < 4; i++)

        for (int j = 0; j < 4; j++)

            p.b[i][j] = b[i][j];


    for (int i = 0; i < 4; i++)

        for (int j = 0; j < 4; j++)

            b[j][i] = p.b[i][j];
}
//3x3 행렬을 다른 행렬에 대입할 때 쓰는 함수
void mat3::operator=(const mat3& x)

{

    for (int i = 0; i < 3; i++)

        for (int j = 0; j < 3; j++)

            a[i][j] = x.a[i][j];

}
//4x4 행렬을 다른 행렬에 대입할 때 쓰는 함수
void mat4::operator=(const mat4& x)

{
    for (int i = 0; i < 4; i++)

        for (int j = 0; j < 4; j++)

            b[i][j] = x.b[i][j];
}
//3x3 행렬 두 개를 전치 후 곱셈을 진행하여 그 결과값을 리턴해주는 함수
void mat3::multiplytransposematrix(mat3 x, mat3 y) {
    mat3  v, p;
    //x행렬 전치
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            v.a[j][i] = x.a[i][j];
    //y행렬 전치
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            p.a[j][i] = y.a[i][j];

    //1행
    a[0][0] = (v.a[0][0] * p.a[0][0]) + (v.a[0][1] * p.a[1][0]) + (v.a[0][2] * p.a[2][0]);
    a[0][1] = (v.a[0][0] * p.a[0][1]) + (v.a[0][1] * p.a[1][1]) + (v.a[0][2] * p.a[2][1]);
    a[0][2] = (v.a[0][0] * p.a[0][2]) + (v.a[0][1] * p.a[1][2]) + (v.a[0][2] * p.a[2][2]);
  
    //2행
    a[1][0] = (v.a[1][0] * p.a[0][0]) + (v.a[1][1] * p.a[1][0]) + (v.a[1][2] * p.a[2][0]);
    a[1][1] = (v.a[1][0] * p.a[0][1]) + (v.a[1][1] * p.a[1][1]) + (v.a[1][2] * p.a[2][1]);
    a[1][2] = (v.a[1][0] * p.a[0][2]) + (v.a[1][1] * p.a[1][2]) + (v.a[1][2] * p.a[2][2]);
    
    //3행
    a[2][0] = (v.a[2][0] * p.a[0][0]) + (v.a[2][1] * p.a[1][0]) + (v.a[2][2] * v.a[2][0]);
    a[2][1] = (v.a[2][0] * p.a[0][1]) + (v.a[2][1] * p.a[1][1]) + (v.a[2][2] * v.a[2][1]);
    a[2][2] = (v.a[2][0] * p.a[0][2]) + (v.a[2][1] * p.a[1][2]) + (v.a[2][2] * v.a[2][2]);
}
//4x4 행렬 두 개를 전치 후 곱셈을 진행하여 그 결과값을 리턴해주는 함수
void mat4::multiplytransposematrix(mat4 x, mat4 y) {
    mat4  v, p;
    //x행렬 전치
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            v.b[j][i] = x.b[i][j];
    //y행렬 전치
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            p.b[j][i] = y.b[i][j];
    //1행
    b[0][0] = (v.b[0][0] * p.b[0][0]) + (v.b[0][1] * p.b[1][0]) + (v.b[0][2] * p.b[2][0]) + (v.b[0][3] * p.b[3][0]);
    b[0][1] = (v.b[0][0] * p.b[0][1]) + (v.b[0][1] * p.b[1][1]) + (v.b[0][2] * p.b[2][1]) + (v.b[0][3] * p.b[3][1]);
    b[0][2] = (v.b[0][0] * p.b[0][2]) + (v.b[0][1] * p.b[1][2]) + (v.b[0][2] * p.b[2][2]) + (v.b[0][3] * p.b[3][2]);
    b[0][3] = (v.b[0][0] * p.b[0][3]) + (v.b[0][1] * p.b[1][3]) + (v.b[0][2] * p.b[2][3]) + (v.b[0][3] * p.b[3][3]);
    //2행
    b[1][0] = (v.b[1][0] * p.b[0][0]) + (v.b[1][1] * p.b[1][0]) + (v.b[1][2] * p.b[2][0]) + (v.b[1][3] * p.b[3][0]);
    b[1][1] = (v.b[1][0] * p.b[0][1]) + (v.b[1][1] * p.b[1][1]) + (v.b[1][2] * p.b[2][1]) + (v.b[1][3] * p.b[3][1]);
    b[1][2] = (v.b[1][0] * p.b[0][2]) + (v.b[1][1] * p.b[1][2]) + (v.b[1][2] * p.b[2][2]) + (v.b[1][3] * p.b[3][2]);
    b[1][3] = (v.b[1][0] * p.b[0][3]) + (v.b[1][1] * p.b[1][3]) + (v.b[1][2] * p.b[2][3]) + (v.b[1][3] * p.b[3][3]);
    //3행
    b[2][0] = (v.b[2][0] * p.b[0][0]) + (v.b[2][1] * p.b[1][0]) + (v.b[2][2] * v.b[2][0]) + (v.b[2][3] * p.b[3][0]);
    b[2][1] = (v.b[2][0] * p.b[0][1]) + (v.b[2][1] * p.b[1][1]) + (v.b[2][2] * v.b[2][1]) + (v.b[2][3] * p.b[3][1]);
    b[2][2] = (v.b[2][0] * p.b[0][2]) + (v.b[2][1] * p.b[1][2]) + (v.b[2][2] * v.b[2][2]) + (v.b[2][3] * p.b[3][2]);
    b[2][3] = (v.b[2][0] * p.b[0][3]) + (v.b[2][1] * p.b[1][3]) + (v.b[2][2] * v.b[2][3]) + (v.b[2][3] * p.b[3][3]);
    //4헹
    b[3][0] = (v.b[3][0] * p.b[0][0]) + (v.b[3][1] * p.b[1][0]) + (v.b[3][2] * v.b[2][0]) + (v.b[3][3] * p.b[3][0]);
    b[3][1] = (v.b[3][0] * p.b[0][1]) + (v.b[3][1] * p.b[1][1]) + (v.b[3][2] * v.b[2][1]) + (v.b[3][3] * p.b[3][1]);
    b[3][2] = (v.b[3][0] * p.b[0][2]) + (v.b[3][1] * p.b[1][2]) + (v.b[3][2] * v.b[2][2]) + (v.b[3][3] * p.b[3][2]);
    b[3][3] = (v.b[3][0] * p.b[0][3]) + (v.b[3][1] * p.b[1][3]) + (v.b[3][2] * v.b[2][3]) + (v.b[3][3] * p.b[3][3]);
}

int main()
{
    // 1. 단위행렬 초기화 출력
    mat3 mat3IdentityTest(0, 0, 0, 0, 0, 0, 0, 0, 0);
    mat4 mat4IdentityTest(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    mat3IdentityTest.Mat3identity();
    mat4IdentityTest.Mat4Identity();
    mat3IdentityTest.printmat3();
    mat4IdentityTest.printmat4();

    //2. 전치행렬 출력
    mat3 mat3TransposeTest(1,2,3,1,2,3,1,2,3);
    mat4 mat4TransposeTest(1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4);
    mat3TransposeTest.printmat3();
    mat4TransposeTest.printmat4();
    mat3TransposeTest.Mat3Transpose();
    mat4TransposeTest.Mat4Transpose();
    mat3TransposeTest.printmat3();
    mat4TransposeTest.printmat4();
    
    //3. a) 행렬간 곱셈 출력
    mat3 mat3multiplyTest1(2, 0, 0, 0, 2, 0, 0, 0, 2);
    mat3 mat3multiplyTest2(6, 0, 0, 0, 6, 0, 0, 0, 6);
    mat4 mat4multiplyTest1(2, 0, 0,0, 0, 2, 0,0, 0, 0, 2,0,0,0,0,2);
    mat4 mat4multiplyTest2(6, 0, 0, 0, 0, 6, 0, 0, 0, 0, 6, 0, 0, 0, 0, 6);
    mat3 mat3multiplyResult = mat3multiplyTest1 * mat3multiplyTest2;
    mat4 mat4multiplyResult = mat4multiplyTest1 * mat4multiplyTest2;
    mat3multiplyResult.printmat3();
    mat4multiplyResult.printmat4();

    //3. b) 두 행렬을 전치후 곱셈을 진행하는 함수 출력
    mat3 mat3multiplyTransposeTest1(2, 2, 2, 0, 0, 0, 0, 0, 0);
    mat3 mat3multiplyTransposeTest2(3, 3, 3, 0, 0, 0, 0, 0, 0);
    mat4 mat4multiplyTransposeTest1(3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    mat4 mat4multiplyTransposeTest2(4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    mat3 mat3multiplyTransposeResult;
    mat3multiplyTransposeResult.multiplytransposematrix(mat3multiplyTransposeTest1, mat3multiplyTransposeTest2);
    mat3multiplyTransposeResult.printmat3();
    mat4 mat4multiplyTransposeResult;
    mat4multiplyTransposeResult.multiplytransposematrix(mat4multiplyTransposeTest1, mat4multiplyTransposeTest2);
    mat4multiplyTransposeResult.printmat4();

    //3. c)행렬과 벡터값의 곱셈 결과값 출력
    mat3 mat3multiplytest3(1, 0, 3, 0, 1, 5, 0, 0, 1);
    vec1x3 vec1x3multiplytest(1, 1, 1);
    vec3 vec3multiplytest(1, 1, 1);
    mat4 mat4multiplytest3(1, 0, 0,3, 0, 1,0, 5, 0, 0, 1,0,0,0,0,1);
    vec1x4 vec1x4multiplytest(1, 1, 1,1);
    vec4 vec4multiplytest(1, 1, 1,1);
    vec3 matvec3multiplyResult = mat3multiplytest3 * vec3multiplytest;
    vec1x3 matvec1x3multiplyResult = vec1x3multiplytest * mat3multiplytest3;
    matvec3multiplyResult.printvec3();
    matvec1x3multiplyResult.printvec1x3();
    vec4 matvec4multiplyResult = mat4multiplytest3 * vec4multiplytest;
    vec1x4 matvec1x4multiplyResult = vec1x4multiplytest*mat4multiplytest3;
    matvec4multiplyResult.printvec4();
    matvec1x4multiplyResult.printvec1x4();
    
    //3. d) 행렬에 벡터를 곱했을 때 자동으로 전치 후 계산하는 연산자 오버로딩 출력 
    mat3 mat3multiplyTransposeTest3(1, 0, 3,    0, 1, 5,    0, 0, 1);
    vec3 vec3multiplyTransposeTest(1, 1, 1);
    vec1x3 vec1x3multyplyTransposeTest(1, 1, 1);
    vec3 vec3multiplyTransposeResult = vec3multiplyTransposeTest*mat3multiplyTransposeTest3;
    vec3multiplyTransposeResult.printvec3();
    vec1x3 vec1x3multiplyTransposeResult = mat3multiplyTransposeTest3 * vec1x3multyplyTransposeTest;
    vec1x3multiplyTransposeResult.printvec1x3();
    mat4 mat4multiplyTransposeTest3(1, 0, 0, 3, 0, 1, 0, 5, 0, 0, 1, 0, 0, 0, 0, 1);
    vec4 vec4multiplyTransposeTest(1, 1, 1,1);
    vec1x4 vec1x4multyplyTransposeTest(1, 1, 1,1);
    vec4 vec4multiplyTransposeResult = vec4multiplyTransposeTest * mat4multiplyTransposeTest3;
    vec4multiplyTransposeResult.printvec4();
    vec1x4 vec1x4multiplyTransposeResult = mat4multiplyTransposeTest3 * vec1x4multyplyTransposeTest;
    vec1x4multiplyTransposeResult.printvec1x4();

    //3. e-1) 행렬간 덧셈, 뺄셈
    mat3 mat3_P_M(4, 4, 4, 3, 3, 3, 2, 2, 2);
    mat3 mat3_P_M2(3, 3, 3, 2, 2,2, 1, 1, 1);
    mat4 mat4_P_M(5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2);
    mat4 mat4_P_M2(4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1);
    mat3 mat3_P_M_Result = mat3_P_M + mat3_P_M2;
    mat3_P_M_Result.printmat3();
    mat4 mat4_P_M_Result = mat4_P_M + mat4_P_M2;
    mat4_P_M_Result.printmat4();
    mat3_P_M_Result = mat3_P_M - mat3_P_M2;
    mat3_P_M_Result.printmat3();
    mat4_P_M_Result = mat4_P_M - mat4_P_M2;
    mat4_P_M_Result.printmat4();

    //3. e-2)벡터간 덧셈 뺄셈
    vec3 vec3_P_M(4, 4, 4);
    vec3 vec3_P_M2(3, 3, 3);
    vec4 vec4_P_M(5, 5, 5, 5);
    vec4 vec4_P_M2(4, 4, 4, 4);
    vec3 vec3_P_M_Result = vec3_P_M + vec3_P_M2;
    vec3_P_M_Result.printvec3();
    vec4 vec4_P_M_Result = vec4_P_M + vec4_P_M2;
    vec4_P_M_Result.printvec4();
    vec3_P_M_Result = vec3_P_M - vec3_P_M2;
    vec3_P_M_Result.printvec3();
    vec4_P_M_Result = vec4_P_M - vec4_P_M2;
    vec4_P_M_Result.printvec4();
    vec1x3 vec1x3_P_M(4, 4, 4);
    vec1x3 vec1x3_P_M2(3, 3, 3);
    vec1x4 vec1x4_P_M(5, 5, 5, 5);
    vec1x4 vec1x4_P_M2(4, 4, 4, 4);
    vec1x3 vec1x3_P_M_Result = vec1x3_P_M + vec1x3_P_M2;
    vec1x3_P_M_Result.printvec1x3();
    vec1x4 vec1x4_P_M_Result = vec1x4_P_M + vec1x4_P_M2;
    vec1x4_P_M_Result.printvec1x4();
    vec1x3_P_M_Result = vec1x3_P_M - vec1x3_P_M2;
    vec1x3_P_M_Result.printvec1x3();
    vec1x4_P_M_Result = vec1x4_P_M - vec1x4_P_M2;
    vec1x4_P_M_Result.printvec1x4();

    //3. f-1) 행렬의 상수 곱셈, 나눗셈
    mat3_P_M_Result = mat3_P_M * 3;
    mat3_P_M_Result.printmat3();
    mat3_P_M_Result = 4*mat3_P_M;
    mat3_P_M_Result.printmat3();
    mat3_P_M_Result = mat3_P_M / 2;
    mat3_P_M_Result.printmat3();

    mat4_P_M_Result = mat4_P_M * 3;
    mat4_P_M_Result.printmat4();
    mat4_P_M_Result = 4 * mat4_P_M;
    mat4_P_M_Result.printmat4();
    mat4_P_M_Result = mat4_P_M / 2;
    mat4_P_M_Result.printmat4();
    
    //3. f-2) 벡터의 상수 곱셈, 나눗셈
    vec3_P_M_Result = vec3_P_M * 3;
    vec3_P_M_Result.printvec3();
    vec3_P_M_Result = 4 * vec3_P_M;
    vec3_P_M_Result.printvec3();
    vec3_P_M_Result = vec3_P_M / 2;
    vec3_P_M_Result.printvec3();

    vec1x3_P_M_Result = vec1x3_P_M * 3;
    vec1x3_P_M_Result.printvec1x3();
    vec1x3_P_M_Result = 4 * vec1x3_P_M;
    vec1x3_P_M_Result.printvec1x3();
    vec1x3_P_M_Result = vec1x3_P_M / 2;
    vec1x3_P_M_Result.printvec1x3();

    vec4_P_M_Result = vec4_P_M * 3;
    vec4_P_M_Result.printvec4();
    vec4_P_M_Result = 4 * vec4_P_M;
    vec4_P_M_Result.printvec4();
    vec4_P_M_Result = vec4_P_M / 2;
    vec4_P_M_Result.printvec4();

    vec1x4_P_M_Result = vec1x4_P_M * 3;
    vec1x4_P_M_Result.printvec1x4();
    vec1x4_P_M_Result = 4 * vec1x4_P_M;
    vec1x4_P_M_Result.printvec1x4();
    vec1x4_P_M_Result = vec1x4_P_M / 2;
    vec1x4_P_M_Result.printvec1x4();

}