# Slot 22 — Bài tập: Phạm vi & Thời gian sống của biến

## Bài 1: Biến toàn cục vs cục bộ (global_local.c)
Khai báo biến toàn cục `int g = 100;`. Trong `main()`, khai báo biến cục bộ `int g = 200;`. In `g` ra màn hình.

**Giải thích:** Biến nào được dùng? Tại sao?

---

## Bài 2: Static local — đếm số lần gọi (static_counter.c)
Viết hàm `void demSoLanGoi()` dùng biến `static int soLan = 0;`. Mỗi lần gọi, tăng `soLan` lên 1 và in ra: "Ham da duoc goi X lan."

Trong `main()`, gọi hàm 5 lần. Quan sát sự khác biệt khi bỏ `static`.

---

## Bài 3: Extern — dùng biến từ file khác (extern_demo.c)
Tạo 2 file:
- **`file1.c`:** Khai báo biến toàn cục `int bienDungChung = 42;` và hàm `void inBien()` in ra giá trị biến.
- **`main.c`:** Dùng `extern int bienDungChung;` để truy cập biến từ `file1.c`. Thay đổi giá trị và in ra.

**Yêu cầu:** Compile cả 2 file: `gcc main.c file1.c -o extern_demo.exe`

---

## Bài 4: Vòng đời biến (variable_lifetime.c)
Viết chương trình minh họa:
- Biến `auto` (mặc định) — mất đi khi ra khỏi khối `{}`
- Biến `static` — tồn tại suốt chương trình
- Biến `register` (gợi ý lưu trong thanh ghi)

Dùng `printf("%p", &bien)` để in địa chỉ và nhận xét.
