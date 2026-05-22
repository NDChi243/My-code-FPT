# 🔄 Ép Kiểu trong C

## 1. Tại sao cần ép kiểu?

Trong C, khi các toán hạng khác kiểu, compiler cần chuyển đổi để thực hiện phép toán. Có 2 loại:

1. **Implicit (ngầm định)** — compiler tự động làm
2. **Explicit (tường minh)** — lập trình viên chủ động làm

## 2. Implicit Conversion — Chuyển đổi ngầm định

### Nguyên tắc: "chuyển lên" (type promotion)

```
char → short → int → unsigned int → long → unsigned long → float → double
```

Compiler tự động chuyển kiểu "nhỏ hơn" thành kiểu "lớn hơn" để tránh mất dữ liệu.

### Ví dụ
```c
#include <stdio.h>

int main() {
    char c = 'A';        // 1 byte
    int  i = 100;        // 4 byte
    float f = 3.14f;     // 4 byte
    double d = 2.718;    // 8 byte
    
    // c (char) → int: tự động
    int kq1 = c + i;     // 'A'(65) + 100 = 165
    printf("char + int = %d\n", kq1);
    
    // i (int) → double: tự động
    double kq2 = i + d;  // 100 + 2.718 = 102.718
    printf("int + double = %.3f\n", kq2);
    
    // f (float) → double: tự động
    double kq3 = f + d;  // 3.14 + 2.718 = 5.858
    printf("float + double = %.3f\n", kq3);
    
    // Hỗn hợp: mọi thứ → double
    double kq4 = c + i + f + d;  // 65 + 100 + 3.14 + 2.718
    printf("tong hop = %.3f\n", kq4);
    
    return 0;
}
```

### Cạm bẫy 1: Chia số nguyên

```c
#include <stdio.h>

int main() {
    int a = 5, b = 2;
    
    float kq1 = a / b;          // ❌ Sai: 5/2 = 2 (nguyên), rồi → 2.0
    printf("a/b = %.2f (sai!)\n", kq1);
    
    float kq2 = (float)a / b;   // ✅ Đúng: 5.0/2 = 2.5
    printf("(float)a/b = %.2f (dung!)\n", kq2);
    
    float kq3 = a / (float)b;   // ✅ Đúng: 5/2.0 = 2.5
    printf("a/(float)b = %.2f (dung!)\n", kq3);
    
    return 0;
}
```

### Cạm bẫy 2: Mất dữ liệu khi chuyển ngược

```c
#include <stdio.h>

int main() {
    double d = 3.14159;
    int i = d;                  // Ngầm: double → int, mất phần thập phân
    
    printf("double: %.5f\n", d);  // 3.14159
    printf("int: %d (mat phan thap phan)\n", i);  // 3
    
    // Với số lớn
    double big = 123456789.99;
    int truncated = big;
    printf("\n%.2f → int = %d\n", big, truncated);  // Mất .99
    
    return 0;
}
```

## 3. Explicit Cast — Ép kiểu tường minh

### Cú pháp
```c
(kieu_muon_chuyen)bieu_thuc
```

### Ví dụ
```c
#include <stdio.h>

int main() {
    double d = 3.14159;
    
    int i1 = (int)d;              // 3 (bỏ phần thập phân)
    int i2 = (int)(d + 0.5);      // 4 (làm tròn: +0.5 rồi ép)
    
    printf("(int)d = %d\n", i1);
    printf("(int)(d+0.5) = %d (lam tron)\n", i2);
    
    // Ép kiểu ký tự
    char c = (char)65;            // 'A'
    printf("(char)65 = %c\n", c);
    
    // Ép kiểu trong tính toán
    int a = 10, b = 4;
    double thuong = (double)a / b;  // Ép a thành double trước khi chia
    printf("(double)a/b = %.2f\n", thuong);
    
    return 0;
}
```

## 4. Các tình huống ép kiểu thường gặp

### 4.1 Lấy phần nguyên của số thực
```c
float diem = 8.75;
int diemNguyen = (int)diem;  // 8
```

### 4.2 Làm tròn số
```c
float diem = 8.75;
int diemLamTron = (int)(diem + 0.5);  // (int)9.25 = 9

// Làm tròn đến 1 số thập phân
float pi = 3.14159;
float piLamTron = (int)(pi * 10 + 0.5) / 10.0;  // 3.1
```

### 4.3 Ép kiểu con trỏ (nâng cao)
```c
#include <stdio.h>

int main() {
    int x = 0x41424344;  // 'ABCD' trong memory (little-endian)
    char *p = (char*)&x; // Ép con trỏ int* thành char*
    
    for (int i = 0; i < 4; i++) {
        printf("byte %d: %c\n", i, p[i]);
    }
    
    return 0;
}
```

## 5. Bảng chuyển đổi an toàn ✅

| Chuyển từ | → sang | An toàn? | Ghi chú |
|-----------|--------|----------|---------|
| `int` | `double` | ✅ | Tự động, không mất dữ liệu |
| `float` | `double` | ✅ | Tự động, chính xác hơn |
| `short` | `int` | ✅ | Mở rộng, không mất |
| `int` | `short` | ⚠️ | Mất dữ liệu nếu giá trị lớn |
| `double` | `float` | ⚠️ | Mất độ chính xác |
| `double` | `int` | ⚠️ | Mất phần thập phân |
| `int` | `char` | ⚠️ | Mất 3 byte! |
| `float` | `int` | ⚠️ | Mất phần thập phân |

## 6. Bài tập thực hành

### Bài 1: Chia số
Nhập 2 số nguyên a, b. Tính:
- Giá trị nguyên: `a / b` (kiểu int)
- Giá trị thực: `a / b` (kiểu float, 2 số lẻ)
- Phần dư: `a % b`

### Bài 2: Làm tròn điểm
Nhập điểm thực (0..10). Làm tròn đến:
- Số nguyên gần nhất
- 1 chữ số thập phân
- 2 chữ số thập phân

In tất cả kết quả.

### Bài 3: Tính tuổi chính xác
Nhập năm sinh (`int`), năm hiện tại (`int`). Tính tuổi (có thể là số thực nếu tính cả tháng). Dùng ép kiểu.

### Bài 4: Dự đoán output
```c
int a = 7, b = 2;
printf("%.2f\n", a / b);
printf("%.2f\n", (double)(a / b));
printf("%.2f\n", (double)a / b);
printf("%d\n", (int)(7.8 + 0.5));
```

## 📚 Tham khảo thêm

- [GeeksforGeeks — Type Casting in C](https://www.geeksforgeeks.org/type-casting-in-c/)
- [Programiz — Type Conversion](https://www.programiz.com/c-programming/type-conversion)
- [Implicit vs Explicit Conversion](https://www.tutorialspoint.com/cprogramming/c_type_casting.htm)
