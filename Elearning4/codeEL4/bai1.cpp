#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    long long res = 0;
    for(int i = 0; i < n; i++){
        res += 1LL * a[i] * i;
    }
    cout << "Ket qua: " << res;

    return 0;
}
