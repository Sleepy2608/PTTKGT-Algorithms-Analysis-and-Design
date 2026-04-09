#ifndef THUAT_TOAN_BACKTRACKING_H
#define THUAT_TOAN_BACKTRACKING_H

#include <bits/stdc++.h>
using namespace std;

// Khai báo biến toàn cục
extern int n;
extern double dista[20][20];
extern bool visited[20];

extern double bestCost;
extern double currentCost;
extern double minEdge;

extern vector<int> bestPath;
extern vector<int> path;

// Hàm chính
void solve();

#endif
