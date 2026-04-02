/*
Bài 7:
Viết chương trình nhập vào 1 mảng số nguyên và một số nguyên k, hãy đếm xem có bao nhiêu số bằng k. 
Nhập tiếp 2 số x và y (x<y) và đếm có bao nhiêu số lớn hơn x và nhỏ hơn y. Sử dụng chiến lược chia để trị.
*/

#include <bits/stdc++.h>
using namespace std;

int countK(vector<int>& a, int l, int r, int k){
    if(l == r) return (a[l] == k);
    int mid = (l + r) / 2;
    return countK(a, l, mid, k) + countK(a, mid + 1, r, k);
}

int countRange(vector<int>& a, int l, int r, int x, int y){
    if(l == r) return (a[l] > x && a[l] < y);
    int mid = (l + r) / 2;
    return countRange(a, l, mid, x, y) + countRange(a, mid + 1, r, x, y);
}

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    int k;
    cout << "Nhap k: ";
    cin >> k;
    cout << "Co " << countK(a, 0, n - 1, k) << " so nguyen bang " << k << endl;

    int x, y;
    cout << "Nhap x, y: ";
    cin >> x >> y;
    cout << "Co " << countRange(a, 0, n - 1, x, y) << " so lon hon " << x << " va be hon " << y << endl;

    return 0;
}
