#include <bits/stdc++.h>
using namespace std;

int N, M; //size của grid map, N = Hàng, M = cột
vector<vector<int>> grid;

pair<int,int> start = {0,0}; // depot node
pair<int,int> goal;

vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}}; //vector để giả định việc chọn hướng
//xét tính hợp lệ của hướng đi
bool valid(int x, int y){ 
    return x>=0 && y>=0 && x<N && y<M && grid[x][y]==0;
}

struct Node{
    int x, y;
    int g, f; // g là chi phí hiện tại đã đi, f là tổng chi phí ước lượng

    bool operator>(const Node& other) const {
        return f > other.f;
    }
};
// hàm tính ước lượng
int heuristic(int x,int y){
    return abs(x-goal.first)+abs(y-goal.second);
}
//tính chi phí giữa hai điểm
int astar(pair<int,int> start, pair<int,int> goal) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    vector<vector<int>> gScore(N, vector<int>(M, INT_MAX));
    gScore[start.first][start.second] = 0;

    pq.push({start.first, start.second, 0, heuristic(start.first, start.second)});

    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();

        if (cur.x == goal.first && cur.y == goal.second) {
            return cur.g; // trả về COST
        }

        for (auto [dx, dy] : dirs) {
            int nx = cur.x + dx, ny = cur.y + dy;

            if (!valid(nx, ny)) continue;

            int new_g = cur.g + 1;

            if (new_g < gScore[nx][ny]) {
                gScore[nx][ny] = new_g;
                int f = new_g + abs(nx - goal.first) + abs(ny - goal.second);

                pq.push({nx, ny, new_g, f});
            }
        }
    }

    return INT_MAX; // không có đường
}
