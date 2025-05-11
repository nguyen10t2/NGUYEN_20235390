//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \|
//                / _||||| -:- |||||- \|
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Dao Trong Nguyen _ 20235390 _ IT2-03 _ IT3040 _ 750829_ 2024.2

#include <iostream>
#include <cstring>

using namespace std;

//# Kích thước ma trận
const int N = 128;

struct Matrix {
    unsigned int mat[N][N];

    Matrix() {
        memset(mat, 0, sizeof mat);
    }
};
//# Hàm so sánh 2 ma trận
bool operator == (const Matrix &a, const Matrix &b) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a.mat[i][j] != b.mat[i][j]) return false;
        }
    }
    return true;
}
//# Hàm nhân 2 ma trận
Matrix multiply_naive(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
        }
    }
    return c;
}
//# Hàm nhân 2 ma trận với tối ưu hóa
Matrix multiply_fast(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < N; ++i) {
        // Tối ưu hóa vòng lặp bên ngoài thay for j bằng for k
        // Ko ảnh hưởng tới logic của thuật toán
        for (int k = 0; k < N; ++k) {
            // Lưu giá trị a.mat[i][k] vào biến tạm để tránh truy cập nhiều lần
            int temp_90 = a.mat[i][k];
            for (int j = 0; j < N; ++j) {
                // Sử dụng biến tạm để tính toán
                c.mat[i][j] += temp_90 * b.mat[k][j];
            }
        }
    }
    return c;
}

Matrix gen_random_matrix() {
    Matrix a;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a.mat[i][j] = rand();
        }
    }
    return a;
}

Matrix base_90;

double benchmark(Matrix (*multiply) (const Matrix&, const Matrix&), Matrix &result) {
    const int NUM_TEST = 10;
    const int NUM_ITER = 64;

    Matrix a = base_90;
    result = a;

    double taken = 0;
    for (int t = 0; t < NUM_TEST; ++t) {
        clock_t start = clock();
        for (int i = 0; i < NUM_ITER; ++i) {
            a = multiply(a, result);
            result = multiply(result, a);
        }
        clock_t finish = clock();
        taken += (double)(finish - start);
    }
    taken /= NUM_TEST;
    printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}


int main() {
    base_90 = gen_random_matrix();

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    Matrix a_90, b_90;
    printf("Slow version\n");
    double slow_90 = benchmark(multiply_naive, a_90);
    printf("Fast version\n");
    double fast_90 = benchmark(multiply_fast, b_90);

    if (a_90 == b_90) {
        printf("Correct answer! Your code is %.2f%% faster\n", slow_90 / fast_90 * 100.0);
    } else {
        printf("Wrong answer!\n");
    }
    return 0;
}