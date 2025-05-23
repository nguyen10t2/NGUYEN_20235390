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
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

void print_vector(const std::vector<int> &a_90) {
    for (int v_90 : a_90) std::cout << v_90 << ' ';
    std::cout << std::endl;
}

void delete_even_v1(std::vector<int>& arr_90) {
    int left_90 = 0, right_90 = arr_90.size() - 1;
    while(left_90 < right_90) {
        while(arr_90[left_90] % 2 == 0) left_90++;
        while(arr_90[right_90] % 2 != 0) right_90--;
        if(left_90 < right_90) std::swap(arr_90[left_90], arr_90[right_90]);
    }
    arr_90.erase(arr_90.begin() + left_90, arr_90.end());
}

void delete_even_v2(std::vector<int>& arr_90) {
    arr_90.erase(std::remove_if(arr_90.begin(), arr_90.end(), [](int x_90){return x_90 % 2 == 0;}), arr_90.end());
}

void bench_mark() {
    int NUM_TEST_90 = 20;
    int SIZE_90 = 2500000;
    std::srand(std::time(0));
    double time1_90 = 0, time2_90 = 0;
    for(int t_90 = 0; t_90 < NUM_TEST_90; ++t_90) {
        std::vector<int> vec1_90(SIZE_90);
        std::vector<int> vec2_90(SIZE_90);
        for(int i = 0; i < SIZE_90; ++i) vec1_90[i] = vec2_90[i] = rand();
        auto start_90 = std::chrono::high_resolution_clock::now();
        delete_even_v1(vec1_90);
        auto end_90 = std::chrono::high_resolution_clock::now();
        time1_90 += std::chrono::duration_cast<std::chrono::nanoseconds>(end_90 - start_90).count();
        start_90 = std::chrono::high_resolution_clock::now();
        delete_even_v2(vec2_90);
        end_90 = std::chrono::high_resolution_clock::now();
        time2_90 += std::chrono::duration_cast<std::chrono::nanoseconds>(end_90 - start_90).count();
    }
    time1_90 /= NUM_TEST_90;
    time2_90 /= NUM_TEST_90;
    std::cout << std::fixed << std::setprecision(6) << time1_90 / 100000 << '\\n' << time2_90 / 100000;
}

void sort_decrease(std::vector<int>& arr_90) {
    std::sort(arr_90.begin(), arr_90.end(), [](int a_90, int b_90) {
        return a_90 > b_90;
    });
}

std::vector<int> merge_vectors(const std::vector<int>& a_90, const std::vector<int>& b_90) {
    std::vector<int> res_90;
    int p1_90 = 0, p2_90 = 0;
    int len1_90 = a_90.size(), len2_90 = b_90.size();
    while(p1_90 < len1_90 && p2_90 < len2_90) {
        if(a_90[p1_90] <= b_90[p2_90]) {
            res_90.push_back(b_90[p2_90]);
            p2_90++;
        }
        else {
            res_90.push_back(a_90[p1_90]);
            p1_90++;
        }
    }
    while(p1_90 < len1_90) {
        res_90.push_back(a_90[p1_90]);
        p1_90++;
    }
    while(p2_90 < len2_90) {
        res_90.push_back(b_90[p2_90]);
        p2_90++;
    }
    return res_90;
}

int main() {
    bench_mark();
    // int m_90, n_90, u_90;
    // std::vector<int> a_90, b_90;
    
    // std::cin >> m_90 >> n_90;
    // for(int i = 0; i < m_90; i++){
    //     std:: cin >> u_90;
    //     a_90.push_back(u_90);
    // }
    // for(int i = 0; i < n_90; i++){
    //     std:: cin >> u_90;
    //     b_90.push_back(u_90);
    // }
    // delete_even_v2(a_90);
    // std::cout << "Odd elements of a: ";
    // print_vector(a_90);

    // delete_even_v2(b_90);
    // std::cout << "Odd elements of b: ";
    // print_vector(b_90);

    // sort_decrease(a_90);
    // std::cout << "Decreasingly sorted a: ";
    // print_vector(a_90);

    // sort_decrease(b_90);
    // std::cout << "Decreasingly sorted b: ";
    // print_vector(b_90);

    // std::vector<int> c_90 = merge_vectors(a_90, b_90);
    // std::cout << "Decreasingly sorted c: ";
    // print_vector(c_90);

    return 0;
}