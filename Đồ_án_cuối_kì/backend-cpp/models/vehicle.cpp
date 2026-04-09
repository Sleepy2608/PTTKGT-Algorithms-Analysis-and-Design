#include "Vehicle.h"
#include <iostream>
using namespace std;

// Constructor
Vehicle::Vehicle(int id, int capacity) {
    this->id = id;
    this->capacity = capacity;
    this->currentLoad = 0;
}

// Getter
int Vehicle::getId() const { return id; }
int Vehicle::getCapacity() const { return capacity; }
int Vehicle::getCurrentLoad() const { return currentLoad; }
vector<int> Vehicle::getRoute() const { return route; }

// Check capacity
bool Vehicle::canAdd(int demand) const {
    return currentLoad + demand <= capacity;
}

// Add customer
void Vehicle::addCustomer(int customerId, int demand) {
    route.push_back(customerId);
    currentLoad += demand;
}

// Set route (sau khi merge)
void Vehicle::setRoute(const vector<int>& newRoute, int load) {
    route = newRoute;
    currentLoad = load;
}

// // Debug
// void Vehicle::print() const {
//     cout << "Vehicle " << id << ": ";
//     cout << "Load = " << currentLoad << "/" << capacity << " | Route: ";

//     for (int x : route) {
//         cout << x << " ";
//     }
//     cout << endl;
// }