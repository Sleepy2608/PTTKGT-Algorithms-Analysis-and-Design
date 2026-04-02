// Bài 8: Sử dụng chiến lược chia để trị để tìm phần tử lớn thứ k trong một mảng không sắp xếp.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
        cout << "Nhap n: ";
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;

        int k;
        cout << "Nhap k: ";
        cin >> k;

        sort(a.begin(), a.end());
        cout << "So lon thu " << k << " trong mang (co so trung) la: " << a[n-k] << endl;
        set<int> noDupe(a.begin(), a.end());
        cout << "So lon thu " << k << " trong mang (khong co so trung) la: " << a[noDupe.size() - k] << endl;
    return 0;
}
