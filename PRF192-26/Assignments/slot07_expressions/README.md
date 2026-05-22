# Slot 07 — Bài tập: Biểu thức

## Bài 1: Tính điểm trung bình (avg_score.c)
Nhập 3 điểm môn: Toán, Lý, Hóa (hệ số 1). Tính điểm trung bình và in ra.

**Input:**
```
Nhap diem Toan: 8.5
Nhap diem Ly: 7.0
Nhap diem Hoa: 9.0
```
**Output:** `Diem trung binh: 8.17`

---

## Bài 2: Toán tử tăng/giảm (increment_ops.c)
Khai báo `int x = 5;`. Thực hiện lần lượt và in kết quả từng bước:
```c
printf("x = %d\n", x);      // x = 5
printf("x++ = %d\n", x++);  // ?
printf("x = %d\n", x);      // ?
printf("++x = %d\n", ++x);  // ?
printf("x = %d\n", x);      // ?
printf("x-- = %d\n", x--);  // ?
printf("x = %d\n", x);      // ?
```

Dự đoán kết quả trước khi chạy, viết vào comment.

---

## Bài 3: Kiểm tra số chẵn lẻ (even_odd.c)
Nhập một số nguyên `n`. Dùng biểu thức `n % 2` để kiểm tra và in ra:
```
Nhap n: 7
7 la so le
```
```
Nhap n: 10
10 la so chan
```

---

## Bài 4: Tính BMI (bmi_calculator.c)
Nhập cân nặng (kg) và chiều cao (m). Tính BMI:
```
BMI = canNang / (caoCao * caoCao)
```
In ra BMI với 2 chữ số thập phân.

**Kiểm tra:** Input `canNang > 0 && caoCao > 0`.
