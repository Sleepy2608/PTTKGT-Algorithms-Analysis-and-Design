#ifndef DISTANCE_SERVICE_H
#define DISTANCE_SERVICE_H

#include <vector>
#include <utility>
using namespace std;

// Khai báo A*
int astar(pair<int,int> start, pair<int,int> goal);

class DistanceService {
private:
    vector<pair<int,int>> points;
    vector<vector<int>> distCache;

public:
    // Constructor
    DistanceService(const vector<pair<int,int>>& pts);

    // Lấy khoảng cách (có cache)
    int getDist(int i, int j);

    // Precompute toàn bộ
    void precomputeAll();

    // Reset cache
    void resetCache();
};

#endif