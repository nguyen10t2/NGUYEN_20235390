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

std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, int>>>& a_90) {
    int n_90 = a_90.size();
    std::vector<int> dist_90(n_90, INT_MAX);
    std::vector<int> prev_90(n_90, -1);
    dist_90[0] = 0;
    using p_ii_90 = std::pair<int, int>;
    std::priority_queue<p_ii_90, std::vector<p_ii_90>, std::greater<p_ii_90>> pq_90;
    pq_90.push({0, 0});
    while(!pq_90.empty()) {
        p_ii_90 curr_90 = pq_90.top();
        pq_90.pop();
        if(curr_90.first > dist_90[curr_90.second]) continue;
        for(p_ii_90 neigboor_90 : a_90[curr_90.second]) {
            if(dist_90[neigboor_90.first] > dist_90[curr_90.second] + neigboor_90.second) {
                dist_90[neigboor_90.first] = dist_90[curr_90.second] + neigboor_90.second;
                prev_90[neigboor_90.first] = curr_90.second;
                pq_90.push({dist_90[neigboor_90.first], neigboor_90.first});
            }
        }
    }
    return dist_90;
}

int main() {

}