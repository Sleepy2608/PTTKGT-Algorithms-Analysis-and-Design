#include <bits/stdc++.h>
using namespace std;

#include "thuatToanBacktracking.h"

int main() {
    cin >> n;

    vector<pair<double,double>> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    // build distance matrix
    minEdge = 1e18;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            dista[i][j] = hypot(p[i].first - p[j].first,
                                p[i].second - p[j].second);
            if (i != j) minEdge = min(minEdge, dista[i][j]);
        }

    solve();

    cout << "Best cost: " << bestCost << endl;
    cout << "Path: ";
    for (int x : bestPath) cout << x << " ";
    cout << "0\n";

    return 0;
}
