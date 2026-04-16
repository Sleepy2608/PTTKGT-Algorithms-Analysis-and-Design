#include <bits/stdc++.h>
using namespace std;

#include "algorithms/ClarkeWright.h"
#include "models/customer.h"
#include "models/route.h"
#include "service/DistanceService.h"
#include "C:\University Coding Project\Giao hàng shipper - PTTKGT Project\clarkeWrightSavings\algorithms\Astar.cpp"

const int N = 41;

// ================= GRID =================
int grid[N][N];
pair<int,int> startP = {1,1};
pair<int,int> endP = {N-2,N-2};

// ================= RANDOM =================
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// ================= MAZE DFS =================
int dx4[4] = {2,-2,0,0};
int dy4[4] = {0,0,2,-2};

void carve(int x,int y){
    vector<int> dirs = {0,1,2,3};
    shuffle(dirs.begin(), dirs.end(), rng);

    for(int i:dirs){
        int nx = x + dx4[i];
        int ny = y + dy4[i];

        if(nx>0 && ny>0 && nx<N-1 && ny<N-1 && grid[nx][ny]){
            grid[nx][ny] = 0;
            grid[x + dx4[i]/2][y + dy4[i]/2] = 0;
            carve(nx,ny);
        }
    }
}

void generateMaze(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            grid[i][j] = 1;

    grid[1][1] = 0;
    carve(1,1);
}

// ================= BFS DIST =================
int bfsDist(pair<int,int> a, pair<int,int> b){
    queue<pair<int,int>> q;
    vector<vector<int>> dist(N, vector<int>(N,-1));

    q.push(a);
    dist[a.first][a.second]=0;

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    while(!q.empty()){
        auto [x,y]=q.front(); q.pop();

        if(x==b.first && y==b.second)
            return dist[x][y];

        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<N&&ny<N && grid[nx][ny]==0 && dist[nx][ny]==-1){
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    return 1e9;
}

// ================= A* =================
struct Node{
    int x,y,g,f;
    bool operator>(const Node& other) const{
        return f > other.f;
    }
};

int heuristic(int x,int y){
    return abs(x-endP.first)+abs(y-endP.second);
}

vector<pair<int,int>> astar(){
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    map<pair<int,int>, pair<int,int>> parent;
    vector<vector<bool>> vis(N, vector<bool>(N,false));

    pq.push({startP.first,startP.second,0,heuristic(startP.first,startP.second)});

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();

        if(vis[cur.x][cur.y]) continue;
        vis[cur.x][cur.y]=true;

        if(cur.x==endP.first && cur.y==endP.second) break;

        for(int i=0;i<4;i++){
            int nx=cur.x+dx[i], ny=cur.y+dy[i];
            if(nx>=0&&ny>=0&&nx<N&&ny<N && !grid[nx][ny] && !vis[nx][ny]){
                parent[{nx,ny}] = {cur.x,cur.y};
                int g = cur.g + 1;
                int f = g + heuristic(nx,ny);
                pq.push({nx,ny,g,f});
            }
        }
    }

    vector<pair<int,int>> path;
    pair<int,int> cur = endP;

    while(cur != startP){
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(startP);
    reverse(path.begin(), path.end());
    return path;
}

// ================= VRP (Clarke-Wright) =================
vector<vector<pair<int,int>>> solveVRP(vector<pair<int,int>> customers){

    int n = customers.size();

    vector<int> distDepot(n);
    for(int i=0;i<n;i++)
        distDepot[i] = bfsDist(startP, customers[i]);

    vector<vector<int>> dist(n, vector<int>(n,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j)
                dist[i][j] = bfsDist(customers[i], customers[j]);

    struct Save{int i,j,s;};
    vector<Save> savings;

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            savings.push_back({i,j,distDepot[i]+distDepot[j]-dist[i][j]});

    sort(savings.begin(), savings.end(), [](auto &a, auto &b){
        return a.s > b.s;
    });

    vector<vector<int>> routes;
    for(int i=0;i<n;i++) routes.push_back({i});

    auto findRoute=[&](int x){
        for(auto &r:routes)
            if(find(r.begin(), r.end(), x)!=r.end())
                return &r;
        return (vector<int>*)nullptr;
    };

    for(auto &sv:savings){
        auto r1 = findRoute(sv.i);
        auto r2 = findRoute(sv.j);

        if(!r1 || !r2 || r1==r2) continue;

        if(r1->back()==sv.i && r2->front()==sv.j){
            r1->insert(r1->end(), r2->begin(), r2->end());
            routes.erase(remove(routes.begin(), routes.end(), *r2), routes.end());
        }
    }

    vector<vector<pair<int,int>>> res;
    for(auto &r:routes){
        vector<pair<int,int>> tmp;
        for(int i:r) tmp.push_back(customers[i]);
        res.push_back(tmp);
    }

    return res;
}

// ================= MAIN =================
int main(){
    generateMaze();

    // ===== sample customers =====
    vector<pair<int,int>> customers = {
        {5,5},{10,15},{20,20},{30,10}
    };

    // ===== A* test =====
    auto path = astar();
    cout << "A* path length: " << path.size() << "\n";

    // ===== VRP =====
    auto routes = solveVRP(customers);

    cout << "\nSo shipper: " << routes.size() << "\n";

    int id=1;
    for(auto &r:routes){
        cout << "Shipper " << id++ << ": Kho";
        for(auto &p:r){
            cout << " -> ("<<p.first<<","<<p.second<<")";
        }
        cout << "\n";
    }

    return 0;
}
