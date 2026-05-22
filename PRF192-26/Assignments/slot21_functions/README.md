# Slot 21 — Bài tập: Built-in vs User-defined Functions

## Bài 1: Viết lại hàm pow() (my_pow.c)
Viết hàm `double myPow(double base, int exp)` tự tính lũy thừa bằng vòng lặp (không dùng `math.h`).

**Yêu cầu:** Xử lý `exp` âm (trả về `1 / myPow(base, -exp)`).

---

## Bài 2: Hàm abs() tự chế (my_abs.c)
Viết hàm `int myAbs(int n)` tự tính giá trị tuyệt đối không dùng `abs()` trong `stdlib.h`.

Trong `main()`, nhập số nguyên, gọi cả `myAbs()` và `abs()` để so sánh kết quả.

---

## Bài 3: Ứng dụng math.h — giải phương trình bậc 2 (quadratic_math.c)
Nhập `a, b, c` (số thực). Giải phương trình `ax^2 + bx + c = 0` dùng `sqrt()` từ `math.h`.

**Yêu cầu:**
- Xét đủ trường hợp: `a == 0` (pt bậc 1), `delta > 0`, `delta == 0`, `delta < 0`
- Kiểm tra `a, b, c` hợp lệ (số thực)

---

## Bài 4: Sinh số ngẫu nhiên — game xúc xắc (dice_game.c)
Dùng `rand()` và `srand(time(NULL))` để mô phỏng tung 2 con xúc xắc (6 mặt).

In kết quả mỗi lần tung:
```
Tung xuc xac: 3 + 5 = 8
```
Cho người chơi đoán tổng (2-12). Nếu đúng → "Chuc mung!", sai → "Tong la X. Ban doan sai!"
