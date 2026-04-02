// Bài 4: Sử dụng chiến lược chia để trị để tính giá trị trung bình của một dãy số nguyên.

#include <bits/stdc++.h>
using namespace std;

long long sum(vector<int>& a, int l, int r){
    if(l == r) return a[l];
    int mid = (l + r) / 2;
    return sum(a, l, mid) + sum(a, mid + 1, r);
}

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    double avg = (double)sum(a, 0, n - 1) / n;
    cout << "Ket qua: " << avg;
    return 0;
}
