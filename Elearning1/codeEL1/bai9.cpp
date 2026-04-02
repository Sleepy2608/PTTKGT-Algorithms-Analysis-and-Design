/* 
Bài 9: Sử dụng chiến lược quay lui thực hiện bài toán sau:
Cho một mảng các số nguyên dương phân biệt A và một giá trị B. Yêu cầu tìm tất cả các tổ hợp các số trong mảng A sao cho tổng các số trong tổ hợp có tổng bằng giá trị B. 
Các số trong mảng A có thể được sử dụng nhiều lần để tạo thành các tổ hợp.
Ví dụ: Mảng A[4] = {1, 2, 3, 4} và B = 4 thì các tổ hợp mong muốn là: {1,1,1,1}, {1,1,2}, {1,3}, {2,2}, {4}.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> A = {1,2,3,4};
vector<int> x;

void printResult() {
    cout << "{";
    for(int i = 0; i < x.size(); i++) {
        cout << x[i];
        if(i < x.size() - 1) cout << ",";
    }
    cout << "}" << endl;
}

void Try(int i, int sum, int B) {
    if(sum == B) {
        printResult();
        return;
    }

    if(sum > B) return;

    for(int j = i; j < A.size(); j++) {
        x.push_back(A[j]);

        Try(j, sum + A[j], B); // cho phép lặp

        x.pop_back(); // quay lui
    }
}

int main() {
    int B = 4;

    Try(0, 0, B);

    return 0;
}
