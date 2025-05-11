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
#include <algorithm>
#include <random>
#include <ctime>

//# Tạo 1 cấu trúc myPair với 2 biến int
struct myPair {
    int first;
    int second;

    //# Hàm so sánh 2 myPair
    bool operator<(const myPair& other) const {
        return (second < other.second) || (second == other.second && first < other.first);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    myPair *myPairs_90 = new myPair[1000];
    int length_90 = 0;
    
    while(std::cin >> myPairs_90[length_90].first >> myPairs_90[length_90].second) {
        length_90++;
    }

    // sắp xếp
    std::sort(myPairs_90, myPairs_90 + length_90, [](const myPair& a, const myPair& b) {
        return !(a < b);
    });

    for(int i = 0; i < length_90; i++) {
        std::cout << myPairs_90[i].first << " " << myPairs_90[i].second << std::endl;
    }
}