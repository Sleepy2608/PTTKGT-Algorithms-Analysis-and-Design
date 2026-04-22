#include "DistanceService.h"

// ===== Constructor =====
DistanceService::DistanceService(const vector<pair<int,int>>& pts) {
    points = pts;
    int n = pts.size();
    distCache.assign(n, vector<int>(n, -1));
}

// ===== Get Distance (with cache) =====
int DistanceService::getDist(int i, int j) {
    if (distCache[i][j] != -1)
        return distCache[i][j];

    int d = astar(points[i], points[j]);

    distCache[i][j] = d;
    distCache[j][i] = d;

    return d;
}

// ===== Precompute =====
void DistanceService::precomputeAll() {
    int n = points.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (distCache[i][j] == -1) {
                int d = astar(points[i], points[j]);
                distCache[i][j] = d;
                distCache[j][i] = d;
            }
        }
    }
}

// ===== Reset Cache =====
void DistanceService::resetCache() {
    int n = points.size();
    distCache.assign(n, vector<int>(n, -1));
}
