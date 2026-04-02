// Viết chương trình sử dụng đệ quy thực hiện in ngược một dòng ký tự cho trước. Ví dụ cho dòng “ABCDEF” thì in ra “FEDCBA” 

#include <iostream>
#include <string>
using namespace std;

void reverseString(string s, int i){
    if(i == s.length()) return;
    reverseString(s, i + 1);
    cout << s[i]; 
}

int main(){
    string s;
    cout << "Nhap chuoi: ";
    getline(cin, s);
    cout << "Ket qua: ";
    reverseString(s, 0);
    return 0;
}
