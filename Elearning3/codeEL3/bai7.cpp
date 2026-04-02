/*
Bài 7:
Sử dụng chiến lược quy hoạch động đề giải quyết bài toán chia kẹo sau:
Giả sử có n gói kẹo, mỗi gói kẹo có m viên kẹo. Hãy chia thành 2 phần sao cho số lượng kẹo của 2 phần chênh lệch ít nhất và không phải xé các gói kẹo.
Ví dụ: Có 5 gói kẹo với số lượng kẹo tương ứng là gói 1: 2 viên, gói 2: 5 viên, gói 3: 4 viên, gói 4: 3 viên, gói 5: 15 viên.
Kết quả 2 phần sẽ là: phần1 gồm gói 1,2,3,4(14 viên), phần 2: gói 5 (15 viên)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cout << "Nhap n: ";
    cin >> n;
    vector<int> a(n);
    int sum = 0;

    for(int &x : a){
        cin >> x;
        sum += x;
    }

    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for(int x : a){
        for(int j = target; j >= x; j--){
            dp[j] = dp[j] || dp[j - x]; // có thể tạo ra tổng j hay không?
        }
    }

    int best = 0;
    for(int j = target; j >= 0; j--){
        if(dp[j]){
            best = j;
            break;
        }
    }

    cout << "Phan 1: " << best << endl;
    cout << "Phan 2: " << sum - best << endl;
}

// Note: This one was coded by AI
