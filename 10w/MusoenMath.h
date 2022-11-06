#pragma once



	class vec3

	{

	private:



	public:
		float v[3];
		vec3(float a = 0.0, float b = 0.0, float c = 0.0);

		~vec3()

		{

		}

		void printvec3();

	};

	vec3::vec3(float a, float b, float c)

	{
		v[0] = a;
		v[1] = b;
		v[2] = c;
	}

	class mat3

	{

	private:



	public:
		float m[3][3];
		mat3(float a = 0.0, float b = 0.0, float c = 0.0, float d = 0.0, float e = 0.0, float f = 0.0, float g = 0.0, float h = 0.0, float i = 0.0);
		~mat3()

		{

		}

		void printmat3();

		mat3 operator*(const mat3& a);

		void operator=(const mat3& a);

	};

	mat3::mat3(float a, float b, float c, float d, float e, float f, float g, float h, float i)

	{
		m[0][0] = a;
		m[0][1] = b;
		m[0][2] = c;
		m[1][0] = d;
		m[1][1] = e;
		m[1][2] = f;
		m[2][0] = g;
		m[2][1] = h;
		m[2][2] = i;
	}

	mat3 mat3::operator*(const mat3& a)

	{

		mat3 b;

		b.m[0][0] = (m[0][0] * a.m[0][0]) + (m[0][1] * a.m[1][0]) + (m[0][2] * a.m[2][0]);
		b.m[0][1] = (m[0][0] * a.m[0][1]) + (m[0][1] * a.m[1][1]) + (m[0][2] * a.m[2][1]);
		b.m[0][2] = (m[0][0] * a.m[0][2]) + (m[0][1] * a.m[1][2]) + (m[0][2] * a.m[2][2]);

		b.m[1][0] = (m[1][0] * a.m[0][0]) + (m[1][1] * a.m[1][0]) + (m[1][2] * a.m[2][0]);
		b.m[1][1] = (m[1][0] * a.m[0][1]) + (m[1][1] * a.m[1][1]) + (m[1][2] * a.m[2][1]);
		b.m[1][2] = (m[1][0] * a.m[0][2]) + (m[1][1] * a.m[1][2]) + (m[1][2] * a.m[2][2]);

		b.m[2][0] = (m[2][0] * a.m[0][0]) + (m[2][1] * a.m[1][0]) + (m[2][2] * a.m[2][0]);
		b.m[2][1] = (m[2][0] * a.m[0][1]) + (m[2][1] * a.m[1][1]) + (m[2][2] * a.m[2][1]);
		b.m[2][2] = (m[2][0] * a.m[0][2]) + (m[2][1] * a.m[1][2]) + (m[2][2] * a.m[2][2]);

		return b;

	}

	void mat3::operator=(const mat3& a)

	{
		for (int i = 0; i < 3; i++)

			for (int j = 0; j < 3; j++)

				m[i][j] = a.m[i][j];
	}


	class posMath
	{
	private:

	public:
		float pm[3][3];
		float pv[3];


		posMath()
		{
			
			
		}
		~posMath()
		{

		}
		void mat3Set(float a , float b, float c , float d , float e , float f , float g , float h , float i);
		void vec3Set(float a, float b, float c);
		void printPmat3();
		void printPvec3();
		posMath operator*(const posMath& a);

		void operator=(const posMath& a);

	};


	void posMath::operator=(const posMath& a)

	{
		for (int i = 0; i < 3; i++)

			for (int j = 0; j < 3; j++)

				pm[i][j] = a.pm[i][j];

		for (int i = 0; i < 3; i++)
				pv[i] = a.pv[i];

	}





	posMath posMath::operator*(const posMath& a)

	{

		posMath b;
		b.pv[0] = (pv[0] * a.pm[0][0]) + (pv[1] * a.pm[1][0]) + (pv[2] * a.pm[2][0]);
		b.pv[1] = (pv[0] * a.pm[0][1]) + (pv[1] * a.pm[1][1]) + (pv[2] * a.pm[2][1]);
		b.pv[2] = (pv[0] * a.pm[0][2]) + (pv[1] * a.pm[1][2]) + (pv[2] * a.pm[2][2]);

		/*b.pm[0][0] = (pm[0][0] * a.pm[0][0]) + (pm[0][1] * a.pm[1][0]) + (pm[0][2] * a.pm[2][0]);
		b.pm[0][1] = (pm[0][0] * a.pm[0][1]) + (pm[0][1] * a.pm[1][1]) + (pm[0][2] * a.pm[2][1]);
		b.pm[0][2] = (pm[0][0] * a.pm[0][2]) + (pm[0][1] * a.pm[1][2]) + (pm[0][2] * a.pm[2][2]);

		b.pm[1][0] = (pm[1][0] * a.pm[0][0]) + (pm[1][1] * a.pm[1][0]) + (pm[1][2] * a.pm[2][0]);
		b.pm[1][1] = (pm[1][0] * a.pm[0][1]) + (pm[1][1] * a.pm[1][1]) + (pm[1][2] * a.pm[2][1]);
		b.pm[1][2] = (pm[1][0] * a.pm[0][2]) + (pm[1][1] * a.pm[1][2]) + (pm[1][2] * a.pm[2][2]);

		b.pm[2][0] = (pm[2][0] * a.pm[0][0]) + (pm[2][1] * a.pm[1][0]) + (pm[2][2] * a.pm[2][0]);
		b.pm[2][1] = (pm[2][0] * a.pm[0][1]) + (pm[2][1] * a.pm[1][1]) + (pm[2][2] * a.pm[2][1]);
		b.pm[2][2] = (pm[2][0] * a.pm[0][2]) + (pm[2][1] * a.pm[1][2]) + (pm[2][2] * a.pm[2][2]);*/
		return b;

	}

