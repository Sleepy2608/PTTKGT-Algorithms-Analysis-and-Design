#include "Customer.h"
#include <cmath>

Customer::Customer(int id, double x, double y, int demand) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->demand = demand;
}

int Customer::getId() const { return id; }
double Customer::getX() const { return x; }
double Customer::getY() const { return y; }
int Customer::getDemand() const { return demand; }

double Customer::distanceTo(const Customer& other) const {
    return sqrt((x - other.x)*(x - other.x) +
                (y - other.y)*(y - other.y));
}