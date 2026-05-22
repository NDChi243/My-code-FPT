# 📦 Biến và Hằng Số trong C

## 1. Biến (Variable) là gì?

**Biến** là vùng nhớ trong RAM, dùng để lưu trữ dữ liệu. Mỗi biến có:
- **Tên** (identifier) — để tham chiếu
- **Kiểu dữ liệu** — quyết định kích thước và cách lưu
- **Địa chỉ** — vị trí trong RAM
- **Giá trị** — nội dung đang lưu

### Khai báo biến

```c
// Cú pháp: <kieu_du_lieu> <ten_bien>;
int tuoi;               // Khai báo 1 biến
float diemToan, diemVan; // Khai báo nhiều biến cùng kiểu
char chuCai;

// Khai báo + khởi tạo (gán giá trị ban đầu)
int soLuong = 10;
float giaTien = 25000.5;
char kyTu = 'A';
```

> **Lưu ý C99:** Khai báo biến ở **đầu khối lệnh** `{}`, trước tất cả câu lệnh thực thi.

```c
// ❌ SAI (nếu compiler không hỗ trợ C99 hoặc dev-C++ mặc định)
int main() {
    printf("Hello\n");
    int x = 5;  // Khai báo sau lệnh thực thi
    return 0;
}

// ✅ ĐÚNG — khai báo ở đầu khối
int main() {
    int x = 5;
    printf("Hello\n");
    return 0;
}
```

## 2. Các kiểu dữ liệu cơ bản

| Kiểu | Từ khóa | Kích thước | Giá trị |
|------|---------|-----------|---------|
| Số nguyên | `int` | 4 bytes | -2.147.483.648 → 2.147.483.647 |
| Số thực | `float` | 4 bytes | ±3.4×10⁻³⁸ → ±3.4×10³⁸ |
| Số thực độ chính xác kép | `double` | 8 bytes | ±1.7×10⁻³⁰⁸ → ±1.7×10³⁰⁸ |
| Ký tự | `char` | 1 byte | -128 → 127 (hoặc 0 → 255 unsigned) |
| Không kiểu | `void` | 0 | Không có giá trị |

### Biến thể: `short`, `long`, `unsigned`

```c
short int s;            // 2 bytes
long int l;             // 4 hoặc 8 bytes
unsigned int u;         // 0 → 4.294.967.295 (không có số âm)
unsigned char c;        // 0 → 255
long double ld;         // 10 bytes (độ chính xác rất cao)
```

## 3. Hằng số (Constant)

### 3.1 Dùng `#define`

```c
#define SO_LUONG_SV 50
#define TEN_TRUONG "FPT University"
#define PI 3.14159

int main() {
    printf("Truong: %s\n", TEN_TRUONG);
    printf("So luong SV: %d\n", SO_LUONG_SV);
    // SO_LUONG_SV = 60; // ❌ Lỗi! #define không thể gán lại
    return 0;
}
```

### 3.2 Dùng `const`

```c
const int MAX = 100;
const float NHIET_DO_TRUNG_BINH = 37.5;
const char KY_TU = 'Z';

int main() {
    // MAX = 200; // ❌ Lỗi! const không thể thay đổi
    printf("Gia tri MAX: %d\n", MAX);
    return 0;
}
```

## 4. Địa chỉ bộ nhớ của biến — dùng `&` và `%p`

```c
#include <stdio.h>

int main() {
    int tuoi = 20;
    float diem = 8.5;
    char c = 'X';
    
    printf("Gia tri tuoi: %d\n", tuoi);
    printf("Dia chi cua tuoi: %p\n", (void*)&tuoi);
    
    printf("\nDia chi cua diem: %p\n", (void*)&diem);
    printf("Dia chi cua c: %p\n", (void*)&c);
    
    return 0;
}
```

Kết quả tham khảo (mỗi lần chạy có thể khác):
```
Gia tri tuoi: 20
Dia chi cua tuoi: 0060FEC4
Dia chi cua diem: 0060FEC0
Dia chi cua c: 0060FEBF
```

> Quan sát: `int` (4B), `float` (4B), `char` (1B) — các địa chỉ cách nhau đúng bằng kích thước kiểu!

## 5. `sizeof()` — Lấy kích thước kiểu dữ liệu

```c
#include <stdio.h>

int main() {
    printf("char:   %d byte\n", sizeof(char));
    printf("short:  %d byte\n", sizeof(short));
    printf("int:    %d byte\n", sizeof(int));
    printf("long:   %d byte\n", sizeof(long));
    printf("float:  %d byte\n", sizeof(float));
    printf("double: %d byte\n", sizeof(double));
    printf("long double: %d byte\n", sizeof(long double));
    
    int x;
    printf("\nKich thuoc bien x: %d byte\n", sizeof(x));
    
    return 0;
}
```

## 6. Overflow — Tràn số

Khi gán giá trị vượt quá giới hạn của kiểu:

```c
#include <stdio.h>

int main() {
    unsigned char c = 255;  // unsigned char: 0..255
    printf("c = %d\n", c);
    
    c = c + 1;  // 256 vượt quá 255 → overflow!
    printf("c + 1 = %d (overflow!)\n", c);  // In ra 0 (quay vòng)
    
    c = 0;
    c = c - 1;
    printf("c - 1 = %d (underflow!)\n", c);  // In ra 255
    
    return 0;
}
```

## 7. Bài tập thực hành

### Bài 1: Khai báo và in
Khai báo các biến: `hoTen` (mảng char), `tuoi` (int), `diemTB` (float). Gán giá trị và in ra màn hình theo format:
```
Ho ten: Nguyen Van A
Tuoi: 20
Diem TB: 8.75
```

### Bài 2: Tính sizeof
Viết chương trình in ra kích thước (số byte) của: `int`, `float`, `double`, `char`, `short`, `long`, `long double` — kèm tên kiểu.

### Bài 3: Hằng số
Dùng `#define` để định nghĩa:
- `SO_LUONG_HANG` = 100
- `DON_GIA` = 25000

Tính tổng tiền = `SO_LUONG_HANG * DON_GIA` và in kết quả.

### Bài 4: Quan sát overflow
Khai báo `int n = 2147483647;` (giá trị max của int). In `n` ra, rồi in `n + 1`. Giải thích kết quả.

## 📚 Tham khảo thêm

- [GeeksforGeeks — Variables in C](https://www.geeksforgeeks.org/variables-in-c/)
- [GeeksforGeeks — Constants in C](https://www.geeksforgeeks.org/constants-in-c/)
- [TutorialsPoint — C Variables](https://www.tutorialspoint.com/cprogramming/c_variables.htm)
- [Video: Biến và Kiểu dữ liệu trong C](https://www.youtube.com/watch?v=8o6rR4q7iMk)
