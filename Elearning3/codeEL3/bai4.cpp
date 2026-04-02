/*
Bài 4:
Viết chương trình sử dụng chiến lược quy hoạch động:
Nhập vào 2 chuỗi ký tự str1 và str2. Tìm chuỗi ký tự con chung dài nhất của 2 chuỗi này (các phần tử có thể liên tiếp nhau hoặc không).
Ví dụ: str1= “ABCDEF”, str2 = “AXBCYDGH” → chuỗi con chung dài nhất là ABCD có độ dài là 4.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cout << "Nhap chuoi a, b: ";
    cin >> a >> b;

    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m];
    return 0;
}
