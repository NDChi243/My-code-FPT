# Slot 48 — Bài tập: Mảng chuỗi & Thư viện string.h

## Bài 1: Sắp xếp mảng chuỗi (sort_strings.c)
Nhập `n` chuỗi (tối đa 10 chuỗi, mỗi chuỗi tối đa 50 ký tự).
Sắp xếp các chuỗi theo thứ tự alphabet (dùng `strcmp`).
In danh sách trước và sau khi sắp xếp.

---

## Bài 2: Ghép chuỗi (string_concat.c)
Nhập 2 chuỗi `s1` và `s2`. Dùng `strcat()` để ghép `s2` vào `s1`.
In chuỗi kết quả.

**Yêu cầu:** Đảm bảo `s1` đủ lớn để chứa kết quả ghép.

---

## Bài 3: Tìm kiếm trong chuỗi (string_search.c)
Nhập chuỗi `str` và từ khóa `key`. Dùng `strstr()` để tìm `key` trong `str`.
Nếu tìm thấy, in vị trí bắt đầu (chỉ số). Nếu không, in "Khong tim thay."

---

## Bài 4: Sao chép chuỗi (string_copy.c)
Nhập chuỗi `src`. Dùng `strcpy()` để copy sang `dest`.
Tự cài đặt hàm `void myStrcpy(char dest[], char src[])` và so sánh kết quả.

---

## Bài 5: Đếm ký tự đặc biệt (count_vowels_consonants.c)
Nhập chuỗi. Đếm:
- Số nguyên âm (a, e, i, o, u, A, E, I, O, U)
- Số phụ âm
- Số ký tự khác (số, khoảng trắng, ký tự đặc biệt)

Dùng `strchr()` để kiểm tra nguyên âm.
