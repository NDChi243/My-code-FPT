# ➕ Biểu Thức và Toán Tử trong C

## 1. Toán tử là gì?

**Toán tử (operator)** là ký hiệu bảo máy tính thực hiện một phép toán.
**Biểu thức (expression)** là tổ hợp của toán tử và toán hạng (hằng, biến, hàm).

```
Ví dụ:    a + b * 5
           ↑   ↑   ↑
        toán hạng  toán hạng
             ↑
          toán tử
```

## 2. Phân loại toán tử

### 2.1 Toán tử số học (Arithmetic Operators)

| Toán tử | Ý nghĩa | Ví dụ | Kết quả |
|---------|---------|-------|---------|
| `+` | Cộng | `5 + 3` | `8` |
| `-` | Trừ | `5 - 3` | `2` |
| `*` | Nhân | `5 * 3` | `15` |
| `/` | Chia | `5 / 3` | `1` (chia nguyên) |
| `%` | Chia lấy dư (modulo) | `5 % 3` | `2` |

> ⚠️ **Lưu ý:** `5 / 3` với số nguyên = 1 (không phải 1.666)! Muốn số thực thì `5.0 / 3`.

```c
#include <stdio.h>

int main() {
    int a = 10, b = 3;
    
    printf("%d + %d = %d\n", a, b, a + b);   // 13
    printf("%d - %d = %d\n", a, b, a - b);   // 7
    printf("%d * %d = %d\n", a, b, a * b);   // 30
    printf("%d / %d = %d (chia nguyen)\n", a, b, a / b);  // 3
    printf("%d %% %d = %d (phan du)\n", a, b, a % b);     // 1
    
    // Chia số thực
    printf("%d / %d = %.2f (so thuc)\n", a, b, (float)a / b);  // 3.33
    
    return 0;
}
```

### 2.2 Toán tử gán (Assignment Operators)

| Toán tử | Tương đương | Ví dụ |
|---------|------------|-------|
| `=` | `x = 5` | Gán 5 cho x |
| `+=` | `x = x + 5` | `x += 5` |
| `-=` | `x = x - 5` | `x -= 5` |
| `*=` | `x = x * 5` | `x *= 5` |
| `/=` | `x = x / 5` | `x /= 5` |
| `%=` | `x = x % 5` | `x %= 5` |
| `++` | `x = x + 1` | `x++` hoặc `++x` |
| `--` | `x = x - 1` | `x--` hoặc `--x` |

### 2.3 Toán tử tăng/giảm — `++` và `--`

```c
#include <stdio.h>

int main() {
    int x = 5;
    
    // Prefix: ++x — tăng trước, dùng sau
    printf("x = %d\n", x);     // 5
    printf("++x = %d\n", ++x); // 6 (tăng x lên 6, rồi in)
    printf("x = %d\n", x);     // 6
    
    // Postfix: x++ — dùng trước, tăng sau
    x = 5;
    printf("\nx = %d\n", x);   // 5
    printf("x++ = %d\n", x++); // 5 (in x=5 trước, rồi tăng lên 6)
    printf("x = %d\n", x);     // 6
    
    return 0;
}
```

> **Mẹo nhớ:** Prefix (++x) = tăng rồi dùng; Postfix (x++) = dùng rồi tăng.

### 2.4 Toán tử quan hệ (Relational Operators)

| Toán tử | Ý nghĩa | Ví dụ | Kết quả |
|---------|---------|-------|---------|
| `==` | Bằng | `5 == 5` | `1` (true) |
| `!=` | Không bằng | `5 != 3` | `1` (true) |
| `>` | Lớn hơn | `5 > 3` | `1` (true) |
| `<` | Nhỏ hơn | `5 < 3` | `0` (false) |
| `>=` | Lớn hơn hoặc bằng | `5 >= 5` | `1` (true) |
| `<=` | Nhỏ hơn hoặc bằng | `5 <= 3` | `0` (false) |

> Kết quả: **1** = đúng (true), **0** = sai (false). Trong C, mọi số ≠ 0 đều là true!

### 2.5 Toán tử logic (Logical Operators)

| Toán tử | Ý nghĩa | Ví dụ | Kết quả |
|---------|---------|-------|---------|
| `&&` | VÀ (AND) | `(5>3) && (5<10)` | `1` |
| `\|\|` | HOẶC (OR) | `(5>3) \|\| (5>10)` | `1` |
| `!` | PHỦ ĐỊNH (NOT) | `!(5>3)` | `0` |

```c
#include <stdio.h>

int main() {
    int tuoi = 20;
    float diem = 8.5;
    
    // Kiểm tra điều kiện phức tạp
    int ketQua = (tuoi >= 18) && (diem >= 5.0);
    printf("Du tuoi va du diem: %d\n", ketQua);  // 1
    
    // Short-circuit evaluation
    int a = 0, b = 5;
    if (a != 0 && b / a > 2) {  // Bỏ qua vế phải vì a=0 → false
        printf("Không chạy đến đây\n");
    }
    
    return 0;
}
```

> **Short-circuit:** Với `&&`, nếu vế trái sai → không tính vế phải. Với `||`, nếu vế trái đúng → không tính vế phải.

### 2.6 Toán tử bitwise (Bitwise Operators) ⭐

| Toán tử | Ý nghĩa | Ví dụ | Kết quả |
|---------|---------|-------|---------|
| `&` | AND bit | `5 & 3` | `1` (101 & 011 = 001) |
| `\|` | OR bit | `5 \| 3` | `7` (101 \| 011 = 111) |
| `^` | XOR bit | `5 ^ 3` | `6` (101 ^ 011 = 110) |
| `~` | NOT bit | `~5` | `-6` (111...1010) |
| `<<` | Dịch trái | `5 << 1` | `10` (101 → 1010) |
| `>>` | Dịch phải | `5 >> 1` | `2` (101 → 10) |

```c
#include <stdio.h>

int main() {
    unsigned char a = 5;  // 0000 0101
    unsigned char b = 3;  // 0000 0011
    
    printf("a & b = %d\n", a & b);   // 1  (0000 0001)
    printf("a | b = %d\n", a | b);   // 7  (0000 0111)
    printf("a ^ b = %d\n", a ^ b);   // 6  (0000 0110)
    printf("~a = %d\n", (unsigned char)~a); // 250 (1111 1010)
    printf("a << 1 = %d\n", a << 1); // 10 (0000 1010)
    printf("a >> 1 = %d\n", a >> 1); // 2  (0000 0010)
    
    return 0;
}
```

### 2.7 Toán tử ba ngôi (Ternary Operator)

```c
// Cú pháp: dieu_kien ? gia_tri_dung : gia_tri_sai
int x = 10, y = 20;
int max = (x > y) ? x : y;  // max = 20

// Tương đương với:
int max;
if (x > y) {
    max = x;
} else {
    max = y;
}
```

## 3. Độ ưu tiên toán tử (Operator Precedence)

Thứ tự từ cao xuống thấp:

| Mức | Toán tử | Ghi chú |
|-----|---------|---------|
| 1 | `()` `[]` `.` `->` | Cao nhất |
| 2 | `++` `--` (prefix) `+` `-` (unary) `!` `~` `*` `&` `sizeof` | Unary |
| 3 | `*` `/` `%` | Nhân, chia, chia dư |
| 4 | `+` `-` | Cộng, trừ |
| 5 | `<<` `>>` | Dịch bit |
| 6 | `<` `<=` `>` `>=` | So sánh |
| 7 | `==` `!=` | So sánh bằng |
| 8 | `&` | AND bit |
| 9 | `^` | XOR bit |
| 10 | `\|` | OR bit |
| 11 | `&&` | AND logic |
| 12 | `\|\|` | OR logic |
| 13 | `?:` | Ba ngôi |
| 14 | `=` `+=` `-=` `*=` `/=` `%=` `>>=` `<<=` `&=` `^=` `\|=` | Gán |
| 15 | `,` | Thấp nhất |

```c
#include <stdio.h>

int main() {
    int a = 2, b = 3, c = 4;
    
    // Thứ tự: * trước +, nên: 2 + 12 = 14
    int kq1 = a + b * c;
    printf("a + b * c = %d\n", kq1);  // 14
    
    // () thay đổi thứ tự: (2+3)*4 = 20
    int kq2 = (a + b) * c;
    printf("(a + b) * c = %d\n", kq2);  // 20
    
    // Biểu thức phức tạp
    int kq3 = a++ - --b + c * 2;
    printf("a++ - --b + c * 2 = %d\n", kq3);
    
    return 0;
}
```

> **Mẹo:** Khi không chắc thứ tự ưu tiên → dùng `()` cho rõ ràng. Code dễ đọc hơn code ngắn!

## 4. Chuyển đổi kiểu trong biểu thức

### Implicit conversion (tự động)
```c
int a = 5;
float b = 2.5;
float kq = a + b;  // a tự động chuyển thành 5.0f → kq = 7.5
```

### Explicit conversion (chủ động — ép kiểu)
```c
int a = 5, b = 2;
float kq1 = a / b;          // 2.0  (vì a/b = 2 → float)
float kq2 = (float)a / b;   // 2.5  (a thành 5.0, 5.0/2 = 2.5)
```

## 5. Bài tập thực hành

### Bài 1: Tính toán cơ bản
Nhập 2 số nguyên a, b. Tính và in:
```
a + b = ...
a - b = ...
a * b = ...
a / b = ... (phần nguyên)
a / b = ... (số thực, 2 số lẻ)
a % b = ...
```

### Bài 2: Hoán đổi giá trị (không dùng biến phụ)
Nhập a, b. In ra trước và sau khi hoán đổi bằng cách dùng `+` và `-` (hoặc `^` XOR):
```
Truoc: a=5, b=10
Sau:   a=10, b=5
```

### Bài 3: Tiền điện
Nhập số kWh. Tính tiền theo bậc:
- 0–50 kWh: 1.678đ/kWh
- 51–100 kWh: 1.734đ/kWh
- Trên 100 kWh: 2.014đ/kWh

Dùng toán tử ba ngôi `?:` và biểu thức.

### Bài 4: Kiểm tra năm nhuận
Nhập năm. Dùng biểu thức logic để kiểm tra:
- Chia hết cho 400 → nhuận
- Chia hết cho 4 và KHÔNG chia hết cho 100 → nhuận

In `1` nếu nhuận, `0` nếu không. Dùng 1 dòng code (toán tử `&&`, `||`).

## 📚 Tham khảo thêm

- [GeeksforGeeks — Operators in C](https://www.geeksforgeeks.org/operators-in-c/)
- [Programiz — C Operators](https://www.programiz.com/c-programming/c-operators)
- [Operator Precedence Table](https://en.cppreference.com/w/c/language/operator_precedence)
- [Video: Bitwise Operations](https://www.youtube.com/watch?v=4vN4YkAY_Ek)
