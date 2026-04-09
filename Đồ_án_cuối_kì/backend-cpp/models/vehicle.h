#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
using namespace std;

class Vehicle {
private:
    int id;                 // mã xe
    int capacity;           // tải trọng tối đa = bằng tổng demand của các khách hàng
    int currentLoad;        // tải hiện tại
    vector<int> route;      // danh sách customer id

public:
    // Constructor
    Vehicle(int id, int capacity);

    // Getter
    int getId() const;
    int getCapacity() const;
    int getCurrentLoad() const;
    vector<int> getRoute() const;

    // Kiểm tra còn chở được không
    bool canAdd(int demand) const;

    // Thêm khách vào route
    void addCustomer(int customerId, int demand);

    // Set route (dùng khi Clarke-Wright merge)
    void setRoute(const vector<int>& newRoute, int load);

    // Debug
    void print() const;
};

#endif