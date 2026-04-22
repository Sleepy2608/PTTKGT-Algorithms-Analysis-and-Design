#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
private:
    int id;// id nội bộ
    double x, y;
    int demand;// số lượng hàng của khách hàng

public:
    Customer(int id, double x, double y, int demand);

    int getId() const;
    double getX() const;
    double getY() const;
    int getDemand() const;

    double distanceTo(const Customer& other) const;
};

#endif