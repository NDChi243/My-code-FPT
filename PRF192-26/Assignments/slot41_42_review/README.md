# Slot 41-42 — Bài tập: Ôn tập CLO7

## Bài 1: Quản lý danh sách sinh viên (student_manager.c)
Dùng struct + mảng để quản lý tối đa 50 sinh viên. Mỗi sinh viên gồm: tên, MSSV, điểm 3 môn (Toán, Lý, Hóa).

Chức năng:
1. Thêm sinh viên
2. In danh sách (dạng bảng kèm điểm TB)
3. Tìm sinh viên theo MSSV
4. Thoát

**Yêu cầu:** Tính điểm TB = (Toán + Lý + Hóa) / 3.

---

## Bài 2: Sắp xếp sinh viên theo tên (sort_by_name.c)
Nhập `n` sinh viên (struct gồm tên, MSSV, điểm).
Sắp xếp danh sách theo **tên** alphabet (dùng `strcmp`).
In danh sách trước và sau khi sắp xếp.

---

## Bài 3: Ma trận — tổng các số nguyên tố (prime_matrix.c)
Nhập ma trận `m x n` số nguyên dương. Đếm và tính tổng các số nguyên tố trong ma trận.
Viết hàm riêng `int laSoNguyenTo(int n)` để kiểm tra.
