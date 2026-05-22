# Slot 40 — Bài tập: Struct

## Bài 1: Khai báo và sử dụng struct (struct_basic.c)
Khai báo struct `SinhVien` gồm: `ten[50]`, `mssv[10]`, `tuoi`, `diemTB`.
Nhập thông tin 1 sinh viên từ bàn phím. In thông tin ra màn hình.

---

## Bài 2: Mảng struct — danh sách sinh viên (student_list.c)
Khai báo struct `SinhVien` như trên.
Nhập `n` sinh viên. In danh sách dạng bảng.

**Yêu cầu:** Kiểm tra `0 <= diemTB <= 10`.

---

## Bài 3: Tìm kiếm sinh viên theo tên (search_student.c)
Nhập `n` sinh viên. Sau đó nhập tên cần tìm.
Tìm và in ra sinh viên có tên chứa từ khóa (dùng `strstr`).
Nếu không tìm thấy: "Khong tim thay sinh vien."

---

## Bài 4: Sắp xếp sinh viên theo điểm (sort_students.c)
Nhập `n` sinh viên. Sắp xếp danh sách theo điểm trung bình **giảm dần**.
In danh sách sau khi sắp xếp (kèm xếp loại: Gioi, Kha, TB, Yeu).

---

## Bài 5: Thống kê điểm (grade_stats.c)
Nhập `n` sinh viên. Thống kê:
- Điểm TB cao nhất (tên sinh viên + điểm)
- Điểm TB thấp nhất
- Điểm TB của toàn lớp
- Số sinh viên đạt (diemTB >= 5) và số sinh viên trượt
