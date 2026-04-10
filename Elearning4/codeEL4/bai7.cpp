// Bài 7: Mô tả và cài đặt bài toán người du lịch (TSP) sử dụng chiến lược tham lam và chiến lược quay lui nhánh và cận. So sánh 2 phương pháp.
#include <bits/stdc++.h>
using namespace std;

int n = 4;
int cost[4][4] = {
    {0,10,15,20},
    {10,0,35,25},
    {15,35,0,30},
    {20,25,30,0}
};

int visited[20], best = INT_MAX;

void Try(int u, int cnt, int sum){
    if(cnt == n){
        best = min(best, sum + cost[u][0]);
        return;
    }
    for(int v=0;v<n;v++){
        if(!visited[v]){
            visited[v]=1;
            Try(v, cnt+1, sum+cost[u][v]);
            visited[v]=0;
        }
    }
}

int main(){
    visited[0]=1;
    Try(0,1,0);
    cout << best;
}
