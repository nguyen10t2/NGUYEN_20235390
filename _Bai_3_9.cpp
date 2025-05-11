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
#include <queue>

//# Kiểu dữ liệu chứa chuỗi nhị phân và số lượng bit 1 sau cùng
struct myPair {
    std::string str;
    int l_one;
    myPair(std::string _str, int _l_one) : str(_str), l_one(_l_one) {}
};

int n, k1, k2;

//# Đệ quy sinh tất cả tổ hợp
// Không có 2 ngày nghỉ liên tiếp
// Số ngày đi làm liên tiệp >= k1 và <= k2
void recuise(std::string str, int l_one) {
    // Nếu đã đủ n ngày
    if(str.length() == n) {
        // Nếu số ngày đi làm liên tiếp >= k1 hoặc == 0
        // In ra chuỗi
        if(l_one >= k1 || l_one == 0) std::cout << str << '\n';
        // Trả về
        return;
    }
    // Nếu số ngày đi làm liên tiếp < k1
    if(l_one < k1) {
        // Coi tất cả các ngày còn lại đều đi làm
        // Tổng số ngày đi làm liên tiếp < k1 thì dĩ nhiên không thể
        // Ngược lại thì đi làm
        if(n - str.length() + l_one >= k1) recuise(str + "1", l_one + 1);
    }
    // Nếu số ngày đi làm liên tiếp == k2 chắc chắn phải nghỉ
    else if(l_one == k2) recuise(str + "0", 0);
    else {
        // Ngược lại số ngày đi làm đã >= k1 và < k2 thì chắc chẵn có thể nghỉ
        recuise(str + "0", 0);
        // Nếu số ngày đi làm liên tiếp < k1 thì dĩ nhiên không thể
        // Ngược lại thì đi làm
        if(n - str.length() + l_one >= k1) recuise(str + "1", l_one + 1);
    }
}

void not_recuise() {
    std::queue<myPair> q;

    // Giải đệ quy
    q.push({"0", 0});
    q.push({"1", 1});
    while(q.front().str.size() < n) {
        myPair curr = q.front();
        q.pop();
        if(curr.l_one < k1) {
            if(n - curr.str.size() + curr.l_one >= k1) q.push(myPair(curr.str + "1", curr.l_one + 1));
        }
        else if(curr.l_one == k2) q.push(myPair(curr.str + "0", 0));
        else {
            q.push(myPair(curr.str + "0", 0));
            if(n - curr.str.size() + curr.l_one >= k1)
                q.push(myPair(curr.str + "1", curr.l_one + 1));
        }
    }
    while(!q.empty()) {
        std::cout << q.front().str << '\n';
        q.pop();
    }
}

int main() {
    std::cin >> n >> k1 >> k2;
    // recuise("0", 0);
    // recuise("1", 1);
    not_recuise();
}