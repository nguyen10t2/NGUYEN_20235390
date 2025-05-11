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

void print_vector(const std::vector<int> &a) {
    for (int v : a) std::cout << v << ' ';
    std::cout << std::endl;
}

void delete_even_v1(std::vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        while(arr[left] % 2 == 0) left++;
        while(arr[right] % 2 != 0) right--;
        if(left < right) std::swap(arr[left], arr[right]);
    }
    arr.erase(arr.begin() + left, arr.end());
}

void delete_even_v2(std::vector<int>& arr) {
    arr.erase(std::remove_if(arr.begin(), arr.end(), [](int x){return x % 2 == 0;}), arr.end());
}

void bench_mark() {
    int NUM_TEST = 20;
    int SIZE = 2500000;
    std::srand(std::time(0));
    double time1 = 0, time2 = 0;
    for(int t = 0; t < NUM_TEST; ++t) {
        std::vector<int> vec1(SIZE);
        std::vector<int> vec2(SIZE);
        for(int i = 0; i < SIZE; ++i) vec1[i] = vec2[i] = rand();
        auto start = std::chrono::high_resolution_clock::now();
        delete_even_v1(vec1);
        auto end = std::chrono::high_resolution_clock::now();
        time1 += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        start = std::chrono::high_resolution_clock::now();
        delete_even_v2(vec2);
        end = std::chrono::high_resolution_clock::now();
        time2 += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }
    time1 /= NUM_TEST;
    time2 /= NUM_TEST;
    std::cout << std::fixed << std::setprecision(6) << time1 / 100000 << '\n' << time2 / 100000;
}

void sort_decrease(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        return a > b;
    });
}

std::vector<int> merge_vectors(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> res;
    int p1 = 0, p2 = 0;
    int len1 = a.size(), len2 = b.size();
    while(p1 < len1 && p2 < len2) {
        if(a[p1] <= b[p2]) {
            res.push_back(b[p2]);
            p2++;
        }
        else {
            res.push_back(a[p1]);
            p1++;
        }
    }
    while(p1 < len1) {
        res.push_back(a[p1]);
        p1++;
    }
    while(p2 < len2) {
        res.push_back(a[p2]);
        p2++;
    }
    return res;
}

int main() {
    bench_mark();
    // int m, n, u;
    // std::vector<int> a, b;
    
    // std::cin >> m >> n;
    // for(int i = 0; i < m; i++){
    //     std:: cin >> u;
    //     a.push_back(u);
    // }
    // for(int i = 0; i < n; i++){
    //     std:: cin >> u;
    //     b.push_back(u);
    // }
    // delete_even(a);
    // std::cout << "Odd elements of a: ";
    // print_vector(a);

    // delete_even(b);
    // std::cout << "Odd elements of b: ";
    // print_vector(b);

    // sort_decrease(a);
    // std::cout << "Decreasingly sorted a: ";
    // print_vector(a);

    // sort_decrease(b);
    // std::cout << "Decreasingly sorted b: ";
    // print_vector(b);

    // std::vector<int> c = merge_vectors(a, b);
    // std::cout << "Decreasingly sorted c: ";
    // print_vector(c);

    return 0;
}