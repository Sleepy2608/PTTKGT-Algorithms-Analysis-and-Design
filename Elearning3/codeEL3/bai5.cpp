// Bài 5: Cho 3 chuỗi A, B, C. Tìm chuỗi con chung dài nhất của 3 chuỗi trên. Sử dụng chiến lược quy hoạch động.

int main() {
    string a, b, c;
    cout << "Chuoi a: "; cin >> a;
    cout << "Chuoi b: "; cin >> b;
    cout << "Chuoi c: "; cin >> c;

    int n = a.length(), m = b.length(), l = c.length();
    int dp[101][101][101] = {};

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= l; k++){
                if(a[i-1] == b[j-1] && b[j-1] == c[k-1])
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else
                    dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
            }
        }
    }
    cout << "Ket qua: " << dp[n][m][l];
    return 0;
}

// Note: This one was coded by AI
