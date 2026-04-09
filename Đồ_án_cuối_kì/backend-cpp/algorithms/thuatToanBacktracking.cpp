#include "thuatToanBacktracking.h"

int n;
double dista[20][20];
bool visited[20];

double bestCost;
double currentCost;
double minEdge;

vector<int> bestPath;
vector<int> path;

// Hàm backtracking (DFS + Branch & Bound)
void backtrack(int u, int count) {
    if (count == n) {
        double total = currentCost + dista[u][0];
        if (total < bestCost) {
            bestCost = total;
            bestPath = path;
        }
        return;
    }

    for (int v = 1; v < n; v++) {
        if (!visited[v]) {

            double temp = currentCost + dista[u][v];

            // Branch & Bound
            double bound = temp + (n - count) * minEdge;
            if (bound >= bestCost) continue;

            visited[v] = true;
            path.push_back(v);
            currentCost += dista[u][v];

            backtrack(v, count + 1);

            // quay lui
            visited[v] = false;
            path.pop_back();
            currentCost -= dista[u][v];
        }
    }
}

// Hàm solve chính
void solve() {
    memset(visited, false, sizeof(visited));

    bestCost = 1e18;
    currentCost = 0;
    path.clear();
    bestPath.clear();

    visited[0] = true;
    path.push_back(0);

    backtrack(0, 1);
}
