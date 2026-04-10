/*
Bài 5:
Mô tả và cài đặt bài toán đổi tiền sử dụng chiến lược tham lam và chiến lược quy hoạch động. So sánh 2 phương pháp.
*/
#include <bits/stdc++.h>
using namespace std;

// Greedy
int greedy(vector<int> c, int S){
    sort(c.rbegin(), c.rend());
    int cnt = 0;
    for(int coin : c){
        cnt += S / coin;
        S %= coin;
    }
    return (S == 0) ? cnt : -1;
}

// DP
int dp(vector<int>& c, int S){
    vector<int> dp(S+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1;i <= S; i++){
        for(int coin : c){
            if(i >= coin && dp[i-coin] != INT_MAX)
                dp[i] = min(dp[i], dp[i-coin] + 1);
        }
    }
    if(dp[S] == INT_MAX) return -1;
    return dp[S];
}

int main(){
    vector<int> c = {3, 5, 7};
    cout << "Greedy: " << greedy(c, 13) << endl;
    cout << "DP: " << dp(c, 13);
}
