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
#include <iomanip>
#include <cmath>

struct Complex {
    double real_90;
    double imag_90;
};
//# Hàm cộng 2 số phức
Complex operator +(Complex a_90, Complex b_90) {
    Complex result_90;
    result_90.real_90 = a_90.real_90 + b_90.real_90;
    result_90.imag_90 = a_90.imag_90 + b_90.imag_90;
    return result_90;
}
//# Hàm trừ 2 số phức
Complex operator -(Complex a_90, Complex b_90) {
    Complex result_90;
    result_90.real_90 = a_90.real_90 - b_90.real_90;
    result_90.imag_90 = a_90.imag_90 - b_90.imag_90;
    return result_90;
}
//# Hàm nhân 2 số phức
Complex operator *(Complex a_90, Complex b_90) {
    Complex result_90;
    result_90.real_90 = a_90.real_90 * b_90.real_90 - a_90.imag_90 * b_90.imag_90;
    result_90.imag_90 = a_90.real_90 * b_90.imag_90 + a_90.imag_90 * b_90.real_90;
    return result_90;
}
//# Hàm chia 2 số phức
Complex operator /(Complex a_90, Complex b_90) {
    Complex result_90;
    double denominator_90 = b_90.real_90 * b_90.real_90 + b_90.imag_90 * b_90.imag_90;
    result_90.real_90 = (a_90.real_90 * b_90.real_90 + a_90.imag_90 * b_90.imag_90) / denominator_90;
    result_90.imag_90 = (a_90.imag_90 * b_90.real_90 - a_90.real_90 * b_90.imag_90) / denominator_90;
    return result_90;
}
//# Hàm in số phức
std::ostream& operator<<(std::ostream& os_90, const Complex& c_90) {
    os_90 << '(' << std::setprecision(2) << c_90.real_90 << (c_90.imag_90 >= 0 ? '+' : '-') << fabs(c_90.imag_90) << 'i' << ')';
    return os_90;
}

int main() {
    double real_a_dtn_90, real_b_dtn_90, img_a_dtn_90, img_b_dtn_90;
    std::cin >> real_a_dtn_90 >> img_a_dtn_90;
    std::cin >> real_b_dtn_90 >> img_b_dtn_90;
    //# Khai báo 2 số phức a_dtn_90 và b_dtn_90
    Complex a_dtn_90{real_a_dtn_90, img_a_dtn_90};
    Complex b_dtn_90{real_b_dtn_90, img_b_dtn_90};
    //# In ra cộng, trừ, nhân, chia 2 số phức a_dtn_90 và b_dtn_90
    std::cout << a_dtn_90 << " + " << b_dtn_90 << " = " << a_dtn_90 + b_dtn_90 << std::endl;
    std::cout << a_dtn_90 << " - " << b_dtn_90 << " = " << a_dtn_90 - b_dtn_90 << std::endl;
    std::cout << a_dtn_90 << " * " << b_dtn_90 << " = " << a_dtn_90 * b_dtn_90 << std::endl;
    std::cout << a_dtn_90 << " / " << b_dtn_90 << " = " << a_dtn_90 / b_dtn_90 << std::endl;
    //# -- Dao Trong Nguyen _ 20235390 _ IT2-03 _ IT3040 _ 750829_ 2024.2 --
    return 0;
}