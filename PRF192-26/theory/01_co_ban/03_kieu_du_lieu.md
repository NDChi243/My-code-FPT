# 🏷️ Kiểu Dữ Liệu trong C

## 1. Tổng quan

Mỗi kiểu dữ liệu trong C quyết định:
- **Kích thước** (số byte) — biến chiếm bao nhiêu RAM
- **Dải giá trị** — số lớn/nhỏ nhất có thể lưu
- **Cách biểu diễn** — số nguyên, số thực, ký tự,...

```
Kiểu dữ liệu C
├── Cơ bản (Primitive)
│   ├── char     — 1 byte, ký tự
│   ├── int      — 4 byte, số nguyên
│   ├── float    — 4 byte, số thực
│   ├── double   — 8 byte, số thực chính xác kép
│   └── void     — không kiểu
├── Dẫn xuất (Derived)
│   ├── array    — mảng
│   ├── pointer  — con trỏ
│   └── struct   — cấu trúc
└── Định nghĩa (User-defined)
    ├── typedef
    └── enum
```

## 2. Kiểu `char` — Ký tự

Lưu một ký tự theo bảng mã ASCII.

```c
#include <stdio.h>

int main() {
    char c1 = 'A';       // Ký tự chữ
    char c2 = 65;        // Số 65 = 'A' trong bảng ASCII
    char c3 = '\n';      // Ký tự xuống dòng (escape sequence)
    
    printf("c1 = %c, ma ASCII: %d\n", c1, c1);   // A, 65
    printf("c2 = %c, ma ASCII: %d\n", c2, c2);   // A, 65
    printf("c3 la ky tu xuong dong");
    
    // Duyệt bảng ASCII
    for (int i = 32; i <= 126; i++) {
        printf("%3d: %c\t", i, i);
        if ((i - 32 + 1) % 5 == 0) printf("\n");
    }
    
    return 0;
}
```

### Bảng ASCII cần nhớ (một phần)

| Giá trị | Ký tự | Ý nghĩa |
|---------|-------|---------|
| 48–57 | `'0'` → `'9'` | Chữ số |
| 65–90 | `'A'` → `'Z'` | Chữ hoa |
| 97–122 | `'a'` → `'z'` | Chữ thường |
| 32 | ` ` | Space |
| 0 | `\0` | Null terminator (kết thúc chuỗi) |
| 10 | `\n` | Newline (xuống dòng) |

### `signed char` vs `unsigned char`

```c
signed char c1 = -128;    // OK: -128..127
unsigned char c2 = 255;   // OK: 0..255
// signed char c3 = 200;  // WARNING: vượt quá 127!
```

## 3. Kiểu `int` — Số nguyên

```c
#include <stdio.h>
#include <limits.h>  // Chứa INT_MIN, INT_MAX, ...

int main() {
    int a = 42;
    int b = -100;
    int c = 0xFF;       // Hệ thập lục phân (255)
    int d = 0b1010;     // Hệ nhị phân (10) — C99 (một số compiler)
    
    printf("int: %d byte, tu %d den %d\n", 
           sizeof(int), INT_MIN, INT_MAX);
    printf("unsigned int: %d byte, tu 0 den %u\n", 
           sizeof(unsigned int), UINT_MAX);
    
    return 0;
}
```

### Các biến thể của int

| Kiểu | Kích thước | Dải giá trị |
|------|-----------|-------------|
| `short int` | 2 byte | -32.768 → 32.767 |
| `unsigned short` | 2 byte | 0 → 65.535 |
| `int` | 4 byte | -2.147.483.648 → 2.147.483.647 |
| `unsigned int` | 4 byte | 0 → 4.294.967.295 |
| `long int` | 4 byte (Win) / 8 byte (Linux) | Giống int hoặc rộng hơn |
| `long long int` | 8 byte | -2⁶³ → 2⁶³-1 |

## 4. Kiểu `float` và `double` — Số thực

```c
#include <stdio.h>
#include <float.h>  // Chứa FLT_MIN, DBL_MAX, ...

int main() {
    float f = 3.14159f;         // Chú ý hậu tố 'f'
    double d = 3.14159265358979;
    
    printf("float:  %d byte\n", sizeof(float));
    printf("double: %d byte\n", sizeof(double));
    
    printf("\nfloat precision: %d chu so\n", FLT_DIG);
    printf("double precision: %d chu so\n", DBL_DIG);
    
    // So sánh độ chính xác
    float  fPi = 3.14159265358979f;
    double dPi = 3.14159265358979;
    
    printf("\nfloat pi = %.15f\n", fPi);   // Chỉ đúng ~6-7 số
    printf("double pi = %.15f\n", dPi);    // Đúng ~15 số
    
    return 0;
}
```

### Khi nào dùng float, khi nào dùng double?

| Tình huống | Dùng | Lý do |
|-----------|------|-------|
| Điểm sinh viên (0–10) | `float` | Đủ chính xác, tiết kiệm bộ nhớ |
| Tính toán khoa học | `double` | Cần độ chính xác cao |
| Đồ họa game | `float` | Hàng nghìn phép tính/giây |
| Tiền tệ/lãi suất | `double` hoặc dùng số nguyên (xu) | Tránh sai số do làm tròn |

## 5. Kiểu `void` — Không kiểu

```c
void inThongBao();       // Hàm không trả về giá trị
void *conTro;            // Con trỏ void — trỏ được tới mọi kiểu
```

## 6. `typedef` — Đặt tên mới cho kiểu

```c
#include <stdio.h>

typedef int SoNguyen;           // SoNguyen = int
typedef float DiemSo;           // DiemSo = float
typedef unsigned long long ULL; // ULL = unsigned long long

int main() {
    SoNguyen x = 10;
    DiemSo  diem = 8.75;
    ULL     big = 1234567890ULL;
    
    printf("x = %d, diem = %.2f, big = %llu\n", x, diem, big);
    
    return 0;
}
```

## 7. `enum` — Kiểu liệt kê

```c
#include <stdio.h>

// Định nghĩa enum
enum Thu { HAI = 2, BA, TU, NAM, SAU, BAY, CHU_NHAT = 8 };
enum Thang { THANG_1 = 1, THANG_2, THANG_3, THANG_4, THANG_5, THANG_6,
             THANG_7, THANG_8, THANG_9, THANG_10, THANG_11, THANG_12 };
enum GioiTinh { NAM = 0, NU = 1, KHAC = 2 };

int main() {
    enum Thu homNay = TU;
    printf("Hom nay la thu %d\n", homNay);  // 4
    
    enum Thang sinhNhat = THANG_9;
    printf("Sinh nhat thang %d\n", sinhNhat);  // 9
    
    return 0;
}
```

## 8. Bảng tóm tắt kiểu dữ liệu

| Kiểu | Từ khóa | Byte | Format specifier |
|------|---------|------|-----------------|
| Ký tự | `char` | 1 | `%c` |
| Số nguyên | `int` | 4 | `%d` |
| Số nguyên ngắn | `short` | 2 | `%hd` |
| Số nguyên dài | `long` | 4/8 | `%ld` |
| Số nguyên rất dài | `long long` | 8 | `%lld` |
| Số thực | `float` | 4 | `%f` |
| Số thực chính xác kép | `double` | 8 | `%lf` (scanf), `%f` (printf) |
| Không dấu | `unsigned` | — | `%u` |
| Địa chỉ | con trỏ | 4/8 | `%p` |

## 9. Bài tập thực hành

### Bài 1: ASCII art
In ra bảng ASCII từ mã 32 đến 126, mỗi dòng 8 ký tự.

### Bài 2: Kiểm tra giới hạn
Dùng `limits.h` và `float.h` để in ra:
- `INT_MAX`, `INT_MIN`
- `UINT_MAX`
- `FLT_MAX`, `FLT_MIN`
- `DBL_MAX`, `DBL_MIN`

### Bài 3: So sánh float vs double
Khai báo `float f = 1.0f / 3.0f;` và `double d = 1.0 / 3.0;`. In cả hai với 20 chữ số thập phân. Quan sát sự khác biệt.

### Bài 4: typedef + enum
Định nghĩa `enum Mua { XUAN, HA, THU, DONG };` và `typedef enum Mua MuaTrongNam;`. Khai báo biến `MuaTrongNam muaHienTai = THU;` và in ra.

## 📚 Tham khảo thêm

- [GeeksforGeeks — Data Types in C](https://www.geeksforgeeks.org/data-types-in-c/)
- [C Programming — Data Types (Programiz)](https://www.programiz.com/c-programming/c-data-types)
- [Bảng ASCII đầy đủ](https://www.asciitable.com/)
- [Float vs Double (Stack Overflow)](https://stackoverflow.com/questions/2386772/what-is-the-difference-between-float-and-double)
