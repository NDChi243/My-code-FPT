# Slot 33 — Bài tập: Thư viện math.h & ctype.h

## Bài 1: Đếm ký tự trong chuỗi (count_chars.c)
Nhập một chuỗi (dùng `fgets`). Dùng các hàm `ctype.h` để đếm:
- Số chữ hoa (`isupper`)
- Số chữ thường (`islower`)
- Số chữ số (`isdigit`)
- Số khoảng trắng (`isspace`)

**Input:** `Nhap chuoi: PRF192 - Co so Lap trinh C`  
**Output:**
```
Chu hoa: 5
Chu thuong: 12
Chu so: 3
Khoang trang: 5
```

---

## Bài 2: Tính toán hình học với math.h (geometry_math.c)
Nhập bán kính `r`. Dùng `math.h` tính:
- Diện tích hình tròn: `S = M_PI * pow(r, 2)`
- Thể tích hình cầu: `V = 4.0/3 * M_PI * pow(r, 3)`
- Làm tròn: `ceil(S)`, `floor(S)`

**Yêu cầu:** Liên kết thư viện math với `-lm` khi compile.

---

## Bài 3: Chuyển đổi chữ hoa/thường (case_converter.c)
Nhập chuỗi. Dùng `toupper()` và `tolower()` để:
- In chuỗi viết hoa toàn bộ
- In chuỗi viết thường toàn bộ

**Input:** `Nhap chuoi: PRF192-C`  
**Output:**
```
Viet hoa: PRF192-C
Viet thuong: prf192-c
```

---

## Bài 4: Giải tam giác vuông (right_triangle.c)
Nhập độ dài 2 cạnh góc vuông `a, b`. Dùng `math.h`:
- Tính cạnh huyền: `c = sqrt(a*a + b*b)`
- Tính góc A: `sinA = a/c`, dùng `asin(sinA) * 180 / M_PI` để ra độ

**Output:**
```
Canh huyen: 5.00
Goc A: 36.87 do
Goc B: 53.13 do
```
