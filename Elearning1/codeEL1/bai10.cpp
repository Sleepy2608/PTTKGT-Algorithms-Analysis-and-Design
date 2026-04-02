/* 
Bài 10: Sử dụng chiến lược quay lui thực hiện bài toán điền các toán tử vào biểu thức. 
Biết rằng một toán tử có thể điền được nhiều lần trong biểu thức và các toán hạng có thể đổi chỗ để đạt được yêu cầu bài toán (nếu không đạt được yêu cầu bài toán sẽ thông báo là không được).
Ví dụ:
Ta có biểu thức: 1 (x1) 2 (x2) 3 (x3) 4 = 1 với x1, x2, x3 là các toán tử + - * / thì kết quả mong muốn là (x1) là *, (x2) là +, (x3) là –
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> nums = {1,2,3,4};
vector<int> perm;
vector<bool> used(4, false);

char op[] = {'+', '-', '*', '/'};

// tính biểu thức
double calc(double a, double b, char op) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    if(op == '/') {
        if(b == 0) return 1e9; // tránh chia 0
        return a / b;
    }
    return 0;
}

// thử các toán tử
void TryOperators(vector<int>& p) {
    for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
    for(int k = 0; k < 4; k++) {

        double res = calc(
                        calc(
                            calc(p[0], p[1], op[i]),
                            p[2], op[j]
                        ),
                        p[3], op[k]
                    );

        if(abs(res - 1.0) < 1e-6) {
            cout << p[0] << " " << op[i] << " "
                 << p[1] << " " << op[j] << " "
                 << p[2] << " " << op[k] << " "
                 << p[3] << " = 1" << endl;
        }
    }
}

// quay lui hoán vị
void TryPerm(int i) {
    for(int j = 0; j < 4; j++) {
        if(!used[j]) {
            used[j] = true;
            perm.push_back(nums[j]);

            if(i == 3)
                TryOperators(perm);
            else
                TryPerm(i + 1);

            perm.pop_back();     // quay lui
            used[j] = false;
        }
    }
}

int main() {
    TryPerm(0);
    return 0;
}
