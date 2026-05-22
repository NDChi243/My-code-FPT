# Slot 32 — Bài tập: Thư viện stdlib.h & time.h

## Bài 1: Sinh mảng ngẫu nhiên (random_array.c)
Nhập `n`. Dùng `srand(time(NULL))` và `rand()` để sinh mảng `n` số ngẫu nhiên trong `[10, 99]`. In mảng ra màn hình.

---

## Bài 2: Game Kéo - Búa - Bao (rock_paper_scissors.c)
Máy tính random 0=Keo, 1=Bua, 2=Bao. Người chơi nhập lựa chọn.
In kết quả: "Thang!", "Thua!", "Hoa!". Chơi đến khi người chơi chọn thoát.

**Yêu cầu:** Đếm số trận thắng của người chơi.

---

## Bài 3: Chuyển chuỗi thành số (string_to_num.c)
Nhập một chuỗi từ bàn phím. Dùng `atoi()` và `atof()` để chuyển thành số nguyên và số thực.

**Input:** `Nhap chuoi: 123.45abc`  
**Output:**
```
atoi("123.45abc") = 123
atof("123.45abc") = 123.45
```

**Yêu cầu:** Xử lý trường hợp `atoi`/`atof` trả về 0 (kiểm tra chuỗi hợp lệ).

---

## Bài 4: Tìm số lớn nhất ngẫu nhiên (max_random.c)
Sinh ngẫu nhiên 20 số trong `[1, 100]`. In ra các số và tìm số lớn nhất, kèm vị trí xuất hiện đầu tiên.

**Output mẫu:**
```
Cac so: 45 12 78 23 91 34 ...
So lon nhat: 91 (o vi tri thu 5)
```
