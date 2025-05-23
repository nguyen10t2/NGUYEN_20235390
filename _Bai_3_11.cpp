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
#include <sstream>
#include <limits>
#include <algorithm>

//# Vô cùng
#define inf 0x7fffffff


//# Đọc một dòng từ đầu vào
std::string readLine() {
    std::string s;
    std::getline(std::cin, s);
    return s;
}

int n, r;
std::vector<std::vector<short>> graph;

//# Đọc đồ thị
void init() {
    std::cin >> n >> r;
    graph.resize(n, std::vector<short>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {
            std::cin >> graph[i][j];
            if(!graph[i][j]) graph[i][j] = -1;
        }
    // Đọc hết cache để tránh lỗi
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
//# Đọc danh sách các thành phố cuat từng du khách
void read_list(std::vector<short>& list, short& start) {
    std::string line = readLine();
    std::stringstream ss(line);
    short number;
    // Đọc thành phố đầu tiên
    short temp;
    ss >> temp;
    // Đọc các thành phố còn lại
    while(ss >> number) {
        list.push_back(number - 1);
    }
    // Đọc thành phố đầu tiên
    start = temp - 1;
}

void solution() {
    while(r--) {
        std::vector<short> list;
        short start = -1;
        short index = -1;
        read_list(list, start);
        std::sort(list.begin(), list.end() - 1);
        std::vector<std::vector<short>> permutation;
        // Vét tất cả các tổ hợp trừ điểm đầu và điểm cuối (điểm đầu tách ra start rồi)
        do {
            permutation.push_back(list);
        } while(std::next_permutation(list.begin(), list.end() - 1));
        int best = inf;
        short curr = start;
        // Cho đi thử tất cả cá tổ hợp nếu gãy thì tiếp tục tìm tổ hợp mới
        for(std::vector<short> _: permutation) {
            int cost = 0;
            bool flag = false;
            // Duyệt từng thành phần của tổ hợp
            for(short city: _) {
                // Nếu đường gãy đánh dấu và thoát khỏi vòng lặp
                if(graph[curr][city] == -1) {
                    flag = true;
                    break;
                }
                // Cộng dồn chi phí
                cost += graph[curr][city];
                curr = city;
            }
            curr = start;
            // Cờ đánh dấu là đường gãy
            if(flag) continue;
            // Không gãy thì cập nhật giá trị
            best = std::min(best, cost);
        }
        // Nếu không có đường đi nào thì in ra 0 ngược lại in ra giá trị nhỏ nhất
        if(best == inf) std::cout << '0' << '\n';
        else std::cout << best << '\n';
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    init();
    solution();
    return 0;
}