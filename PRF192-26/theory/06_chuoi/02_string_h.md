# 📚 Thư Viện string.h — Xử Lý Chuỗi Chuyên Nghiệp

## 1. Giới thiệu

`string.h` cung cấp các hàm tiện ích để xử lý chuỗi. Luôn `#include <string.h>` khi dùng.

## 2. `strlen()` — Độ dài chuỗi

```c
#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "Hello World";
    
    int len = strlen(s);
    printf("Chuoi: '%s'\n", s);
    printf("Do dai: %d\n", len);  // 11 (không tính '\0')
    
    // sizeof vs strlen
    printf("sizeof(s): %d byte\n", sizeof(s));  // 12 (cả '\0')
    printf("strlen(s): %d\n", strlen(s));       // 11
    
    return 0;
}
```

## 3. `strcpy()` — Sao chép chuỗi

```c
#include <stdio.h>
#include <string.h>

int main() {
    char nguon[] = "FPT University";
    char dich[50];
    
    strcpy(dich, nguon);  // Sao chép nguon → dich
    
    printf("Nguon: %s\n", nguon);
    printf("Dich: %s\n", dich);  // FPT University
    
    return 0;
}
```

> ⚠️ **Đảm bảo `dich` đủ lớn** để chứa `nguon` (kể cả '\0')!

## 4. `strncpy()` — Sao chép an toàn với giới hạn

```c
#include <stdio.h>
#include <string.h>

int main() {
    char dich[10];  // Chỉ đủ 9 ký tự + '\0'
    char nguon[] = "FPT University";
    
    strncpy(dich, nguon, sizeof(dich) - 1);
    dich[sizeof(dich) - 1] = '\0';  // Đảm bảo kết thúc chuỗi
    
    printf("Dich: %s\n", dich);  // "FPT Unive"
    
    return 0;
}
```

## 5. `strcat()` — Nối chuỗi

```c
#include <stdio.h>
#include <string.h>

int main() {
    char s1[50] = "Hello";
    char s2[] = " World";
    
    strcat(s1, s2);  // Nối s2 vào cuối s1
    
    printf("s1: %s\n", s1);  // "Hello World"
    printf("s2: %s\n", s2);  // " World"
    
    return 0;
}
```

> ⚠️ **`s1` phải đủ lớn** để chứa kết quả!

## 6. `strcmp()` — So sánh chuỗi

```c
#include <stdio.h>
#include <string.h>

int main() {
    char s1[] = "Hello";
    char s2[] = "Hello";
    char s3[] = "World";
    char s4[] = "HELLO";
    
    printf("'%s' vs '%s': %d\n", s1, s2, strcmp(s1, s2));  // 0 (bằng)
    printf("'%s' vs '%s': %d\n", s1, s3, strcmp(s1, s3));  // <0 (Hello < World)
    printf("'%s' vs '%s': %d\n", s3, s1, strcmp(s3, s1));  // >0 (World > Hello)
    printf("'%s' vs '%s': %d\n", s1, s4, strcmp(s1, s4));  // >0 ('H' == 'H', 'e' > 'E')
    
    // So sánh không phân biệt hoa/thường
    printf("stricmp: %d\n", stricmp(s1, s4));  // 0 (bằng — không phân biệt hoa/thường)
    
    return 0;
}
```

### Giá trị trả về của `strcmp`

| Kết quả | Ý nghĩa |
|---------|---------|
| `== 0` | Hai chuỗi bằng nhau |
| `< 0` | Chuỗi 1 nhỏ hơn chuỗi 2 (theo ASCII) |
| `> 0` | Chuỗi 1 lớn hơn chuỗi 2 |

> **strcmp so sánh theo ASCII:** 'A'(65) < 'a'(97), 'a'(97) < 'b'(98).

## 7. `strchr()` — Tìm ký tự trong chuỗi

```c
#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "Hello World";
    char *p;
    
    p = strchr(s, 'o');  // Tìm 'o' xuất hiện đầu tiên
    if (p != NULL) {
        printf("Tim thay 'o' tai vi tri: %ld\n", p - s);  // 4
        printf("Phan con lai: %s\n", p);  // "o World"
    }
    
    // Tìm tất cả vị trí của 'o'
    p = s;
    while ((p = strchr(p, 'o')) != NULL) {
        printf("Tim thay 'o' tai: %ld\n", p - s);
        p++;  // Tiếp tục tìm từ vị trí tiếp theo
    }
    
    return 0;
}
```

## 8. `strstr()` — Tìm chuỗi con

```c
#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "Xin chao, toi la sinh vien FPT";
    char *p;
    
    p = strstr(s, "FPT");
    if (p != NULL) {
        printf("Tim thay 'FPT' tai vi tri: %ld\n", p - s);
        printf("Phan con lai: %s\n", p);  // "FPT"
    } else {
        printf("Khong tim thay!\n");
    }
    
    return 0;
}
```

## 9. `strtok()` — Tách chuỗi (Tokenization)

```c
#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "Nguyen Van A,20,8.75";
    char *token;
    
    // Lấy token đầu tiên (ngăn cách bởi dấu phẩy)
    token = strtok(s, ",");
    
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, ",");  // Tiếp tục tách
    }
    
    return 0;
}
// Output:
// Token: Nguyen Van A
// Token: 20
// Token: 8.75
```

> ⚠️ `strtok` làm hỏng chuỗi gốc! Dùng bản sao nếu cần giữ nguyên.

## 10. `strlwr()` và `strupr()` — Chuyển hoa/thường

```c
#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "Hello World";
    
    printf("Goc: %s\n", s);
    
    // strlwr: chuyển thành chữ thường
    strlwr(s);
    printf("Thuong: %s\n", s);  // "hello world"
    
    // strupr: chuyển thành chữ hoa
    strupr(s);
    printf("Hoa: %s\n", s);  // "HELLO WORLD"
    
    return 0;
}
```

> ⚠️ `strlwr` và `strupr` không phải chuẩn C — có thể không có trên một số compiler. Dùng vòng lặp + `toupper`/`tolower` từ ctype.h để an toàn.

## 11. Bảng tổng hợp hàm string.h

| Hàm | Cú pháp | Chức năng |
|-----|---------|-----------|
| `strlen` | `size_t strlen(const char *s)` | Độ dài chuỗi |
| `strcpy` | `char *strcpy(char *d, const char *s)` | Sao chép chuỗi |
| `strncpy` | `char *strncpy(char *d, const char *s, size_t n)` | Sao chép n ký tự |
| `strcat` | `char *strcat(char *d, const char *s)` | Nối chuỗi |
| `strncat` | `char *strncat(char *d, const char *s, size_t n)` | Nối n ký tự |
| `strcmp` | `int strcmp(const char *s1, const char *s2)` | So sánh chuỗi |
| `strncmp` | `int strncmp(const char *s1, const char *s2, size_t n)` | So sánh n ký tự |
| `stricmp` | `int stricmp(const char *s1, const char *s2)` | So sánh không phân biệt hoa/thường |
| `strchr` | `char *strchr(const char *s, int c)` | Tìm ký tự |
| `strrchr` | `char *strrchr(const char *s, int c)` | Tìm ký tự từ cuối |
| `strstr` | `char *strstr(const char *hay, const char *needle)` | Tìm chuỗi con |
| `strtok` | `char *strtok(char *s, const char *delim)` | Tách chuỗi |
| `strlwr` | `char *strlwr(char *s)` | → chữ thường (không chuẩn) |
| `strupr` | `char *strupr(char *s)` | → chữ hoa (không chuẩn) |

## 12. Bài tập thực hành

### Bài 1: Các thao tác cơ bản
Nhập 2 chuỗi s1, s2. Thực hiện:
- In độ dài từng chuỗi
- So sánh 2 chuỗi (in kết quả: bằng/lớn hơn/nhỏ hơn)
- Nối s2 vào s1, in kết quả
- Sao chép s1 vào s3, in s3

### Bài 2: Xử lý tên
Nhập họ tên đầy đủ (vd: "Nguyen Van A"). Dùng `strtok` để tách:
```
Ho: Nguyen
Dem: Van
Ten: A
```

### Bài 3: Đếm số lần xuất hiện
Nhập chuỗi s và từ t. Đếm số lần từ t xuất hiện trong s (dùng `strstr`).

### Bài 4: Thay thế chuỗi
Nhập chuỗi s, từ cần tìm old, từ thay thế new. Thay thế tất cả old bằng new trong s.
```
s = "toi hoc C, C la ngon ngu hay"
old = "C"
new = "C++"
→ "toi hoc C++, C++ la ngon ngu hay"
```

### Bài 5: Phân tích Email
Nhập địa chỉ email. Dùng `strchr` để tách:
- Tên người dùng (trước @)
- Tên miền (sau @)

## 📚 Tham khảo thêm

- [GeeksforGeeks — string.h](https://www.geeksforgeeks.org/string-h-in-c/)
- [GeeksforGeeks — strtok](https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/)
- [C String Reference](https://en.cppreference.com/w/c/string/byte)
- [Video: string.h functions](https://www.youtube.com/watch?v=5E8vxSJkWJg)
