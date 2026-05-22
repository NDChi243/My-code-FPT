# Slot 47 — Bài tập: Nhập/Xuất chuỗi

## Bài 1: Nhập họ tên đầy đủ (fullname_input.c)
Nhập họ tên đầy đủ bằng `fgets()`. In ra:
- Họ
- Tên đệm
- Tên

**Input:** `Nhap ho ten: Nguyen Van Anh`  
**Output:**
```
Ho: Nguyen
Dem: Van
Ten: Anh
```

---

## Bài 2: Đếm từ trong câu (word_count.c)
Nhập một câu (có dấu cách). Đếm số từ trong câu.

**Input:** `Nhap cau: PRF192 la mon hoc co so lap trinh C`  
**Output:** `So tu: 8`

**Yêu cầu:** Xử lý nhiều khoảng trắng liên tiếp.

---

## Bài 3: Nhập số nguyên bằng chuỗi (input_as_string.c)
Nhập một số nguyên dưới dạng chuỗi (dùng `fgets`). Dùng `atoi()` để chuyển thành số.
Kiểm tra: nếu `atoi` trả về 0 và chuỗi khác "0", báo "Du lieu khong hop le!"

---

## Bài 4: Xóa ký tự xuống dòng (trim_newline.c)
Nhập 3 chuỗi liên tiếp bằng `fgets()`. Sau mỗi lần nhập, xóa ký tự `\n` thừa.
In 3 chuỗi trên cùng một dòng, cách nhau bởi dấu `;`.
