# Slot 04 — Bài tập: Biến và Hằng số

## Bài 1: Khai báo nhiều kiểu (declare_vars.c)
Khai báo 5 biến với các kiểu `int`, `float`, `double`, `char`, `char[]`. Gán giá trị và in tất cả ra màn hình.

**Yêu cầu:** Dùng `sizeof()` để in kích thước từng kiểu.
```
Kieu int:     a = 10, kich thuoc = 4 byte
Kieu float:   b = 3.14, kich thuoc = 4 byte
Kieu double:  c = 3.141592, kich thuoc = 8 byte
Kieu char:    d = 'A', kich thuoc = 1 byte
Kieu chuoi:   e = "PRF192", kich thuoc = 7 byte
```

---

## Bài 2: Hằng số (constants.c)
Sử dụng cả `#define` và `const` để khai báo:
- Hằng `PI = 3.14159` (dùng `#define`)
- Hằng `SO_NGAY_TRONG_TUAN = 7` (dùng `const`)
- Hằng `NHIET_DO_DONG_BANG = 0` (dùng `const`)

In ra màn hình giá trị các hằng và giải thích sự khác nhau giữa `#define` và `const`.

---

## Bài 3: In địa chỉ biến (print_address.c)
Khai báo 3 biến: `int soNguyen = 42`, `float soThuc = 9.99`, `char kyTu = 'Z'`.

In ra địa chỉ từng biến bằng `printf("%p", &bien)` và quan sát sự chênh lệch địa chỉ.

**Output mẫu:**
```
Bien soNguyen (int)   = 42, dia chi: 0060FEFC
Bien soThuc (float)   = 9.99, dia chi: 0060FEF8
Bien kyTu (char)      = Z, dia chi: 0060FEF7
```

---

## Bài 4: Hoán đổi giá trị (swap_values.c)
Khai báo hai biến `int x = 5, y = 10`. In ra trước khi hoán đổi.
Dùng biến tạm `temp` để hoán đổi giá trị. In ra sau khi hoán đổi.

**Output:**
```
Truoc: x = 5, y = 10
Sau:   x = 10, y = 5
```
