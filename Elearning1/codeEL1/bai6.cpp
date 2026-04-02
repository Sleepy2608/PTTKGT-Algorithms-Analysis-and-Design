// Bài 6: Cho tập hợp gồm N phần tử khác nhau, hãy tìm tất cả các tập con gồm K phần tử của tập này. Mỗi tập con gồm K phần tử.

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

void printResult(int& K){
    cout << "{";
    for(int i = 1; i <= K; i++){
        cout << arr[i];
        if(i < K) cout << ",";
    }
    cout << "}" << endl;
}

void Try(int i, int& N, int& K){
    for(int j = arr[i-1] + 1; j <= N - K + i; j++){
        arr[i] = j;
        if(i == K) printResult(K);
        else Try(i + 1, N, K);
    }
}

int main(){
    int N, K;
    cout << "Nhap N va K: ";
    cin >> N >> K;

    arr.resize(N); // resize lại vector để có thể truy cập vào từng phần tử trong mảng
    arr[0] = 0;

    cout << "Ket qua:\n";
    Try(1, N, K);

    return 0;
}
