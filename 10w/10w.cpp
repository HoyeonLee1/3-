#include <iostream>
#include "Musoenmath.h"

using namespace std;

void mat3::printmat3()
{
    // mat3 ��¿� �Լ� ����
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
    // vec3 ��¿� �Լ� ����
    cout << "----------------" << endl;

    cout << x << " " << y << " " << z << " ";

    cout << endl;
    cout << "----------------" << endl;
    cout << endl;
}

//
int main()
{
    // �ﰢ�Լ� ����
    const float PI = 3.1415926;
    float a = sin(30 * PI / 180);
    float b = cos(30 * PI / 180);

    //��ǥ �ʱⰪ (1,1,1) �ʱ�ȭ
    vec3 v = vec3(1, 1, 1);

    // (3,5) �̵���� �ʱ�ȭ
    mat3 Tr = mat3(1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        3.0, 5.0, 1.0);
    // 30�� ȸ����� �ʱ�ȭ
    mat3 Ro = mat3(b, -a, 0.0,
        a, b, 0.0,
        0.0, 0.0, 1.0);
    // 2�� Ȯ�� ������ ��� �ʱ�ȭ
    mat3 Sc = mat3(2.0, 0.0, 0.0,
        0.0, 2.0, 0.0,
        0.0, 0.0, 1.0);

    // ����� �� �ʱ�ȭ �Ǿ����� Ȯ���ϴ� ��¹�
    v.printvec3();
    Tr.printmat3();
    Ro.printmat3();
    Sc.printmat3();
    // ����� ��ǥ = �ʱⰪ * �̵���� * ȸ����� * ���������
    vec3 p = v * Tr * Ro * Sc;
    // ���� ��ǥ�� ���
    p.printvec3();
}