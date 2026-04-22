#include "Route.h"
#include <iostream>

Route::Route() {
    load = 0;
}

const std::vector<Customer>& Route::getCustomers() const {
    return customers;
}

int Route::getLoad() const {
    return load;
}

void Route::addCustomer(const Customer& customer) {
    customers.push_back(customer);
    load += customer.getDemand();
}

const Customer* Route::getFirst() const {
    if (customers.empty()) return nullptr;
    return &customers.front();
}

const Customer* Route::getLast() const {
    if (customers.empty()) return nullptr;
    return &customers.back();
}

bool Route::isEmpty() const {
    return customers.empty();
}

void Route::mergeWith(const Route& other, bool reverseOther = false) {
    if (reverseOther) {
        for (int i = other.getCustomers().size() - 1; i >= 0; i--) {
            customers.push_back(other.getCustomers()[i]);
        }
    } else {
        for (const Customer& c : other.getCustomers()) {
            customers.push_back(c);
        }
    }

    load += other.getLoad();
}

void Route::setCustomers(const std::vector<Customer>& newCustomers) {
    customers = newCustomers;

    // tính lại load
    load = 0;
    for (const Customer& c : customers) {
        load += c.getDemand();
    }
}

void Route::print() const {
    std::cout << "Route: 0 -> ";
    for (const Customer& c : customers) {
        std::cout << c.getId() << " -> ";
    }
    std::cout << "0 | Load = " << load << std::endl;
}
