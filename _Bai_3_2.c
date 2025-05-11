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
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int n;
int X[100], Y[100]; //# Lưu tọa độ các bước di chuyển của quân mã
int mark[100][100]; //# Đánh dấu vị trí các ô mà quân mã đã di chuyển qua

//# Mảng hx, hy mô tả 8 vị trí quân mã có thể di chuyển kể từ vị trí hiện tại
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra dãy các di chuyển tìm được
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

void try(int k) {
    for(int i = 0; i < 8; ++i) {
        int x = X[k - 1] + hx[i]; //# Tính tọa độ ô tiếp theo
        int y = Y[k - 1] + hy[i];
        if (x < 1 || x > n || y < 1 || y > n) continue; //# Kiểm tra xem ô có nằm trong bàn cờ không
        if (mark[x][y]) continue; //# Kiểm tra ô đã được đánh dấu chưa
        mark[x][y] = 1; //# Đánh dấu ô đã được quân mã di chuyển qua
        X[k] = x; Y[k] = y; //# Lưu tọa độ ô vào mảng
        if (k == n * n) print_sol(); //# Nếu đã đi hết bàn cờ thì in ra kết quả
        try(k + 1); //# Tiếp tục tìm kiếm các bước di chuyển tiếp theo
        mark[x][y] = 0; //# Đánh dấu lại ô chưa được quân mã di chuyển qua
    }

}

int main() {
    printf("Nhap n: ");
    scanf("%d", &n); //# Nhập kích thước bàn cờ
    memset(mark, 0, sizeof(mark)); //# Khởi tạo mảng đánh dấu
    memset(X, 0, sizeof(X)); //# Khởi tạo mảng lưu tọa độ X
    memset(Y, 0, sizeof(Y)); //# Khởi tạo mảng lưu tọa độ Y
    mark[1][1] = 1; //# Đánh dấu ô (1, 1) đã được quân mã di chuyển qua
    X[1] = 1; Y[1] = 1; //# Lưu tọa độ ô (1, 1) vào mảng
    try(2);
    return 0;
}
