#include <bits/stdc++.h>
using namespace std;

#include "algorithms/ClarkeWright.h"
#include "models/customer.h"
#include "models/route.h"
#include "service/DistanceService.h"
#include "C:\University Coding Project\Giao hàng shipper - PTTKGT Project\clarkeWrightSavings\algorithms\Astar.cpp"

int main() {
    int n;
    cin >> n;

    // ===== INPUT =====
    vector<pair<int,int>> pts;

    int dx, dy;
    cin >> dx >> dy; // depot
    pts.push_back({dx, dy});

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pts.push_back({x, y});
    }

    // ===== DISTANCE SERVICE =====
    DistanceService ds(pts);
    ds.precomputeAll();

    // ===== BUILD CUSTOMERS =====
    vector<Customer> customers;
    for (int i = 1; i <= n; i++) {
        customers.emplace_back(i, pts[i].first, pts[i].second, 0);
    }

    Customer depot(0, dx, dy, 0);

    // ===== RUN CLARKE =====
    ClarkeWright cw(customers, depot, 0, ds);

    vector<Route> routes = cw.solve();

    // ===== OUTPUT =====
    cout << "So shipper: " << routes.size() << "\n\n";

    int id = 1;
    for (auto &r : routes) {
        cout << "Shipper " << id++ << ": Kho";

        for (auto &c : r.getCustomers()) {
            cout << " -> Diem " << c.getId();
        }

        cout << "\n";
    }

    return 0;
}
