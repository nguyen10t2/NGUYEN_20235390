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
#include <cstring>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <chrono>
#include <thread>
#include <mutex>

const int MAX = 31;

int n, k, m;
std::unordered_map<int, std::vector<int>> graph;

//# Thiết lập đồ thị
// Tạo đồ thị từ đầu vào
void init() {
    for(int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
//# Depth-limited search
// Tìm kiếm theo chiều sâu có giới hạn độ sâu
// Trả về 1 nếu tìm thấy một đường đi đơn có độ dài k
int dls(const std::unordered_map<int, std::vector<int>>& graph, std::bitset<MAX>& visted, int depth, int maxdepth, int vertex) {
    if(depth == maxdepth) return 1;
    if(maxdepth - depth > MAX - visted.count()) return 0;
    int total = 0;
    for(int neigboor: graph.at(vertex)) {
        if(visted[neigboor]) continue;
        visted[neigboor] = 1;
        total += dls(graph, visted, depth + 1, maxdepth, neigboor);
        visted[neigboor] = 0;
    }
    return total;
}

int solution() {
    int res = 0;
    // Nếu không đa luông thì dùng biến toàn cục
    // std::bitset<MAX> visited; 

    // Tạo một vector để lưu các luồng <bỏ qua nếu không đa luồng>
    std::vector<std::thread> threads; 
    // Tạo một biến mutex để đồng bộ hóa truy cập vào biến res
    // <bỏ qua nếu không đa luồng>
    std::mutex mtx;
    for(auto& [vertex, _]: graph) {
        threads.emplace_back([&, vertex]() {
            // visited.reset();  <nếu không đa luồng>
            std::bitset<MAX> local_visited; // <bỏ qua nếu không đa luồng>
            local_visited[vertex] = 1;
            // Cộng thẳng vào res nếu không đa luồng
            int count = dls(graph, local_visited, 0, k, vertex);
            // Bỏ qua nếu không đa luồng
            std::lock_guard<std::mutex> lock(mtx);
            res += count;
        });
    }
    // Bỏ qua nếu không đa luồng
    // Chờ tất cả các luồng hoàn thành
    for(auto& thread: threads) {
        thread.join();
    }

    return res >> 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::cin >> n >> k >> m;
    init();
    std::cout << solution();
}
