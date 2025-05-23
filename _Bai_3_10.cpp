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

//# Đệ quy sinh tất cả tổ hợp có đúng k bit 1 trong n bit
void back_track(std::vector<std::string>& res, std::string curr, int n, int k, int len, int count_one) {
    if(len == n) {
        if(k == count_one) res.push_back(curr);
        return;
    }
    back_track(res, curr + '0', n, k, len + 1, count_one);
    if(count_one < k) back_track(res, curr + '1', n, k, len + 1, count_one + 1);
}

//# Sinh tất cả tổ hợp có đúng k bit 1 trong n bit
std::vector<std::string> generate(int n, int k) {
    // Trả về tất cả tổ hợp có đúng k bit 1 trong n bit
    std::vector<std::string> res;
    // Gọi hàm đệ quy
    back_track(res, "", n, k, 0, 0);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 0, n = 0, k = 0;
    std::cin >> t;
    while(t--) {
        std::cin >> n >> k;
        std::vector<std::string> res = generate(n, k);
        for(std::string ele: res) std::cout << ele << '\n';
    }
    return 0;
}