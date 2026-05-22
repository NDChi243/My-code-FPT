# 📊 Mảng 1 Chiều (1D Array) trong C

## 1. Mảng là gì?

**Mảng** là tập hợp các phần tử **cùng kiểu dữ liệu**, nằm liên tiếp nhau trong bộ nhớ.

```
Bộ nhớ:  [10][20][30][40][50]
Index:     0   1   2   3   4
```

## 2. Khai báo và khởi tạo

```c
// Cú pháp: <kieu> <ten>[<kich_thuoc>];

// Cách 1: Khai báo + gán sau
int arr[5];
arr[0] = 10;
arr[1] = 20;

// Cách 2: Khai báo + khởi tạo toàn bộ
int a[5] = {1, 2, 3, 4, 5};

// Cách 3: Khởi tạo một phần (phần còn lại = 0)
int b[5] = {1, 2};      // b = {1, 2, 0, 0, 0}

// Cách 4: Không cần kích thước (tự động xác định)
int c[] = {1, 2, 3, 4, 5};  // Kích thước = 5

// Cách 5: Khởi tạo toàn 0
int d[100] = {0};  // Tất cả = 0
```

## 3. Truy cập phần tử

```c
#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    
    // Đọc
    printf("arr[0] = %d\n", arr[0]);  // 10
    printf("arr[3] = %d\n", arr[3]);  // 40
    
    // Ghi
    arr[2] = 99;  // arr = {10, 20, 99, 40, 50}
    
    // Dùng vòng lặp
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    return 0;
}
```

> ⚠️ **Mảng C bắt đầu từ index 0!** `arr[5]` có index 0..4.

## 4. Duyệt mảng — 3 cách

```c
#include <stdio.h>

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);  // Công thức tính số phần tử
    
    // Cách 1: for với index
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Cách 2: while
    int i = 0;
    while (i < n) {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
    
    // Cách 3: con trỏ
    int *p = arr;
    for (int i = 0; i < n; i++) {
        printf("%d ", *(p + i));
    }
    
    return 0;
}
```

## 5. Tính tổng, tìm min/max

```c
#include <stdio.h>

int main() {
    int arr[] = {7, 2, 9, 1, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Tính tổng
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i];
    }
    printf("Tong: %d\n", tong);
    
    // Tìm max
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Max: %d\n", max);
    
    // Tìm min
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Min: %d\n", min);
    
    // Tính trung bình
    float tb = (float)tong / n;
    printf("Trung binh: %.2f\n", tb);
    
    return 0;
}
```

## 6. Các thao tác cơ bản với mảng

### 6.1 Nhập mảng từ bàn phím
```c
#include <stdio.h>

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    
    int arr[100];  // Giả sử n <= 100
    
    // Nhập
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    // In
    printf("Mang vua nhap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
```

### 6.2 Đảo ngược mảng
```c
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    
    printf("Mang dao nguoc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);  // 5 4 3 2 1
    }
    
    return 0;
}
```

### 6.3 Thêm phần tử vào mảng
```c
#include <stdio.h>

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5;  // Số phần tử hiện tại
    
    // Thêm ở cuối
    arr[n] = 6;
    n++;
    
    // Chèn ở vị trí 2
    int viTri = 2;
    int giaTri = 99;
    
    // Dịch các phần tử sang phải
    for (int i = n; i > viTri; i--) {
        arr[i] = arr[i - 1];
    }
    arr[viTri] = giaTri;
    n++;
    
    // In: 1 2 99 3 4 5 6
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
```

### 6.4 Xóa phần tử khỏi mảng
```c
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 99, 3, 4, 5};
    int n = 6;
    int viTriXoa = 2;
    
    // Dịch các phần tử sang trái
    for (int i = viTriXoa; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    
    // In: 1 2 3 4 5
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
```

## 7. Các lỗi thường gặp

### Lỗi 1: Truy cập vượt biên (Index out of bounds)
```c
int arr[5] = {1, 2, 3, 4, 5};
arr[5] = 10;   // ❌ Vi phạm! arr chỉ có index 0..4
arr[-1] = 0;   // ❌ Index âm!
// C không kiểm tra biên — undefined behavior!
```

### Lỗi 2: Nhầm `=` với `==` khi kiểm tra
```c
if (arr[i] = 5) {  // ❌ Gán arr[i]=5, luôn đúng!
    printf("Tim thay 5");
}
```

### Lỗi 3: Quên kích thước mảng
```c
void ham(int arr[]) {       // arr là con trỏ, không biết kích thước!
    int n = sizeof(arr) / sizeof(arr[0]);  // ❌ SAI!
    // sizeof(arr) = 4 (kích thước con trỏ), không phải mảng!
}

// ✅ ĐÚNG: Luôn truyền thêm tham số n
void ham(int arr[], int n) {
    // ...
}
```

## 8. Bài tập thực hành

### Bài 1: Nhập và thống kê
Nhập n, nhập mảng n số nguyên. Tính và in:
- Tổng các phần tử
- Trung bình cộng
- Số lượng số chẵn, số lẻ
- Số lượng số dương, số âm

### Bài 2: Tìm phần tử xuất hiện nhiều nhất
Nhập mảng n số nguyên. Tìm phần tử xuất hiện nhiều nhất.

### Bài 3: Mảng đối xứng (Palindrome)
Kiểm tra mảng có đối xứng không?
```
[1, 2, 3, 2, 1] → Đối xứng
[1, 2, 3, 4, 5] → Không đối xứng
```

### Bài 4: Gộp 2 mảng
Nhập 2 mảng a (m phần tử), b (n phần tử). Tạo mảng c = a + b (ghép nối tiếp). In mảng c.

### Bài 5: Xóa phần tử trùng
Nhập mảng n số nguyên. Xóa các phần tử trùng nhau, chỉ giữ 1 bản sao.

## 📚 Tham khảo thêm

- [GeeksforGeeks — Arrays in C](https://www.geeksforgeeks.org/arrays-in-c/)
- [Programiz — C Arrays](https://www.programiz.com/c-programming/c-arrays)
- [GeeksforGeeks — Insert and Delete in Array](https://www.geeksforgeeks.org/search-insert-and-delete-in-an-unsorted-array/)
