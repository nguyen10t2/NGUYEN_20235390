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

int a_90[1000], n_90;
int mem_90[1000]; //# mảng ghi nhớ lời giải các bài toán con đã được giải

//# Chuẩn bị dữ liệu
void init(){
    memset(mem_90, -1, sizeof(mem_90));
}

//# Hàm max
int max(int a, int b) {
    return a > b ? a : b;
}

//# Quy hoạch động, 
//# Hàm lis(i) trả về độ dài dãy con tăng dài nhất kết thúc bởi a[i]
int lis(int i) {
    // Nếu đã tính toán rồi thì trả về giá trị đã tính
    if(mem_90[i] != -1) return mem_90[i];
    // Nếu chưa tính toán thì tính toán
    int result = 1;
    // Duyệt qua các phần tử trước a[i]
    //# Nếu a[j] < a[i] thì có thể nối a[j] với a[i]
    for(int j = 0; j < i; ++j) {
        if(a_90[j] < a_90[i]) result = max(result, lis(j) + 1);
    }
    // Lưu kết quả vào mảng ghi nhớ
    mem_90[i] = result;
    // Trả về kết quả
    return mem_90[i];
}

//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a_90[j] < a_90[i] && mem_90[i] == 1 + mem_90[j]){
            trace(j);
            break;
        }
    }
    printf("%d ", a_90[i]);
}

int main(){
    init();
    scanf("%d", &n_90);
    for(int i = 0; i < n_90; i++) scanf("%d", &a_90[i]);
    int res_90 = 1, pos_90 = 0;
    for(int i = 1; i < n_90; i++){
        if (res_90 < lis(i)){
            res_90 = lis(i);
            pos_90 = i;
        }
    }
    printf("%d\n", res_90);
    trace(pos_90);
    return 0;
}