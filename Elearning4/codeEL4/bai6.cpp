// Bài 6: Mô tả và cài đặt bài toán xếp ba lô (Knapsack) sử dụng chiến lược tham lam, chiến lược quy hoạch động và chiến lược quay lui nhánh cận. So sánh các phương pháp.
#include <bits/stdc++.h>
using namespace std;

//greedy
struct Item {
    int wt, val;
};

bool cmp(Item a, Item b){
    return (double)a.val / a.wt > (double)b.val / b.wt;
}

double greedyKnapsack(int W, vector<Item> a){
    sort(a.begin(), a.end(), cmp);
    double total = 0;

    for(auto x : a){
        if(W >= x.wt){
            total += x.val;
            W -= x.wt;
        } else {
            total += x.val * ((double)W / x.wt);
            break;
        }
    }
    return total;
}

// dp
int knapsackDP(int W, vector<int>& wt, vector<int>& val){
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(wt[i-1] <= w){
                dp[i][w] = max(dp[i-1][w],
                               val[i-1] + dp[i-1][w - wt[i-1]]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

// backtracking
int best = 0;

void Try(int i, int curW, int curVal, int W,
         vector<int>& wt, vector<int>& val){
    if(i == wt.size()){
        best = max(best, curVal);
        return;
    }

    // Không chọn
    Try(i+1, curW, curVal, W, wt, val);

    // Chọn
    if(curW + wt[i] <= W){
        Try(i+1, curW + wt[i], curVal + val[i], W, wt, val);
    }
}

int main(){
    int W = 50;
    vector<int> wt = {10,20,30};
    vector<int> val = {60,100,120};

    vector<Item> items;
    for(int i = 0; i < wt.size(); i++){
        items.push_back({wt[i], val[i]});
    }

    cout << "Greedy (fractional): " << greedyKnapsack(W, items) << endl;
    cout << "DP (Bai toan 0/1): " << knapsackDP(W, wt, val) << endl;
    best = 0;
    Try(0, 0, 0, W, wt, val);
    cout << "Backtracking: " << best << endl;

    return 0;
}
