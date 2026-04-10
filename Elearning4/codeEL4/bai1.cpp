// Bài 1: Cho mảng A có n phần tử. Hãy bố trí lại thứ tự các phần tử trong mảng A sao tổng lớn nhất của A[i]*i là lớn nhất. 
// Cài đặt và giải thích việc áp dụng chiến lược tham lam vào bài toán.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    long long res = 0;
    for(int i = 0; i < n; i++){
        res += 1LL * a[i] * i;
    }
    cout << "Ket qua: " << res;

    return 0;
}
