#include "Route.h"
#include <iostream>
using namespace std;

// Constructor
Route::Route() {
    load = 0;
}

// Getter
vector<int> Route::getCustomers() const {
    return customers;
}

int Route::getLoad() const {
    return load;
}

// Add customer vào cuối
void Route::addCustomer(int customerId, int demand) {
    customers.push_back(customerId);
    load += demand;
}

// Lấy phần tử đầu
int Route::getFirst() const {
    if (customers.empty()) return -1;
    return customers.front();
}

// Lấy phần tử cuối
int Route::getLast() const {
    if (customers.empty()) return -1;
    return customers.back();
}

// Check empty
bool Route::isEmpty() const {
    return customers.empty();
}

// Merge route: this = this + other
void Route::mergeWith(const Route& other) {
    for (int x : other.customers) {
        customers.push_back(x);
    }
    load += other.load;
}

// Set lại route
void Route::setCustomers(const vector<int>& newCustomers, int newLoad) {
    customers = newCustomers;
    load = newLoad;
}

// Debug
void Route::print() const {
    cout << "Route: 0 -> ";
    for (int x : customers) {
        cout << x << " -> ";
    }
    cout << "0 | Load = " << load << endl;
}
