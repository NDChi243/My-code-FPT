# Slot 28 — Bài tập: Giới thiệu Con trỏ

## Bài 1: In địa chỉ và giá trị (address_print.c)
Khai báo `int x = 42; float y = 3.14; char z = 'A';`.
In địa chỉ (`%p`) và giá trị của từng biến. Gán con trỏ cho từng biến và in giá trị qua con trỏ.

**Output mẫu:**
```
x = 42, dia chi cua x: 0060FEFC
y = 3.14, dia chi cua y: 0060FEF8
z = 'A', dia chi cua z: 0060FEF7
Qua con tro: *px = 42, *py = 3.14, *pz = 'A'
```

---

## Bài 2: Thay đổi giá trị qua con trỏ (change_via_ptr.c)
Khai báo `int a = 10; int *p = &a;`. Thực hiện:
1. In `a` và `*p`
2. Gán `*p = 20;`
3. In lại `a` và `*p` — quan sát sự thay đổi

---

## Bài 3: Con trỏ và mảng (pointer_array.c)
Khai báo mảng `int arr[] = {2, 4, 6, 8, 10};` và con trỏ `int *p = arr;`.
Dùng con trỏ để:
- Duyệt và in từng phần tử
- Tính tổng các phần tử
- Tìm phần tử lớn nhất

**Yêu cầu:** Không dùng chỉ số mảng `arr[i]`, chỉ dùng `*(p + i)`.

---

## Bài 4: Vẽ sơ đồ bộ nhớ (memory_diagram.c)
Viết chương trình khai báo:
```c
int x = 5;
int *p = &x;
int **q = &p;
```
In ra: giá trị của `x`, `*p`, `**q`. In địa chỉ: `&x`, `p`, `&p`, `q`, `&q`.
Vẽ sơ đồ hộp bằng comment trong code để mô tả mối quan hệ giữa các biến.
