// Bài 3: Tìm giá trị nhỏ nhất của một mảng A gồm n số nguyên sử dụng chiến lược chia để trị.

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& arr, int l, int r){
    if(l == r) return arr[l];
    int mid = (l + r) / 2;
    return min(findMin(arr, l, mid), findMin(arr, mid + 1, r));
}

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;

    cout << "So nho nhat la: " << findMin(arr, 0, n - 1);
    return 0;
}
