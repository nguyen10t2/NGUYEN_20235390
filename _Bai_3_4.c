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

int a[1000], n;
int mem[1000]; //# mảng ghi nhớ lời giải các bài toán con đã được giải

//# Chuẩn bị dữ liệu
void init(){
    memset(mem, -1, sizeof(mem));
}

//# Hàm max
int max(int a, int b) {
    return a > b ? a : b;
}

//# Quy hoạch động, 
//# Hàm lis(i) trả về độ dài dãy con tăng dài nhất kết thúc bởi a[i]
int lis(int i) {
    if(mem[i] != -1) return mem[i];
    int result = 1;
    for(int j = 0; j < i; ++j) {
        if(a[j] < a[i]) result = max(result, lis(j) + 1);
    }
    mem[i] = result;
    return mem[i];
}

//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
            trace(j);
            break;
        }
    }
    printf("%d ", a[i]);
}

int main(){
    init();
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        }
    }
    printf("%d\n", res);
    trace(pos);
    return 0;
}