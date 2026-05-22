# Slot 06 — Bài tập: Bộ nhớ & Nhập/Xuất cơ bản

## Bài 1: Lời chào cá nhân (greeting.c)
Viết chương trình nhập họ tên và tuổi từ bàn phím, sau đó in ra lời chào.

**Input:**
```
Nhap ho ten: Nguyen Van B
Nhap tuoi: 20
```
**Output:**
```
Xin chao Nguyen Van B! Ban 20 tuoi.
```

**Yêu cầu:** Dùng `fgets()` để nhập chuỗi có dấu cách.

---

## Bài 2: Máy tính cơ bản (basic_calculator.c)
Nhập 2 số nguyên `a` và `b` từ bàn phím. In ra tổng, hiệu, tích, thương (dạng số thực với 2 chữ số thập phân).

**Yêu cầu:** Kiểm tra `b != 0` trước khi chia.

---

## Bài 3: Tính chu vi & diện tích (circle_calc.c)
Nhập bán kính `r` (float). Tính và in:
- Chu vi: `C = 2 * PI * r`
- Diện tích: `S = PI * r * r`

Dùng `PI = 3.14159`. Làm tròn 2 chữ số thập phân.

---

## Bài 4: Nhập xuất hỗn hợp (mixed_io.c)
Nhập một ký tự, một số nguyên, một số thực:
```
Nhap mot ky tu: M
Nhap mot so nguyen: 2024
Nhap mot so thuc: 3.14159
```
In ra theo format:
```
Ky tu: 'M' (ma ASCII: 77)
So nguyen: 2024
So thuc: 3.14
```
