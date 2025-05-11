#include <iostream>
#include <stack>
#include <vector>

int M;

void print(int *m, int *x, int n) {
    for (int i = 1; i <= n; ++i){
        if (x[i] == -1) std::cout << '-' << m[i];
        if (x[i] == 1) std::cout << '+' << m[i];
    }
    std::cout << "=" << M;
}

void TRY(int *m, int *x, int n, int sum, int i) {
    if(i == n + 1) {
        if(sum == M) {
            print(m, x, n);
            exit(0);
        }
        return;
    }

    x[i] = -1;
    TRY(m, x, n, sum - m[i], i + 1);

    x[i] = 0;
    TRY(m, x, n, sum, i + 1);

    x[i] = 1;
    TRY(m, x, n, sum + m[i], i + 1);
}

int main() {
    int n;
    std::cin >> n >> M;
    int m[n+1];
    int x[n+1];
    for (int i = 1; i <= n; ++i) std::cin >> m[i];

    // TRY(m, x, n, 0, 1);

    // Tuple bộ ba số nguyên
    using state = std::tuple<int, int, int>;
    // Khởi tạo stack
    std::stack<state> myStack;
    // Đẩy vào stack trạng thái ban đầu (mảng tính từ 1)
    myStack.push({0, 0, 0});
    // Duyệt stack
    while(!myStack.empty()) {
        // Lấy trạng thái trên cùng
        state top = myStack.top();
        // Lấy chỉ số i, x[i], và tổng sum
        int i = std::get<1>(top);
        x[i] = std::get<2>(top);
        int sum = std::get<0>(top);
        // Xóa trạng thái trên cùng
        myStack.pop();
        // Nếu đã thử hết các phần tử
        if(i == n + 1) {
            // Nếu tổng bằng M thì in ra
            if(sum == M) {
                print(m, x, n);
                return 0;
            }
            // Nếu không thì tiếp tục
            continue;
        }
        // Nếu chưa thử hết các phần tử thì thử 3 trường hợp
        // 1. Không chọn phần tử i
        // 2. Chọn phần tử i với dấu +
        // 3. Chọn phần tử i với dấu -
        sum += + m[i] * x[i];
        myStack.push({sum, i + 1, -1});
        myStack.push({sum, i + 1, 0});
        myStack.push({sum, i + 1, 1});
    }

    std::cout << -1;
    return 0;
}
