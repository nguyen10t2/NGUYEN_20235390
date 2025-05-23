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
#include <unordered_map>

int subString(const std::string& str_90) {
    std::unordered_map<char, int> charCount_90;
    int balance_90 = 0;
    int ans_90 = 0;
    charCount_90[0] = 1;
    for(const char& c_90 : str_90) {
        if(c_90 == '1') {
            balance_90++;
        } else {
            balance_90--;
        }
        ans_90 += charCount_90[balance_90]; 
        charCount_90[balance_90]++;
    }
    return ans_90;
}

int main() {
    std::string str_90;
    std::cin >> str_90;
    std::cout << subString(str_90) << '\\n';
    return 0;
}