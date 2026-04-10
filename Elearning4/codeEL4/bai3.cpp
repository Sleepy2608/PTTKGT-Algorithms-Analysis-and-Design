/*
Bài 3:
Sử dụng giải thuật tham lam cho bài toán được mô tả như sau:
Một người cần mua gạo cho gia đình tại một cửa hàng gạo(cửa hàng đóng cửa vào ngày chủ nhật).
Bài toán có các tham số sau:
- A là số lượng gạo người đó có thể mua nhiều nhất trong 1 ngày
- B là số lượng ngày mà gia đình người đó cần gạo để dùng.
- C là số lượng gạo gia đình mỗi ngày gia đình đó cần.
Giả sử đang ở ngày thứ 2 trong tuần và cần gạo cho B ngày sắp tới.
Yêu cầu bài toán cần xác định số lượng ngày ít nhất người đó cần phải mua gạo để đáp ứng đủ cho nhu cầu gia đình.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C;
    cout << "Nhap A, B, C: ";
    cin >> A >> B >> C;
    if(A * 6 < C * 7) return -1;
    cout << "So luong ngay: " << ceil((double)(B * C) / A);
    return 0;
}
