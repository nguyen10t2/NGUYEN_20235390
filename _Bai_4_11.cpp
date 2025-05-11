#include <iostream>
#include <vector>
#include <algorithm>


int n, s;
int full_monsters;

void solution(const std::vector<int>& monsters, const std::vector<int>& x) {
    std::vector<int> dp(s + 1, 0);
    for(int i = 0; i < n; ++i) {
        int max_soldiers = monsters[i] < x[i] ? 1 : monsters[i] / x[i];
        int monster_per_soldier = std::min(monsters[i], x[i]);

        std::vector<std::pair<int, int>> battles;
        int k = 1;
        while(max_soldiers > 0) {
            int soldier = std::min(k, max_soldiers);
            int killed_monster = soldier * monster_per_soldier;
            if(killed_monster > monsters[i]) killed_monster = monsters[i];
            battles.emplace_back(soldier, killed_monster);
            max_soldiers -= soldier;
            k <<= 1;
        }

        for(auto& battle : battles) {
            int soldier = battle.first;
            int monters = battle.second;
            for(int j = s; j >= soldier; --j) {
                dp[j] = std::max(dp[j], dp[j - soldier] + monters);
            } 
        }
    }
    std::cout << full_monsters - *std::max_element(dp.begin(), dp.end());
}

void init() {
    std::cin >> n >> s;
    std::vector<int> monsters(n);
    std::vector<int> x(n);
    full_monsters = 0;
    for(int i = 0; i < n; ++i) {
        std::cin >> monsters[i] >> x[i];
        full_monsters += monsters[i];
    }
    solution(monsters, x);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    init();
}