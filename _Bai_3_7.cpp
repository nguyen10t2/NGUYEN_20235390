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
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};

int main() {
    int n, k;
    cin >> n >> k;
    int x[n + 1];
    stack<state> s;
    //# number of consecutive suffix 1
    s.push(state());
    while (!s.empty()){
        state top = s.top();
        s.pop();
        x[top.i] = top.j;
        if(top.i >= n) {
            for(int i = 1; i <= n; ++i) cout << x[i] << ' ';
            cout << '\n';
            continue;
        }
        int L = top.j ? top.old_L + 1 : 0;
        if(L + 1 != k) s.push(state(top.i + 1, 1, L));
        s.push(state(top.i + 1, 0, L));
    }
    return 0;
}