// Bài 3: Sử dụng chiến lược quy hoạch động để tính chỉnh hợp chập K của N.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; 
    cout << "Nhap n, k (n >= k): ";
    do{
        cin >> n >> k;
        if(n < k) cout << "Nhap n, k (n >= k): ";
    }while(n < k);
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));

    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= min(i, k); j++){
            dp[i][j] = i * dp[i-1][j-1];
        }
    }

    cout << dp[n][k];
    return 0;
}
