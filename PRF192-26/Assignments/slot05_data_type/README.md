# Slot 05 — Bài tập: Kiểu dữ liệu

## Bài 1: Kích thước các kiểu (sizeof_types.c)
Dùng `sizeof()` in ra kích thước (byte) của tất cả các kiểu:
`char`, `short`, `int`, `long`, `float`, `double`, `long double`.

**Yêu cầu:** In đẹp dạng bảng:
```
KIEU         | KICH THUOC (byte)
-------------|------------------
char         | 1
short        | 2
int          | 4
long         | 4
float        | 4
double       | 8
long double  | 8
```

---

## Bài 2: Giới hạn signed vs unsigned (signed_unsigned.c)
Khai báo:
- `int a = 2147483647;` (INT_MAX)
- `unsigned int b = 4294967295;` (UINT_MAX)

In ra giá trị. Sau đó cộng thêm 1 vào mỗi biến và in ra. Quan sát hiện tượng **tràn số (overflow)**.

**Output mẫu:**
```
int a = 2147483647
a + 1 = -2147483648   (tran so!)
unsigned int b = 4294967295
b + 1 = 0             (tran so!)
```

---

## Bài 3: Ép kiểu tự động (implicit_cast.c)
Khai báo:
```c
int a = 5, b = 2;
float c = a / b;          // ?
float d = (float)a / b;   // ?
```

In ra giá trị của `c` và `d`. Giải thích bằng comment tại sao kết quả khác nhau.

---

## Bài 4: Chuyển đổi nhiệt độ (temperature.c)
Khai báo biến `double doC = 37.5` (nhiệt độ cơ thể). Tính và in ra độ F theo công thức:
```
doF = doC * 9 / 5 + 32
```

**Output:** `37.50 do C = 99.50 do F`
