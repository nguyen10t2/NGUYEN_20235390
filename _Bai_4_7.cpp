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
#include <unordered_set>

template <class T> using set = std::unordered_set<T>;

template<class T>
void print_set(const set<T> &a) {
    for (const T &x : a) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

template <typename T> 
set<T> set_union(const set<T>& a, const set<T>& b) {
    set<T> res = a;
    for(const T& x : b) res.insert(x);
    return res;
}

template <typename T> 
set<T> set_intersection(const set<T>& a, const set<T>& b) {
    set<T> res;
    for(const T& x : a) {
        if(b.find(x) != b.end()) res.insert(x);
    }
    return res;
}



int main() {
    set<int> a = {1, 2, 3, 5, 7};
    set<int> b = {2, 4, 5, 6, 9};
    set<int> c = set_union(a, b);
    set<int> d = set_intersection(a, b);
        
    std::cout << "Union: "; print_set(c);
    std::cout << "Intersection: "; print_set(d);
}