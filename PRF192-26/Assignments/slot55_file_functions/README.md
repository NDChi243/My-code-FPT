# Slot 55 — Bài tập: Các hàm File

## Bài 1: Ghi danh sách dùng fprintf (fprintf_list.c)
Nhập `n` sinh viên (tên, MSSV, điểm). Ghi danh sách vào file `output.txt` dùng `fprintf` theo format:
```
STT | Ho ten          | MSSV   | Diem
1   | Nguyen Van A    | SV001  | 8.50
2   | Tran Thi B      | SV002  | 7.00
```

---

## Bài 2: Đọc file dùng fscanf (fscanf_read.c)
Đọc file `output.txt` (đã tạo ở bài 1) dùng `fscanf` để đọc từng dòng.
In ra màn hình nội dung đã đọc.

**Yêu cầu:** Bỏ qua dòng tiêu đề (header). Xử lý lỗi file không tồn tại.

---

## Bài 3: Đọc file dùng fgets (fgets_read.c)
Mở file `output.txt`. Đọc từng dòng bằng `fgets()` và in ra màn hình.
So sánh với cách dùng `fscanf` (ưu/nhược điểm).

---

## Bài 4: Copy file (file_copy.c)
Nhập tên file nguồn và file đích. Copy nội dung từ file nguồn sang file đích.
Dùng `fgets()` / `fputs()` hoặc `fgetc()` / `fputc()`.

**Yêu cầu:** Kiểm tra file nguồn tồn tại. Không ghi đè nếu file đích đã tồn tại (hỏi người dùng trước).
