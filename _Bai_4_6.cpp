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

void bfs(std::vector<std::list<int> > adj) {
    std::vector<bool> visited(adj.size(), false);
    std::queue<int> myQueue;
    myQueue.push(1);
    while(!myQueue.empty()) {
        int curr = myQueue.front();
        myQueue.pop();
        if(visited[curr]) continue;
        visited[curr] = true;
        std::cout << curr << '\n';
        for(auto it = adj[curr].begin(); it != adj[curr].end(); ++it) {
            if(!visited[*it]) myQueue.push(*it);
        }
    }
}

int main() {
    int n = 7;
    std::vector<std::list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);
}