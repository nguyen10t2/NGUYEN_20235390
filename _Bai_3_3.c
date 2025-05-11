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

#include <stdio.h>
#include <string.h>

#define MAX 100
#define inf 0x7fffffff

int n, c[MAX][MAX]; //# số thành phố và ma trận chi phí
int cmin = inf; //# chi phí đi lại nhỏ nhất giữa hai thành phố khác nhau
int best = inf; //# tổng chi phí nhỏ nhất cần tìm, ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
int curr; //# tổng chi phí tới thời điểm hiện tại
int mark[MAX]; //# đánh dấu những thành phố đã đi
int x[MAX]; //# lưu giữ các thành phố đã đi

//# Hàm min
int min(int a, int b) {
    return a < b ? a : b;
}

//# Chuẩn bị đầu vào
void init() {
    best = inf;
    memset(mark, 0, sizeof(mark));
}

//# Đọc dữ liệu vào
void input(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            scanf("%d", &c[i][j]);
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}

//# Thuật toán quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
        if(mark[i]) continue;
        mark[i] = 1;
        x[k] = i;
        curr += c[x[k - 1]][i];
        if(k == n) {
            best = min(best, curr + c[x[n]][1]);
        }
        else if(curr + (n - k + 1) * cmin < best) TRY(k + 1);
        // Quay lui
        mark[i] = 0;
        curr -= c[x[k - 1]][i];
    }
}

int main() {
    input();
    init();
    x[1] = 1;
    TRY(2);
    printf("%d", best);
    return 0;
}