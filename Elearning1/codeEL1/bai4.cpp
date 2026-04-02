// Bài 4: Viết chương trình sử dụng đệ quy để kiểm tra một mảng 1 chiều có đối xứng hay không.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(vector<int> &a, int left, int right){
    if(left >= right) return true;
    if(a[left] != a[right]) return false;

    return isPalindrome(a, left + 1, right - 1);
}

int main(){
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    vector<int> a(n);

    cout << "Nhap mang:\n";
    for(int i = 0; i < n; i++) cin >> a[i];

    if(isPalindrome(a, 0, n - 1)) cout << "Mang doi xung";
    else cout << "Mang khong doi xung";

    return 0;
}
