#include "Vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(int id, int capacity) {
    this->id = id;
    this->capacity = capacity;
}

int Vehicle::getId() const { return id; }
int Vehicle::getCapacity() const { return capacity; }

const Route& Vehicle::getRoute() const {
    return route;
}

bool Vehicle::canAssign(const Route& r) const {
    return r.getLoad() <= capacity;
}

void Vehicle::setRoute(const Route& r) {
    route = r;
}

void Vehicle::print() const {
    cout << "Vehicle " << id << ": ";
    route.print();
}