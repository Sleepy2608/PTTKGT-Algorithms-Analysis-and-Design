#ifndef VEHICLE_H
#define VEHICLE_H

#include "Route.h"

class Vehicle {
private:
    int id;
    int capacity;
    Route route;

public:
    Vehicle(int id, int capacity);

    int getId() const;
    int getCapacity() const;

    const Route& getRoute() const;

    bool canAssign(const Route& r) const;

    void setRoute(const Route& r);

    void print() const;
};

#endif