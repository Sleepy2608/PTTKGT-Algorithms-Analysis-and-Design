// Bài 7: Sử dụng chiến lược quay lui cho bài toán in ra tất cả hoán vị của N phần tử.

#include <iostream>
#include <vector>
using namespace std;

vector<int> x;
vector<bool> used;

void printResult(int N){
    for(int i = 1; i <= N; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Try(int i, int N){
    for(int j = 1; j <= N; j++){
        if(!used[j]){
            x[i] = j;
            used[j] = true;

            if(i == N) printResult(N);
            else Try(i + 1, N);
            used[j] = false; // quay lui
        }
    }
}

int main(){
    int N;
    cout << "Nhap N: ";
    cin >> N;

    x.resize(N + 1); // resize lại vector để có thể truy cập vào từng phần tử trong mảng
    used.resize(N + 1, false); // resize lại vector lưu các hoán vị đã dùng

    Try(1, N);
    return 0;
}
