# Đồ án cuối kì
Topic: Xây dựng hệ thống giao hàng shipper

Thông tin dự án:
  - Ngôn ngữ
    - Ngôn ngữ chính: C++
    - Các ngôn ngữ khác: JavaScript, HTML, CSS
  - Dùng mê cung để diễn tả thành đường đi giao hàng rồi từ đó phát triển lên thành bản đồ thực tế
  - Hệ thống chạy bằng server local host
  - Hệ thống sử dụng thuật toán DFS, BFS, Greedy Best-First Search và A*. Sau đó, ứng dụng thuật toán Clarke-Wright Savings để tối ưu hóa đường đi (Đồ án chủ yếu tập trung vào thuật toán A* và Clarke-Wright)

Các file chính liên quan đến đồ án cuối kì:
- Các file ở folder mazeDemo
- Các file ở folder clarkeWrightSavingsAlgorithm
  - Folder algorithms
  - customer.cpp, customer.h, route.cpp, route.h
- File kết quả ở results

Tài liệu tham khảo:
1. A* algorithm: https://en.wikipedia.org/wiki/A*_search_algorithm
2. Clarke and Wright Savings Algorithm as Solutions Vehicle Routing Problem with Simultaneous Pickup Delivery (VRPSPD): https://iopscience.iop.org/article/10.1088/1742-6596/2421/1/012045/pdf
3. Vehicle routing problem (VRP): https://en.wikipedia.org/wiki/Vehicle_routing_problem
