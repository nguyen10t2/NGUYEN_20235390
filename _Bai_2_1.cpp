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

//# Hàm tính cạnh huyền của tam giác vuông
float get_hypotenuse(float x_90, float y_90) {
    return sqrt(x_90 * x_90 + y_90 * y_90);
}

int main() {
    float x_dtn_90, y_dtn_90;
    std::cin >> x_dtn_90 >> y_dtn_90;
    // gọi hàm get_hypotenuse với 2 tham số x_dtn_90 và y_dtn_90
    float z_dtn_90 = get_hypotenuse(x_dtn_90, y_dtn_90);
    // In ra cạnh huyền với 2 chữ số thập phân
    std::cout << std::fixed << std::setprecision(2) << z_dtn_90 << std::endl;
    // -- Dao Trong Nguyen _ 20235390 _ IT2-03 _ IT3040 _ 750829_ 2024.2 --
    return 0;
}