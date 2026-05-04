# Đồ án cuối kì
**Topic: Xây dựng hệ thống giao hàng shipper**

---

**Thông tin dự án:**
  - Ngôn ngữ
    - Ngôn ngữ chính: C++
    - Các ngôn ngữ khác: JavaScript, HTML, CSS
  - Dùng mê cung để diễn tả thành đường đi giao hàng rồi từ đó phát triển lên thành bản đồ thực tế
  - Hệ thống chạy bằng server local host
  - Hệ thống sử dụng các thuật toán DFS, BFS, Greedy Best-First Search và A* để tìm đường đi. Sau đó, ứng dụng thuật toán Clarke-Wright Savings để tối ưu hóa đường đi
    - Thuật toán DFS được áp dụng để tạo mê cung
    - Đồ án chủ yếu tập trung vào thuật toán A* và cách tối ưu đường đi giao hàng thông qua thuật toán Clarke-Wright Savings

---

**Các file chính liên quan đến đồ án cuối kì:**
- Các file ở folder mazeDemo
- Các file ở folder clarkeWrightSavingsAlgorithm
  - Folder algorithms
  - customer.cpp, customer.h, route.cpp, route.h
- File kết quả ở results

---

**Các file khác:**
- Nhóm có dự định phát triển đồ án lên bản đồ thực tế (Google Map) từ mô phỏng mê cung như này nên các file backend-cpp, frontend, data và server là cho phần map của nhóm sau này
- File results có chứa hình ảnh UI/UX của hệ thống khi nâng cấp lên map

---

**Cách tải chương trình:**


---

**Cách chạy chương trình:**
- Mở file `maze.html` và chọn Open with Live Server hoặc với phím tắt Alt+L Alt+O
- Hoặc chạy dưới frontend:

```text
[http://localhost:5173](http://127.0.0.1:5500/frontend/maze.html)
```


**Tài liệu tham khảo:**
1. A* algorithm: https://en.wikipedia.org/wiki/A*_search_algorithm
2. Clarke and Wright Savings Algorithm as Solutions Vehicle Routing Problem with Simultaneous Pickup Delivery (VRPSPD): https://iopscience.iop.org/article/10.1088/1742-6596/2421/1/012045/pdf
3. Vehicle routing problem (VRP): https://en.wikipedia.org/wiki/Vehicle_routing_problem
