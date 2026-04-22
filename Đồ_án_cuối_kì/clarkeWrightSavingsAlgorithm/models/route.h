#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include "Customer.h"

class Route {
private:
    std::vector<Customer> customers; // danh sách Customer (không chứa depot)
    int load;                        // tổng demand

public:
    // Constructor
    Route();

    // Getter
    const std::vector<Customer>& getCustomers() const;
    int getLoad() const;

    // Thêm customer
    void addCustomer(const Customer& customer);

    // Lấy customer đầu/cuối
    const Customer* getFirst() const;
    const Customer* getLast() const;

    // Kiểm tra rỗng
    bool isEmpty() const;

    // Merge route
    void mergeWith(const Route& other, bool reverseOther = false);

    // Set lại route
    void setCustomers(const std::vector<Customer>& newCustomers);

    // Debug
    void print() const;
};

#endif