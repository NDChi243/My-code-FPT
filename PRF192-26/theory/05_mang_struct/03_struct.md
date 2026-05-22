# 🏗️ Struct trong C

## 1. Struct là gì?

**Struct** là kiểu dữ liệu do người dùng tự định nghĩa, cho phép nhóm nhiều biến có kiểu khác nhau lại thành một "đối tượng".

```c
// Ví dụ: Một sinh viên có
// - Mã số (chuỗi)
// - Họ tên (chuỗi)
// - Tuổi (số nguyên)
// - Điểm TB (số thực)

struct SinhVien {
    char maSV[20];
    char hoTen[50];
    int tuoi;
    float diemTB;
};  // <-- QUÊN DẤU ; LÀ LỖI!
```

## 2. Khai báo và sử dụng struct

### Cách 1: Khai báo struct + biến riêng
```c
#include <stdio.h>
#include <string.h>

struct SinhVien {
    char maSV[20];
    char hoTen[50];
    int tuoi;
    float diemTB;
};

int main() {
    // Khai báo biến struct
    struct SinhVien sv1;
    
    // Gán giá trị cho từng trường (field)
    strcpy(sv1.maSV, "SE123456");
    strcpy(sv1.hoTen, "Nguyen Van A");
    sv1.tuoi = 20;
    sv1.diemTB = 8.75;
    
    // In
    printf("Ma SV: %s\n", sv1.maSV);
    printf("Ho ten: %s\n", sv1.hoTen);
    printf("Tuoi: %d\n", sv1.tuoi);
    printf("Diem TB: %.2f\n", sv1.diemTB);
    
    return 0;
}
```

### Cách 2: Khởi tạo cùng lúc
```c
struct SinhVien sv2 = {"SE789", "Tran Van B", 19, 7.5};
```

### Cách 3: Dùng `typedef` — Gọn hơn ✅ KHUYÊN DÙNG

```c
#include <stdio.h>
#include <string.h>

// Dùng typedef — không cần viết 'struct' mỗi lần
typedef struct {
    char maSV[20];
    char hoTen[50];
    int tuoi;
    float diemTB;
} SinhVien;

int main() {
    SinhVien sv1;  // Không cần 'struct'
    strcpy(sv1.maSV, "SE123");
    strcpy(sv1.hoTen, "Nguyen Van A");
    sv1.tuoi = 20;
    sv1.diemTB = 8.75;
    
    SinhVien sv2 = {"SE456", "Tran Van B", 19, 7.5};  // Khởi tạo
    
    printf("sv1: %s - %s - %d - %.2f\n",
           sv1.maSV, sv1.hoTen, sv1.tuoi, sv1.diemTB);
    
    return 0;
}
```

## 3. Truy cập thành viên struct

### Toán tử `.` — Với biến struct thường
```c
SinhVien sv;
sv.tuoi = 20;          // Gán
printf("%d", sv.tuoi); // Đọc
```

### Toán tử `->` — Với con trỏ struct
```c
SinhVien sv;
SinhVien *ptr = &sv;

// Hai cách tương đương:
(*ptr).tuoi = 20;   // Giải tham chiếu rồi dùng .
ptr->tuoi = 20;     // Dùng -> (gọn hơn)

printf("%d", ptr->tuoi);  // In 20
```

## 4. Mảng struct

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char ten[50];
    int tuoi;
    float diem;
} SinhVien;

int main() {
    SinhVien lop[3];  // Mảng 3 sinh viên
    
    // Nhập
    for (int i = 0; i < 3; i++) {
        printf("Nhap sinh vien %d:\n", i + 1);
        printf("Ten: "); scanf(" %[^\n]", lop[i].ten);
        printf("Tuoi: "); scanf("%d", &lop[i].tuoi);
        printf("Diem: "); scanf("%f", &lop[i].diem);
    }
    
    // In
    printf("\n--- DANH SACH LOP ---\n");
    for (int i = 0; i < 3; i++) {
        printf("%s - %d tuoi - %.2f diem\n",
               lop[i].ten, lop[i].tuoi, lop[i].diem);
    }
    
    // Tính điểm TB cả lớp
    float tong = 0;
    for (int i = 0; i < 3; i++) {
        tong += lop[i].diem;
    }
    printf("\nDiem TB lop: %.2f\n", tong / 3);
    
    return 0;
}
```

## 5. Struct lồng nhau (Nested Struct)

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    int ngay;
    int thang;
    int nam;
} NgayThang;

typedef struct {
    char maSV[20];
    char hoTen[50];
    NgayThang ngaySinh;  // Struct lồng nhau
    float diemTB;
} SinhVien;

int main() {
    SinhVien sv;
    
    strcpy(sv.maSV, "SE123");
    strcpy(sv.hoTen, "Nguyen Van A");
    sv.ngaySinh.ngay = 15;
    sv.ngaySinh.thang = 6;
    sv.ngaySinh.nam = 2004;
    sv.diemTB = 8.5;
    
    printf("%s - %s - %d/%d/%d - %.2f\n",
           sv.maSV, sv.hoTen,
           sv.ngaySinh.ngay, sv.ngaySinh.thang, sv.ngaySinh.nam,
           sv.diemTB);
    
    return 0;
}
```

## 6. Struct và hàm

### Truyền struct cho hàm — Pass by Value
```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char ten[50];
    float diem;
} SinhVien;

void inThongTin(SinhVien sv) {  // Copy toàn bộ struct
    printf("Ten: %s, Diem: %.2f\n", sv.ten, sv.diem);
}

int main() {
    SinhVien sv = {"Nguyen Van A", 8.5};
    inThongTin(sv);
    return 0;
}
```

### Truyền con trỏ struct — Pass by Reference (tiết kiệm bộ nhớ)
```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char maSV[20];
    char hoTen[50];
    float diemToan;
    float diemLy;
    float diemHoa;
} SinhVien;

// Truyền con trỏ — không copy struct lớn
void nhapSinhVien(SinhVien *sv) {
    printf("Nhap ma SV: "); scanf("%s", sv->maSV);
    printf("Nhap ho ten: "); scanf(" %[^\n]", sv->hoTen);
    printf("Nhap diem Toan, Ly, Hoa: ");
    scanf("%f %f %f", &sv->diemToan, &sv->diemLy, &sv->diemHoa);
}

float tinhDiemTB(const SinhVien *sv) {
    return (sv->diemToan + sv->diemLy + sv->diemHoa) / 3;
}

void inSinhVien(const SinhVien *sv) {
    printf("%-10s %-20s %5.2f %5.2f %5.2f %5.2f\n",
           sv->maSV, sv->hoTen,
           sv->diemToan, sv->diemLy, sv->diemHoa,
           tinhDiemTB(sv));
}

int main() {
    SinhVien sv;
    nhapSinhVien(&sv);
    
    printf("\n%-10s %-20s %5s %5s %5s %5s\n",
           "Ma SV", "Ho ten", "Toan", "Ly", "Hoa", "TB");
    inSinhVien(&sv);
    
    return 0;
}
```

## 7. `sizeof` với struct

```c
#include <stdio.h>

// Có thể có padding bytes (byte đệm)
typedef struct {
    char c;     // 1 byte
    int i;      // 4 byte
    double d;   // 8 byte
} Mixed;

#pragma pack(1)  // Bỏ padding (nếu muốn tiết kiệm)
typedef struct {
    char c;
    int i;
    double d;
} Packed;

int main() {
    printf("Kich thuoc struct (co padding): %d byte\n", sizeof(Mixed));
    printf("Kich thuoc struct (packed): %d byte\n", sizeof(Packed));
    
    return 0;
}
```

## 8. Bài tập thực hành

### Bài 1: Struct điểm sinh viên
Định nghĩa struct `DiemSinhVien` gồm: họ tên, MSSV, điểm Toán, Lý, Hóa.
- Nhập n sinh viên
- Tính điểm TB từng sinh viên
- In danh sách dạng bảng
- Tìm sinh viên có điểm TB cao nhất

### Bài 2: Quản lý sách
```c
typedef struct {
    char maSach[20];
    char tenSach[100];
    char tacGia[50];
    int namXuatBan;
    float giaTien;
    int soLuong;
} Sach;
```
Thực hiện: nhập, in, tìm theo tên, tính tổng tiền kho.

### Bài 3: Struct lồng nhau — Quản lý hóa đơn
```c
typedef struct {
    char tenSP[50];
    int soLuong;
    float donGia;
} MatHang;

typedef struct {
    char maHD[20];
    char khachHang[50];
    NgayThang ngayMua;  // Từ bài trước
    MatHang dsHang[100];
    int soMatHang;
} HoaDon;
```
Tính tổng tiền hóa đơn.

### Bài 4: Struct với con trỏ
Dùng cấp phát động cho mảng struct. Nhập n, cấp phát mảng n sinh viên, nhập/xuất, giải phóng.

## 📚 Tham khảo thêm

- [GeeksforGeeks — Structures in C](https://www.geeksforgeeks.org/structures-in-c/)
- [Programiz — C Structures](https://www.programiz.com/c-programming/c-structures)
- [GeeksforGeeks — Structure Padding](https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/)
- [Video: Struct trong C](https://www.youtube.com/watch?v=3s9LnHtj0rA)
