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

//# Hàm tính tổng của 2 mảng với kiểu dữ liệu tổng quát
template <typename T> T arr_sum(T* a_90, int n_90, T* b_90, int m_90) {
    T sum_90 = 0;
    // Tổng các phần tử trong mảng a_90
    for (int i_90 = 0; i_90 < n_90; ++i_90) {
        sum_90 += a_90[i_90];
    }
    // Tổng các phần tử trong mảng b_90
    for (int j_90 = 0; j_90 < m_90; ++j_90) {
        sum_90 += b_90[j_90];
    }
    return sum_90;
}


int main() {
    int val_dtn_90;
    std::cin >> val_dtn_90;

    {
        //# Khai báo mảng a_dtn_90 và b_dtn_90 với kiểu int
        int a_dtn_90[] = {3, 2, 0, val_dtn_90};
        int b_dtn_90[] = {5, 6, 1, 2, 7};
        // Gọi hàm arr_sum với kiểu int
        std::cout << arr_sum(a_dtn_90, 4, b_dtn_90, 5) << std::endl;
    }

    {
        //# Khai báo mảng a_dtn_90 và b_dtn_90 với kiểu float
        double a_dtn_90[] = {3.0, 2, 0, val_dtn_90 * 1.0};
        double b_dtn_90[] = {5, 6.1, 1, 2.3, 7};
        // Gọi hàm arr_sum với kiểu float
        std::cout << arr_sum(a_dtn_90, 4, b_dtn_90, 5) << std::endl;
    }
    //# -- Dao Trong Nguyen _ 20235390 _ IT2-03 _ IT3040 _ 750829_ 2024.2 --
    return 0;
}