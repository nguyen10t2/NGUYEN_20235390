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
#include <map>

template<class T_90>
void print_fuzzy_set(const std::map<T_90, double> &a_90) {
    std::cout << "{ ";
    for (const auto &x_90 : a_90) {
        std::cout << "(" << x_90.first << ", " << x_90.second << ") ";
    }
    std::cout << "}";
    std::cout << std::endl;
}

template <class T_90> 
std::map<T_90, double> fuzzy_set_union(const std::map<T_90, double>& a_90, const std::map<T_90, double>& b_90) {
    std::map<T_90, double> res_90 = a_90;
    for(auto it_90 = b_90.begin(); it_90 != b_90.end(); ++it_90) {
        res_90[it_90->first] = std::max(res_90[it_90->first], it_90->second);
    }
    return res_90;
}

template<class T_90>
std::map<T_90, double> fuzzy_set_intersection(const std::map<T_90, double> &a_90, const std::map<T_90, double> &b_90) {
    std::map<T_90, double> res_90;
    for(auto it_90 = a_90.begin(); it_90 != a_90.end(); ++it_90) {
        if(b_90.count(it_90->first)) res_90[it_90->first] = std::min(it_90->second, b_90.at(it_90->first));
    }
    return res_90;
}

int main() {
    std::map<int, double> a_90 = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b_90 = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a_90);
    std::cout << "B = "; print_fuzzy_set(b_90);
    std::map<int, double> c_90 = fuzzy_set_union(a_90, b_90);
    std::map<int, double> d_90 = fuzzy_set_intersection(a_90, b_90);
    std::cout << "Union: "; print_fuzzy_set(c_90);
    std::cout << "Intersection: "; print_fuzzy_set(d_90);
}