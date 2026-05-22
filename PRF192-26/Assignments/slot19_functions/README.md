# Slot 19 — Bài tập: Định nghĩa Function

## Bài 1: Viết hàm tính tổng (sum_function.c)
Viết hàm `int tinhTong(int a, int b)` trả về tổng hai số nguyên. 
Trong `main()`, nhập 2 số, gọi hàm và in kết quả.

**Yêu cầu:** Khai báo prototype trước `main()`, định nghĩa hàm sau `main()`.

---

## Bài 2: Hàm kiểm tra nguyên tố (is_prime.c)
Viết hàm `int laSoNguyenTo(int n)`:
- Trả về `1` nếu `n` là số nguyên tố
- Trả về `0` nếu không phải

Trong `main()`, nhập `n` và gọi hàm kiểm tra. In kết quả ra màn hình.

**Yêu cầu:** Kiểm tra `n > 0` trước khi xử lý.

---

## Bài 3: Hàm tính giai thừa (factorial_func.c)
Viết hàm `long long tinhGiaiThua(int n)` tính `n!` bằng vòng lặp.

**Chú ý:** `n!` tăng rất nhanh. Dùng `long long` để tránh tràn số. Nếu `n < 0` hoặc `n > 20`, trả về `-1`.

**Input:** `Nhap n: 6`  
**Output:** `6! = 720`

---

## Bài 4: Hàm in hình chữ nhật (print_rect.c)
Viết hàm `void inHinhChuNhat(int dai, int rong)` in hình chữ nhật bằng `*`.

Trong `main()`, nhập chiều dài và chiều rộng (nguyên dương), gọi hàm.

**Input:** `Nhap dai: 6, rong: 3`  
**Output:**
```
******
*    *
******
```
