#pragma once

class vec3;
class mat3;

class vec3 {
private:
    double vec[3];

public:
    vec3() {}

    vec3(double x, double y, double z) {
        vec[0] = x;
        vec[1] = y;
        vec[2] = z;
    }

    double at(int i) {
        return vec[i];
    }

    vec3 operator=(vec3 vec) {
        this->vec[0] = vec.vec[0];
        this->vec[1] = vec.vec[1];
        this->vec[2] = vec.vec[2];
    }

    double operator*(vec3 vec);
    vec3 operator*(mat3& mat);
};

class mat3 {
private:
    double mat[3][3];

public:
    mat3() {}
    mat3(vec3 r1, vec3 r2, vec3 r3) {
        mat[0][0] = r1.at(0);
        mat[0][1] = r1.at(1);
        mat[0][2] = r1.at(2);

        mat[1][0] = r2.at(0);
        mat[1][1] = r2.at(1);
        mat[1][2] = r2.at(2);

        mat[2][0] = r3.at(0);
        mat[2][1] = r3.at(1);
        mat[2][2] = r3.at(2);
    }

    double at(int r, int c) {
        return mat[r][c];
    }

    vec3 get_column_vec(int c) {
        return vec3(mat[0][c], mat[1][c], mat[2][c]);
    }

    vec3 get_row_vec(int r) {
        return vec3(mat[r][0], mat[r][1], mat[r][2]);
    }
};

double vec3::operator*(vec3 vec) {
    return this->vec[0] * vec.vec[0] +
        this->vec[1] * vec.vec[1] +
        this->vec[2] * vec.vec[2];
}

vec3 vec3::operator*(mat3& mat) {
    return vec3(
        *this * mat.get_column_vec(0),
        *this * mat.get_column_vec(1),
        *this * mat.get_column_vec(2)
    );
}