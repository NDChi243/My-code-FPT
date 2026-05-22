# Slot 53 — Bài tập: Text File vs Binary File

## Bài 1: Ghi text file (text_write.c)
Ghi danh sách 5 sinh viên (tên, MSSV, điểm) vào file `sinhvien.txt` ở dạng text.
Mỗi sinh viên trên một dòng, các trường cách nhau bởi dấu `|`.

**Định dạng:**
```
Nguyen Van A|SV001|8.5
Tran Thi B|SV002|7.0
```

---

## Bài 2: Đọc text file (text_read.c)
Đọc file `sinhvien.txt` (đã tạo ở bài 1). In ra màn hình dạng bảng đẹp.

**Yêu cầu:** Dùng `fscanf` để đọc từng trường. Kiểm tra file tồn tại.

---

## Bài 3: Ghi binary file (binary_write.c)
Khai báo struct `SinhVien` gồm tên, MSSV, điểm.
Nhập 3 sinh viên. Dùng `fwrite()` ghi mảng struct vào file `sinhvien.dat` (binary).

---

## Bài 4: Đọc binary file (binary_read.c)
Đọc file `sinhvien.dat` (đã tạo ở bài 3) bằng `fread()`.
In thông tin các sinh viên ra màn hình.

**Yêu cầu:** So sánh kích thước file text vs binary (dùng `ftell` hoặc xem file properties).
