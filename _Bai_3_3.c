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

int n_90, c_90[MAX][MAX]; //# số thành phố và ma trận chi phí
int cmin_90 = inf; //# chi phí đi lại nhỏ nhất giữa hai thành phố khác nhau
int best_90 = inf; //# tổng chi phí nhỏ nhất cần tìm, ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
int curr_90; //# tổng chi phí tới thời điểm hiện tại
int mark_90[MAX]; //# đánh dấu những thành phố đã đi
int x_90[MAX]; //# lưu giữ các thành phố đã đi

//# Hàm min
int min(int a, int b) {
    return a < b ? a : b;
}

//# Chuẩn bị đầu vào
void init() {
    best_90 = inf;
    memset(mark_90, 0, sizeof(mark_90));
}

//# Đọc dữ liệu vào
void input(){
    scanf("%d", &n_90);
    for (int i = 1; i <= n_90; ++i)
        for (int j = 1; j <= n_90; ++j){
            scanf("%d", &c_90[i][j]);
            if (c_90[i][j] > 0) cmin_90 = min(cmin_90, c_90[i][j]);
        }
}

//# Thuật toán quay lui
void TRY(int k){
    for(int i = 2; i <= n_90; i++){
        // Nếu thành phố đã đi thì bỏ qua
        if(mark_90[i]) continue;
        // Nếu thành phố chưa đi thì đánh dấu
        mark_90[i] = 1;
        x_90[k] = i;
        // Cập nhật tổng chi phí
        curr_90 += c_90[x_90[k - 1]][i];
        // Nếu đã đi hết các thành phố thì cập nhật tổng chi phí
        if(k == n_90) {
            best_90 = min(best_90, curr_90 + c_90[x_90[n_90]][1]);
        }
        // Cắt nhánh 
        else if(curr_90 + (n_90 - k + 1) * cmin_90 < best_90)
            TRY(k + 1);
        // Quay lui
        mark_90[i] = 0;
        curr_90 -= c_90[x_90[k - 1]][i];
    }
}

int main() {
    input();
    init();
    x_90[1] = 1;
    TRY(2);
    printf("%d", best_90);
    return 0;
}