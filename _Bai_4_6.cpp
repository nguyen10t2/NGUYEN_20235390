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
#include <list>
#include <cstring>
#include <queue>

void bfs(std::vector<std::list<int> > adj_90) {
    std::vector<bool> visited_90(adj_90.size(), false);
    std::queue<int> myQueue_90;
    myQueue_90.push(1);
    while(!myQueue_90.empty()) {
        int curr_90 = myQueue_90.front();
        myQueue_90.pop();
        if(visited_90[curr_90]) continue;
        visited_90[curr_90] = true;
        std::cout << curr_90 << '\n';
        for(auto it_90 = adj_90[curr_90].begin(); it_90 != adj_90[curr_90].end(); ++it_90) {
            if(!visited_90[*it_90]) myQueue_90.push(*it_90);
        }
    }
}

int main() {
    int n_90 = 7;
    std::vector<std::list<int> > adj_90;
    adj_90.resize(n_90 + 1);
    adj_90[1].push_back(2);
    adj_90[2].push_back(4);
    adj_90[1].push_back(3);
    adj_90[3].push_back(4);
    adj_90[3].push_back(5);
    adj_90[5].push_back(2);
    adj_90[2].push_back(7);
    adj_90[6].push_back(7);
    bfs(adj_90);
}