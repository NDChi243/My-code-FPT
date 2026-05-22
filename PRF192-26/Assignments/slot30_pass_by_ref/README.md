# Slot 30 — Bài tập: Con trỏ là tham số — Pass by Reference

## Bài 1: Hoán đổi đúng cách (swap_ok.c)
Viết hàm `void hoanVi(int *a, int *b)` hoán đổi giá trị hai biến thông qua con trỏ.

Trong `main()`, nhập `x` và `y`, gọi `hoanVi(&x, &y)` và in kết quả.

**Yêu cầu:** So sánh với Bài 1 của slot20 — giải thích tại sao lần này hoán đổi được.

---

## Bài 2: Tính min và max (find_min_max.c)
Viết hàm `void timMinMax(int arr[], int n, int *min, int *max)`:
- `*min` lưu giá trị nhỏ nhất trong mảng
- `*max` lưu giá trị lớn nhất trong mảng

Trong `main()`, nhập mảng, gọi hàm và in min, max.

---

## Bài 3: Hàm trả về nhiều kết quả (circle_stats.c)
Viết hàm `void tinhHinhTron(double r, double *chuVi, double *dienTich)`:
- `*chuVi = 2 * PI * r`
- `*dienTich = PI * r * r`

Trong `main()`, nhập `r`, gọi hàm và in kết quả.

**Yêu cầu:** Kiểm tra `r > 0`.

---

## Bài 4: Tách số thành chữ số (digit_split.c)
Viết hàm `void tachChuSo(int n, int *soLuong, int tong)`:
- `*soLuong` = số lượng chữ số
- `*tong` = tổng các chữ số

**Input:** `Nhap n: 1234`  
**Output:** `So luong chu so: 4, Tong chu so: 10`
