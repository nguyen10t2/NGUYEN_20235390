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
#include <algorithm>
#include <queue>

int global_soldiers_90, global_castles_90;
int total_monsters_90;

typedef struct Battle_90 {
    int monsters_90, monsters_per_soldier_90;
    Battle_90() : monsters_90(0), monsters_per_soldier_90(0) {}
    Battle_90(int m_90, int mps_90) : monsters_90(m_90), monsters_per_soldier_90(mps_90) {}
    bool operator<(const Battle_90& other_90) const {
        if(this->monsters_per_soldier_90 == other_90.monsters_per_soldier_90)
            return this->monsters_90 < other_90.monsters_90;
        return this->monsters_per_soldier_90 < other_90.monsters_per_soldier_90;
    }
} Battle_90;

std::vector<Battle_90> battles_90;

void input() {
    std::cin >> global_castles_90 >> global_soldiers_90;
    battles_90.resize(global_castles_90);
    total_monsters_90 = 0;
    for(int i = 0; i < global_castles_90; ++i) {
        std::cin >> battles_90[i].monsters_90 >> battles_90[i].monsters_per_soldier_90;
        total_monsters_90 += battles_90[i].monsters_90;
    }
}

// int solution() {
//     std::vector<int> dp_90(global_soldiers_90 + 1, 0);
//     for(Battle_90 battle_90 : battles_90) {
//         int max_soldiers_90 = (battle_90.monsters_90 < battle_90.monsters_per_soldier_90) ? 1 : battle_90.monsters_90 / battle_90.monsters_per_soldier_90; // Renamed max_soilers to max_soldiers
//         int monsters_per_soldier_loc_90 = std::min(battle_90.monsters_90, battle_90.monsters_per_soldier_90);

//         for(int soldier_90 = 1; soldier_90 <= max_soldiers_90; ++soldier_90) {
//             int killed_monsters_90 = soldier_90 * monsters_per_soldier_loc_90;
//             if(killed_monsters_90 > battle_90.monsters_90) killed_monsters_90 = battle_90.monsters_90;
//             for(int j = global_soldiers_90; j >= soldier_90; --j)
//                 dp_90[j] = std::max(dp_90[j], dp_90[j - soldier_90] + killed_monsters_90);
//         }
//     }
//     return total_monsters_90 - *std::max_element(dp_90.begin(), dp_90.end());
// }

int solution() {
    std::priority_queue<Battle_90> pq_90(battles_90.begin(), battles_90.end());
    int result_90 = 0;
    int current_global_soldiers_90 = global_soldiers_90; // Use a local copy to modify
    while(!pq_90.empty()) {
        Battle_90 top_90 = pq_90.top();
        pq_90.pop();
        int max_soldiers_loc_90 = std::min(current_global_soldiers_90, top_90.monsters_90 / top_90.monsters_per_soldier_90);
        int killed_monsters_90 = std::max(0, max_soldiers_loc_90 * top_90.monsters_per_soldier_90);
        result_90 += killed_monsters_90;
        current_global_soldiers_90 -= max_soldiers_loc_90;
        if(top_90.monsters_90 > killed_monsters_90) pq_90.emplace(top_90.monsters_90 - killed_monsters_90, top_90.monsters_90 - killed_monsters_90); // Original emplace logic maintained
        if(current_global_soldiers_90 <= 0) break;
    }
    return total_monsters_90 - result_90;
}

void output() {
    std::cout << solution();
}

int main() {
    input();
    output();
    return 0;
}