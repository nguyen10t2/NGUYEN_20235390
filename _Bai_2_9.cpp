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

#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>

using namespace std;

const int LIMIT_90 = 100;
const int NUM_ITER_90 = 100000;
const int NUM_INPUTS_90 = NUM_ITER_90 * 100;

double sigmoid_slow(double x_90) {
    return 1.0 / (1.0 + exp(-x_90));
}

double x_90[NUM_INPUTS_90];

void prepare_input() {
    const int PRECISION_90 = 1000000;
    const double RANGE_90 = LIMIT_90 / 20.0;
    for (int i_90 = 0; i_90 < NUM_INPUTS_90; ++i_90) {
        x_90[i_90] = RANGE_90 * (rand() % PRECISION_90 - rand() % PRECISION_90) / PRECISION_90;
    }
}
//# Kích thước bảng tra cứu
const int TABLE_SIZE_90 = 1 << 15;
//# Giới hạn giá trị đầu vào
const double MIN_X_90 = -8.0, MAX_X_90 = 8.0;
//# Bảng tra cứu cho hàm sigmoid
double sigmoid_lookup_90[TABLE_SIZE_90];
//# Tỉ lệ để chuyển đổi giá trị đầu vào thành chỉ số bảng tra cứu
const double SCALE_90 = (TABLE_SIZE_90 - 1) / (MAX_X_90 - MIN_X_90);

//# hàm chuẩn bị dữ liệu
void precalc() {
    for (int i_90 = 0; i_90 < TABLE_SIZE_90; ++i_90) {
        //# Chuyển đổi chỉ số bảng tra cứu thành giá trị đầu vào
        double x_90 = MIN_X_90 + i_90 / SCALE_90;
        sigmoid_lookup_90[i_90] = 1.0 / (1.0 + exp(-x_90));
    }
}

//# hàm tính sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x_90) {
    // Nếu x nằm ngoài khoảng [MIN_X_90, MAX_X_90], trả về 0 hoặc 1
    if (x_90 <= MIN_X_90) return 0.0;
    if (x_90 >= MAX_X_90) return 1.0;
    // Tính chỉ số bảng tra cứu và phần dư
    double pos_90 = (x_90 - MIN_X_90) * SCALE_90;
    // Lấy chỉ số nguyên và phần dư
    int index_90 = (int)pos_90;
    // frac là phần dư
    double frac_90 = pos_90 - index_90;
    // Trả về giá trị sigmoid(x) bằng cách nội suy giữa hai giá trị trong bảng tra cứu
    return sigmoid_lookup_90[index_90] * (1.0 - frac_90) + sigmoid_lookup_90[index_90 + 1] * frac_90;
}

//# END fast code

double benchmark(double (*calc_90)(double), vector<double> &result_90) {
    const int NUM_TEST_90 = 20;

    double taken_90 = 0;
    result_90 = vector<double>();
    result_90.reserve(NUM_ITER_90);

    int input_id_90 = 0;
    clock_t start_90 = clock();
    for (int t_90 = 0; t_90 < NUM_TEST_90; ++t_90) {
        double sum_90 = 0;
        for (int i_90 = 0; i_90 < NUM_ITER_90; ++i_90) {
            double v_90 = fabs(calc_90(x_90[input_id_90]));
            sum_90 += v_90;
            if (t_90 == 0) result_90.push_back(v_90);
            if ((++input_id_90) == NUM_INPUTS_90) input_id_90 = 0;
        }
    }
    clock_t finish_90 = clock();
    taken_90 = (double)(finish_90 - start_90);
//#  printf("Time: %.9f\n", taken_90 / CLOCKS_PER_SEC);
    return taken_90;
}

bool is_correct(const vector<double> &a_90, const vector<double> &b_90) {
    const double EPS_90 = 1e-6;

    if (a_90.size() != b_90.size()) return false;
    for (int i_90 = 0; i_90 < a_90.size(); ++i_90) {
        if (fabs(a_90[i_90] - b_90[i_90]) > EPS_90) {
            return false;
        }
    }
    return true;
}

int main() {
    prepare_input();
    precalc();

    vector<double> a_90, b_90;
    double slow_90 = benchmark(sigmoid_slow, a_90);
    double fast_90 = benchmark(sigmoid_fast, b_90);

    double xval_90;
    scanf("%lf", &xval_90);
    printf("%.2f \n", sigmoid_fast(xval_90));
    printf("%.2f \n", slow_90 / fast_90);
    
    if (is_correct(a_90, b_90) && (slow_90 / fast_90 > 1.3)) {
        printf("Correct answer! Your code is faster\n");
    } else {
        printf("Wrong answer or your code is not fast enough!\n");
    }
    
    return 0;
}