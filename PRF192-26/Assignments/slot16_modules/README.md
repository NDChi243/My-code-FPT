# Slot 16 — Bài tập: Module

## Bài 1: Phân rã bài toán (problem_decomp.c)
Cho bài toán: "Quản lý thư viện sách". Viết chương trình in ra sơ đồ phân rã các module chức năng dạng text:

```
===== HE THONG QUAN LY THU VIEN =====
1. Quan ly sach
   - Them sach moi
   - Tim sach theo ten
   - Cap nhat so luong
2. Quan ly doc gia
   - Dang ky doc gia
   - Tra cuu doc gia
3. Quan ly muon tra
   - Cho muon sach
   - Nhan tra sach
4. Bao cao thong ke
   - Thong ke sach dang muon
   - Thong ke doc gia qua han
```

**Yêu cầu:** Chỉ dùng `printf`. Mỗi menu mục 1-4 gọi một hàm riêng (chưa cần xử lý, chỉ in tên).

---

## Bài 2: Chia để trị (divide_conquer.c)
Viết chương trình: Nhập một số nguyên `n`. Tính:
- Tổng các số từ 1 đến `n` (gọi hàm `tinhTong1()`)
- Tổng các số lẻ từ 1 đến `n` (gọi hàm `tinhTongLe()`)
- Tổng các số chẵn từ 1 đến `n` (gọi hàm `tinhTongChan()`)

**Yêu cầu:** Mỗi hàm làm một việc duy nhất. Prototype trước `main()`.

---

## Bài 3: Menu chức năng (module_menu.c)
Viết chương trình có menu:
```
===== MENU =====
1. Tinh tong
2. Tinh hieu
3. Tinh tich
4. Thoat
```
Nhập lựa chọn (1-4). Nếu 1-3 thì nhập 2 số và in kết quả tương ứng. Chọn 4 thì kết thúc.

**Yêu cầu:** Mỗi chức năng là một hàm riêng (`tinhTong()`, `tinhHieu()`, `tinhTich()`). Dùng `do-while` cho menu.
