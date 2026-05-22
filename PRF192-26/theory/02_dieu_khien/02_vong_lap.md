# 🔄 Vòng Lặp: for, while, do-while

## 1. Tại sao cần vòng lặp?

Không có vòng lặp, muốn in "Xin chao" 10 lần bạn phải viết 10 dòng `printf`!
Vòng lặp cho phép **lặp lại** một khối lệnh nhiều lần.

## 2. Vòng lặp `for` — Dùng khi biết trước số lần lặp

### Cú pháp
```c
for (khoi_tao; dieu_kien; cap_nhat) {
    // Code lặp
}
```

| Thành phần | Ví dụ | Mô tả |
|-----------|-------|-------|
| Khởi tạo | `int i = 0;` | Chạy 1 lần đầu tiên |
| Điều kiện | `i < 5;` | Kiểm tra trước mỗi lần lặp — đúng thì chạy |
| Cập nhật | `i++` | Chạy sau mỗi lần lặp |

### Ví dụ: In 5 lần
```c
#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        printf("Xin chao lan %d\n", i + 1);
    }
    return 0;
}
```

**Output:**
```
Xin chao lan 1
Xin chao lan 2
Xin chao lan 3
Xin chao lan 4
Xin chao lan 5
```

### Luồng thực thi của `for`

```
1. int i = 0;
2. i < 5? (0 < 5 → true)
3. → printf("Xin chao...");
4. i++ → i = 1
5. i < 5? (1 < 5 → true)
6. → printf(...)
7. i++ → i = 2
...lặp...
8. i = 5, i < 5? (5 < 5 → false) → THOÁT
```

### Các biến thể của `for`

```c
// Đếm ngược
for (int i = 10; i >= 1; i--) {
    printf("%d ", i);
}  // Output: 10 9 8 7 6 5 4 3 2 1

// Bước nhảy 2
for (int i = 0; i <= 10; i += 2) {
    printf("%d ", i);
}  // Output: 0 2 4 6 8 10

// Nhiều biến
for (int i = 0, j = 10; i < j; i++, j--) {
    printf("i=%d, j=%d\n", i, j);
}
```

## 3. Vòng lặp `while` — Dùng khi không biết trước số lần lặp

### Cú pháp
```c
while (dieu_kien) {
    // Code lặp — chạy khi điều kiện đúng
}
```

### Ví dụ: Đọc cho đến khi nhập đúng
```c
#include <stdio.h>

int main() {
    int n;
    printf("Nhap so duong: ");
    scanf("%d", &n);
    
    while (n <= 0) {
        printf("Sai! Vui long nhap so duong: ");
        scanf("%d", &n);
    }
    
    printf("Ban da nhap: %d\n", n);
    return 0;
}
```

### Ví dụ: In 5 lần với while
```c
int i = 0;
while (i < 5) {
    printf("Xin chao\n");
    i++;  // Quan trọng! Nếu quên → vòng lặp vô hạn!
}
```

> ⚠️ **Quên cập nhật biến đếm = Vòng lặp vô hạn!** Luôn đảm bảo điều kiện có thể thành `false`.

## 4. Vòng lặp `do-while` — Chạy ít nhất 1 lần

### Cú pháp
```c
do {
    // Code — chạy trước, kiểm tra sau
} while (dieu_kien);
```

### Ví dụ: Menu chương trình
```c
#include <stdio.h>

int main() {
    int luaChon;
    
    do {
        printf("\n=== MENU ===\n");
        printf("1. Tinh tong\n");
        printf("2. Tinh hieu\n");
        printf("3. Thoat\n");
        printf("Chon: ");
        scanf("%d", &luaChon);
        
        switch (luaChon) {
            case 1:
                printf("Ban chon tinh tong\n");
                break;
            case 2:
                printf("Ban chon tinh hieu\n");
                break;
            case 3:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 3);
    
    return 0;
}
```

### So sánh 3 vòng lặp

| Vòng lặp | Kiểm tra điều kiện | Số lần chạy tối thiểu | Khi nào dùng |
|-----------|-------------------|----------------------|-------------|
| `for` | Đầu vòng | 0 | Biết trước số lần lặp |
| `while` | Đầu vòng | 0 | Kiểm tra trước khi chạy |
| `do-while` | Cuối vòng | 1 | Cần chạy ít nhất 1 lần |

## 5. `break` — Thoát khỏi vòng lặp

```c
#include <stdio.h>

int main() {
    // Tìm số đầu tiên chia hết cho 7
    for (int i = 1; i <= 100; i++) {
        if (i % 7 == 0) {
            printf("So dau tien chia het cho 7: %d\n", i);
            break;  // Thoát ngay khi tìm thấy
        }
    }
    return 0;
}
```

## 6. `continue` — Bỏ qua lần lặp hiện tại

```c
#include <stdio.h>

int main() {
    // In số lẻ từ 1 đến 10
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // Bỏ qua số chẵn
        }
        printf("%d ", i);
    }
    // Output: 1 3 5 7 9
    return 0;
}
```

## 7. Vòng lặp lồng nhau (Nested loops)

### Ví dụ: In bảng cửu chương
```c
#include <stdio.h>

int main() {
    for (int i = 2; i <= 9; i++) {
        printf("--- Bang cuu chuong %d ---\n", i);
        for (int j = 1; j <= 10; j++) {
            printf("%2d x %2d = %2d\n", i, j, i * j);
        }
        printf("\n");
    }
    return 0;
}
```

### Ví dụ: In hình chữ nhật
```c
#include <stdio.h>

int main() {
    int cao, rong;
    printf("Nhap chieu cao va rong: ");
    scanf("%d %d", &cao, &rong);
    
    for (int i = 0; i < cao; i++) {
        for (int j = 0; j < rong; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
```

## 8. Vòng lặp vô hạn — và cách thoát

```c
// Vòng lặp vô hạn với for
for (;;) {
    printf("Chay mai...");
}

// Vòng lặp vô hạn với while
while (1) {
    printf("Chay mai...");
}
```

Thoát bằng: `break`, `return`, hoặc `Ctrl+C` khi chạy chương trình.

## 9. Các lỗi thường gặp

### Lỗi 1: Vòng lặp vô hạn do quên cập nhật
```c
// ❌ SAI
int i = 0;
while (i < 5) {
    printf("%d", i);
    // Quên i++ → i luôn = 0 → loop vô hạn!
}
```

### Lỗi 2: Điều kiện sai ngay từ đầu
```c
for (int i = 0; i > 10; i++) {  // i > 10 sai từ đầu
    printf("Khong chay");  // Không bao giờ chạy
}
```

### Lỗi 3: Dùng `=` thay `==`
```c
int i = 0;
while (i = 5) {  // Gán i=5 → 5 là true → vô hạn!
    printf("Vinh vien...");
}
```

## 10. Bài tập thực hành

### Bài 1: Tổng 1..n
Nhập n (nguyên dương). Tính `S = 1 + 2 + 3 + ... + n` bằng 3 cách (for, while, do-while).

### Bài 2: Số nguyên tố
Nhập n. Kiểm tra n có phải số nguyên tố không.
> Số nguyên tố là số > 1, chỉ chia hết cho 1 và chính nó.

### Bài 3: Fibonacci
In n số Fibonacci đầu tiên: `0 1 1 2 3 5 8 13 21 ...`

### Bài 4: Tam giác số
In tam giác Pascal dạng số:
```
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
```

### Bài 5: Game đoán số (Dùng while)
Máy random số 1-100. Người chơi đoán, máy báo "lớn hơn" / "nhỏ hơn" / "đúng". Đếm số lần đoán.

## 📚 Tham khảo thêm

- [GeeksforGeeks — Loops in C](https://www.geeksforgeeks.org/loops-in-c/)
- [Programiz — C for Loop](https://www.programiz.com/c-programming/c-for-loop)
- [Programiz — C while Loop](https://www.programiz.com/c-programming/c-do-while-loops)
- [Video: Vòng lặp trong C (full)](https://www.youtube.com/watch?v=W3Q2ooHDBR8)
