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

template <class T_90> using set_90 = std::unordered_set<T_90>;

template<class T_90>
void print_set(const set_90<T_90> &a_90) {
    for (const T_90 &x_90 : a_90) {
        std::cout << x_90 << ' ';
    }
    std::cout << std::endl;
}

template <typename T_90> 
set_90<T_90> set_union(const set_90<T_90>& a_90, const set_90<T_90>& b_90) {
    set_90<T_90> res_90 = a_90;
    for(const T_90& x_90 : b_90) res_90.insert(x_90);
    return res_90;
}

template <typename T_90> 
set_90<T_90> set_intersection(const set_90<T_90>& a_90, const set_90<T_90>& b_90) {
    set_90<T_90> res_90;
    for(const T_90& x_90 : a_90) {
        if(b_90.find(x_90) != b_90.end()) res_90.insert(x_90);
    }
    return res_90;
}



int main() {
    set_90<int> a_90 = {1, 2, 3, 5, 7};
    set_90<int> b_90 = {2, 4, 5, 6, 9};
    set_90<int> c_90 = set_union(a_90, b_90);
    set_90<int> d_90 = set_intersection(a_90, b_90);
        
    std::cout << "Union: "; print_set(c_90);
    std::cout << "Intersection: "; print_set(d_90);
}