# Slot 09 — Bài tập: Cấu trúc rẽ nhánh

## Bài 1: Phân loại học lực (grade_classifier.c)
Nhập điểm (thang 10). In ra học lực tương ứng:
- 9-10: **Xuat sac**
- 8-<9: **Gioi**
- 7-<8: **Kha**
- 5-<7: **Trung binh**
- <5: **Yeu**

**Yêu cầu:** Kiểm tra `0 <= diem <= 10`.

---

## Bài 2: Giải phương trình bậc 1 (linear_eq.c)
Nhập hệ số `a` và `b` của phương trình `ax + b = 0`.
- Nếu `a == 0 && b == 0`: "Vo so nghiem"
- Nếu `a == 0 && b != 0`: "Vo nghiem"
- Nếu `a != 0`: `x = -b / a`

---

## Bài 3: Máy tính switch-case (switch_calc.c)
Nhập 2 số và một phép toán (`+`, `-`, `*`, `/`). Dùng `switch-case` để tính và in kết quả.

**Input mẫu:**
```
Nhap a: 10
Nhap b: 3
Nhap phep toan (+, -, *, /): /
```
**Output:** `10.00 / 3.00 = 3.33`

**Yêu cầu:** Kiểm tra chia cho 0. Dùng `default` cho phép toán không hợp lệ.

---

## Bài 4: Tìm số lớn nhất (max_of_three.c)
Nhập 3 số nguyên. Dùng toán tử ba ngôi `?:` để tìm và in số lớn nhất (không dùng `if`).

**Input:** `Nhap ba so: 7 12 5`
**Output:** `So lon nhat la: 12`
