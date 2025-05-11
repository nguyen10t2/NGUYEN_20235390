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
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int val1_dtn_90, val2_dtn_90;
    cin >> val1_dtn_90 >> val2_dtn_90;
    vector< vector<int> > a_dtn_90 = {
        {1, 3, 7},
        {2, 3, 4, val1_dtn_90},
        {9, 8, 15},
        {10, val2_dtn_90},
    };

    // sort(a_dtn_90.begin(), a_dtn_90.end(), [](const vector<int> &a_90, const vector<int> &b_90) {
    //     return std::accumulate(a_90.begin(), a_90.end(), 0) < std::accumulate(b_90.begin(), b_90.end(), 0);
    // });

    //Tương tự như trên, nhưng sử dụng vòng lặp for để tính tổng của từng vector thay vì hàm
    sort(a_dtn_90.begin(), a_dtn_90.end(), [](const vector<int> &a_90, const vector<int> &b_90) {
        int sum_a_dtn_90 = 0;
        // Tính tổng của vector a_90
        for (int it_90 : a_90) {
            sum_a_dtn_90 += it_90;
        }
        int sum_b_dtn_90 = 0;
        // Tính tổng của vector b_90
        for (int it_90 : b_90) {
            sum_b_dtn_90 += it_90;
        }
        // So sánh tổng của 2 vector
        return sum_a_dtn_90 < sum_b_dtn_90;
    });

    for (const auto &v_dtn_90 : a_dtn_90) {
        for (int it_90 : v_dtn_90) {
            cout << it_90 << ' ';
        }
        cout << endl;
    }
    // -- Dao Trong Nguyen _ 20235390 _ IT2-03 _ IT3040 _ 750829_ 2024.2 --
    return 0;
}