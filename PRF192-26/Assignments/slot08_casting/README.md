# Slot 08 — Bài tập: Ép kiểu & Độ ưu tiên toán tử

## Bài 1: Dự đoán kết quả (predict_results.c)
Tính và in kết quả các biểu thức sau. Viết dự đoán vào comment trước mỗi dòng:
```c
int a = 5, b = 2, c = 10;
float x;

x = a / b;              // ?
x = (float)a / b;       // ?
x = a / (float)b;       // ?
x = (float)(a / b);     // ?
x = a + b * c;          // ?
x = (a + b) * c;        // ?
x = c / (a - b);        // ?
```

---

## Bài 2: Ép kiểu tính tiền (money_cast.c)
Nhập số lượng và đơn giá (số nguyên). Tính tổng tiền = số lượng × đơn giá.
In ra kết quả dạng số thực (để mô phỏng có thuế VAT 10%).

**Output mẫu:**
```
Nhap so luong: 5
Nhap don gia: 25000
Tong truoc thue: 125000
Thue VAT (10%): 12500.00
Tong sau thue: 137500.00
```

---

## Bài 3: Tính trung bình 3 số (avg_three.c)
Nhập 3 số nguyên. Tính trung bình cộng dạng số thực với 2 chữ số thập phân.

**Yêu cầu:** Ép kiểu để có kết quả chính xác. Kiểm tra input hợp lệ.

---

## Bài 4: Kiểm tra độ ưu tiên (precedence_test.c)
Cho các biểu thức, yêu cầu sinh viên điền kết quả vào comment, sau đó chạy code để kiểm tra:
```c
int a = 3, b = 4, c = 5;
int r1 = a + b * c;         // r1 = ?
int r2 = (a + b) * c;       // r2 = ?
int r3 = a > b && c > b;    // r3 = ?
int r4 = a < b || c < b;    // r4 = ?
int r5 = ++a * b--;         // r5 = ?
```
