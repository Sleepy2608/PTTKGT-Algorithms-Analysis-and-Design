// Bài 6: Sử dụng chiến lược chia để trị kết hợp đệ quy để viết chương trình tính giá trị biểu thức an

#include <iostream>
using namespace std;

long long a, n;

long long power(long long a, long long n){
    if(n == 0) return 1;
    long long half = power(a, n / 2);
    if(n % 2 == 0) return half * half;
    return a * half * half;
}

int main(){
    cout << "Nhap a, n: ";
    cin >> a >> n;
    cout << "Ket qua: " << power(a, n);
    return 0;
}
