# Đồ án cuối kì
Topic: Xây dựng hệ thống giao hàng shipper

Thông tin dự án:
  - Ngôn ngữ
    - Ngôn ngữ chính: C++
    - Các ngôn ngữ khác: JavaScript, HTML, CSS
  - Dùng mê cung để diễn tả thành đường đi giao hàng rồi từ đó phát triển lên thành bản đồ thực tế
  - Hệ thống chạy bằng server local host
  - Hệ thống sử dụng thuật toán A*, Branch & Bound và Clarke-Wright Savings Algorithm để tối ưu hóa đường đi

Cách chạy chương trình: 
- Down file code về máy
- Check gitbash trước khi chạy server
  - Vào file server (cd ../server)
  - Chạy lệnh `npm start`. Nếu có:
  > server@1.0.0 start
  
  > node server.js
  
  thì đã chạy thành công
- Vô hmtl chạy local

# Known Bugs: (Cho map)
- Lỗi hàm solve khiến không thể tối ưu hóa đường đi
- Đường đi bị đè, chưa hiện rõ
- Tính toán thời gian còn sai số nhiều giữa các điểm khi di chuyển
