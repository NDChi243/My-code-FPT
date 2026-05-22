# Slot 37 — Bài tập: Mảng 1 chiều

## Bài 1: Nhập xuất mảng (array_io.c)
Nhập số phần tử `n` (nguyên dương, ≤ 100) và mảng `n` số nguyên. In mảng ra màn hình.

**Yêu cầu:** Kiểm tra `n > 0 && n <= 100`.

---

## Bài 2: Thống kê mảng (array_stats.c)
Nhập mảng `n` số nguyên. Tính và in:
- Tổng các phần tử
- Trung bình cộng (dạng số thực)
- Phần tử lớn nhất và nhỏ nhất
- Số lượng số dương, số âm, số 0

---

## Bài 3: Đếm tần suất (frequency_count.c)
Nhập mảng `n` số nguyên (0-99). Đếm số lần xuất hiện của mỗi số.

**Input:**
```
Nhap n: 8
Nhap mang: 3 5 3 7 5 3 9 5
```
**Output:**
```
3: 3 lan
5: 3 lan
7: 1 lan
9: 1 lan
```

---

## Bài 4: Mảng đối xứng (symmetric_array.c)
Nhập mảng `n` số nguyên. Kiểm tra mảng có đối xứng không?
(Ví dụ: `1 2 3 2 1` là đối xứng, `1 2 3 4 5` không đối xứng)

---

## Bài 5: Xóa phần tử trùng (remove_dup.c)
Nhập mảng `n` số nguyên. Xóa các phần tử trùng nhau (giữ lại phần tử đầu tiên).
In mảng sau khi xóa.

**Input:** `n = 7, mang: 1 3 3 2 5 3 1`  
**Output:** `Mang sau khi xoa trung: 1 3 2 5`
