// Bài 8: Liệt kê các xâu nhị phân có độ dài là 5 và không có 2 bit 0 đứng liền nhau. Sử dụng chiến lược quay lui.

#include <iostream>
#include <vector>
using namespace std;

vector<int> x;

void printResult(int n){
    for(int i = 0; i < n; i++){
        cout << x[i];
    }
    cout << endl;
}

void Try(int i, int n){
    for(int j = 0; j <= 1; j++){
        if(i == 0 || !(x[i-1] == 0 && j == 0)){ // không cho 00
            x[i] = j;
            if(i == n - 1) printResult(n);
            else Try(i + 1, n);
        }
    }
}

int main(){
    int n = 5;
    x.resize(n);

    Try(0, n);
    return 0;
}
