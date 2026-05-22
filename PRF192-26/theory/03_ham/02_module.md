# 📦 Module trong C

## 1. Module là gì?

**Module** là cách tổ chức code thành các file riêng biệt, mỗi file nhóm các hàm liên quan đến nhau.

### Nguyên tắc thiết kế module

```
┌─────────────────────────────┐
│      CHƯƠNG TRÌNH           │
│                             │
│  main.c (điều phối)         │
│    ├── nhập/xuất dữ liệu    │
│    ├── gọi các module       │
│    └── điều khiển luồng     │
│                             │
│  Module 1: tinhToan.c/h     │
│    ├── tinhTong()           │
│    ├── tinhHieu()           │
│    └── tinhTich()           │
│                             │
│  Module 2: hinhHoc.c/h      │
│    ├── tinhDienTich()       │
│    ├── tinhChuVi()          │
│    └── ...                  │
└─────────────────────────────┘
```

### Tiêu chí module tốt

| Tiêu chí | Giải thích | Tốt | Xấu |
|----------|------------|-----|-----|
| **Cohesion (tính gắn kết)** | Các hàm trong module liên quan chặt chẽ | Module `tinhToan` chỉ chứa hàm toán học | Module `tienIch` chứa cả nhập/xuất + tính toán + ghi file |
| **Coupling (tính ghép nối)** | Module phụ thuộc ít vào module khác | `tinhToan` không cần biết `nhapXuat` | `tinhToan` gọi hàm từ `nhapXuat` |

## 2. Tổ chức module trong C

### Cấu trúc file
```
thuMucDuAn/
├── main.c           ← Chương trình chính
├── tinhToan.h       ← Header file (khai báo prototype)
├── tinhToan.c       ← Source file (định nghĩa hàm)
└── nhapXuat.h       ← Header file
└── nhapXuat.c       ← Source file
```

### Header file `.h` — Chứa prototype
```c
// ===== tinhToan.h =====
#ifndef TINH_TOAN_H   // Include guard — tránh include nhiều lần
#define TINH_TOAN_H

// Prototype — khai báo hàm
int tinhTong(int a, int b);
int tinhHieu(int a, int b);
int tinhTich(int a, int b);
double tinhThuong(int a, int b);

#endif
```

### Source file `.c` — Chứa định nghĩa
```c
// ===== tinhToan.c =====
#include "tinhToan.h"  // Include header của chính nó

int tinhTong(int a, int b) {
    return a + b;
}

int tinhHieu(int a, int b) {
    return a - b;
}

int tinhTich(int a, int b) {
    return a * b;
}

double tinhThuong(int a, int b) {
    if (b == 0) {
        printf("Loi: chia cho 0!\n");
        return 0;
    }
    return (double)a / b;
}
```

### `main.c` — Sử dụng module
```c
// ===== main.c =====
#include <stdio.h>
#include "tinhToan.h"
#include "nhapXuat.h"

int main() {
    int a, b;
    
    nhapSoNguyen(&a, &b);
    
    printf("Tong: %d\n", tinhTong(a, b));
    printf("Hieu: %d\n", tinhHieu(a, b));
    printf("Tich: %d\n", tinhTich(a, b));
    printf("Thuong: %.2f\n", tinhThuong(a, b));
    
    return 0;
}
```

## 3. Include guard — Tránh include trùng lặp

```c
// Cách 1: #ifndef (chuẩn, dùng được mọi nơi)
#ifndef TEN_FILE_H
#define TEN_FILE_H
// ... nội dung header ...
#endif

// Cách 2: #pragma once (ngắn gọn, nhưng không phải compiler nào cũng hỗ trợ)
#pragma once
// ... nội dung header ...
```

## 4. `extern` — Dùng biến toàn cục giữa các file

```c
// ===== bienToanCuc.h =====
#ifndef BIEN_TOAN_CUC_H
#define BIEN_TOAN_CUC_H

extern int soLuongSinhVien;  // Khai báo (không định nghĩa)

#endif

// ===== bienToanCuc.c =====
#include "bienToanCuc.h"

int soLuongSinhVien = 0;  // Định nghĩa thực sự

// ===== main.c =====
#include <stdio.h>
#include "bienToanCuc.h"

int main() {
    soLuongSinhVien = 50;
    printf("So luong SV: %d\n", soLuongSinhVien);
    return 0;
}
```

> ⚠️ Hạn chế dùng biến toàn cục (global variable). Nên truyền qua tham số hàm.

## 5. `static` trong module

### Static hàm — Chỉ dùng trong file hiện tại
```c
// ===== tinhToan.c =====

// Hàm này CHỈ được gọi trong file tinhToan.c
static int kiemTraSoAm(int n) {
    return n < 0;
}

int tinhGiaiThua(int n) {
    if (kiemTraSoAm(n)) {  // Gọi static function
        return -1;
    }
    // ... tính giai thừa
}
```

### Static biến — Giữ giá trị giữa các lần gọi
```c
#include <stdio.h>

int demSoLanGoi() {
    static int dem = 0;  // Chỉ khởi tạo 1 lần
    dem++;
    return dem;
}

int main() {
    printf("Lan goi: %d\n", demSoLanGoi());  // 1
    printf("Lan goi: %d\n", demSoLanGoi());  // 2
    printf("Lan goi: %d\n", demSoLanGoi());  // 3
    return 0;
}
```

## 6. Ví dụ module hoàn chỉnh

### Bài toán: Quản lý điểm sinh viên

**Phân rã module:**
```
quanLyDiem/
├── main.c              ← Menu + điều phối
├── sinhVien.h/.c       ← Struct SinhVien + hàm xử lý
├── nhapXuat.h/.c       ← Nhập/xuất dữ liệu
└── tinhToan.h/.c       ← Tính điểm TB, xếp loại
```

```c
// ===== sinhVien.h =====
#ifndef SINH_VIEN_H
#define SINH_VIEN_H

typedef struct {
    char maSV[20];
    char hoTen[50];
    float diemToan;
    float diemVan;
    float diemAnh;
} SinhVien;

float tinhDiemTrungBinh(SinhVien sv);
void xepLoai(SinhVien sv);

#endif
```

## 7. Bài tập thực hành

### Bài 1: Module hình học
Tạo thư mục `hinhHoc/` với 3 file:
- `hinhHoc.h` — prototype: `tinhDienTichHinhTron()`, `tinhChuViHinhTron()`, `tinhDienTichHCN()`, `tinhChuViHCN()`
- `hinhHoc.c` — định nghĩa các hàm
- `main.c` — gọi các hàm với dữ liệu nhập vào

### Bài 2: Module mảng số
Tạo module `mangSo/` gồm:
- `mangSo.h`: `nhapMang()`, `inMang()`, `tinhTong()`, `timMax()`, `timMin()`
- `mangSo.c`: định nghĩa
- `main.c`: menu gọi các chức năng

### Bài 3: Phân tích module
Cho chương trình quản lý thư viện. Hãy vẽ sơ đồ module (dùng text) và xác định:
- Cần bao nhiêu module?
- Mỗi module gồm hàm gì?
- Module nào phụ thuộc module nào?

## 📚 Tham khảo thêm

- [GeeksforGeeks — Header Files in C](https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/)
- [GeeksforGeeks — Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)
- [Programiz — C Storage Class](https://www.programiz.com/c-programming/c-storage-class)
