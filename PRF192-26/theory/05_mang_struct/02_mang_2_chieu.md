# 🔲 Mảng 2 Chiều (Ma Trận) trong C

## 1. Mảng 2 chiều là gì?

Mảng 2 chiều = **mảng của mảng**. Hay còn gọi là **ma trận** với **hàng** và **cột**.

```
int mt[3][4];  // 3 hàng, 4 cột

       Cột 0  Cột 1  Cột 2  Cột 3
Hàng 0: [  ]   [  ]   [  ]   [  ]
Hàng 1: [  ]   [  ]   [  ]   [  ]
Hàng 2: [  ]   [  ]   [  ]   [  ]
```

## 2. Khai báo và khởi tạo

```c
#include <stdio.h>

int main() {
    // Cách 1: Khai báo + khởi tạo đầy đủ
    int mt1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    // Cách 2: Khởi tạo theo hàng (C tự động phân bổ)
    int mt2[2][3] = {1, 2, 3, 4, 5, 6};  // Giống mt1
    
    // Cách 3: Khởi tạo một phần (phần còn lại = 0)
    int mt3[2][3] = {
        {1, 2},
        {4}
    };  // = {{1, 2, 0}, {4, 0, 0}}
    
    // Cách 4: Khởi tạo toàn 0
    int mt4[10][10] = {0};
    
    return 0;
}
```

## 3. Truy cập và duyệt mảng 2 chiều

```c
#include <stdio.h>

int main() {
    int mt[3][4] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12}
    };
    
    // Duyệt bằng 2 vòng for lồng nhau
    for (int i = 0; i < 3; i++) {        // i = hàng
        for (int j = 0; j < 4; j++) {    // j = cột
            printf("%3d ", mt[i][j]);
        }
        printf("\n");  // Xuống dòng sau mỗi hàng
    }
    
    // Truy cập phần tử cụ thể
    printf("\nmt[1][2] = %d\n", mt[1][2]);  // 7
    mt[2][0] = 99;  // Gán giá trị mới
    
    return 0;
}
```

## 4. Nhập ma trận từ bàn phím

```c
#include <stdio.h>

int main() {
    int M, N;
    
    printf("Nhap so hang M: ");
    scanf("%d", &M);
    printf("Nhap so cot N: ");
    scanf("%d", &N);
    
    int mt[100][100];  // Giả sử M, N <= 100
    
    // Nhập
    printf("Nhap ma tran:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("mt[%d][%d] = ", i, j);
            scanf("%d", &mt[i][j]);
        }
    }
    
    // In
    printf("\nMa tran vua nhap:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%5d ", mt[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

## 5. Các thao tác cơ bản với ma trận

### 5.1 Tổng các phần tử
```c
int tong = 0;
for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
        tong += mt[i][j];
    }
}
printf("Tong cac phan tu: %d\n", tong);
```

### 5.2 Tổng từng hàng
```c
for (int i = 0; i < M; i++) {
    int tongHang = 0;
    for (int j = 0; j < N; j++) {
        tongHang += mt[i][j];
    }
    printf("Tong hang %d: %d\n", i, tongHang);
}
```

### 5.3 Tổng từng cột
```c
for (int j = 0; j < N; j++) {
    int tongCot = 0;
    for (int i = 0; i < M; i++) {
        tongCot += mt[i][j];
    }
    printf("Tong cot %d: %d\n", j, tongCot);
}
```

### 5.4 Tìm max, min
```c
int max = mt[0][0];
int min = mt[0][0];
for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
        if (mt[i][j] > max) max = mt[i][j];
        if (mt[i][j] < min) min = mt[i][j];
    }
}
printf("Max: %d, Min: %d\n", max, min);
```

### 5.5 Tổng đường chéo chính (ma trận vuông)
```c
// Ma trận vuông M = N
int tongCheo = 0;
for (int i = 0; i < M; i++) {
    tongCheo += mt[i][i];  // Đường chéo chính: i == j
}
printf("Tong duong cheo chinh: %d\n", tongCheo);

// Đường chéo phụ: i + j == N - 1
int tongCheoPhu = 0;
for (int i = 0; i < M; i++) {
    tongCheoPhu += mt[i][N - 1 - i];
}
```

## 6. Chuyển vị ma trận

```c
#include <stdio.h>

int main() {
    int mt[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int M = 3, N = 4;
    
    // Ma trận chuyển vị: Kích thước N x M
    int chuyenVi[4][3];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            chuyenVi[i][j] = mt[j][i];
        }
    }
    
    // In ma trận chuyển vị
    printf("Ma tran chuyen vi:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%3d ", chuyenVi[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

## 7. Nhân 2 ma trận

```c
#include <stdio.h>

int main() {
    int A[10][10], B[10][10], C[10][10] = {0};
    int M, N, P;
    
    // A: M x N, B: N x P, C = A * B: M x P
    printf("Nhap M, N, P: ");
    scanf("%d %d %d", &M, &N, &P);
    
    printf("Nhap ma tran A (%dx%d):\n", M, N);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);
    
    printf("Nhap ma tran B (%dx%d):\n", N, P);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < P; j++)
            scanf("%d", &B[i][j]);
    
    // Nhân ma trận
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    printf("Ma tran C = A * B:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            printf("%5d ", C[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

## 8. Bài tập thực hành

### Bài 1: Nhập và thống kê ma trận
Nhập ma trận M×N. Tính và in:
- Tổng các phần tử
- Trung bình cộng
- Số lượng số chẵn
- Tổng các phần tử ở biên (hàng đầu, hàng cuối, cột đầu, cột cuối)

### Bài 2: Ma trận đơn vị
In ra ma trận đơn vị kích thước N:
```
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
```

### Bài 3: Xoay ma trận 90°
Nhập ma trận M×N. Xoay 90° theo chiều kim đồng hồ.

### Bài 4: Tính định thức ma trận 3×3
Nhập ma trận vuông 3×3. Tính định thức.

## 📚 Tham khảo thêm

- [GeeksforGeeks — Multidimensional Arrays in C](https://www.geeksforgeeks.org/multidimensional-arrays-in-c/)
- [Programiz — C 2D Arrays](https://www.programiz.com/c-programming/c-multi-dimensional-arrays)
- [Matrix Operations in C](https://www.tutorialspoint.com/cprogramming/c_multi_dimensional_arrays.htm)
