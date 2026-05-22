# 🎯 Phạm Vi và Thời Gian Sống của Biến

## 1. Tổng quan

Mỗi biến trong C có:
- **Phạm vi (scope)** — nơi nào trong code có thể truy cập biến
- **Thời gian sống (lifetime)** — biến tồn tại trong bao lâu

## 2. Phân loại biến theo phạm vi

### 2.1 Biến địa phương (Local Variable)

- Khai báo **bên trong hàm** hoặc khối `{}`
- Chỉ truy cập được **trong hàm/khối đó**
- Thời gian sống: **từ khi khai báo đến khi ra khỏi khối**

```c
#include <stdio.h>

void hamA() {
    int x = 10;  // Biến địa phương của hamA
    printf("hamA: x = %d\n", x);
}

void hamB() {
    // printf("hamB: x = %d", x);  // ❌ LỖI! x không tồn tại ở đây
    int y = 20;
    printf("hamB: y = %d\n", y);
}

int main() {
    hamA();
    hamB();
    // printf("%d", x);  // ❌ LỖI! x không tồn tại ngoài hamA
    // printf("%d", y);  // ❌ LỖI! y không tồn tại ngoài hamB
    return 0;
}
```

### 2.2 Biến trong khối (Block Scope)

```c
#include <stdio.h>

int main() {
    int a = 5;  // Biến của main
    
    if (a > 0) {
        int b = 10;  // Chỉ tồn tại trong khối if
        printf("Trong if: a=%d, b=%d\n", a, b);
    }
    
    // printf("b = %d", b);  // ❌ LỖI! b không tồn tại ở đây
    
    for (int i = 0; i < 3; i++) {  // i chỉ tồn tại trong for
        printf("%d ", i);
    }
    // printf("%d", i);  // ❌ LỖI! i không tồn tại ở đây
    
    return 0;
}
```

### 2.3 Biến toàn cục (Global Variable)

- Khai báo **bên ngoài tất cả hàm**
- Có thể truy cập từ **bất kỳ hàm nào**
- Thời gian sống: **toàn bộ chương trình**

```c
#include <stdio.h>

// Biến toàn cục
int soLuongSinhVien = 0;
const char *TEN_TRUONG = "FPT University";

void themSinhVien() {
    soLuongSinhVien++;  // Truy cập biến toàn cục
}

void inThongTin() {
    printf("Truong: %s\n", TEN_TRUONG);
    printf("So luong SV: %d\n", soLuongSinhVien);
}

int main() {
    themSinhVien();
    themSinhVien();
    themSinhVien();
    inThongTin();  // So luong SV: 3
    return 0;
}
```

> ⚠️ **Hạn chế biến toàn cục!** Dễ gây lỗi khó debug vì hàm nào cũng có thể thay đổi. Nên truyền tham số.

## 3. Lớp lưu trữ (Storage Class)

| Từ khóa | Phạm vi | Thời gian sống | Giá trị mặc định |
|---------|---------|---------------|-----------------|
| `auto` | Địa phương | Khối | Rác (không xác định) |
| `static` (local) | Địa phương | Toàn bộ chương trình | 0 |
| `static` (global) | File hiện tại | Toàn bộ chương trình | 0 |
| `extern` | Toàn bộ chương trình | Toàn bộ chương trình | 0 |
| `register` | Địa phương | Khối | Rác |

### 3.1 `auto` — Mặc định

```c
void ham() {
    auto int x = 5;  // Tương đương int x = 5;
    // x tự động hủy khi ra khỏi hàm
}
```

### 3.2 `static` local — Giữ giá trị giữa các lần gọi

```c
#include <stdio.h>

void demSoLan() {
    static int dem = 0;  // Chỉ khởi tạo 1 lần duy nhất
    dem++;
    printf("Da goi ham %d lan\n", dem);
}

int main() {
    demSoLan();  // 1
    demSoLan();  // 2
    demSoLan();  // 3
    return 0;
}
```

**So sánh static vs thường:**
```c
#include <stdio.h>

void khongStatic() {
    int x = 0;    // Mỗi lần gọi đều tạo mới x = 0
    x++;
    printf("khongStatic: %d\n", x);  // Luôn in 1
}

void coStatic() {
    static int x = 0;  // Chỉ tạo 1 lần duy nhất
    x++;
    printf("coStatic: %d\n", x);  // 1, 2, 3,...
}

int main() {
    khongStatic();  // 1
    khongStatic();  // 1
    khongStatic();  // 1
    
    coStatic();     // 1
    coStatic();     // 2
    coStatic();     // 3
    return 0;
}
```

### 3.3 `extern` — Dùng biến từ file khác

Xem bài [`02_module.md`](02_module.md) phần extern.

### 3.4 `register` — Đề nghị lưu trong CPU (hiếm dùng)

```c
void ham() {
    register int counter;  // Đề nghị compiler lưu trong thanh ghi CPU
    // Không thể lấy địa chỉ: &counter → lỗi
}
```

## 4. Bảng so sánh đầy đủ

| Loại biến | Khai báo | Truy cập từ | Khởi tạo mặc định | Hủy khi |
|-----------|---------|-------------|-------------------|---------|
| Local (auto) | Trong hàm | Trong hàm đó | Rác | Kết thúc hàm |
| Static local | Trong hàm với `static` | Trong hàm đó | 0 | Kết thúc chương trình |
| Global | Ngoài tất cả hàm | Mọi file (nếu có `extern`) | 0 | Kết thúc chương trình |
| Static global | Ngoài hàm với `static` | Chỉ trong file hiện tại | 0 | Kết thúc chương trình |

## 5. Quy tắc "che biến" (Variable Shadowing)

Khi biến trong phạm vi hẹp trùng tên với biến phạm vi rộng:

```c
#include <stdio.h>

int x = 100;  // Global

int main() {
    int x = 50;  // Local — che global
    
    printf("x local = %d\n", x);      // 50
    
    {
        int x = 10;  // Block scope — che local
        printf("x block = %d\n", x);  // 10
    }
    
    printf("x local = %d\n", x);      // 50 (block đã kết thúc)
    
    return 0;
}
```

> ⚠️ Tránh đặt tên biến trùng nhau — gây nhầm lẫn và khó debug!

## 6. Bài tập thực hành

### Bài 1: Đếm số lần gọi hàm
Viết hàm `void inSoLanGoi()` dùng `static int` để đếm. Gọi hàm 5 lần từ `main()`, mỗi lần in ra "Da goi lan thu X".

### Bài 2: Phân tích output
Đoán output của chương trình sau, chạy thử để kiểm tra:
```c
#include <stdio.h>
int a = 10;
void ham() {
    static int b = 0;
    int c = 0;
    a++; b++; c++;
    printf("a=%d, b=%d, c=%d\n", a, b, c);
}
int main() {
    ham();
    ham();
    ham();
    return 0;
}
```

### Bài 3: Tính tổng lũy tiến
Viết hàm `int tinhTongLuyTien(int n)` dùng `static` để lưu tổng tích lũy.
```
lan 1: tinhTongLuyTien(5) → 5
lan 2: tinhTongLuyTien(3) → 8 (5+3)
lan 3: tinhTongLuyTien(2) → 10 (8+2)
```

### Bài 4: Sửa lỗi scope
Đoạn code sau sai ở đâu? Sửa lại.
```c
#include <stdio.h>
int main() {
    for (int i = 0; i < 5; i++) {
        int x = i * 2;
    }
    printf("Gia tri cuoi cua x: %d\n", x);  // Lỗi
    return 0;
}
```

## 📚 Tham khảo thêm

- [GeeksforGeeks — Scope of Variables in C](https://www.geeksforgeeks.org/scope-rules-in-c/)
- [GeeksforGeeks — Storage Classes in C](https://www.geeksforgeeks.org/storage-classes-in-c/)
- [Programiz — C Storage Class](https://www.programiz.com/c-programming/c-storage-class)
- [Video: Scope and Lifetime of Variables](https://www.youtube.com/watch?v=8o6rR4q7iMk)
