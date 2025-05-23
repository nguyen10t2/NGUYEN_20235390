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
#include <stack>
#define MAX_90 0x7fffffff

int global_size_90;
std::vector<int> global_map_90;

void input() {
    std::cin >> global_size_90;
    global_map_90.resize(global_size_90);
    for(int i = 0; i < global_size_90; ++i) std::cin >> global_map_90[i];
}

int solution() {
    global_map_90.push_back(0);
    std::stack<int> open_stack_90;
    int best_90 = -MAX_90;
    // open_stack_90.push(0);
    for(int i = 0; i < global_map_90.size(); ++i) {
        while(!open_stack_90.empty() && global_map_90[i] < global_map_90[open_stack_90.top()]) {
            int height_90 = global_map_90[open_stack_90.top()];
            open_stack_90.pop();
            int wight_90 = open_stack_90.empty() ? i : (i - open_stack_90.top() - 1);
            best_90 = std::max(best_90, height_90 * wight_90);
        }
        open_stack_90.push(i);
    }
    return best_90;
}

void output() {
    std::cout << solution();
}

int main() {
    input();
    output();
}