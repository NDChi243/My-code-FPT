# 🖥️ Giới Thiệu Ngôn Ngữ C

## 1. C là gì?

**C** là ngôn ngữ lập trình bậc trung (middle-level), được phát triển bởi **Dennis Ritchie** tại Bell Labs năm 1972.

| Đặc điểm | Mô tả |
|---------|-------|
| 🏗️ Kiểu | Thủ tục (Procedural) — chương trình là chuỗi các hàm |
| ⚡ Tốc độ | Nhanh, gần với assembly |
| 🔧 Ứng dụng | Hệ điều hành, Embedded, Game Engine, Compiler |
| 📚 Cơ sở | Ảnh hưởng đến C++, Java, C#, Python (CPython) |

## 2. Cấu trúc chương trình C

```c
#include <stdio.h>   // Thư viện nhập xuất chuẩn
#include <stdlib.h>  // Thư viện hàm tiện ích

// Hàm main — điểm vào của chương trình
int main() {
    // Code ở đây
    printf("Hello, World!\n");
    
    return 0;  // Báo cho OS biết chương trình kết thúc thành công
}
```

### Giải thích từng dòng:

| Dòng code | Ý nghĩa |
|-----------|---------|
| `#include <stdio.h>` | Nạp thư viện chứa `printf`, `scanf`, `fopen`,... |
| `int main()` | Hàm chính — khi chạy .exe, máy tính chạy `main()` đầu tiên |
| `{ ... }` | Khối lệnh — body của hàm |
| `printf(...)` | In ra màn hình console |
| `return 0;` | Trả về 0 cho OS = chương trình chạy thành công |

## 3. Quy trình biên dịch

```
Code (.c)  →  Preprocessor  →  Compiler  →  Assembler  →  Linker  →  Executable (.exe)
   viết         xử lý #include    dịch sang asm   asm → obj     ghép thư viện      chạy được
```

Trên Dev-C++: nhấn **F9** (Compile & Run) — tự động làm tất cả các bước trên.

## 4. Comment trong C

```c
// Comment 1 dòng — dùng giải thích ngắn

/*
   Comment nhiều dòng
   Dùng để giải thích dài hoặc
   tạm thời vô hiệu hóa code
*/
```

## 5. Quy tắc đặt tên (Identifier)

| Quy tắc | Ví dụ đúng | Ví dụ sai |
|---------|-----------|-----------|
| Chữ cái, số, underscore `_` | `soSinhVien`, `tinhTong` | `so-sv`, `tinh.tong` |
| **Không bắt đầu bằng số** | `mang1`, `arr2` | `1mang`, `2arr` |
| Phân biệt hoa/thường | `So` ≠ `so` ≠ `SO` | — |
| Không trùng từ khóa | — | `int`, `return`, `if` |

> **Quy tắc đặt tên cho môn PRF192:** Dùng **camelCase** — chữ đầu viết thường, chữ sau viết hoa: `soLuong`, `tinhDiemTrungBinh`, `timKiemNhiPhan`.

### Từ khóa (Keywords) — không được dùng làm tên biến

```
auto    break   case    char    const   continue    default
do      double  else    enum    extern  float       for
goto    if      int     long    register return     short
signed  sizeof  static  struct  switch  typedef     union
unsigned void    volatile while
```

## 6. Hằng số `#define` và `const`

```c
#include <stdio.h>
#define PI 3.14159      // Hằng số — thay thế văn bản, không tốn bộ nhớ
const int MAX = 100;    // Hằng số — kiểu dữ liệu rõ ràng

int main() {
    printf("PI = %.5f\n", PI);
    // PI = 3.14;   // ❌ Lỗi! Không thể gán lại hằng số
    // MAX = 200;   // ❌ Lỗi!
    
    return 0;
}
```

### `#define` vs `const`

| Tiêu chí | `#define` | `const` |
|---------|-----------|---------|
| Xử lý tại | Preprocessor (trước biên dịch) | Compiler (lúc biên dịch) |
| Kiểu dữ liệu | Không có kiểu — chỉ thay text | Có kiểu cụ thể |
| Debug | Khó (không thấy trong debugger) | Dễ |
| Tốn bộ nhớ | Không (chỉ thay text) | Có (biến thường) |

## 7. Bài tập thực hành

### Bài 1: Hello World nâng cao
Viết chương trình in ra:
```
Ten cua ban: Nguyen Van A
MSSV: SE123456
Mon hoc: PRF192
Truong: FPT University
```

### Bài 2: Hằng số và biến
Khai báo hằng số `SO_PI = 3.14159`, khai báo biến `banKinh = 5`. Tính và in chu vi hình tròn `C = 2 * SO_PI * banKinh`.

### Bài 3: Sửa lỗi
```c
#include <stdio.h>
int main() {
    int 1stNumber = 10;     // Lỗi 1
    int return = 20;        // Lỗi 2
    printf("Tong: %d", 1stNumber + return);
    return 0
}                           // Lỗi 3: thiếu dấu ?
```

## 📚 Tham khảo thêm

- [Learn-C.org — Introduction](https://www.learn-c.org/)
- [W3Schools — C Tutorial](https://www.w3schools.com/c/)
- [GeeksforGeeks — C Programming Language](https://www.geeksforgeeks.org/c-programming-language/)
- [Video: CS50 — C (Bài giảng của Harvard)](https://www.youtube.com/watch?v=zYierUhIFNQ)
