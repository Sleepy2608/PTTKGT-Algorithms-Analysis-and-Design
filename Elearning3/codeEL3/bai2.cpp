/*
Bài 2:
Viết chương trình sử dụng chiến lược quy hoạch động:
Nhập vào một mảng A có N phần tử. Tính tổng lớn nhất của dãy con trong mảng biết rằng dãy con này không được có 2 phần tử liền kề nhau.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cout << "Nhap n: ";
    cin >> n;
    vector<int> a(n), dp(n);
    for(int &x : a) cin >> x;

    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);

    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + a[i]);
    }

    cout << "Ket qua: " << dp[n-1];
    return 0;
}
