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

int binom(int n_90, int k_90) {
    if (k_90 > n_90) return 0;
    if (k_90 == 0) return 1;
    return binom(n_90-1, k_90) + binom(n_90-1, k_90-1);
}

//# Chuẩn bị bảng tra
int look_up_90[37][19];

void init() {
    memset(look_up_90, 0, sizeof(look_up_90));
}

int binom2(int n_90, int k_90){
    // Nếu k_90 > n_90 thì không tồn tại tổ hợp
    if (k_90 > n_90) return 0;
    // Nếu k_90 = 0 thì C(n_90, 0) = 1
    if (k_90 == 0) return 1;
    // Nếu đã tính toán rồi thì trả về giá trị đã tính
    if (look_up_90[n_90][k_90]) return look_up_90[n_90][k_90];
    // Nếu chưa tính toán thì tính toán
    look_up_90[n_90][k_90] = binom2(n_90 - 1, k_90) + binom2(n_90 - 1, k_90 - 1);
    // Lưu kết quả vào bảng tra và trả về kết quả
    return look_up_90[n_90][k_90];
}

int main() {
    int m_90;
    scanf("%d", &m_90);
    for (int n_90 = 1; n_90 <= m_90; ++n_90) {
        for (int k_90 = 0; k_90 <= n_90; ++k_90)
            printf("%d ", binom(n_90, k_90));
        printf("\n");
    }
    for (int n_90 = 1; n_90 <= m_90; ++n_90) {
        for (int k_90 = 0; k_90 <= n_90; ++k_90)
            printf("%d ", binom2(n_90, k_90));
        printf("\n");
    }
    return 0;
}