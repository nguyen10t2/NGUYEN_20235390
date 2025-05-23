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
#include <cmath>
#include <iomanip>

using Vector = std::tuple<double, double, double>;

Vector cross_product(Vector a_90, Vector b_90) {
    Vector res_90 = {0, 0, 0};
    std::get<0>(res_90) = std::get<1>(a_90) * std::get<2>(b_90) - std::get<1>(b_90) * std::get<2>(a_90);
    std::get<1>(res_90) = std::get<2>(a_90) * std::get<0>(b_90) - std::get<2>(b_90) * std::get<0>(a_90);
    std::get<2>(res_90) = std::get<0>(a_90) * std::get<1>(b_90) - std::get<0>(b_90) * std::get<1>(a_90);
    return res_90;
}

int main() {
    std::cout << std::setprecision(2) << std::fixed;
    Vector a_90 {1.2, 4, -0.5};
    Vector b_90 {1.5, -2, 2.5};
    Vector c_90 = cross_product(a_90, b_90);
    std::cout << std::get<0>(c_90) << ' ' << std::get<1>(c_90) << ' ' << std::get<2>(c_90) << std::endl;
    return 0;
}