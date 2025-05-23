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
#include <stack>
using namespace std;

struct state{
    int i_90, j_90, old_L_90;
    //# constructor
    state(int _i_90 = 0, int _j_90 = 0, int _L_90 = 0):
        i_90(_i_90), j_90(_j_90), old_L_90(_L_90){}
};

int main() {
    int n_90, k_90;
    cin >> n_90 >> k_90;
    int x_90[n_90 + 1];
    stack<state> s_90;
    //# number of consecutive suffix 1
    s_90.push(state());
    while (!s_90.empty()){
        // Lấy trạng thái trên cùng
        state top_90 = s_90.top();
        s_90.pop();
        // gán giá trị cho x[i] như trong thuật toán đệ quy
        x_90[top_90.i_90] = top_90.j_90;
        // Nếu đã thử hết các phần tử
        if(top_90.i_90 >= n_90) {
            for(int i_90 = 1; i_90 <= n_90; ++i_90) cout << x_90[i_90] << ' ';
            cout << '\n';
            continue;
        }
        // Tính toán L và thêm trạng thái mới vào stack ngược so với thuật toán đệ quy
        int L_90 = top_90.j_90 ? top_90.old_L_90 + 1 : 0;
        if(L_90 + 1 != k_90) s_90.push(state(top_90.i_90 + 1, 1, L_90));
        s_90.push(state(top_90.i_90 + 1, 0, L_90));
    }
    return 0;
}