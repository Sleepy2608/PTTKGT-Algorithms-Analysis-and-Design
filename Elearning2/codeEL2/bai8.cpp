// Bài 8: Sử dụng chiến lược chia để trị để tìm phần tử lớn thứ k trong một mảng không sắp xếp.

//AI coded
#include <bits/stdc++.h>
using namespace std;

// Các số trong mảng không trùng nhau
int partition(vector<int>& a, int l, int r){
    int pivot = a[r];
    int i = l;
    for(int j = l; j < r; j++){
        if(a[j] > pivot){
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}

int quickSelect(vector<int>& a, int l, int r, int k){
    if(l <= r){
        int pos = partition(a, l, r);
        if(pos == k - 1) return a[pos];
        if(pos > k - 1) return quickSelect(a, l, pos - 1, k);
        return quickSelect(a, pos + 1, r, k);
    }
    return -1;
}

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

   //tạo set để tránh mảng bị trùng lặp số
    set<int> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());

    int k;
    cout << "Nhap k: ";
    cin >> k;
    
    cout << "Phan tu lon thu " << k << " trong mang la: " << quickSelect(a, 0, n - 1, k);
    return 0;
}

// Nếu muốn kết quả không tính số bị trùng:
int partition(vector<int>& a, int l, int r){
    int pivot = a[r];
    int i = l;
    for(int j = l; j < r; j++){
        if(a[j] > pivot){
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}

int quickSelect(vector<int>& a, int l, int r, int k){
    if(l <= r){
        int pos = partition(a, l, r);
        if(pos == k - 1) return a[pos];
        if(pos > k - 1) return quickSelect(a, l, pos - 1, k);
        return quickSelect(a, pos + 1, r, k);
    }
    return -1;
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
    
    cout << "Phan tu lon thu " << k << " trong mang la: " << quickSelect(a, 0, n - 1, k);
    return 0;
}
