# Slot 29 — Bài tập: Khai báo & Các toán tử con trỏ

## Bài 1: Duyệt mảng bằng con trỏ (ptr_traverse.c)
Khai báo mảng `int arr[] = {12, 34, 56, 78, 90};`. Dùng con trỏ `int *p = arr;` để:
- In địa chỉ từng phần tử (dùng `p + i`)
- In giá trị từng phần tử (dùng `*(p + i)`)
- In kích thước bước nhảy: `(p+1) - (p+0)` (byte)

---

## Bài 2: Con trỏ và phép toán số học (ptr_arithmetic.c)
Khai báo mảng `int arr[] = {10, 20, 30, 40, 50}; int *p = arr;`.
Thực hiện lần lượt và in kết quả từng bước:
```c
printf("*p = %d\n", *p);      // ?
p++;
printf("*p = %d\n", *p);      // ?
p += 2;
printf("*p = %d\n", *p);      // ?
p--;
printf("*p = %d\n", *p);      // ?
```

**Câu hỏi:** Nếu `p` là `int*`, mỗi lần `p++` thì địa chỉ tăng bao nhiêu byte?

---

## Bài 3: So sánh địa chỉ (ptr_compare.c)
Khai báo mảng `int a[5]`. Dùng con trỏ để so sánh địa chỉ:
```c
int *p1 = &a[0];
int *p2 = &a[3];
printf("p1 = %p, p2 = %p\n", p1, p2);
if (p1 < p2) printf("p1 truoc p2\n");
else printf("p1 sau p2\n");
```
Tính số phần tử giữa `p1` và `p2`: `p2 - p1`.

---

## Bài 4: Con trỏ void (void_ptr.c)
Khai báo con trỏ `void *vp`. Gán lần lượt địa chỉ của `int`, `float`, `char`.
In địa chỉ ra (luôn được). Ép kiểu `vp` về đúng kiểu trước khi in giá trị.

**Yêu cầu:** Giải thích tại sao cần ép kiểu khi in giá trị qua `void*`.
