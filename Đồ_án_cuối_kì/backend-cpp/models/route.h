#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
using namespace std;

class Route {
private:
    vector<int> customers; // danh sách customer id (KHÔNG chứa depot)
    int load;              // tổng demand <= capacity của xe

public:
    // Constructor
    Route();

    // Getter
    vector<int> getCustomers() const;
    int getLoad() const;

    // Thêm customer (cuối route)
    void addCustomer(int customerId, int demand);

    // Kiểm tra vị trí đầu/cuối
    int getFirst() const;
    int getLast() const;

    // Kiểm tra rỗng
    bool isEmpty() const;

    // Merge 2 route (A + B)
    void mergeWith(const Route& other);

    // Set route (dùng khi cần override)
    void setCustomers(const vector<int>& newCustomers, int newLoad);

    //  Debug
    void print() const;
};

#endif