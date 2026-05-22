# Slot 56 — Bài tập: Ôn tập CLO9

## Bài 1: Đọc file CSV — sắp xếp — ghi file mới (csv_sort.c)
Cho file `data.csv` có nội dung:
```
Ten,MSSV,Diem
Nguyen Van A,SV001,8.5
Tran Thi B,SV002,6.5
Le Van C,SV003,9.0
...
```
Đọc file CSV, lưu vào mảng struct. Sắp xếp theo điểm giảm dần.
Ghi kết quả vào file `sorted.csv`.

---

## Bài 2: Quản lý sách dùng file (book_manager.c)
Quản lý danh sách sách (tên, tác giả, năm XB, giá) dùng file nhị phân `books.dat`.
Chức năng:
1. Thêm sách mới (ghi thêm vào cuối file)
2. In danh sách (đọc toàn bộ file)
3. Tìm sách theo tên
4. Thoát

---

## Bài 3: Thống kê file văn bản (file_stats.c)
Nhập tên file văn bản. Thống kê:
- Số dòng
- Số từ
- Số ký tự (không tính khoảng trắng)
- Số ký tự khoảng trắng

**Yêu cầu:** Dùng `feof()` để kiểm tra kết thúc file.
