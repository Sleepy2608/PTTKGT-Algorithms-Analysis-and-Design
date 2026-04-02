//Bài 1: Viết chương trình sử dụng đệ quy chuyển đổi 1 số từ hệ thập phân sang hệ nhị phân.

#include <iostream>
using namespace std;

void decimalToBinary(int n){
    if (n == 0) return;

    decimalToBinary(n / 2);
    cout << n % 2;   
}

int main(){
    int n;
    cout << "Nhap so thap phan: ";
    cin >> n;
    cout << "Ket qua: ";
    if (n == 0) cout << 0;
    else decimalToBinary(n);
    return 0;
}
