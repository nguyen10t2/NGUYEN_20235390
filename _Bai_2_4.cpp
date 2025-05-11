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

int cube(int n_90) {
    return n_90 * n_90 * n_90;
}

double cube(double n_90) {
    return n_90 * n_90 * n_90;
}

int main() {
    int n_dtn_90;
    double f_dtn_90;
    std::cin >> n_dtn_90 >> f_dtn_90;
    // Gọi hàm cube với tham số là n_dtn_90
    std::cout << "Int: " << cube(n_dtn_90) << std::endl;
    // Gọi hàm cube với tham số là f_dtn_90 lấy 2 chữ số thập phân
    std::cout << std::fixed << std::setprecision(2) << "Float: " << cube(f_dtn_90) << std::endl;
    // -- Dao Trong Nguyen _ 20235390 _ IT2-03 _ IT3040 _ 750829_ 2024.2 --
    return 0;
}