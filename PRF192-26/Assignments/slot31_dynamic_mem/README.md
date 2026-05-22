# Slot 31 — Bài tập: Cấp phát bộ nhớ động

## Bài 1: Cấp phát mảng động (malloc_array.c)
Nhập `n` (nguyên dương). Dùng `malloc()` cấp phát mảng `n` số nguyên.
Nhập các phần tử, tính tổng và in ra. Giải phóng bộ nhớ bằng `free()`.

**Yêu cầu:** Kiểm tra con trỏ NULL sau `malloc`. Kiểm tra `n > 0`.

---

## Bài 2: calloc vs malloc (calloc_demo.c)
So sánh `malloc()` và `calloc()`:
1. Dùng `malloc(5 * sizeof(int))`: in giá trị các phần tử (có thể là rác)
2. Dùng `calloc(5, sizeof(int))`: in giá trị các phần tử (phải là 0)

**Yêu cầu:** Giải thích sự khác biệt bằng comment trong code.

---

## Bài 3: Mở rộng mảng với realloc (realloc_demo.c)
Cấp phát mảng 3 số nguyên bằng `malloc`. Nhập giá trị.
Dùng `realloc()` để mở rộng mảng lên 5 phần tử. Nhập thêm 2 giá trị mới.
In toàn bộ mảng trước và sau khi `realloc`.

---

## Bài 4: Quản lý điểm động (dynamic_grades.c)
Nhập số sinh viên `n`. Dùng `malloc` cấp phát mảng `float` điểm.
Nhập điểm từng sinh viên. Tính:
- Điểm trung bình
- Điểm cao nhất
- Điểm thấp nhất

**Yêu cầu:** Kiểm tra `0 <= diem <= 10`. `free()` sau khi dùng xong.
