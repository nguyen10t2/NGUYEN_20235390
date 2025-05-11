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

void print(int n_90) {
    std::cout << n_90 << std::endl;
}
//# Hàm con trỏ hàm odd
int mul_3_plus_1(int n_90) {
    return 3 * n_90 + 1;
}
//# Hàm con trỏ hàm even
int div_2(int n_90) {
    return n_90 / 2;
}
//# Hàm simulate
void simulate(int n_90, int (*odd_90)(int), int (*even_90)(int), void (*output_90)(int)) {
    (*output_90)(n_90);
    if(n_90 == 1) return;
    if(n_90 % 2 == 0) {
        n_90 = (*even_90)(n_90);
    }
    else {
        n_90 = (*odd_90)(n_90);
    }
    simulate(n_90, odd_90, even_90, output_90);
}

int main() {
    // Khai báo các hàm con trỏ hàm odd_dtn_90, even_dtn_90 và output_dtn_90
    int (*odd_dtn_90)(int) = &mul_3_plus_1;
    int (*even_dtn_90)(int) = &div_2;
    void (*output_dtn_90)(int) = &print;

    int n_dtn_90;
    std::cin >> n_dtn_90;
    // Gọi hàm simulate với tham số là n_dtn_90, odd_dtn_90, even_dtn_90 và output_dtn_90
    simulate(n_dtn_90, odd_dtn_90, even_dtn_90, output_dtn_90);
    // -- Dao Trong Nguyen _ 20235390 _ IT2-03 _ IT3040 _ 750829_ 2024.2 --
    return 0;
}