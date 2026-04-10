/*
Bài 2:
Cho mảng A gồm các số từ 0 đến 9. Hãy tìm tổng nhỏ nhất của 2 số được tạo từ các số trong mảng A (khi tạo số cần sử dụng tất cả các phần tử trong mảng A).
Ví dụ: Ta có mảng A = {2,1,4,3,5} thì 2 số nhỏ nhất được tạo từ các phần tử trong mảng A là 24 và 135 nên tổng sẽ là 159.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cout << "Nhap n: ";
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    long long n1 = 0, n2 = 0;
    for(int i = 0; i < a.size(); i++){
        if(i % 2 == 0) n1 = n1 * 10 + a[i];
        else n2 = n2 * 10 + a[i];
    }
    cout << "Ket qua: " << n1 + n2;
    return 0;
}
