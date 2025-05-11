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
#include <queue>
#include <unordered_map>
#include <unordered_set>

std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, int>>>& a) {
    int n = a.size();
    std::vector<int> dist(n, INT_MAX);
    std::vector<int> prev(n, -1);
    dist[0] = 0;
    using p_ii = std::pair<int, int>;
    std::priority_queue<p_ii, std::vector<p_ii>, std::greater<p_ii>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        p_ii curr = pq.top();
        pq.pop();
        if(curr.first > dist[curr.second]) continue;
        for(p_ii neigboor : a[curr.second]) {
            if(dist[neigboor.first] > dist[curr] + neigboor.second) {
                dist[neigboor.first] = dist[curr] + neigboor.second;
                prev[neigboor.first] = curr;
                pq.push({dist[neigboor.first], neigboor.first});
            }
        }
    }
    return dist;
}

int main() {

}