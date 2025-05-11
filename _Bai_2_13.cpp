#include <iostream>
#include <cstring>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

typedef std::complex<double> cd;
const double PI = acos(-1);

//# Vẫn là cái hàm fft bên _Bai_2_11.cpp y nguyên
void fft(std::vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    std::vector<cd> a0(n/2), a1(n/2);
    for (int i = 0; 2*i < n; ++i) {
        a0[i] = a[i*2];
        a1[i] = a[i*2+1];
    }

    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2*i < n; ++i) {
        a[i]     = a0[i] + w * a1[i];
        a[i+n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i]     /= 2;
            a[i+n/2] /= 2;
        }
        w *= wn;
    }
}


class BigNum {

    // ---------------------- Converter ------------------------
    // Chuyển đổi BigNum thành vector<int> và ngược lại
    static std::vector<int> toVector(const BigNum& bn) {
        int len = strlen(bn.getNum());
        std::vector<int> result(len);
        for (int i = 0; i < len; ++i)
            result[i] = bn.getNum()[len - 1 - i] - '0';
        return result;
    }

    static BigNum fromVector(const std::vector<int>& vec, char sign) {
        int len = vec.size();
        while(len > 1 && vec[len - 1] == 0)
            --len;

        char *buffer = new char[len + 1];
        for (int i = 0; i < len; ++i)
            buffer[i] = vec[len - 1 - i] + '0';
        buffer[len] = '\0';

        BigNum result;
        result.setSign(sign);
        result.setNum(buffer);
        delete[] buffer;
        return result;
    }
    
    // -------------------- Addition and Subtraction ---------------------
    //# Hàm cộng 2 vector<int> và trả về vector<int> kết quả
    std::vector<int> addVectors(const std::vector<int>& a, const std::vector<int>& b) {
        int n = std::max(a.size(), b.size());
        std::vector<int> res(n + 1, 0);
    
        for (int i = 0; i < n; ++i) {
            if (i < a.size()) res[i] += a[i];
            if (i < b.size()) res[i] += b[i];
            if (res[i] >= 10) {
                res[i] -= 10;
                res[i+1]++;
            }
        }
    
        if (res.back() == 0) res.pop_back();
        return res;
    }
    
    //# Hàm trừ 2 vector<int> và trả về vector<int> kết quả
    std::vector<int> subtractVectors(const std::vector<int>& a, const std::vector<int>& b) {
        // Assumes a >= b
        std::vector<int> res = a;
        for (int i = 0; i < b.size(); ++i) {
            res[i] -= b[i];
            if (res[i] < 0) {
                res[i] += 10;
                res[i+1]--;
            }
        }
    
        for (int i = b.size(); i < res.size(); ++i) {
            if (res[i] < 0) {
                res[i] += 10;
                res[i+1]--;
            }
        }
    
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        return res;
    }

    // -------------------- Comparison ---------------------

    //# Hàm so sánh 2 vector<int> và trả về 1 nếu a > b, -1 nếu a < b, 0 nếu a == b
    int compareVectors(const std::vector<int>& a, const std::vector<int>& b) {
        if (a.size() != b.size()) return a.size() - b.size();
        for (int i = a.size() - 1; i >= 0; --i) {
            if (a[i] != b[i]) return a[i] - b[i];
        }
        return 0;
    }
    
    
private:
    char sign;
    char *num;
public:
    BigNum() : sign('+') {
        num = new char[2];
        num[0] = '1';
        num[1] = '\0';
    }
    BigNum(const char *n) {
        if (n[0] == '0') {
            sign = '-';
            num = new char[strlen(n) + 1];
            strcpy(num, n + 1);
        } else {
            sign = '+';
            num = new char[strlen(n) + 1];
            strcpy(num, n + 1);
        }
    }

    BigNum(const BigNum& other) {
        sign = other.sign;
        if (other.num) {
            num = new char[strlen(other.num) + 1];
            strcpy(num, other.num);
        } else num = nullptr;
    }

    BigNum& operator=(const BigNum& other) {
        if (this != &other) {
            sign = other.sign;
            delete[] num;
            if (other.num) {
                num = new char[strlen(other.num) + 1];
                strcpy(num, other.num);
            } else num = nullptr;
        }
        return *this;
    }

    ~BigNum() {
        delete[] num;
    }

    friend std::istream& operator>>(std::istream& is, BigNum& bn) {
        char buffer[1000];
        is >> buffer;
        delete[] bn.num;
        if (buffer[0] == '0') {
            bn.sign = '-';
            bn.num = new char[strlen(buffer) + 1];
            strcpy(bn.num, buffer + 1);
        } else {
            bn.sign = '+';
            bn.num = new char[strlen(buffer) + 1];
            strcpy(bn.num, buffer + 1);
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const BigNum& bn) {
        if (bn.sign == '-' && !(bn.num[0] == '0' && bn.num[1] == '\0'))
            os << '-';
        os << bn.num;
        return os;
    }

    //# Hàm cộng 2 BigNum và trả về BigNum kết quả
    BigNum operator+(const BigNum& rhs) {
        std::vector<int> a = BigNum::toVector(*this);
        std::vector<int> b = BigNum::toVector(rhs);
    
        if ((*this).getSign() == rhs.getSign()) {
            std::vector<int> sum = addVectors(a, b);
            return BigNum::fromVector(sum, (*this).getSign());
        } else {
            if (compareVectors(a, b) >= 0) {
                std::vector<int> diff = subtractVectors(a, b);
                return BigNum::fromVector(diff, (*this).getSign());
            } else {
                std::vector<int> diff = subtractVectors(b, a);
                return BigNum::fromVector(diff, rhs.getSign());
            }
        }
    }

    //# Hàm trừ 2 BigNum và trả về BigNum kết quả
    BigNum operator-(const BigNum& rhs) {
        BigNum rhsNeg = rhs;
        rhsNeg.setSign(rhs.getSign() == '+' ? '-' : '+');
        return (*this) + rhsNeg;
    }
    
    // -------------------- Getters and Setters ---------------------
    void setSign(char s) {
        sign = s;
    }

    void setNum(const char *n) {
        delete[] num;
        num = new char[strlen(n) + 1];
        strcpy(num, n);
    }

    char getSign() const {
        return sign;
    }

    char* getNum() const {
        return num;
    }
};


// ------------------------- Main --------------------------
int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Khai báo 2 BigNum a và b
    BigNum a_90, b_90;
    std::cin >> a_90 >> b_90;

    BigNum c1 = "03\0";
    BigNum c2 = "14\0";

    BigNum result_90 = a_90 * b_90 + a_90 * c1 + b_90 * c2;
    
    std::cout << result_90 << '\n';

    // -- Dao Trong Nguyen - 20235390 - IT3140 - 750289 --
    return 0;
}
