# 🔗 Truyền Tham Chiếu (Pass by Reference) qua Con Trỏ

## 1. Vấn đề của Pass by Value

Trong C, mặc định tham số được truyền bằng **giá trị** (pass by value). Hàm nhận **bản sao**, không phải biến gốc.

```c
#include <stdio.h>

// ❌ Hàm này KHÔNG hoán đổi được
void hoanViSai(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Trong ham: a=%d, b=%d\n", a, b);  // Đã đổi
}

int main() {
    int x = 5, y = 10;
    
    printf("Truoc: x=%d, y=%d\n", x, y);  // 5, 10
    hoanViSai(x, y);
    printf("Sau: x=%d, y=%d\n", x, y);    // 5, 10 (KHÔNG đổi!)
    
    return 0;
}
```

## 2. Giải pháp: Dùng con trỏ — Pass by Reference

Thay vì truyền giá trị, ta truyền **địa chỉ** của biến. Hàm có thể thay đổi giá trị gốc qua địa chỉ đó.

```c
#include <stdio.h>

// ✅ Hàm này hoán đổi được — nhận địa chỉ
void hoanViDung(int *a, int *b) {
    int temp = *a;   // Lấy giá trị tại địa chỉ a
    *a = *b;         // Gán giá trị mới vào địa chỉ a
    *b = temp;       // Gán temp vào địa chỉ b
}

int main() {
    int x = 5, y = 10;
    
    printf("Truoc: x=%d, y=%d\n", x, y);  // 5, 10
    hoanViDung(&x, &y);  // Truyền địa chỉ!
    printf("Sau: x=%d, y=%d\n", x, y);    // 10, 5 (ĐÃ đổi!)
    
    return 0;
}
```

## 3. Khi nào cần Pass by Reference?

### 3.1 Thay đổi giá trị biến gốc
```c
void themPhanTu(int *n, int arr[]) {
    arr[*n] = 100;
    (*n)++;  // Tăng số lượng phần tử — thay đổi biến gốc!
}

int main() {
    int arr[100] = {1, 2, 3};
    int soLuong = 3;
    
    themPhanTu(&soLuong, arr);
    printf("So luong: %d, arr[3] = %d\n", soLuong, arr[3]);  // 4, 100
    return 0;
}
```

### 3.2 Trả về nhiều kết quả từ một hàm
```c
#include <stdio.h>

// Hàm tính tổng và tích, trả về qua tham số
void tinhTongVaTich(int a, int b, int *tong, int *tich) {
    *tong = a + b;
    *tich = a * b;
}

int main() {
    int x = 5, y = 3;
    int tong, tich;
    
    tinhTongVaTich(x, y, &tong, &tich);
    
    printf("Tong: %d\n", tong);   // 8
    printf("Tich: %d\n", tich);   // 15
    
    return 0;
}
```

### 3.3 Tiết kiệm bộ nhớ (không copy dữ liệu lớn)
```c
#include <stdio.h>

typedef struct {
    char ten[50];
    int tuoi;
    float diem[10];
} SinhVien;

// ✅ Truyền con trỏ — không copy 50+4+40=94 byte
void inThongTin(const SinhVien *sv) {
    printf("Ten: %s, Tuoi: %d\n", sv->ten, sv->tuoi);
    // Dùng const để đảm bảo không sửa đổi
}

// ❌ Truyền giá trị — copy toàn bộ struct (~94 byte)
void inThongTinSai(SinhVien sv) {
    printf("Ten: %s\n", sv.ten);
}
```

## 4. Mảng và con trỏ trong tham số hàm

```c
#include <stdio.h>

// Các cách khai báo tương đương:
// void xuLyMang(int arr[], int n)
// void xuLyMang(int *arr, int n)
void xuLyMang(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] * 2;  // Thay đổi arr gốc!
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;
    
    xuLyMang(a, n);  // a là địa chỉ — pass by reference
    
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);  // 2 4 6 8 10
    }
    
    return 0;
}
```

> ⚠️ Mảng luôn được truyền bằng tham chiếu (pass by reference) trong C!

## 5. Con trỏ hàm (Function Pointer) — Nâng cao

```c
#include <stdio.h>

int cong(int a, int b) { return a + b; }
int tru(int a, int b) { return a - b; }
int nhan(int a, int b) { return a * b; }

int main() {
    int (*phepToan)(int, int);  // Con trỏ hàm
    
    phepToan = cong;
    printf("5 + 3 = %d\n", phepToan(5, 3));  // 8
    
    phepToan = tru;
    printf("5 - 3 = %d\n", phepToan(5, 3));  // 2
    
    phepToan = nhan;
    printf("5 * 3 = %d\n", phepToan(5, 3));  // 15
    
    return 0;
}
```

## 6. `const` với tham số con trỏ

```c
void docDuLieu(const int *p) {
    // *p = 10;  // ❌ LỖI! Không thể sửa qua con trỏ const
    printf("%d", *p);  // ✅ OK — chỉ đọc
}

void ghiDuLieu(int * const p) {
    *p = 10;   // ✅ OK — có thể sửa
    // p = NULL; // ❌ LỖI! Không thể đổi địa chỉ p trỏ đến
}

void docVaGhi(const int * const p) {
    // *p = 10;  // ❌ LỖI
    // p = NULL; // ❌ LỖI
    printf("%d", *p);  // ✅ OK — chỉ đọc
}
```

## 7. Bài tập thực hành

### Bài 1: Hoán địa chỉ
Viết hàm `void hoanVi(int *a, int *b)` và kiểm tra với 2 số nhập từ bàn phím.

### Bài 2: Min, Max, Sum
Viết hàm:
```c
void thongKeMang(int arr[], int n, int *min, int *max, int *sum);
```
Tính đồng thời min, max, tổng của mảng.

### Bài 3: Tìm kiếm và trả vị trí
Viết `int timViTri(int arr[], int n, int giaTri, int *viTri)`:
- Trả về 1 nếu tìm thấy (và gán `*viTri` = vị trí)
- Trả về 0 nếu không tìm thấy

### Bài 4: Phân tích số
Viết `void phanTichSo(int n, int *soLuongChuSo, int *tongChuSo, int *soDaoNguoc)`.
```
Ví dụ: n = 1234
→ soLuongChuSo = 4
→ tongChuSo = 10
→ soDaoNguoc = 4321
```

## 📚 Tham khảo thêm

- [GeeksforGeeks — Pass by Reference in C](https://www.geeksforgeeks.org/passing-by-pointer-vs-passing-by-reference-in-c/)
- [GeeksforGeeks — Function Pointer in C](https://www.geeksforgeeks.org/function-pointer-in-c/)
- [Programiz — Pass Address to Functions](https://www.programiz.com/c-programming/c-pointer-functions)
