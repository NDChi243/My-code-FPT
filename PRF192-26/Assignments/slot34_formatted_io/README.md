# Slot 34 — Bài tập: Nhập xuất có định dạng

## Bài 1: In bảng điểm (grade_table.c)
In bảng điểm 3 sinh viên với format căn lề đẹp:

```
+------+-----------------+------+------+------+-------+
|  STT | Ho ten          | Toan |  Ly  |  Hoa |  TB   |
+------+-----------------+------+------+------+-------+
|   1  | Nguyen Van A    | 8.50 | 7.00 | 9.00 |  8.17 |
|   2  | Tran Thi B      | 6.50 | 8.00 | 7.50 |  7.33 |
|   3  | Le Van C        | 9.00 | 9.50 | 8.00 |  8.83 |
+------+-----------------+------+------+------+-------+
```

**Yêu cầu:** Dùng `%5.2f`, `%-15s`, `%4d` để căn chỉnh.

---

## Bài 2: Định dạng số (number_format.c)
Nhập một số thực. In ra các định dạng khác nhau:
```c
double x;
printf("Nhap so thuc: ");
scanf("%lf", &x);
printf("%%10.2f: [%10.2f]\n", x);
printf("%%-10.2f: [%-10.2f]\n", x);
printf("%%010.2f: [%010.2f]\n", x);
printf("%%+.2f: [%+.2f]\n", x);
printf("%% .2f: [% .2f]\n", x);
```

Quan sát sự khác nhau giữa các format specifier.

---

## Bài 3: Căn lề chuỗi (string_align.c)
Nhập họ tên (dùng `fgets`). In ra với 3 kiểu căn lề:
```
[%-20s]  (can trai)
[%20s]   (can phai)
[%10.10s] (cat ngan 10 ky tu)
```

---

## Bài 4: Bảng chuyển đổi nhiệt độ (temp_table.c)
In bảng chuyển đổi từ độ C sang độ F từ 0 đến 100, mỗi bước 10 độ:

```
  C     |    F
--------+--------
  0.00  |  32.00
 10.00  |  50.00
 20.00  |  68.00
...
100.00  | 212.00
```

**Yêu cầu:** Dùng `%7.2f` cho số, căn giữa bằng dấu `|`.
