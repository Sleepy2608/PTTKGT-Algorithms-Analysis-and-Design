/*
Bài 4:
Cho chuỗi ký tự S gồm các ký tự in hoa. Sử dụng chiến lược tham lam để kiểm tra xem có thể sắp xếp lại các ký tự trong chuỗi S để 2 ký tự liền kề nhau không giống nhau hay không.
Ví dụ:
- Chuỗi S = AAABBC thì có thể sắp lại chuỗi S theo yêu cầu.
- Chuỗi S = AAAABB thì không thể sắp lại chuỗi S theo yêu cầu.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout << "Nhap chuoi: ";
    cin >> s;

    unordered_map<char, int> mp;
    for(char c : s) mp[c]++;
    
    int maxFreq = INT_MIN;
    for(auto &[key, freq] : mp){
        maxFreq = max(maxFreq, freq);
    }
    
    if(maxFreq <= (s.length() + 1) / 2) cout << "Co the sap xep chuoi S" << endl;
    else cout << "Khong the sap xep chuoi S" << endl;
    return 0;
}
