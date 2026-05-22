# 📍 Con Trỏ (Pointer) trong C

## 1. Con trỏ là gì?

**Con trỏ** là biến lưu **địa chỉ bộ nhớ** của một biến khác.

Hãy tưởng tượng:
- **Biến thường** là ngôi nhà (chứa giá trị)
- **Con trỏ** là tờ giấy ghi địa chỉ của ngôi nhà đó

```
Bộ nhớ RAM:
┌─────────┬──────────────┐
│ Địa chỉ │ Giá trị      │
├─────────┼──────────────┤
│ 0x1000  │ x = 5        │ ← Biến thường
│ 0x1004  │ p = 0x1000   │ ← Con trỏ (trỏ tới x)
└─────────┴──────────────┘
```

## 2. Khai báo và khởi tạo con trỏ

```c
#include <stdio.h>

int main() {
    int x = 5;          // Biến thường
    int *p;             // Khai báo con trỏ (trỏ đến int)
    
    p = &x;             // p lưu địa chỉ của x
    
    printf("Gia tri cua x: %d\n", x);       // 5
    printf("Dia chi cua x: %p\n", &x);      // 0x1000 (vd)
    printf("Gia tri cua p: %p\n", p);       // 0x1000 (giống &x)
    printf("Gia tri tai dia chi p tro den: %d\n", *p);  // 5
    
    return 0;
}
```

## 3. Hai toán tử quan trọng

| Toán tử | Tên gọi | Ý nghĩa |
|---------|---------|---------|
| `&` | Address-of (lấy địa chỉ) | Lấy địa chỉ của biến |
| `*` | Dereference (giải tham chiếu) | Lấy giá trị tại địa chỉ |

```c
int x = 42;
int *p = &x;    // &: lấy địa chỉ của x → gán cho p
int y = *p;     // *: lấy giá trị p trỏ đến → gán cho y (y = 42)
```

## 4. Thay đổi giá trị qua con trỏ

```c
#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;
    
    printf("Truoc: x = %d\n", x);  // 10
    
    *p = 25;  // Thay đổi giá trị tại địa chỉ p trỏ đến (= thay x)
    
    printf("Sau: x = %d\n", x);    // 25 (đã thay đổi!)
    
    return 0;
}
```

## 5. Kiểu con trỏ và kích thước

```c
#include <stdio.h>

int main() {
    int    *pInt;
    float  *pFloat;
    char   *pChar;
    double *pDouble;
    
    // Mọi con trỏ đều có cùng kích thước (4 byte trên 32-bit, 8 byte trên 64-bit)
    printf("Kich thuoc con tro: %d byte\n", sizeof(pInt));    // 4 hoặc 8
    printf("Kich thuoc con tro: %d byte\n", sizeof(pFloat));  // 4 hoặc 8
    printf("Kich thuoc con tro: %d byte\n", sizeof(pChar));   // 4 hoặc 8
    
    // Nhưng khi dereference, kiểu xác định cách đọc
    printf("Kich thuoc int* tro den: %d byte\n", sizeof(*pInt));    // 4
    printf("Kich thuoc char* tro den: %d byte\n", sizeof(*pChar));  // 1
    
    return 0;
}
```

## 6. Số học con trỏ (Pointer Arithmetic)

```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;  // p trỏ đến arr[0]
    
    printf("p tro den: %d\n", *p);       // 10 (arr[0])
    printf("p+1 tro den: %d\n", *(p+1)); // 20 (arr[1])
    printf("p+2 tro den: %d\n", *(p+2)); // 30 (arr[2])
    
    // Dịch chuyển con trỏ
    p++;  // Giờ p trỏ đến arr[1]
    printf("\nSau p++: %d\n", *p);  // 20
    
    p += 2;  // Giờ p trỏ đến arr[3]
    printf("Sau p+=2: %d\n", *p);  // 40
    
    // So sánh địa chỉ
    int *q = &arr[4];
    printf("\nSo phan tu giua p va q: %d\n", q - p);  // 1 (arr[4] - arr[3])
    
    return 0;
}
```

> `p + 1` không phải là tăng 1 byte, mà là tăng lên `sizeof(kiểu)` byte. Với `int*`: tăng 4 byte.

## 7. Con trỏ `void*` — Con trỏ vô kiểu

```c
#include <stdio.h>

int main() {
    int x = 42;
    float y = 3.14;
    
    void *p;  // Con trỏ void — có thể trỏ đến bất kỳ kiểu nào
    
    p = &x;   // Trỏ đến int
    printf("Gia tri int: %d\n", *(int*)p);  // Phải ép kiểu trước khi dereference
    
    p = &y;   // Trỏ đến float
    printf("Gia tri float: %.2f\n", *(float*)p);
    
    return 0;
}
```

## 8. Con trỏ NULL — Con trỏ không trỏ đến đâu

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = NULL;  // Con trỏ chưa trỏ đến đâu
    
    // Luôn kiểm tra NULL trước khi dùng
    if (p != NULL) {
        printf("%d", *p);  // Không chạy vì p là NULL
    } else {
        printf("Con tro chua duoc khoi tao!\n");
    }
    
    // ❌ Nếu không kiểm tra: segmentation fault!
    // printf("%d", *p);  // Crash!
    
    return 0;
}
```

## 9. Con trỏ và mảng — Quan hệ mật thiết

```c
#include <stdio.h>

int main() {
    int arr[] = {2, 4, 6, 8};
    int *p = arr;  // arr = &arr[0] (tên mảng là địa chỉ phần tử đầu)
    
    // Hai cách truy cập tương đương:
    printf("arr[0] = %d, *p = %d\n", arr[0], *p);      // 2, 2
    printf("arr[1] = %d, *(p+1) = %d\n", arr[1], *(p+1)); // 4, 4
    
    // Duyệt mảng bằng con trỏ
    for (int i = 0; i < 4; i++) {
        printf("arr[%d] = %d (cach 1)\n", i, arr[i]);
        printf("arr[%d] = %d (cach 2)\n", i, *(p + i));
    }
    
    return 0;
}
```

## 10. Các lỗi thường gặp

### Lỗi 1: Dereference con trỏ chưa khởi tạo
```c
int *p;      // Chưa khởi tạo — chứa địa chỉ rác
*p = 10;     // ❌ Ghi vào vùng nhớ không xác định → crash!
```

### Lỗi 2: Nhầm `*` khi khai báo
```c
int* p, q;   // p là con trỏ, q là int (không phải con trỏ!)
int *p, *q;  // ✅ Cả p và q đều là con trỏ
```

### Lỗi 3: Quên `&` trong scanf — VÀ dùng đúng con trỏ
```c
int x;
int *p = &x;
scanf("%d", p);   // ✅ Đúng: p đã là địa chỉ
scanf("%d", &x);  // ✅ Đúng: &x là địa chỉ
// scanf("%d", &p); // ❌ Sai: ghi vào địa chỉ của p, không phải của x!
```

## 11. Bài tập thực hành

### Bài 1: Cơ bản về con trỏ
Khai báo `int x = 100; int *p = &x;`. In ra:
- Giá trị của x
- Địa chỉ của x
- Giá trị của p
- Giá trị *p
- Địa chỉ của p

Thay đổi *p = 200, in lại x.

### Bài 2: Duyệt mảng bằng con trỏ
Khai báo mảng `int arr[] = {3, 7, 1, 9, 4};`. Dùng con trỏ để:
- In tất cả phần tử
- Tính tổng
- Tìm max

### Bài 3: Con trỏ đến con trỏ
```c
int x = 10;
int *p = &x;
int **q = &p;  // q là con trỏ đến con trỏ

// Dùng **q để in giá trị x (10)
// Dùng *q để in địa chỉ của x
```

### Bài 4: Đảo ngược mảng bằng con trỏ
Viết hàm `void daoNguoc(int *arr, int n)` dùng 2 con trỏ (đầu và cuối) để đảo mảng.

## 📚 Tham khảo thêm

- [GeeksforGeeks — Pointers in C](https://www.geeksforgeeks.org/pointers-in-c/)
- [Programiz — C Pointers](https://www.programiz.com/c-programming/c-pointers)
- [Pointer Arithmetic](https://www.tutorialspoint.com/cprogramming/c_pointer_arithmetic.htm)
- [Video: Con trỏ trong C (chi tiết)](https://www.youtube.com/watch?v=2GDiXG4VqXk)
