# Slot 49-50 — Bài tập: Ôn tập CLO8

## Bài 1: Kiểm tra Palindrome (palindrome_string.c)
Nhập chuỗi. Kiểm tra chuỗi có đối xứng (palindrome) không?
(Bỏ qua khoảng trắng và phân biệt hoa/thường).

**Ví dụ:** "Race car", "A man a plan a canal Panama" là palindrome.

---

## Bài 2: Chuẩn hóa tên (normalize_name.c)
Nhập họ tên (có thể thừa khoảng trắng đầu/cuối/giữa). Chuẩn hóa:
- Xóa khoảng trắng đầu và cuối
- Giữa các từ chỉ 1 khoảng trắng
- Viết hoa chữ cái đầu mỗi từ

**Input:** `"   nguyen  VAN   anh  "`  
**Output:** `"Nguyen Van Anh"`

---

## Bài 3: Mã hóa Caesar (caesar_cipher.c)
Nhập chuỗi và số `k` (1-25). Mã hóa chuỗi bằng Caesar cipher:
- Mỗi chữ cái dịch lên `k` vị trí trong bảng chữ cái
- Giữ nguyên chữ hoa/thường
- Ký tự không phải chữ cái giữ nguyên

**Input:** `Chuoi: "Hello World", k = 3`  
**Output:** `"Khoor Zruog"`
