# Slot 46 — Bài tập: Khai báo & Khởi tạo String

## Bài 1: Nhập xuất chuỗi an toàn (safe_string.c)
Nhập họ tên đầy đủ (có dấu cách) bằng `fgets()`. In ra chuỗi đã nhập.
Xóa ký tự `\n` thừa do `fgets` để lại.

---

## Bài 2: Đếm ký tự trong chuỗi (str_length.c)
Nhập chuỗi. Đếm số ký tự trong chuỗi **không dùng `strlen()`** (tự đếm bằng vòng lặp đến `\0`).

**Input:** `Nhap chuoi: PRF192`  
**Output:** `Chuoi co 6 ky tu`

---

## Bài 3: So sánh chuỗi tự viết (my_strcmp.c)
Viết hàm `int myStrcmp(char s1[], char s2[])` tự so sánh 2 chuỗi (không dùng `strcmp`):
- Trả về `0` nếu bằng nhau
- Trả về `1` nếu `s1 > s2`
- Trả về `-1` nếu `s1 < s2`

Nhập 2 chuỗi, gọi hàm và in kết quả so sánh.

---

## Bài 4: Kiểm tra chuỗi rỗng (empty_check.c)
Nhập chuỗi. Kiểm tra chuỗi có rỗng không (độ dài = 0 hoặc chỉ gồm khoảng trắng).
Dùng vòng lặp duyệt từng ký tự.

---

## Bài 5: Đảo ngược chuỗi (reverse_string.c)
Nhập chuỗi. In chuỗi đảo ngược.

**Input:** `Nhap chuoi: PRF192`  
**Output:** `Chuoi dao nguoc: 291FRP`

**Yêu cầu:** Không dùng `strrev()`. Tự cài đặt bằng vòng lặp.
