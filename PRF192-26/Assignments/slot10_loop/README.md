# Slot 10 — Bài tập: Vòng lặp

## Bài 1: Bảng cửu chương (multiplication_table.c)
In bảng cửu chương từ 1 đến 10. Mỗi bảng cách nhau một dòng trống.

**Output mẫu (rút gọn):**
```
Bang nhan 1:
1 x 1 = 1
1 x 2 = 2
...
1 x 10 = 10

Bang nhan 2:
2 x 1 = 2
...
```

---

## Bài 2: Số nguyên tố (prime_check.c)
Nhập số nguyên dương `n`. Kiểm tra `n` có phải số nguyên tố không.
- Định nghĩa: số nguyên tố > 1 và chỉ chia hết cho 1 và chính nó.
- Dùng vòng lặp từ 2 đến `sqrt(n)` để kiểm tra.

**Yêu cầu:** Kiểm tra `n > 0`. Nếu `n < 2` → "Khong phai so nguyen to".

---

## Bài 3: Đếm chữ số (count_digits.c)
Nhập số nguyên dương `n`. Đếm số lượng chữ số của `n`.
(Không dùng `string.h`, dùng vòng lặp chia nguyên cho 10).

**Input:** `Nhap n: 12345`  
**Output:** `So 12345 co 5 chu so`

---

## Bài 4: Game đoán số (guess_number.c)
Máy tính random số bí mật trong khoảng 1-100. Người chơi đoán, máy gợi ý "Lon hon" / "Nho hon" cho đến khi đúng.

**Yêu cầu:** Đếm số lần đoán. In ra "Chuc mung! Ban da doan dung sau X lan."
