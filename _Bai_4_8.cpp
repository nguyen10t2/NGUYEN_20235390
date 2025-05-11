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

template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    std::cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    std::cout << "}";
    std::cout << std::endl;
}

template <class T> 
std::map<T, double> fuzzy_set_union(const std::map<T, double>& a, const std::map<T, double>& b) {
    std::map<T, double> res = a;
    for(auto it = b.begin(); it != b.end(); ++it) {
        res[it->first] = std::max(res[it->first], it->second);
    }
    return res;
}

template<class T>
std::map<T, double> fuzzy_set_intersection(const std::map<T, double> &a, const std::map<T, double> &b) {
    std::map<T, double> res;
    for(auto it = a.begin(); it != a.end(); ++it) {
        if(b.find(it->first) != b.end()) res[it->first] = std::min(it->second, b.at(it->first));
    }
    return res;
}

int main() {
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a);
    std::cout << "B = "; print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: "; print_fuzzy_set(c);
    std::cout << "Intersection: "; print_fuzzy_set(d);
}