# Slot 39 — Bài tập: Tìm kiếm & Sắp xếp

## Bài 1: Linear Search (linear_search.c)
Nhập mảng `n` số nguyên và một số `x`. Dùng linear search tìm vị trí đầu tiên của `x` trong mảng.
Nếu không tìm thấy, in "Khong tim thay x trong mang."

---

## Bài 2: Selection Sort (selection_sort.c)
Nhập mảng `n` số nguyên. Sắp xếp tăng dần bằng Selection Sort.
In mảng sau mỗi bước (để quan sát thuật toán).

**Input:** `n = 6, mang: 5 2 7 1 9 3`  
**Output mẫu (từng bước):**
```
Buoc 1: 1 2 7 5 9 3
Buoc 2: 1 2 7 5 9 3
Buoc 3: 1 2 3 5 9 7
Buoc 4: 1 2 3 5 9 7
Buoc 5: 1 2 3 5 7 9
```

---

## Bài 3: Tìm kiếm nhị phân (binary_search.c)
Nhập mảng `n` số nguyên **đã sắp xếp tăng dần** và số `x`.
Dùng **Binary Search** tìm `x`. In vị trí nếu tìm thấy, "Khong tim thay" nếu không.

**Yêu cầu:** Đếm số bước so sánh.

---

## Bài 4: Sắp xếp giảm dần (bubble_sort.c)
Nhập mảng `n` số thực. Sắp xếp giảm dần bằng Bubble Sort.
In mảng sau khi sắp xếp.

---

## Bài 5: Tìm phần tử xuất hiện nhiều nhất (mode_find.c)
Nhập mảng `n` số nguyên. Tìm phần tử xuất hiện nhiều nhất (mode).
Nếu có nhiều phần tử cùng tần suất, in phần tử nhỏ nhất.

**Input:** `n = 9, mang: 1 3 3 2 5 3 1 2 1`  
**Output:** `Phan tu xuat hien nhieu nhat: 1 (3 lan), 3 (3 lan) => chon 1`
