# Slot 20 — Bài tập: Gọi hàm & Truyền tham số (Pass by Value)

## Bài 1: Hoán địa — tại sao không swap? (swap_fail.c)
Viết hàm `void hoanVi(int a, int b)` hoán đổi giá trị hai biến.
Trong `main()`, gán `x = 5, y = 10`, gọi `hoanVi(x, y)` và in `x, y` sau khi gọi.

**Câu hỏi (trả lời bằng comment trong code):** Tại sao `x` và `y` không thực sự hoán đổi?

---

## Bài 2: Tính tổng các chữ số (digit_sum_func.c)
Viết hàm `int tongChuSo(int n)` trả về tổng các chữ số của `n`.
(Không dùng vòng lặp — dùng đệ quy hoặc vòng lặp đều được).

**Input:** `Nhap n: 1234`  
**Output:** `Tong chu so cua 1234 la: 10`

---

## Bài 3: Hàm trả về nhiều giá trị dùng tham chiếu (min_max.c)
Viết hàm `void timMinMax(int a, int b, int c, int *min, int *max)`:
- `*min` lưu giá trị nhỏ nhất
- `*max` lưu giá trị lớn nhất

Trong `main()`, nhập 3 số, gọi hàm và in ra min, max.

---

## Bài 4: Copy value demonstration (copy_demo.c)
Viết chương trình chứng minh pass-by-value:
```c
void tangGiaTri(int x) {
    x = x + 10;
    printf("Trong ham: x = %d\n", x);
}
```
Trong `main()`, khai báo `int a = 5;`, gọi `tangGiaTri(a)`, in `a` sau khi gọi.
Giải thích kết quả bằng comment.
