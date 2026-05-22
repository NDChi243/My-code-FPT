# Slot 38 — Bài tập: Mảng 2 chiều (Ma trận)

## Bài 1: Nhập xuất ma trận (matrix_io.c)
Nhập ma trận kích thước `m x n` (nguyên dương, ≤ 10). In ma trận dạng bảng.

**Yêu cầu:** Kiểm tra `m, n > 0 && m, n <= 10`.

---

## Bài 2: Tổng hàng và tổng cột (row_col_sum.c)
Nhập ma trận `m x n`. Tính và in:
- Tổng từng hàng
- Tổng từng cột
- Tổng toàn bộ ma trận

---

## Bài 3: Ma trận chuyển vị (transpose_matrix.c)
Nhập ma trận `m x n`. In ma trận chuyển vị (`n x m`).

**Input:**
```
Ma tran goc:
1 2 3
4 5 6

Ma tran chuyen vi:
1 4
2 5
3 6
```

---

## Bài 4: Đường chéo chính & phụ (diagonals.c)
Nhập ma trận vuông `n x n`. Tính:
- Tổng đường chéo chính (từ trái sang phải)
- Tổng đường chéo phụ (từ phải sang trái)

---

## Bài 5: Nhân hai ma trận (matrix_multiply.c)
Nhập ma trận `A` kích thước `m x n`, ma trận `B` kích thước `n x p`.
Tính và in ma trận tích `C = A * B` (kích thước `m x p`).

**Yêu cầu:** Kiểm tra số cột của `A` bằng số hàng của `B`.
