# 📚 Thư Viện Chuẩn: stdlib.h, math.h, ctype.h, time.h

## 1. `stdlib.h` — Thư viện tiện ích

### 1.1 `rand()` và `srand()` — Số ngẫu nhiên

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // time()

int main() {
    // Khởi tạo seed cho random
    srand(time(NULL));  // Dùng thời gian hiện tại làm seed
    
    // In 5 số ngẫu nhiên 0..99
    for (int i = 0; i < 5; i++) {
        int soNgauNhien = rand() % 100;  // 0..99
        printf("So %d: %d\n", i + 1, soNgauNhien);
    }
    
    // Số ngẫu nhiên trong khoảng a..b
    int a = 10, b = 50;
    int soTrongKhoang = a + rand() % (b - a + 1);
    printf("So ngau nhien %d..%d: %d\n", a, b, soTrongKhoang);
    
    return 0;
}
```

> ⚠️ Nếu không gọi `srand()`, `rand()` luôn cho cùng dãy số mỗi lần chạy!

### 1.2 `abs()` — Giá trị tuyệt đối

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = -42;
    printf("abs(%d) = %d\n", x, abs(x));  // 42
    
    return 0;
}
```

### 1.3 `atoi()`, `atof()` — Chuyển chuỗi thành số

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char soStr[] = "123";
    char piStr[] = "3.14159";
    
    int so = atoi(soStr);        // "123" → 123
    double pi = atof(piStr);     // "3.14159" → 3.14159
    
    printf("So: %d\n", so);      // 123
    printf("Pi: %.5f\n", pi);    // 3.14159
    
    // Nếu chuỗi không phải số → trả về 0
    int loi = atoi("abc");
    printf("Loi: %d\n", loi);    // 0
    
    return 0;
}
```

### 1.4 `exit()` — Kết thúc chương trình ngay

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so > 0: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Loi! Thoat chuong trinh.\n");
        exit(1);  // Kết thúc ngay, trả về 1 cho OS
    }
    
    printf("Ban da nhap: %d\n", n);
    return 0;
}
```

### 1.5 `system()` — Chạy lệnh hệ thống

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Xoa man hinh...\n");
    system("cls");   // Windows: xóa màn hình console
    // system("clear");  // Linux/Mac
    
    system("pause");  // Windows: "Press any key to continue..."
    
    return 0;
}
```

## 2. `math.h` — Thư viện toán học

```c
#include <stdio.h>
#include <math.h>   // Link với -lm trên Linux

int main() {
    double x = 9.0;
    double y = 2.0;
    
    printf("sqrt(%.1f) = %.2f\n", x, sqrt(x));      // Căn bậc 2: 3.00
    printf("pow(%.1f, %.1f) = %.2f\n", x, y, pow(x, y)); // Lũy thừa: 81.00
    printf("ceil(3.14) = %.0f\n", ceil(3.14));       // Làm tròn lên: 4
    printf("floor(3.14) = %.0f\n", floor(3.14));     // Làm tròn xuống: 3
    printf("round(3.5) = %.0f\n", round(3.5));       // Làm tròn: 4
    printf("fabs(-5.5) = %.1f\n", fabs(-5.5));       // Trị tuyệt đối: 5.5
    
    return 0;
}
```

### Các hàm lượng giác
```c
#include <stdio.h>
#include <math.h>

int main() {
    double goc = 30.0;
    double rad = goc * M_PI / 180.0;  // Đổi độ → radian
    
    printf("sin(%.0f°) = %.4f\n", goc, sin(rad));
    printf("cos(%.0f°) = %.4f\n", goc, cos(rad));
    printf("tan(%.0f°) = %.4f\n", goc, tan(rad));
    
    printf("\nHang so PI: %.10f\n", M_PI);
    printf("Hang so E:  %.10f\n", M_E);
    
    return 0;
}
```

### Bảng hàm math.h thông dụng

| Hàm | Ý nghĩa | Ví dụ |
|-----|---------|-------|
| `sqrt(x)` | Căn bậc 2 | `sqrt(9)` → 3 |
| `pow(x, y)` | x mũ y | `pow(2, 10)` → 1024 |
| `ceil(x)` | Làm tròn lên | `ceil(3.2)` → 4 |
| `floor(x)` | Làm tròn xuống | `floor(3.8)` → 3 |
| `round(x)` | Làm tròn | `round(3.5)` → 4 |
| `fabs(x)` | Giá trị tuyệt đối (double) | `fabs(-5.5)` → 5.5 |
| `fmod(x, y)` | Chia lấy dư (double) | `fmod(5.5, 2)` → 1.5 |
| `exp(x)` | e mũ x | `exp(1)` → 2.71828 |
| `log(x)` | Log tự nhiên (ln) | `log(2.718)` → 1 |
| `log10(x)` | Log cơ số 10 | `log10(100)` → 2 |

## 3. `ctype.h` — Xử lý ký tự

```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'A';
    
    printf("isalpha('%c') = %d\n", c, isalpha(c));      // 1 (chữ cái)
    printf("isdigit('%c') = %d\n", c, isdigit(c));      // 0 (không phải số)
    printf("isupper('%c') = %d\n", c, isupper(c));      // 1 (chữ hoa)
    printf("islower('%c') = %d\n", c, islower(c));      // 0 (không phải thường)
    
    printf("\ntoupper('a') = %c\n", toupper('a'));      // 'A'
    printf("tolower('Z') = %c\n", tolower('Z'));        // 'z'
    
    // Đếm chữ hoa, chữ thường, chữ số trong chuỗi
    char str[] = "Hello 123 World!";
    int hoa = 0, thuong = 0, so = 0, khac = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i]))       hoa++;
        else if (islower(str[i]))  thuong++;
        else if (isdigit(str[i]))  so++;
        else                       khac++;
    }
    
    printf("Chuoi: %s\n", str);
    printf("Chu hoa: %d, chu thuong: %d, chu so: %d, khac: %d\n",
           hoa, thuong, so, khac);
    
    return 0;
}
```

### Bảng hàm ctype.h

| Hàm | Kiểm tra | Ví dụ đúng |
|-----|----------|-----------|
| `isalpha(c)` | Chữ cái (a-z, A-Z) | `'a'`, `'Z'` |
| `isdigit(c)` | Chữ số (0-9) | `'5'` |
| `isalnum(c)` | Chữ cái hoặc số | `'a'`, `'3'` |
| `isupper(c)` | Chữ hoa (A-Z) | `'A'` |
| `islower(c)` | Chữ thường (a-z) | `'z'` |
| `isspace(c)` | Khoảng trắng | `' '`, `'\n'`, `'\t'` |
| `ispunct(c)` | Dấu câu | `'.'`, `','`, `'!'` |
| `toupper(c)` | Chuyển thành chữ hoa | `toupper('a')` → `'A'` |
| `tolower(c)` | Chuyển thành chữ thường | `tolower('Z')` → `'z'` |

## 4. `time.h` — Thời gian

```c
#include <stdio.h>
#include <time.h>

int main() {
    // Lấy thời gian hiện tại (epoch time: số giây từ 1/1/1970)
    time_t now = time(NULL);
    printf("Epoch time: %ld\n", now);
    
    // Đổi thành chuỗi thời gian
    printf("Thoi gian hien tai: %s", ctime(&now));
    
    // Đo thời gian thực thi
    clock_t start = clock();
    
    // Tính toán gì đó tốn thời gian
    long sum = 0;
    for (int i = 0; i < 100000000; i++) {
        sum += i;
    }
    
    clock_t end = clock();
    double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tong: %ld\n", sum);
    printf("Thoi gian chay: %.3f giay\n", timeSpent);
    
    return 0;
}
```

## 5. Bài tập thực hành

### Bài 1: Game đoán số (stdlib.h + time.h)
- Random số 1-100
- Người chơi đoán, máy báo "Lớn hơn" / "Nhỏ hơn" / "Chính xác!"
- Đếm số lần đoán

### Bài 2: Giải phương trình bậc 2 (math.h)
Nhập a, b, c. Dùng `sqrt()` để tính delta và nghiệm.

```c
// delta = b*b - 4*a*c
// x1 = (-b + sqrt(delta)) / (2*a)
// x2 = (-b - sqrt(delta)) / (2*a)
```

### Bài 3: Đếm ký tự trong chuỗi (ctype.h)
Nhập chuỗi. Đếm và in:
- Số chữ hoa
- Số chữ thường
- Số chữ số
- Số khoảng trắng
- Số ký tự khác

### Bài 4: Tính diện tích hình tròn (math.h)
Nhập bán kính. Dùng `M_PI` và `pow()` để tính diện tích. In kết quả với 3 số thập phân.

## 📚 Tham khảo thêm

- [GeeksforGeeks — stdlib.h](https://www.geeksforgeeks.org/utility-library-c-stdlib-h/)
- [GeeksforGeeks — math.h](https://www.geeksforgeeks.org/math-h-c-header/)
- [GeeksforGeeks — ctype.h](https://www.geeksforgeeks.org/ctype-h-c/)
- [GeeksforGeeks — time.h](https://www.geeksforgeeks.org/time-h-header-file-in-c-with-examples/)
