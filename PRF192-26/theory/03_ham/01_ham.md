# 🧩 Hàm (Function) trong C

## 1. Hàm là gì?

**Hàm** là một khối code thực hiện một nhiệm vụ cụ thể. Giống như một "cỗ máy nhỏ":
- **Nhận vào:** tham số (input)
- **Xử lý:** code bên trong
- **Trả ra:** giá trị (output)

### Tại sao cần hàm?
- ✅ **Tái sử dụng** — viết một lần, dùng nhiều nơi
- ✅ **Dễ bảo trì** — sửa một chỗ, ảnh hưởng mọi nơi
- ✅ **Dễ đọc** — chia nhỏ bài toán phức tạp
- ✅ **Dễ kiểm thử** — test từng hàm riêng

## 2. Cú pháp hàm

```c
// Định nghĩa hàm
kieu_tra_ve tenHam(kieu_ts1 ten_ts1, kieu_ts2 ten_ts2, ...) {
    // Thân hàm: code xử lý
    return gia_tri;  // (nếu kiểu trả về != void)
}
```

### Ví dụ đơn giản
```c
#include <stdio.h>

// Hàm tính tổng 2 số nguyên
int tinhTong(int a, int b) {
    int tong = a + b;
    return tong;  // Trả về kết quả kiểu int
}

int main() {
    int x = 5, y = 10;
    int ketQua = tinhTong(x, y);  // Gọi hàm
    
    printf("Tong %d + %d = %d\n", x, y, ketQua);
    return 0;
}
```

## 3. Cấu trúc hàm trong chương trình

### Cách 1: Định nghĩa trước `main()`
```c
#include <stdio.h>

// Hàm định nghĩa trước — compiler biết từ đầu
int binhPhuong(int n) {
    return n * n;
}

int main() {
    printf("%d", binhPhuong(5));  // 25
    return 0;
}
```

### Cách 2: Prototype (khai báo trước, định nghĩa sau) ✅ KHUYÊN DÙNG
```c
#include <stdio.h>

// Prototype — khai báo trước
int binhPhuong(int n);
double tinhDienTichHinhTron(double banKinh);
void inThongBao();

int main() {
    printf("%d\n", binhPhuong(5));
    printf("%.2f\n", tinhDienTichHinhTron(3.0));
    inThongBao();
    return 0;
}

// Định nghĩa sau main
int binhPhuong(int n) {
    return n * n;
}

double tinhDienTichHinhTron(double banKinh) {
    return 3.14159 * banKinh * banKinh;
}

void inThongBao() {
    printf("Hello from function!\n");
}
```

## 4. Phân loại hàm

### 4.1 Hàm có trả về — có tham số
```c
int tinhGiaiThua(int n) {
    int gt = 1;
    for (int i = 1; i <= n; i++) {
        gt *= i;
    }
    return gt;
}
// Dùng: int kq = tinhGiaiThua(5);  // 120
```

### 4.2 Hàm có trả về — không tham số
```c
int nhapSoNguyen() {
    int n;
    printf("Nhap so: ");
    scanf("%d", &n);
    return n;
}
// Dùng: int x = nhapSoNguyen();
```

### 4.3 Hàm không trả về (void) — có tham số
```c
void inMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Dùng: inMang(mang, 5);  // Không gán biến
```

### 4.4 Hàm không trả về — không tham số
```c
void inMenu() {
    printf("1. Tinh tong\n");
    printf("2. Tinh hieu\n");
    printf("3. Thoat\n");
    printf("Chon: ");
}
```

## 5. Tham số và đối số

```c
// Định nghĩa: tham số (parameter)
int tinhTich(int x, int y) {   // x, y là tham số
    return x * y;
}

int main() {
    // Gọi hàm: đối số (argument)
    int kq = tinhTich(5, 3);    // 5, 3 là đối số
    printf("%d", kq);           // 15
    return 0;
}
```

| Thuật ngữ | Tiếng Anh | Vị trí |
|-----------|-----------|--------|
| Tham số | Parameter | Trong định nghĩa hàm |
| Đối số | Argument | Khi gọi hàm |

## 6. Pass by Value — Truyền tham số trị

Trong C, **mặc định** tham số được truyền bằng **giá trị** (pass by value). Nghĩa là hàm nhận **bản sao**, không phải biến gốc.

```c
#include <stdio.h>

void tangLen(int x) {
    x = x + 10;  // Chỉ thay đổi bản sao
    printf("Trong ham: x = %d\n", x);  // 15
}

int main() {
    int a = 5;
    printf("Truoc khi goi: a = %d\n", a);  // 5
    
    tangLen(a);  // Truyền bản sao của a
    
    printf("Sau khi goi: a = %d\n", a);   // Vẫn là 5!
    return 0;
}
```

> ⚠️ Muốn thay đổi biến gốc → dùng con trỏ (Pass by Reference, xem bài `04_con_tro/02_truyen_tham_chieu.md`).

## 7. Hàm `main()` — Hàm đặc biệt

```c
int main() {               // Không tham số
    return 0;
}

// Hoặc:
int main(int argc, char *argv[]) {  // Có tham số dòng lệnh
    printf("So tham so: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}
```

## 8. Lưu ý quan trọng

### 8.1 Kiểm tra đầu vào trong hàm
```c
int tinhGiaiThua(int n) {
    if (n < 0) {
        printf("Loi: n phai >= 0!\n");
        return -1;  // Giá trị báo lỗi
    }
    int gt = 1;
    for (int i = 2; i <= n; i++) {
        gt *= i;
    }
    return gt;
}
```

### 8.2 Mỗi hàm làm một việc (Single Responsibility)
```c
// ✅ TỐT: Tách riêng
int tinhTong(int arr[], int n);       // Việc 1: tính tổng
void inMang(int arr[], int n);         // Việc 2: in mảng
int timMax(int arr[], int n);          // Việc 3: tìm max

// ❌ KHÔNG TỐT: Một hàm làm quá nhiều
void xuLyMang(int arr[], int n) {     // Vừa tính, vừa in, vừa tìm...
    // ... quá dài, khó bảo trì
}
```

## 9. Bài tập thực hành

### Bài 1: Thư viện hình học
Viết các hàm:
- `double tinhChuViHinhTron(double r)`
- `double tinhDienTichHinhTron(double r)`
- `double tinhChuViHinhChuNhat(double dai, double rong)`
- `double tinhDienTichHinhChuNhat(double dai, double rong)`

Gọi từ `main()` với dữ liệu nhập vào.

### Bài 2: Hàm kiểm tra
Viết hàm:
- `int laSoNguyenTo(int n)` — trả về 1 nếu n nguyên tố, 0 nếu không
- `int laSoHoanHao(int n)` — 1 nếu n là số hoàn hảo (tổng ước số = n)
- `int laSoChinhPhuong(int n)` — 1 nếu n là số chính phương

In ra các số thỏa mãn từ 1 đến 1000.

### Bài 3: Đảo ngược số
Viết `int daoNguocSo(int n)` — trả về số đảo ngược.
```
Ví dụ: daoNguocSo(1234) → 4321
```

### Bài 4: Menu bằng hàm
Viết chương trình có menu:
1. Tính tổng 1..n
2. Tính n!
3. Kiểm tra số nguyên tố
4. Thoát

Mỗi chức năng là một hàm riêng.

## 📚 Tham khảo thêm

- [GeeksforGeeks — Functions in C](https://www.geeksforgeeks.org/functions-in-c/)
- [Programiz — C Functions](https://www.programiz.com/c-programming/c-functions)
- [GeeksforGeeks — Difference between argument and parameter](https://www.geeksforgeeks.org/difference-between-argument-and-parameter-in-c/)
