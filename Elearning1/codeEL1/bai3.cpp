// Bài 3: Viết chương trình sử dụng đệ quy tính tổng các chữ số của một số nguyên dương N. 

#include <iostream>
using namespace std;

int sumDigits(int n){
    if (n == 0) return 0;
    int last = n % 10;
    return (last + sumDigits(n / 10));
}

int main(){
    int n;
    cout << "Nhap N: ";
    cin >> n;

    cout << "Tong cac chu so = " << sumDigits(n);
    return 0;
}
