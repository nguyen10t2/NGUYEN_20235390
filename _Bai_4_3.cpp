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

Vector cross_product(Vector a, Vector b) {
    Vector res = {0, 0, 0};
    std::get<0>(res) = std::get<1>(a) * std::get<2>(b) - std::get<1>(b) * std::get<2>(a);
    std::get<1>(res) = std::get<2>(a) * std::get<0>(b) - std::get<2>(b) * std::get<0>(a);
    std::get<2>(res) = std::get<0>(a) * std::get<1>(b) - std::get<0>(b) * std::get<1>(a);
    return res;
}

int main() {
    std::cout << std::setprecision(2) << std::fixed;
    Vector a {1.2, 4, -0.5};
    Vector b {1.5, -2, 2.5};
    Vector c = cross_product(a, b);
    std::cout << std::get<0>(c) << ' ' << std::get<1>(c) << ' ' << std::get<2>(c) << std::endl;
    return 0;
}