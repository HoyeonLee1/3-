#pragma once


struct vec3
{
	float x;
	float y;
	float z;

	vec3()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	vec3(float x_, float y_, float z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}
	void printvec3();
};

vec3 operator*(vec3 a, vec3 b)
{
	vec3 result(a.x * b.x, a.y * b.y, a.z * b.z);
	return result;
}

struct mat3
{
	float a[3][3];


	mat3()
	{
		a[0][0] = 0;
		a[0][1] = 0;
		a[0][2] = 0;
		a[1][0] = 0;
		a[1][1] = 0;
		a[1][2] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;

	}
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
	void printmat3();

};

mat3 operator*(mat3 a, mat3 b)
{
	mat3 r;

	r.a[0][0] = (a.a[0][0] * b.a[0][0]) + (a.a[0][1] * b.a[1][0]) + (a.a[0][2] * b.a[2][0]);
	r.a[0][1] = (a.a[0][0] * b.a[0][1]) + (a.a[0][1] * b.a[1][1]) + (a.a[0][2] * b.a[2][1]);
	r.a[0][2] = (a.a[0][0] * b.a[0][2]) + (a.a[0][1] * b.a[1][2]) + (a.a[0][2] * b.a[2][2]);

	r.a[1][0] = (a.a[1][0] * b.a[0][0]) + (a.a[1][1] * b.a[1][0]) + (a.a[1][2] * b.a[2][0]);
	r.a[1][1] = (a.a[1][0] * b.a[0][1]) + (a.a[1][1] * b.a[1][1]) + (a.a[1][2] * b.a[2][1]);
	r.a[1][2] = (a.a[1][0] * b.a[0][2]) + (a.a[1][1] * b.a[1][2]) + (a.a[1][2] * b.a[2][2]);

	r.a[2][0] = (a.a[2][0] * b.a[0][0]) + (a.a[2][1] * b.a[1][0]) + (a.a[2][2] * b.a[2][0]);
	r.a[2][1] = (a.a[2][0] * b.a[0][1]) + (a.a[2][1] * b.a[1][1]) + (a.a[2][2] * b.a[2][1]);
	r.a[2][2] = (a.a[2][0] * b.a[0][2]) + (a.a[2][1] * b.a[1][2]) + (a.a[2][2] * b.a[2][2]);

	return r;
}



vec3 operator*(vec3 a, mat3 b)
{
	vec3 r;
	r.x = (a.x * b.a[0][0]) + (a.y * b.a[1][0]) + (a.z * b.a[2][0]);
	r.y = (a.x * b.a[0][1]) + (a.y * b.a[1][1]) + (a.z * b.a[2][1]);
	r.z = (a.x * b.a[0][2]) + (a.y * b.a[1][2]) + (a.z * b.a[2][2]);
	return r;
}