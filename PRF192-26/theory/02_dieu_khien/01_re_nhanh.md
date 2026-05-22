# 🔀 Cấu Trúc Rẽ Nhánh: if-else, switch-case

## 1. Câu lệnh `if`

### Cú pháp cơ bản
```c
if (dieu_kien) {
    // Code chạy nếu dieu_kien != 0 (true)
}
```

### Ví dụ
```c
#include <stdio.h>

int main() {
    int tuoi = 20;
    
    if (tuoi >= 18) {
        printf("Ban du tuoi bau cu!\n");
    }
    
    return 0;
}
```

## 2. `if-else`

```c
if (dieu_kien) {
    // Nếu đúng
} else {
    // Nếu sai
}
```

### Ví dụ
```c
#include <stdio.h>

int main() {
    int n;
    printf("Nhap mot so: ");
    scanf("%d", &n);
    
    if (n % 2 == 0) {
        printf("%d la so chan\n", n);
    } else {
        printf("%d la so le\n", n);
    }
    
    return 0;
}
```

## 3. `if-else if-else` — Nhiều điều kiện

### Cú pháp
```c
if (dk1) {
    // dk1 đúng
} else if (dk2) {
    // dk1 sai, dk2 đúng
} else if (dk3) {
    // dk1, dk2 sai, dk3 đúng
} else {
    // Tất cả đều sai
}
```

### Ví dụ: Phân loại học lực
```c
#include <stdio.h>

int main() {
    float diem;
    printf("Nhap diem (0-10): ");
    
    if (scanf("%f", &diem) != 1 || diem < 0 || diem > 10) {
        printf("Diem khong hop le!\n");
        return 1;
    }
    
    if (diem >= 9.0) {
        printf("Hoc luc: XUAT SAC\n");
    } else if (diem >= 8.0) {
        printf("Hoc luc: GIOI\n");
    } else if (diem >= 7.0) {
        printf("Hoc luc: KHA\n");
    } else if (diem >= 5.0) {
        printf("Hoc luc: TRUNG BINH\n");
    } else {
        printf("Hoc luc: YEU\n");
    }
    
    return 0;
}
```

### Lưu ý: Thứ tự điều kiện quan trọng!

```c
// ❌ SAI: Điều kiện >= 5.0 bắt trước >= 8.0
if (diem >= 5.0) {
    printf("TB");       // Diem 9.0 cũng vào đây!
} else if (diem >= 8.0) {
    printf("Gioi");     // Không bao giờ chạy
}

// ✅ ĐÚNG: Xét từ cao xuống thấp
if (diem >= 9.0) {
    printf("Xuat sac");
} else if (diem >= 8.0) {
    printf("Gioi");
} // ...
```

## 4. Toán tử ba ngôi `?:` — if-else rút gọn

```c
// Cú pháp: dieu_kien ? gtri_dung : gtri_sai

int x = 10, y = 20;
int max = (x > y) ? x : y;  // max = 20

// Tương đương:
int max;
if (x > y) {
    max = x;
} else {
    max = y;
}
```

### Lồng nhau (không khuyến khích)
```c
int a = 5, b = 3, c = 8;
int max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
// Khó đọc! Nên dùng if-else thông thường
```

## 5. `switch-case` — Nhiều nhánh với giá trị rời rạc

### Cú pháp
```c
switch (bieu_thuc) {
    case gia_tri_1:
        // Code
        break;
    case gia_tri_2:
        // Code
        break;
    // ...
    default:
        // Không khớp case nào
}
```

### Ví dụ: Thứ trong tuần
```c
#include <stdio.h>

int main() {
    int thu;
    printf("Nhap thu (2-8, 8=Chu nhat): ");
    scanf("%d", &thu);
    
    switch (thu) {
        case 2:
            printf("Thu Hai\n");
            break;
        case 3:
            printf("Thu Ba\n");
            break;
        case 4:
            printf("Thu Tu\n");
            break;
        case 5:
            printf("Thu Nam\n");
            break;
        case 6:
            printf("Thu Sau\n");
            break;
        case 7:
            printf("Thu Bay\n");
            break;
        case 8:
            printf("Chu Nhat\n");
            break;
        default:
            printf("Khong phai thu hop le!\n");
    }
    
    return 0;
}
```

### Fall-through — Có chủ đích
```c
#include <stdio.h>

int main() {
    int thang;
    printf("Nhap thang (1-12): ");
    scanf("%d", &thang);
    
    switch (thang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            printf("Thang %d co 31 ngay\n", thang);
            break;
        case 4: case 6: case 9: case 11:
            printf("Thang %d co 30 ngay\n", thang);
            break;
        case 2:
            printf("Thang 2 co 28 hoac 29 ngay\n");
            break;
        default:
            printf("Thang khong hop le!\n");
    }
    
    return 0;
}
```

### So sánh `switch-case` vs `if-else if-else`

| Tiêu chí | `switch-case` | `if-else if-else` |
|---------|--------------|-------------------|
| Kiểu điều kiện | So sánh bằng (==) với hằng | Bất kỳ biểu thức nào |
| Giá trị | Số nguyên, char, enum | Bất kỳ |
| Tốc độ | Nhanh hơn (dùng jump table) | Chậm hơn (kiểm tra tuần tự) |
| Dùng khi | Có 3+ nhánh với hằng rời rạc | Điều kiện phức tạp, khoảng giá trị |

## 6. Các lỗi thường gặp

### Lỗi 1: Thiếu `break` trong switch
```c
switch (x) {
    case 1:
        printf("Mot");  // Không break → in tiếp "Hai"!
    case 2:
        printf("Hai");
        break;
}
// Với x=1: in "MotHai"
```

### Lỗi 2: Dùng `=` thay vì `==`
```c
// ❌ SAI
if (x = 5) {  // Gán x=5, biểu thức luôn đúng!
    printf("x la 5");  // Luôn chạy!
}

// ✅ ĐÚNG
if (x == 5) {
    printf("x la 5");
}
```

> **Mẹo:** Viết `if (5 == x)` thay vì `if (x == 5)` — nếu lỡ viết `if (5 = x)` thì compiler báo lỗi ngay.

### Lỗi 3: Dùng `;` sau if
```c
// ❌ SAI
if (x > 0); {  // Dấu ; kết thúc if ngay!
    printf("x duong");  // Luôn chạy, không phụ thuộc if!
}

// ✅ ĐÚNG
if (x > 0) {
    printf("x duong");
}
```

## 7. Bài tập thực hành

### Bài 1: Số ngày trong tháng
Nhập tháng và năm. In ra số ngày của tháng đó (chú ý năm nhuận cho tháng 2).

### Bài 2: Máy tính đơn giản
Nhập 2 số và 1 phép tính (+, -, *, /). Dùng `switch-case` để tính:
```
Nhap a: 10
Nhap b: 5
Nhap phep tinh (+, -, *, /): /
10 / 5 = 2.00
```
Lưu ý: Kiểm tra chia cho 0!

### Bài 3: Xếp loại học lực (nâng cao)
Nhập điểm từ 0-100. Xếp loại:
- 90-100: A
- 80-89: B
- 70-79: C
- 60-69: D
- 0-59: F

Dùng `switch-case` (gợi ý: `switch (diem / 10)`).

### Bài 4: Kiểm tra tam giác
Nhập 3 cạnh a, b, c. Kiểm tra:
- Có phải tam giác hợp lệ? (a+b>c, a+c>b, b+c>a)
- Nếu hợp lệ: tam giác gì? (đều, cân, vuông, thường)

## 📚 Tham khảo thêm

- [GeeksforGeeks — if-else in C](https://www.geeksforgeeks.org/c-if-else-statement/)
- [GeeksforGeeks — switch in C](https://www.geeksforgeeks.org/switch-statement-in-c/)
- [Programiz — C if-else](https://www.programiz.com/c-programming/c-if-else-statement)
- [Programiz — C switch-case](https://www.programiz.com/c-programming/c-switch-case-statement)
