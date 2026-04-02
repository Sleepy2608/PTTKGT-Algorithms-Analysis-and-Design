/*
Bài 5:
Viết chương trình sinh ngẫu nhiên một dãy các số nguyên gồm N phần tử.
Hãy tìm vị trí, giá trị của số dương đầu tiên và số nguyên tố cuối cùng trong dãy trên. Sử dụng chiến lược chia để trị.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

struct Result{
    int firstPos;
    int lastPrime;
};

Result solve(vector<int>& a, int l, int r){
    if(l == r){
        Result res;
        res.firstPos = (a[l] > 0 ? l : -1);
        res.lastPrime = (isPrime(a[l]) ? l : -1);
        return res;
    }

    int mid = (l + r) / 2;
    Result left = solve(a, l, mid);
    Result right = solve(a, mid + 1, r);

    Result res;

    if(left.firstPos != -1) res.firstPos = left.firstPos;
    else res.firstPos = right.firstPos;

    if(right.lastPrime != -1) res.lastPrime = right.lastPrime;
    else res.lastPrime = left.lastPrime;

    return res;
}

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    Result res = solve(a, 0, n - 1);

    if(res.firstPos != -1){
        cout << "So duong dau tien: " << a[res.firstPos] << " (vi tri " << res.firstPos << ")\n";
    }
    else cout << "Khong co so duong\n";

    if(res.lastPrime != -1){
        cout << "So nguyen to cuoi: " << a[res.lastPrime] << " (vi tri " << res.lastPrime << ")\n";
    }
    else cout << "Khong co so nguyen to\n";

    return 0;
}

// Coded by AI
