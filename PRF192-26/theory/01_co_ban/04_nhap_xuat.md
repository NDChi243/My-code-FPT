# ⌨️ Nhập Xuất Cơ Bản trong C

## 1. `printf()` — In dữ liệu ra màn hình

### Cú pháp
```c
printf("chuoi dinh dang", tham_so_1, tham_so_2, ...);
```

### Format specifiers — Đặc tả định dạng

| Specifier | Kiểu | Ví dụ |
|-----------|------|-------|
| `%d` hoặc `%i` | `int` (số nguyên có dấu) | `printf("%d", 42);` |
| `%u` | `unsigned int` | `printf("%u", 100U);` |
| `%f` | `float` hoặc `double` | `printf("%f", 3.14);` |
| `%lf` | `double` (với `scanf`) | `scanf("%lf", &x);` |
| `%c` | `char` | `printf("%c", 'A');` |
| `%s` | Chuỗi ký tự (string) | `printf("%s", "Hello");` |
| `%p` | Địa chỉ con trỏ | `printf("%p", &x);` |
| `%x` / `%X` | Số hex (chữ thường/HOA) | `printf("%x", 255);` → `ff` |
| `%o` | Số octal | `printf("%o", 8);` → `10` |
| `%%` | In ra dấu `%` | `printf("100%%");` |

### Ví dụ
```c
#include <stdio.h>

int main() {
    int tuoi = 20;
    float diem = 8.75;
    char chuCai = 'Z';
    
    printf("Toi %d tuoi.\n", tuoi);
    printf("Diem trung binh: %.2f\n", diem);    // 2 số thập phân
    printf("Ky tu: %c, ma ASCII: %d\n", chuCai, chuCai);
    
    return 0;
}
```

### Định dạng nâng cao

```c
#include <stdio.h>

int main() {
    int so = 255;
    float pi = 3.14159265;
    char ten[] = "Nguyen Van A";
    
    // Độ rộng tối thiểu
    printf("Can phai: >>%10d<<\n", so);   // ">>       255<<"
    printf("Can trai: >>%-10d<<\n", so);  // ">>255       <<"
    
    // Số chữ số thập phân
    printf("Pi voi 2 so: %.2f\n", pi);      // 3.14
    printf("Pi voi 4 so: %.4f\n", pi);      // 3.1416
    
    // Kết hợp độ rộng + số thập phân
    printf(">>%10.2f<<\n", pi);             // ">>      3.14<<"
    
    // Padding số 0
    printf("Ma so: %05d\n", 42);            // 00042
    
    // Căn lề chuỗi
    printf(">>%20s<<\n", ten);              // ">>       Nguyen Van A<<"
    printf(">>%-20s<<\n", ten);             // ">>Nguyen Van A       <<"
    
    return 0;
}
```

### Escape sequences — Ký tự đặc biệt

| Escape | Ý nghĩa | Mã ASCII |
|--------|---------|----------|
| `\n` | Xuống dòng (newline) | 10 |
| `\t` | Tab | 9 |
| `\\` | In dấu `\` | 92 |
| `\"` | In dấu `"` | 34 |
| `\'` | In dấu `'` | 39 |
| `\0` | Null terminator | 0 |

## 2. `scanf()` — Nhập dữ liệu từ bàn phím

### Cú pháp
```c
scanf("chuoi dinh dang", &bien_1, &bien_2, ...);
```

> ⚠️ **Luôn dùng `&` trước biến** (trừ mảng char — tên mảng đã là địa chỉ).

### Ví dụ
```c
#include <stdio.h>

int main() {
    int tuoi;
    float diem;
    char kyTu;
    
    printf("Nhap tuoi: ");
    scanf("%d", &tuoi);
    
    printf("Nhap diem: ");
    scanf("%f", &diem);
    
    printf("Nhap mot ky tu: ");
    scanf(" %c", &kyTu);  // Khoảng trắng trước %c để bỏ qua '\n' còn lại
    
    printf("\n--- THONG TIN ---\n");
    printf("Tuoi: %d\n", tuoi);
    printf("Diem: %.2f\n", diem);
    printf("Ky tu: %c (ma: %d)\n", kyTu, kyTu);
    
    return 0;
}
```

### Bẫy với `scanf` và ký tự xuống dòng

```c
#include <stdio.h>

int main() {
    int n;
    char c;
    
    printf("Nhap so: ");
    scanf("%d", &n);        // Nhập 5 + Enter → '\n' còn trong buffer
    
    // Vấn đề: '\n' còn trong buffer sẽ được đọc ngay
    printf("Nhap ky tu: ");
    scanf("%c", &c);        // Đọc '\n' thay vì chờ nhập mới!
    
    printf("n = %d, c = '%c' (ma: %d)\n", n, c, c);
    // Kết quả: n = 5, c = '
    // ' (ma: 10)  ← 10 là '\n'!
    
    return 0;
}
```

**Cách khắc phục:**
```c
// Cách 1: Thêm khoảng trắng trước %c
scanf(" %c", &c);  // Khoảng trắng bỏ qua whitespace (space, tab, enter)

// Cách 2: Dùng getchar() để "ăn" ký tự thừa
scanf("%d", &n);
getchar();          // Đọc bỏ '\n'
scanf("%c", &c);

// Cách 3: Dùng fflush(stdin) — KHÔNG DÙNG (undefined behavior)
```

### Nhập chuỗi có dấu cách — Dùng `fgets`

```c
#include <stdio.h>
#include <string.h>

int main() {
    char hoTen[100];
    int tuoi;
    
    printf("Nhap ho ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);      // Đọc cả dòng, có dấu cách
    hoTen[strcspn(hoTen, "\n")] = '\0';      // Xóa ký tự '\n' ở cuối
    
    printf("Nhap tuoi: ");
    scanf("%d", &tuoi);
    
    printf("\nXin chao %s, %d tuoi!\n", hoTen, tuoi);
    
    return 0;
}
```

> ⚠️ **Không dùng `gets()`** — đã bị loại khỏi C11 vì gây buffer overflow!

## 3. `putchar()` và `getchar()` — Nhập xuất từng ký tự

```c
#include <stdio.h>

int main() {
    char c;
    
    printf("Nhap mot ky tu: ");
    c = getchar();          // Đọc 1 ký tự từ bàn phím
    
    printf("Ban da nhap: ");
    putchar(c);             // In 1 ký tự ra màn hình
    putchar('\n');
    
    return 0;
}
```

## 4. `puts()` và `gets()` — Nhập xuất chuỗi

```c
#include <stdio.h>

int main() {
    char ten[50];
    
    printf("Nhap ten (khong co cach): ");
    scanf("%s", ten);       // Chỉ đọc đến khoảng trắng đầu tiên
    
    printf("Xin chao ");
    puts(ten);              // Tự động thêm '\n' ở cuối
    
    return 0;
}
```

## 5. Bảng so sánh các hàm nhập xuất

| Hàm | Mục đích | Đặc điểm |
|-----|---------|----------|
| `printf()` | In dữ liệu có format | Linh hoạt nhất, dùng `%d`, `%f`,... |
| `puts()` | In chuỗi | Tự động xuống dòng, không cần format |
| `putchar()` | In 1 ký tự | Nhanh, đơn giản |
| `scanf()` | Nhập có format | Dễ dùng, nhưng hay bị lỗi buffer |
| `gets()` | Nhập chuỗi | ⛔ NGUY HIỂM — bị loại khỏi C11 |
| `fgets()` | Nhập chuỗi an toàn | ✅ Dùng `fgets(bien, kichThuoc, stdin)` |
| `getchar()` | Nhập 1 ký tự | Đơn giản |

## 6. Input Validation — Kiểm tra dữ liệu nhập

```c
#include <stdio.h>

int main() {
    int n;
    
    printf("Nhap mot so nguyen duong: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Du lieu khong hop le!\n");
        return 1;
    }
    
    printf("So vua nhap: %d\n", n);
    return 0;
}
```

## 7. Bài tập thực hành

### Bài 1: Thông tin cá nhân
Viết chương trình nhập: họ tên (dùng `fgets`), tuổi (`int`), điểm TB (`float`). In ra:
```
--- SINH VIEN ---
Ho ten: Nguyen Van A
Tuoi: 20
Diem TB: 8.75
```

### Bài 2: Bảng giá
Nhập tên sản phẩm, số lượng, đơn giá. In hóa đơn căn lề đẹp:
```
HOA DON MUA HANG
San pham: .......... (15 ky tu, can trai)
So luong:         10 (5 ky tu, can phai)
Don gia:    25,000.00 (10 ky tu, 2 so thap phan)
Thanh tien: 250,000.00
```

### Bài 3: Chữa lỗi scanf
Đoạn code sau bị lỗi gì? Sửa lại cho đúng:
```c
int tuoi;
float diem;
printf("Nhap tuoi va diem: ");
scanf("%d %f", tuoi, diem);               // Lỗi 1
printf("Tuoi: %d, Diem: %.2f", tuoi, diem);
```

### Bài 4: Tính tổng 2 số
Nhập 2 số nguyên, tính tổng và in ra:
```
Nhap a: 5
Nhap b: 10
5 + 10 = 15
```

## 📚 Tham khảo thêm

- [GeeksforGeeks — printf in C](https://www.geeksforgeeks.org/printf-in-c/)
- [GeeksforGeeks — scanf in C](https://www.geeksforgeeks.org/scanf-in-c/)
- [Programiz — Input Output in C](https://www.programiz.com/c-programming/c-input-output)
- [Video: printf và scanf trong C](https://www.youtube.com/watch?v=fGRTWa4T8GQ)
