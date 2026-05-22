# Slot 54 — Bài tập: Cách truy cập File

## Bài 1: Ghi 10 số, đọc lại, tìm max (file_max.c)
Ghi 10 số nguyên do người dùng nhập vào file `data.txt`.
Đọc lại file, tìm số lớn nhất và in ra.

**Yêu cầu:** Đóng file sau khi ghi, mở lại để đọc.

---

## Bài 2: fseek — đọc phần tử thứ n (fseek_demo.c)
Ghi 10 số nguyên cố định vào file `numbers.bin` (dùng `fwrite`).
Dùng `fseek()` để di chuyển đến phần tử thứ `k` (nhập từ bàn phím) và đọc giá trị.

**Yêu cầu:** Kiểm tra `k` hợp lệ (0-9).

---

## Bài 3: ftell — kích thước file (file_size.c)
Nhập tên file. Dùng `fseek` đến cuối file và `ftell` để lấy kích thước file (byte).
In ra: "Kich thuoc file [ten] la: X byte"

---

## Bài 4: rewind — đọc file 2 lần (rewind_demo.c)
Đọc và in nội dung file `data.txt` lần thứ nhất.
Dùng `rewind()` để quay lại đầu file.
Đọc và in lần thứ hai.

**Yêu cầu:** So sánh kết quả 2 lần đọc.
