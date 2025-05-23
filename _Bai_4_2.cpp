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

using Point = std::pair<double, double>;

double area(Point A_90, Point B_90, Point C_90) {
    double AB_90 = sqrt(pow(A_90.first - B_90.first, 2) + pow(A_90.second - B_90.second, 2));
    double BC_90 = sqrt(pow(C_90.first - B_90.first, 2) + pow(C_90.second - B_90.second, 2));
    double CA_90 = sqrt(pow(A_90.first - C_90.first, 2) + pow(A_90.second - C_90.second, 2));
    double p_90 = (AB_90 + BC_90 + CA_90) / 2;
    return sqrt(p_90 * (p_90 - AB_90) * (p_90 - BC_90) * (p_90 - CA_90));
}

int main() {

}