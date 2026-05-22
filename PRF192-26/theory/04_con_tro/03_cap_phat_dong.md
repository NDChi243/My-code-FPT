# 🧠 Cấp Phát Bộ Nhớ Động (Dynamic Memory Allocation)

## 1. Tĩnh vs Động

| Tiêu chí | Cấp phát tĩnh (Static) | Cấp phát động (Dynamic) |
|----------|----------------------|------------------------|
| Thời điểm | Biên dịch (compile time) | Chạy (runtime) |
| Kích thước | Cố định | Linh hoạt, quyết định lúc chạy |
| Vùng nhớ | Stack | Heap |
| Tự động giải phóng | Có (khi ra khỏi scope) | Không — phải `free()` |
| Ví dụ | `int arr[100];` | `int *arr = malloc(n * sizeof(int));` |

```c
// Tĩnh: phải biết trước kích thước
int arr[100];  // Luôn tốn 400 byte, dù chỉ dùng 10 phần tử

// Động: kích thước do người dùng nhập
int n;
printf("Nhap so phan tu: ");
scanf("%d", &n);
int *arr = (int*)malloc(n * sizeof(int));  // Chỉ tốn n*4 byte
```

## 2. Các hàm cấp phát động

### 2.1 `malloc()` — Memory Allocation

```c
#include <stdio.h>
#include <stdlib.h>  // malloc, free, ...

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    
    // Cấp phát mảng n số nguyên
    int *arr = (int*)malloc(n * sizeof(int));
    
    // Luôn kiểm tra NULL!
    if (arr == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }
    
    // Dùng mảng
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    // Giải phóng — RẤT QUAN TRỌNG!
    free(arr);
    arr = NULL;  // Tránh dangling pointer
    
    return 0;
}
```

> `malloc` không khởi tạo giá trị — vùng nhớ chứa dữ liệu rác!

### 2.2 `calloc()` — Contiguous Allocation

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    
    // calloc: cấp phát + tự động gán 0 cho tất cả phần tử
    int *arr = (int*)calloc(n, sizeof(int));
    
    if (arr == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);  // Tất cả = 0
    }
    
    free(arr);
    arr = NULL;
    return 0;
}
```

### So sánh `malloc` vs `calloc`

```c
// malloc: không khởi tạo
int *a = (int*)malloc(5 * sizeof(int));
// a[0]..a[4] chứa giá trị rác!

// calloc: khởi tạo = 0
int *b = (int*)calloc(5, sizeof(int));
// b[0]..b[4] = 0
```

### 2.3 `realloc()` — Reallocation (thay đổi kích thước)

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3;
    int *arr = (int*)malloc(n * sizeof(int));
    
    if (arr == NULL) return 1;
    
    arr[0] = 10; arr[1] = 20; arr[2] = 30;
    
    // Mở rộng mảng lên 5 phần tử
    int *temp = (int*)realloc(arr, 5 * sizeof(int));
    
    if (temp == NULL) {
        printf("Khong mo rong duoc!\n");
        free(arr);
        return 1;
    }
    
    arr = temp;  // Cập nhật con trỏ
    arr[3] = 40;
    arr[4] = 50;
    
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    free(arr);
    arr = NULL;
    return 0;
}
```

## 3. Giải phóng bộ nhớ — `free()`

```c
int *arr = (int*)malloc(100 * sizeof(int));
// ... dùng arr ...

free(arr);    // Giải phóng — trả memory về heap
arr = NULL;   // Đặt NULL để tránh dangling pointer
```

### 3.1 Dangling pointer — Con trỏ lơ lửng
```c
int *p = (int*)malloc(sizeof(int));
*p = 42;
free(p);
// p vẫn trỏ đến vùng nhớ đã giải phóng!
// printf("%d", *p);  // ❌ UNDEFINED BEHAVIOR!
p = NULL;  // ✅ An toàn
```

### 3.2 Memory leak — Rò rỉ bộ nhớ
```c
// ❌ SAI: Quên free → memory leak!
void ham() {
    int *p = (int*)malloc(1000 * sizeof(int));
    // Dùng p nhưng không free!
}  // p mất, nhưng 4000 byte trên heap vẫn bị chiếm!

// ✅ ĐÚNG
void ham() {
    int *p = (int*)malloc(1000 * sizeof(int));
    // ... dùng p ...
    free(p);
}
```

## 4. Cấp phát động mảng 2 chiều

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int hang = 3, cot = 4;
    
    // Cấp phát mảng con trỏ
    int **mt = (int**)malloc(hang * sizeof(int*));
    if (mt == NULL) return 1;
    
    // Cấp phát từng hàng
    for (int i = 0; i < hang; i++) {
        mt[i] = (int*)malloc(cot * sizeof(int));
        if (mt[i] == NULL) {
            // Giải phóng các hàng đã cấp phát
            for (int j = 0; j < i; j++) free(mt[j]);
            free(mt);
            return 1;
        }
    }
    
    // Gán giá trị
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            mt[i][j] = i * cot + j + 1;
            printf("%3d ", mt[i][j]);
        }
        printf("\n");
    }
    
    // Giải phóng — theo thứ tự ngược lại!
    for (int i = 0; i < hang; i++) {
        free(mt[i]);  // Giải phóng từng hàng
    }
    free(mt);  // Giải phóng mảng con trỏ
    
    return 0;
}
```

## 5. Mẫu chuẩn khi dùng cấp phát động

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr = NULL;
    
    printf("Nhap so phan tu: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Du lieu khong hop le!\n");
        return 1;
    }
    
    // Bước 1: Cấp phát
    arr = (int*)malloc(n * sizeof(int));
    
    // Bước 2: Kiểm tra NULL
    if (arr == NULL) {
        printf("Loi cap phat bo nho!\n");
        return 1;
    }
    
    // Bước 3: Sử dụng
    for (int i = 0; i < n; i++) {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    
    // Bước 4: Giải phóng
    free(arr);
    arr = NULL;
    
    return 0;
}
```

## 6. Bài tập thực hành

### Bài 1: Mảng động cơ bản
Nhập n, cấp phát mảng n số nguyên. Nhập giá trị, tính tổng, trung bình, in ra. Giải phóng đúng cách.

### Bài 2: Mở rộng mảng
Nhập n, cấp phát mảng n phần tử. Sau đó nhập thêm m phần tử mới, dùng `realloc` để mở rộng. In toàn bộ mảng.

### Bài 3: Ma trận động
Nhập M, N. Cấp phát động ma trận M×N. Nhập giá trị, tính tổng từng hàng, tìm max ma trận.

### Bài 4: Quản lý điểm SV động
Dùng struct và cấp phát động:
```c
typedef struct {
    char ten[50];
    float diem;
} SinhVien;
```
Nhập n, cấp phát mảng n sinh viên. Nhập dữ liệu, tính điểm TB, in danh sách. Free đúng cách.

## 📚 Tham khảo thêm

- [GeeksforGeeks — Dynamic Memory Allocation in C](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)
- [Programiz — C Dynamic Memory Allocation](https://www.programiz.com/c-programming/c-dynamic-memory-allocation)
- [Memory Leak Detection](https://www.geeksforgeeks.org/memory-leak-in-c-and-how-to-avoid-it/)
- [Video: malloc, calloc, realloc, free](https://www.youtube.com/watch?v=xa4ugmMDhiE)
