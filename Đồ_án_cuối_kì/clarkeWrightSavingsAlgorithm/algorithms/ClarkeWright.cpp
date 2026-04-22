#include "ClarkeWright.h"
#include <algorithm>

// ===== Constructor =====
ClarkeWright::ClarkeWright(const std::vector<Customer>& customers,
                           const Customer& depot,
                           int capacity = 0,
                           DistanceService& ds)
    : customers(customers), depot(depot), capacity(capacity), distService(ds) {}

// ===== Comparator =====
bool ClarkeWright::cmpSaving(const Saving& a, const Saving& b) {
    return a.val > b.val;
}

// ===== Solve =====
std::vector<Route> ClarkeWright::solve() {
    int n = customers.size();

    // ===== Step 1: mỗi customer là 1 route =====
    std::vector<Route> routes(n);

    for (int i = 0; i < n; i++) {
        routes[i].addCustomer(customers[i]);
    }

    // ===== Step 2: compute savings =====
    std::vector<Saving> savings;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            double s = distService.getDist(0, i+1)
                     + distService.getDist(0, j+1)
                     - distService.getDist(i+1, j+1);

            savings.push_back({i, j, s});
        }
    }

    std::sort(savings.begin(), savings.end(), cmpSaving);

    // ===== Step 3: merge =====
    for (auto &s : savings) {
    int i = s.i;
    int j = s.j;

    Route* ri = nullptr;
    Route* rj = nullptr;

    // tìm route chứa i và j
    for (auto &r : routes) {
        if (!r.isEmpty()) {
            if (r.getFirst()->getId() == customers[i].getId() ||
                r.getLast()->getId() == customers[i].getId())
                ri = &r;

            if (r.getFirst()->getId() == customers[j].getId() ||
                r.getLast()->getId() == customers[j].getId())
                rj = &r;
        }
    }

    if (!ri || !rj || ri == rj) continue;

    const Customer* ri_last = ri->getLast();
    const Customer* rj_first = rj->getFirst();

    // chỉ merge khi đúng đầu-cuối
    if (ri_last->getId() != customers[i].getId()) continue;
    if (rj_first->getId() != customers[j].getId()) continue;

    // merge
    ri->mergeWith(*rj);
    rj->setCustomers({});
    }

    // ===== collect result =====
    std::vector<Route> result;
    for (auto &r : routes) {
        if (!r.isEmpty())
            result.push_back(r);
    }

    return result;
}