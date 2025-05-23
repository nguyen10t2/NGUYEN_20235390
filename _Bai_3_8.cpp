#include <iostream>
#include <stack>
#include <vector>

int M_90;

void print(int *m_90, int *x_90, int n_90) {
    for (int i_90 = 1; i_90 <= n_90; ++i_90) {
        if (x_90[i_90] == -1) std::cout << '-' << m_90[i_90];
        if (x_90[i_90] == 1)  std::cout << '+' << m_90[i_90];
    }
    std::cout << "=" << M_90;
}
//# Đệ quy quay lui
void TRY(int *m_90, int *x_90, int n_90, int sum_90, int i_90) {
    if (i_90 == n_90 + 1) {
        if (sum_90 == M_90) {
            print(m_90, x_90, n_90);
            exit(0);
        }
        return;
    }

    x_90[i_90] = -1;
    TRY(m_90, x_90, n_90, sum_90 - m_90[i_90], i_90 + 1);

    x_90[i_90] = 0;
    TRY(m_90, x_90, n_90, sum_90, i_90 + 1);

    x_90[i_90] = 1;
    TRY(m_90, x_90, n_90, sum_90 + m_90[i_90], i_90 + 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n_90;
    std::cin >> n_90 >> M_90;
    int m_90[n_90+1];
    int x_90[n_90+1];
    for (int i_90 = 1; i_90 <= n_90; ++i_90)
        std::cin >> m_90[i_90];

    // Sử dụng tuple để lưu trữ trạng thái
    using state_90 = std::tuple<int, int, int>;
    // Sử dụng stack để thay thế đệ quy
    std::stack<state_90> myStack_90;
    myStack_90.push({0, 0, 0}); // {sum, index, sign}

    while (!myStack_90.empty()) {
        // Lấy trạng thái trên cùng
        state_90 top_90 = myStack_90.top();
        myStack_90.pop();
        // gán giá trị cho x[i] như trong thuật toán đệ quy
        int i_90   = std::get<1>(top_90);
        x_90[i_90] = std::get<2>(top_90);
        int sum_90 = std::get<0>(top_90) + m_90[i_90] * x_90[i_90];
        // Nếu đã thử hết các phần tử
        if (i_90 == n_90 + 1) {
            if (sum_90 == M_90) {
                print(m_90, x_90, n_90);
                return 0;
            }
            continue;
        }

        // Thử thêm các trạng thái vào stack
        // 1. +m[i],
        // 2. 0
        // 3. -m[i]
        myStack_90.push({sum_90, i_90 + 1, -1});
        myStack_90.push({sum_90, i_90 + 1, 1});
    }

    std::cout << -1;
    return 0;
}
