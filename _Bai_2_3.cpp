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

__int64 get_value(int x_90, int a_90 = 2, int b_90 = 1, int c_90 = 0) {
    return a_90 * x_90 * x_90 + b_90 * x_90 + c_90;
}

int main() {
    int x_dtn_90;
    std::cin >> x_dtn_90;

    int a_dtn_90 = 2, b_dtn_90 = 1, c_dtn_90 = 0;
    std::cin >> a_dtn_90 >> b_dtn_90 >> c_dtn_90;
    // In ra giá trị của hàm get_value với các tham số ngầm định
    std::cout << "a = 2, b = 1, c = 0: " << get_value(x_dtn_90) << std::endl;
    // In ra giá trị của hàm get_value với a = a_dtn_90
    std::cout << "a = " << a_dtn_90 << ", b = 1, c = 0: " << get_value(x_dtn_90, a_dtn_90) << std::endl;
    // In ra giá trị của hàm get_value với a = a_dtn_90, b = b_dtn_90
    std::cout << "a = " << a_dtn_90 << ", b = " << b_dtn_90 << ", c = 0: " << get_value(x_dtn_90, a_dtn_90, b_dtn_90) << std::endl;
    // In ra giá trị của hàm get_value với a = a_dtn_90, b = b_dtn_90, c = c_dtn_90
    std::cout << "a = " << a_dtn_90 << ", b = " << b_dtn_90 << ", c = " << c_dtn_90 << ": " << get_value(x_dtn_90, a_dtn_90, b_dtn_90, c_dtn_90) << std::endl;
    // -- Dao Trong Nguyen _ 20235390 _ IT2-03 _ IT3040 _ 750829_ 2024.2 --
    return 0;
}