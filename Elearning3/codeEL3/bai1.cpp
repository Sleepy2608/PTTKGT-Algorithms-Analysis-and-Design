/* 
Bài 1:
Viết chương trình sử dụng chiến lược quy hoạch động:
Nhập vào một mảng A có N phần tử. Tìm dãy con tăng dài nhất (có thể liên tiếp hoặc không) trong mảng A.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    vector<int> a(n), dp(n, 1);
    for(int &x : a) cin >> x;

    int res = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    cout << "Ket qua: " << res;
    return 0;
}
