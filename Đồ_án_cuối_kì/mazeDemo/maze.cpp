#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> grid;

pair<int,int> start = {0,0};
pair<int,int> goal;

vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

bool valid(int x, int y){
    return x>=0 && y>=0 && x<N && y<M && grid[x][y]==0;
}

// BFS 
vector<pair<int,int>> bfs(){
    vector<vector<bool>> visited(N, vector<bool>(M,false));
    map<pair<int,int>, pair<int,int>> parent;

    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();

        if(x==goal.first && y==goal.second) break;

        for(auto [dx,dy]:dirs){
            int nx=x+dx, ny=y+dy;
            if(valid(nx,ny) && !visited[nx][ny]){
                visited[nx][ny]=true;
                parent[{nx,ny}]={x,y};
                q.push({nx,ny});
            }
        }
    }

    vector<pair<int,int>> path;
    pair<int,int> cur = goal;

    while(cur!=start){
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(start);

    reverse(path.begin(), path.end());
    return path;
}

// DFS 
vector<pair<int,int>> pathDFS;
bool found = false;

void dfsUtil(int x,int y, vector<vector<bool>>& visited){
    if(found) return;

    visited[x][y]=true;
    pathDFS.push_back({x,y});

    if(x==goal.first && y==goal.second){
        found=true;
        return;
    }

    for(auto [dx,dy]:dirs){
        int nx=x+dx, ny=y+dy;
        if(valid(nx,ny) && !visited[nx][ny]){
            dfsUtil(nx,ny,visited);
        }
    }

    if(!found) pathDFS.pop_back();
}

vector<pair<int,int>> dfs(){
    vector<vector<bool>> visited(N, vector<bool>(M,false));
    pathDFS.clear();
    found=false;

    dfsUtil(start.first, start.second, visited);
    return pathDFS;
}

// A* 
struct Node{
    int x, y;
    int g, f;

    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

int heuristic(int x,int y){
    return abs(x-goal.first)+abs(y-goal.second);
}

vector<pair<int,int>> astar(){
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    map<pair<int,int>, pair<int,int>> parent;
    vector<vector<bool>> visited(N, vector<bool>(M,false));

    pq.push({start.first, start.second, 0, heuristic(start.first,start.second)});

    while(!pq.empty()){
        Node cur = pq.top(); pq.pop();

        if(visited[cur.x][cur.y]) continue;
        visited[cur.x][cur.y]=true;

        if(cur.x==goal.first && cur.y==goal.second) break;

        for(auto [dx,dy]:dirs){
            int nx=cur.x+dx, ny=cur.y+dy;

            if(valid(nx,ny) && !visited[nx][ny]){
                parent[{nx,ny}]={cur.x,cur.y};

                int g = cur.g+1;
                int f = g + heuristic(nx,ny);

                pq.push({nx, ny, g, f});
            }
        }
    }

    vector<pair<int,int>> path;
    pair<int,int> cur = goal;

    while(cur!=start){
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(start);

    reverse(path.begin(), path.end());
    return path;
}

int main(){
    cin >> N >> M;
    grid.resize(N, vector<int>(M));

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> grid[i][j];
        }
    }

    goal = {N-1, M-1};

    string type;
    cin >> type; // bfs / dfs / astar

    vector<pair<int,int>> path;

    if(type=="bfs") path = bfs();
    else if(type=="dfs") path = dfs();
    else path = astar();

    cout << "Path:\n";
    for(auto [x,y]:path){
        cout << x << " " << y << "\n";
    }

    return 0;
}
