# Slot 35 — Bài tập: Ôn tập CLO5 & CLO6

## Bài 1: Vector 2D — cộng và độ dài (vector_2d.c)
Dùng con trỏ + malloc + math.h để làm việc với vector 2D.
Viết hàm:
- `void nhapVector(double *v)` — nhập tọa độ x, y
- `double tinhDoDai(double *v)` — `sqrt(x*x + y*y)`
- `void congVector(double *a, double *b, double *c)` — `c = a + b`

---

## Bài 2: Đảo ngược mảng động (reverse_dynamic.c)
Nhập `n`. Dùng `malloc` cấp phát mảng `n` số nguyên. Nhập giá trị.
Đảo ngược mảng (dùng con trỏ, không dùng chỉ số mảng).
In mảng trước và sau khi đảo.

---

## Bài 3: Hàm xử lý mảng tổng hợp (array_ops.c)
Viết các hàm xử lý mảng (dùng con trỏ):
- `void nhapMang(int *arr, int n)`
- `void inMang(int *arr, int n)`
- `int tinhTong(int *arr, int n)`
- `double tinhTrungBinh(int *arr, int n)`
- `int timMax(int *arr, int n)`

Trong `main()`: nhập `n`, cấp phát động, gọi các hàm trên.
