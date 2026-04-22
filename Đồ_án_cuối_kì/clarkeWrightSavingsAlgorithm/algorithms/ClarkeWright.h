#ifndef CLARKE_WRIGHT_H
#define CLARKE_WRIGHT_H

#include <vector>
#include "Customer.h"
#include "Route.h"
#include "Vehicle.h"
#include "DistanceService.h"

class ClarkeWright {
private:
    std::vector<Customer> customers;
    Customer depot;

    int capacity;

    DistanceService& distService;

    struct Saving {
        int i, j;
        double val;
    };

    static bool cmpSaving(const Saving& a, const Saving& b);

public:
    ClarkeWright(const std::vector<Customer>& customers,
                 const Customer& depot,
                 int capacity = 0,
                 DistanceService& ds);

    std::vector<Route> solve();
};

#endif