/*
Bài 6:
Viết chương trình sử dụng chiến lược quy hoạch động:
Nhập vào một mảng A có N phần tử. Tìm dãy con liên tiếp có tổng lớn nhất trong mảng A.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cout << "Nhap n: ";
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> maxSum(n);
    int curSum = a[0];
    for(int i = 1; i < n; i++){
        curSum = max(a[i], a[i] + curSum);
        maxSum[i] = max(maxSum[i-1], curSum);
    }
    cout << "Ket qua : " << *max_element(maxSum.begin(), maxSum.end());

    return 0;
}
