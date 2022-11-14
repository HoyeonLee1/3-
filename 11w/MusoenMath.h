#pragma once

//vec3 구조체
struct vec3

{
	float x[3][1];
	
	//초기값
	vec3()
	{
		x[0][0] = 0;
		x[1][0] = 0;
		x[2][0] = 0;
	}

	//벡터값 직접 초기화
	vec3(float x_, float y_, float z_)
	{
		x[0][0] = x_;
		x[1][0] = y_;
		x[2][0] = z_;
	}
	//프린트 함수 선언
	void printvec3();
};

//vec1x3 구조체
struct vec1x3
{
	float x[1][3];

	//초기값
	vec1x3()
	{
		x[0][0] = 0;
		x[0][1] = 0;
		x[0][2] = 0;
	}
	//직접 초기화
	vec1x3(float x_, float y_, float z_)
	{
		x[0][0] = x_;
		x[0][1] = y_;
		x[0][2] = z_;
	}
	//프린트 함수
	void printvec1x3();
};

// 두 벡터간 뺄셈 연산자 오버로딩
vec3 operator-(vec3 a, vec3 b)
{
	vec3 result(a.x[0][0] - b.x[0][0], a.x[1][0] - b.x[1][0], a.x[2][0] - b.x[2][0]);
	return result;
}
// 두 벡터간 덧셈 연산자 오버로딩
vec3 operator+(vec3 a, vec3 b)
{
	vec3 result(a.x[0][0] + b.x[0][0], a.x[1][0] + b.x[1][0], a.x[2][0] + b.x[2][0]);
	return result;
}

// 벡터*상수 연산자 오버로딩
vec3 operator*(vec3 a, float b) {
	vec3 result(a.x[0][0] * b, a.x[1][0] * b, a.x[2][0] * b);
	return result;
}
// 상수*벡터 연산자 오버로딩
vec3 operator*(float b, vec3 a ) {
	vec3 result(a.x[0][0]*b, a.x[1][0] * b,a.x[2][0] * b);
	return result;
}

// 벡터/상수 연산자 오버로딩
vec3 operator/(vec3 a, float b) {
	vec3 result(a.x[0][0] / b, a.x[1][0] / b, a.x[2][0] / b);
	return result;
}

// 두 1x3벡터간 덧셈 연산자 오버로딩
vec1x3 operator+(vec1x3 a, vec1x3 b)
{
	vec1x3 result(a.x[0][0] + b.x[0][0], a.x[0][1] + b.x[0][1], a.x[0][2] + b.x[0][2]);
	return result;
}

// 두 1x3벡터간 뺄셈 연산자 오버로딩
vec1x3 operator-(vec1x3 a, vec1x3 b)
{
	vec1x3 result(a.x[0][0] - b.x[0][0], a.x[0][1] - b.x[0][1], a.x[0][2] - b.x[0][2]);
	return result;
}
// 상수*1x3벡터 연산자 오버로딩
vec1x3 operator*(float a, vec1x3 b) {
	vec1x3 result(b.x[0][0] * a, b.x[0][1] * a, b.x[0][2] * a);
	return result;
}
// 1x3벡터*상수 연산자 오버로딩
vec1x3 operator*(vec1x3 b,float a) {
	vec1x3 result(b.x[0][0] * a, b.x[0][1] * a, b.x[0][2] * a);
	return result;
}

// 1x3벡터/상수 연산자 오버로딩
vec1x3 operator/(vec1x3 b, float a) {
	vec1x3 result(b.x[0][0] / a, b.x[0][1] / a, b.x[0][2] / a);
	return result;
}


// vec4 구조체
struct vec4
{
	float x[4][1];
	//초기값
	vec4()
	{
		x[0][0] = 0;
		x[1][0] = 0;
		x[2][0] = 0;
		x[3][0] = 0;
	}

	//직접 초기화
	vec4(float x_, float y_, float z_, float w_)
	{
		x[0][0] = x_;
		x[1][0] = y_;
		x[2][0] = z_;
		x[3][0] = w_;
	}
	//프린트 함수
	void printvec4();
	
};

// 두 벡터간 뺄셈 연산자 오버로딩
vec4 operator-(vec4 a, vec4 b)
{
	vec4 result(a.x[0][0] - b.x[0][0], a.x[1][0] - b.x[1][0], a.x[2][0] - b.x[2][0], a.x[3][0] - b.x[3][0]);
	return result;
}
// 두 벡터간 덧셈 연산자 오버로딩
vec4 operator+(vec4 a, vec4 b)
{
	vec4 result(a.x[0][0] + b.x[0][0], a.x[1][0] + b.x[1][0], a.x[2][0] + b.x[2][0], a.x[3][0] + b.x[3][0]);
	return result;
}
// 상수*벡터 연산자 오버로딩
vec4 operator*(float b, vec4 a) {
	vec4 result(a.x[0][0] * b, a.x[1][0] * b, a.x[2][0] * b, a.x[3][0] * b);
	return result;
}
// 벡터*상수 연산자 오버로딩
vec4 operator*(vec4 a, float b) {
	vec4 result(a.x[0][0] * b, a.x[1][0] * b, a.x[2][0] * b, a.x[3][0] * b);
	return result;
}// 벡터/상수 연산자 오버로딩

vec4 operator/(vec4 a, float b) {
	vec4 result(a.x[0][0] / b, a.x[1][0] / b, a.x[2][0] / b, a.x[3][0] / b);
	return result;
}

//vec1x4 구조체
struct vec1x4
{
	float x[1][4];

	//초기값
	vec1x4()
	{
		x[0][0] = 0;
		x[0][1] = 0;
		x[0][2] = 0;
		x[0][3] = 0;
	}

	//직접 초기화
	vec1x4(float x_, float y_, float z_ , float w_)
	{
		x[0][0] = x_;
		x[0][1] = y_;
		x[0][2] = z_;
		x[0][3] = w_;
	}
	//프린트 함수
	void printvec1x4();
};

// 두 벡터간 덧셈 연산자 오버로딩
vec1x4 operator+(vec1x4 a, vec1x4 b)
{
	vec1x4 result(a.x[0][0] + b.x[0][0], a.x[0][1] + b.x[0][1], a.x[0][2] + b.x[0][2] , a.x[0][3] + b.x[0][3]);
	return result;
}

// 두 벡터간 뺄셈 연산자 오버로딩
vec1x4 operator-(vec1x4 a, vec1x4 b)
{
	vec1x4 result(a.x[0][0] - b.x[0][0], a.x[0][1] - b.x[0][1], a.x[0][2] - b.x[0][2], a.x[0][3] - b.x[0][3]);
	return result;
}

// 벡터*상수 연산자 오버로딩
vec1x4 operator*(vec1x4 b, float a) {
	vec1x4 result(b.x[0][0] * a, b.x[0][1] * a, b.x[0][2] * a, b.x[0][3] * a);
	return result;
}

// 상수*벡터 연산자 오버로딩
vec1x4 operator*(float a, vec1x4 b) {
	vec1x4 result(b.x[0][0] * a, b.x[0][1] * a, b.x[0][2] * a , b.x[0][3] * a);
	return result;
}

// 벡터/상수 연산자 오버로딩
vec1x4 operator/(vec1x4 b, float a) {
	vec1x4 result(b.x[0][0] / a, b.x[0][1] / a, b.x[0][2] / a , b.x[0][3]/a);
	return result;
}

//mat3 구조체
struct mat3
{
	float a[3][3];

	
	//초기값
	mat3()
	{
		//1행
		a[0][0] = 0;
		a[0][1] = 0;
		a[0][2] = 0;
		//2행
		a[1][0] = 0;
		a[1][1] = 0;
		a[1][2] = 0;
		//3행
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;
	}
	//초기화
	mat3(float a_, float b_, float c_, float d_, float e_, float f_, float g_, float h_, float i_)
	{
		a[0][0] = a_;
		a[0][1] = b_;
		a[0][2] = c_;

		a[1][0] = d_;
		a[1][1] = e_;
		a[1][2] = f_;

		a[2][0] = g_;
		a[2][1] = h_;
		a[2][2] = i_;
	}
	//대입 연산자 오버로딩
	void operator=(const mat3& a);

	//프린트 함수
	void printmat3();

	//단위행렬 초기화 함수 선언
	void Mat3identity();

	//전치함수 선언
	void Mat3Transpose();

	// 전치 후 곱셈 함수 선언
	void multiplytransposematrix(mat3 x , mat3 y);
};
//3x3 행렬을 다른 행렬에 대입할 때 쓰는 연산자 오버로딩
void mat3::operator=(const mat3& x)

{

	for (int i = 0; i < 3; i++)

		for (int j = 0; j < 3; j++)

			a[i][j] = x.a[i][j];

}

//행렬간 곱셈 연산 연산자 오버로딩
mat3 operator*(mat3 a, mat3 b)
{
	mat3 r;
	//1행
	r.a[0][0] = (a.a[0][0] * b.a[0][0]) + (a.a[0][1] * b.a[1][0]) + (a.a[0][2] * b.a[2][0]);
	r.a[0][1] = (a.a[0][0] * b.a[0][1]) + (a.a[0][1] * b.a[1][1]) + (a.a[0][2] * b.a[2][1]);
	r.a[0][2] = (a.a[0][0] * b.a[0][2]) + (a.a[0][1] * b.a[1][2]) + (a.a[0][2] * b.a[2][2]);
	//2행
	r.a[1][0] = (a.a[1][0] * b.a[0][0]) + (a.a[1][1] * b.a[1][0]) + (a.a[1][2] * b.a[2][0]);
	r.a[1][1] = (a.a[1][0] * b.a[0][1]) + (a.a[1][1] * b.a[1][1]) + (a.a[1][2] * b.a[2][1]);
	r.a[1][2] = (a.a[1][0] * b.a[0][2]) + (a.a[1][1] * b.a[1][2]) + (a.a[1][2] * b.a[2][2]);
	//3행
	r.a[2][0] = (a.a[2][0] * b.a[0][0]) + (a.a[2][1] * b.a[1][0]) + (a.a[2][2] * b.a[2][0]);
	r.a[2][1] = (a.a[2][0] * b.a[0][1]) + (a.a[2][1] * b.a[1][1]) + (a.a[2][2] * b.a[2][1]);
	r.a[2][2] = (a.a[2][0] * b.a[0][2]) + (a.a[2][1] * b.a[1][2]) + (a.a[2][2] * b.a[2][2]);
	return r;
}

// 상수와 3x3행렬 곱셈 연산자 오버로딩
mat3 operator*(float a, mat3 b) {
	
	mat3 r;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			r.a[i][j] =a* b.a[i][j];
	return r;
}

// 행렬과 상수 곱셈 연산자 오버로딩
mat3 operator*( mat3 b, float a) {

	mat3 r;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			r.a[i][j] = b.a[i][j] * a;
	return r;
}

// 행렬 / 상수 연산자 오버로딩
mat3 operator/(mat3 b,float a) {
	
	mat3 r;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			r.a[i][j] = b.a[i][j]/a;
	return r;
}

// 두 행렬간 덧셈 연산자 오버로딩
mat3 operator+(mat3 a, mat3 b) {
	mat3 r;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			r.a[i][j] = a.a[i][j] + b.a[i][j];

	return r;
}

// 두 행렬간 뺄셈 연산자 오버로딩
mat3 operator-(mat3 a, mat3 b) {
	mat3 r;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			r.a[i][j] = a.a[i][j] - b.a[i][j];
	return r;
}

//행렬과 3x1벡터의 곱셈 연산자 오버로딩
vec3 operator*(mat3 b, vec3 a)
{
	//결과값
	vec3 r;

	//1행
	r.x[0][0] = (a.x[0][0] * b.a[0][0]) + (a.x[1][0] * b.a[0][1]) + (a.x[2][0] * b.a[0][2]);
	//2행
	r.x[1][0] = (a.x[0][0] * b.a[1][0]) + (a.x[1][0] * b.a[1][1]) + (a.x[2][0] * b.a[1][2]);
	//3행
	r.x[2][0] = (a.x[0][0] * b.a[2][0]) + (a.x[1][0] * b.a[2][1]) + (a.x[2][0] * b.a[2][2]);
	return r;
}

// 행렬과 3x1벡터의 곱셈 순서가 바뀌었을 때 vec3x1과 행렬을 각각 전치하여 계산하는 연산자 오버로딩
vec3 operator*(vec3 a, mat3 b)
{
	//행렬 전치
	b.Mat3Transpose();

	//결과값
	vec3 r;

	//전치 대상
	vec1x3 a1;
	
	//벡터 전치 진행
	for (int i = 0; i < 3; i++)
			a1.x[0][i] = a.x[i][0];

	//1행
	r.x[0][0] = (a1.x[0][0] * b.a[0][0]) + (a1.x[0][1] * b.a[1][0]) + (a1.x[0][2] * b.a[2][0]);
	//2행
	r.x[0][1] = (a1.x[0][0] * b.a[0][1]) + (a1.x[0][1] * b.a[1][1]) + (a1.x[0][2] * b.a[2][1]);
	//3행
	r.x[0][2] = (a1.x[0][0] * b.a[0][2]) + (a1.x[0][1] * b.a[1][2]) + (a1.x[0][2] * b.a[2][2]);
	return r;
}

//1x3벡터와 행렬간 곱셈 연산자 오버로딩. 연산이 전치 후 진행된다.
vec1x3 operator*(vec1x3 b, mat3 a)
{
	//행렬 전치
	a.Mat3Transpose();

	//결과값
	vec1x3 r;

	//1열
	r.x[0][0] = (b.x[0][0] * a.a[0][0]) + (b.x[0][1] * a.a[1][0]) + (b.x[0][2] * a.a[2][0]);
	//2열
	r.x[0][1] = (b.x[0][0] * a.a[0][1]) + (b.x[0][1] * a.a[1][1]) + (b.x[0][2] * a.a[2][1]);
	//3열
	r.x[0][2] = (b.x[0][0] * a.a[0][2]) + (b.x[0][1] * a.a[1][2]) + (b.x[0][2] * a.a[2][2]);
	return r;
}
// 행렬과 1x3벡터의 곱셈 순서가 바뀌었을 때 vec1x3을 vec3로 전치 후 연산을 진행하는 연산자 오버로딩

vec1x3 operator*(mat3 b,vec1x3 a)
{
	//결과값
	vec1x3 r;

	//전치 대상
	vec3 a1;

	//벡터 전치 진행
	for (int i = 0; i < 3; i++)
		a1.x[i][0] = a.x[0][i];

	//1열
	r.x[0][0] = (a1.x[0][0] * b.a[0][0]) + (a1.x[1][0] * b.a[0][1]) + (a1.x[2][0] * b.a[0][2]);
	//2열
	r.x[0][1] = (a1.x[0][0] * b.a[1][0]) + (a1.x[1][0] * b.a[1][1]) + (a1.x[2][0] * b.a[1][2]);
	//3열
	r.x[0][2] = (a1.x[0][0] * b.a[2][0]) + (a1.x[1][0] * b.a[2][1]) + (a1.x[2][0] * b.a[2][2]);
	return r;
}

//mat4 구조체
struct mat4
{
	float b[4][4];

	//초기값 0
	mat4() {
		//1행
		b[0][0] = 0;
		b[0][1] = 0;
		b[0][2] = 0;
		b[0][3] = 0;

		//2행
		b[1][0] = 0;
		b[1][1] = 0;
		b[1][2] = 0;
		b[1][3] = 0;

		//3행
		b[2][0] = 0;
		b[2][1] = 0;
		b[2][2] = 0;
		b[2][3] = 0;

		//4헹
		b[3][0] = 0;
		b[3][1] = 0;
		b[3][2] = 0;
		b[3][3] = 0;
	}

	//값 초기화
	mat4(float m4_1, float m4_2, float m4_3, float m4_4, float m4_5, float m4_6, float m4_7, float m4_8, float m4_9, float m4_10, float m4_11, float m4_12, float m4_13, float m4_14, float m4_15, float m4_16) {
		b[0][0] = m4_1;
		b[0][1] = m4_2;
		b[0][2] = m4_3;
		b[0][3] = m4_4;

		b[1][0] = m4_5;
		b[1][1] = m4_6;
		b[1][2] = m4_7;
		b[1][3] = m4_8;

		b[2][0] = m4_9;
		b[2][1] = m4_10;
		b[2][2] = m4_11;
		b[2][3] = m4_12;

		b[3][0] = m4_13;
		b[3][1] = m4_14;
		b[3][2] = m4_15;
		b[3][3] = m4_16;
	}
	
	//전치 함수
	void Mat4Transpose();

	// 프린트 함수
	void printmat4();

	// 단위행렬 초기화 함수
	void Mat4Identity();

	//대입 연산자 오버로딩
	void operator=(const mat4& a);

	//전치 후 곱셈을 진행하는 함수 선언
	void multiplytransposematrix(mat4 a, mat4 b);
};

//4x4 행렬을 다른 행렬에 대입할 때 쓰는 연산자 오버로딩
void mat4::operator=(const mat4& x)

{
	for (int i = 0; i < 4; i++)

		for (int j = 0; j < 4; j++)

			b[i][j] = x.b[i][j];
}
//두 행렬간 곱셈 연산자 오버로딩
mat4 operator*(mat4 a, mat4 b)
{
	mat4 r;
	//1행
	r.b[0][0] = (a.b[0][0] * b.b[0][0]) + (a.b[0][1] * b.b[1][0]) + (a.b[0][2] * b.b[2][0]) + (a.b[0][3] * b.b[3][0]);
	r.b[0][1] = (a.b[0][0] * b.b[0][1]) + (a.b[0][1] * b.b[1][1]) + (a.b[0][2] * b.b[2][1]) + (a.b[0][3] * b.b[3][1]);
	r.b[0][2] = (a.b[0][0] * b.b[0][2]) + (a.b[0][1] * b.b[1][2]) + (a.b[0][2] * b.b[2][2]) + (a.b[0][3] * b.b[3][2]);
	r.b[0][3] = (a.b[0][0] * b.b[0][3]) + (a.b[0][1] * b.b[1][3]) + (a.b[0][2] * b.b[2][3]) + (a.b[0][3] * b.b[3][3]);
	//2행
	r.b[1][0] = (a.b[1][0] * b.b[0][0]) + (a.b[1][1] * b.b[1][0]) + (a.b[1][2] * b.b[2][0]) + (a.b[1][3] * b.b[3][0]);
	r.b[1][1] = (a.b[1][0] * b.b[0][1]) + (a.b[1][1] * b.b[1][1]) + (a.b[1][2] * b.b[2][1]) + (a.b[1][3] * b.b[3][1]);
	r.b[1][2] = (a.b[1][0] * b.b[0][2]) + (a.b[1][1] * b.b[1][2]) + (a.b[1][2] * b.b[2][2]) + (a.b[1][3] * b.b[3][2]);
	r.b[1][3] = (a.b[1][0] * b.b[0][3]) + (a.b[1][1] * b.b[1][3]) + (a.b[1][2] * b.b[2][3]) + (a.b[1][3] * b.b[3][3]);
	//3행
	r.b[2][0] = (a.b[2][0] * b.b[0][0]) + (a.b[2][1] * b.b[1][0]) + (a.b[2][2] * b.b[2][0]) + (a.b[2][3] * b.b[3][0]);
	r.b[2][1] = (a.b[2][0] * b.b[0][1]) + (a.b[2][1] * b.b[1][1]) + (a.b[2][2] * b.b[2][1]) + (a.b[2][3] * b.b[3][1]);
	r.b[2][2] = (a.b[2][0] * b.b[0][2]) + (a.b[2][1] * b.b[1][2]) + (a.b[2][2] * b.b[2][2]) + (a.b[2][3] * b.b[3][2]);
	r.b[2][3] = (a.b[2][0] * b.b[0][3]) + (a.b[2][1] * b.b[1][3]) + (a.b[2][2] * b.b[2][3]) + (a.b[2][3] * b.b[3][3]);
	//4행
	r.b[3][0] = (a.b[3][0] * b.b[0][0]) + (a.b[3][1] * b.b[1][0]) + (a.b[3][2] * b.b[2][0]) + (a.b[3][3] * b.b[3][0]);
	r.b[3][1] = (a.b[3][0] * b.b[0][1]) + (a.b[3][1] * b.b[1][1]) + (a.b[3][2] * b.b[2][1]) + (a.b[3][3] * b.b[3][1]);
	r.b[3][2] = (a.b[3][0] * b.b[0][2]) + (a.b[3][1] * b.b[1][2]) + (a.b[3][2] * b.b[2][2]) + (a.b[3][3] * b.b[3][2]);
	r.b[3][3] = (a.b[3][0] * b.b[0][3]) + (a.b[3][1] * b.b[1][3]) + (a.b[3][2] * b.b[2][3]) + (a.b[3][3] * b.b[3][3]);

	return r;
}

// 행렬과 벡터간 곱셈 연산자 오버로딩
vec4 operator*(mat4 b, vec4 a)
{
	
	vec4 r;
	//1행
	r.x[0][0] = (a.x[0][0] * b.b[0][0]) + (a.x[1][0] * b.b[0][1]) + (a.x[2][0] * b.b[0][2]) + (a.x[3][0] * b.b[0][3]);
	//2행
	r.x[1][0] = (a.x[0][0] * b.b[1][0]) + (a.x[1][0] * b.b[1][1]) + (a.x[2][0] * b.b[1][2]) + (a.x[3][0] * b.b[1][3]);
	//3행
	r.x[2][0] = (a.x[0][0] * b.b[2][0]) + (a.x[1][0] * b.b[2][1]) + (a.x[2][0] * b.b[2][2]) + (a.x[3][0] * b.b[2][3]);
	//4행
	r.x[3][0] = (a.x[0][0] * b.b[3][0]) + (a.x[1][0] * b.b[3][1]) + (a.x[2][0] * b.b[3][2]) + (a.x[3][0] * b.b[3][3]);
	return r;
}

//  행렬과 벡터의 곱셈의 순서가 바뀌었을 때 연산자 오버로딩 각각 행렬과 벡터를 전치 후 연산을 진행하는 연산자 오버로딩
vec4 operator*(vec4 b, mat4 a)
{
	//행렬 전치
	a.Mat4Transpose();

	//전치 대상
	vec1x4 b1;

	//연산 결과 값 
	vec4 r;

	//벡터 전치 진행
	for (int i = 0; i < 4; i++)
		b1.x[0][i] = b.x[i][0];

	//1행
	r.x[0][0] = (b1.x[0][0] * a.b[0][0]) + (b1.x[0][1] * a.b[1][0]) + (b1.x[0][2] * a.b[2][0]) + (b1.x[0][3] * a.b[3][0]);
	//2행
	r.x[1][0] = (b1.x[0][0] * a.b[0][1]) + (b1.x[0][1] * a.b[1][1]) + (b1.x[0][2] * a.b[2][1]) + (b1.x[0][3] * a.b[3][1]);
	//3행
	r.x[2][0] = (b1.x[0][0] * a.b[0][2]) + (b1.x[0][1] * a.b[1][2]) + (b1.x[0][2] * a.b[2][2]) + (b1.x[0][3] * a.b[3][2]);
	//4행
	r.x[3][0] = (b1.x[0][0] * a.b[0][3]) + (b1.x[0][1] * a.b[1][3]) + (b1.x[0][2] * a.b[2][3]) + (b1.x[0][3] * a.b[3][3]);
	return r;
}

// 1x4벡터와 행렬간 곱셈 연산자 오버로딩. 행렬을 전치 후 연산을 진행한다.
vec1x4 operator*(vec1x4 b, mat4 a)
{
	//행렬 전치
	a.Mat4Transpose();

	//결과 값
	vec1x4 r;

	//1열
	r.x[0][0] = (b.x[0][0] * a.b[0][0]) + (b.x[0][1] * a.b[1][0]) + (b.x[0][2] * a.b[2][0]) + (b.x[0][3] * a.b[3][0]);
	//2열
	r.x[0][1] = (b.x[0][0] * a.b[0][1]) + (b.x[0][1] * a.b[1][1]) + (b.x[0][2] * a.b[2][1]) + (b.x[0][3] * a.b[3][1]);
	//열
	r.x[0][2] = (b.x[0][0] * a.b[0][2]) + (b.x[0][1] * a.b[1][2]) + (b.x[0][2] * a.b[2][2]) + (b.x[0][3] * a.b[3][2]);
	//4열
	r.x[0][3] = (b.x[0][0] * a.b[0][3]) + (b.x[0][1] * a.b[1][3]) + (b.x[0][2] * a.b[2][3]) + (b.x[0][3] * a.b[3][3]);
	return r;
}

// 행렬과 1x4벡터간 곰셈이 순서가 바뀌었을 경우 연산자 오버로딩. 벡터1x4을 vec4로 전치 후 연산을 진행한다.
vec1x4 operator*(mat4 b, vec1x4 a)
{
	//전치 대상
	vec4 a1;

	//결과값
	vec1x4 r;

	//벡터 전치 진행
	for (int i = 0; i < 4; i++)
		a1.x[i][0] = a.x[0][i];

	//1열
	r.x[0][0] = (a1.x[0][0] * b.b[0][0]) + (a1.x[1][0] * b.b[0][1]) + (a1.x[2][0] * b.b[0][2]) + (a1.x[3][0] * b.b[0][3]);
	//2열
	r.x[0][1] = (a1.x[0][0] * b.b[1][0]) + (a1.x[1][0] * b.b[1][1]) + (a1.x[2][0] * b.b[1][2]) + (a1.x[3][0] * b.b[1][3]);
	//3열
	r.x[0][2] = (a1.x[0][0] * b.b[2][0]) + (a1.x[1][0] * b.b[2][1]) + (a1.x[2][0] * b.b[2][2]) + (a1.x[3][0] * b.b[2][3]);
	//4열
	r.x[0][3] = (a1.x[0][0] * b.b[3][0]) + (a1.x[1][0] * b.b[3][1]) + (a1.x[2][0] * b.b[3][2]) + (a1.x[3][0] * b.b[3][3]);
	return r;
}

//상수와 행렬 곱셈 연산자 오버로딩
mat4 operator*(float a, mat4 b) {
	
	mat4 r;
	
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			r.b[i][j] =a*b.b[i][j];

	return r;
}
// 행렬과 상수 곱셈 연산자 오버로딩
mat4 operator*(mat4 b, float a) {

	mat4 r;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			r.b[i][j] = b.b[i][j] * a;

	return r;
}
// 행렬과 상수 나눗셈 연산자 오버로딩
mat4 operator/(mat4 b ,float a ) {
	
	mat4 r;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			r.b[i][j] = b.b[i][j]/a;

	return r;
}
// 두 행렬간 덧셈 연산자 오버로딩
mat4 operator+(mat4 a, mat4 b) {
	mat4 r;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			r.b[i][j] = a.b[i][j] + b.b[i][j];
	return r;
}

// 두 행렬간 뺄셈 연산자 오버로딩
mat4 operator-(mat4 a, mat4 b) {
	mat4 r;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			r.b[i][j] = a.b[i][j] - b.b[i][j];
	return r;
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