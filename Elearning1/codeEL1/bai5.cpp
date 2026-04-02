// Bài 5: Mô tả các bước di chuyển đĩa từ cột nguồn đến cột đích cho bài toán tháp Hà Nội với số đĩa là 5.

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char A, char B, char C){
    if(n == 1){
        cout << "Chuyen dia 1 tu " << A << " sang " << C << endl;
        return;
    }

    towerOfHanoi(n - 1, A, C, B);
    cout << "Chuyen dia " << n << " tu " << A << " sang " << C << endl;
    towerOfHanoi(n - 1, B, A, C);
}

int main(){
    int n = 5;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
