# 📁 Thao Tác Với File trong C

## 1. File là gì?

**File** là dữ liệu được lưu trên đĩa cứng, tồn tại ngay cả khi tắt chương trình.

```
RAM (tạm thời)                  Ổ cứng (vĩnh viễn)
┌────────────┐                 ┌────────────┐
│ Biến trong C │  → ghi →       │ data.txt   │
│ (mất khi tắt) │  ← đọc ←      │ (còn mãi)  │
└────────────┘                 └────────────┘
```

## 2. Các bước thao tác file

```
Bước 1: Mở file   → fopen("ten.txt", "mode")
Bước 2: Đọc/Ghi   → fprintf, fscanf, fgets, fputs, ...
Bước 3: Đóng file → fclose(fp)
```

## 3. Mở file — `fopen()`

```c
FILE *fp = fopen("ten_file.txt", "mode");
```

### Các mode (chế độ mở file)

| Mode | Ý nghĩa | Nếu file tồn tại | Nếu file chưa có |
|------|---------|-----------------|-----------------|
| `"r"` | Đọc (read) | ✅ Đọc từ đầu | ❌ NULL (lỗi) |
| `"w"` | Ghi (write) | ❌ Ghi đè từ đầu | ✅ Tạo mới |
| `"a"` | Thêm (append) | ✅ Ghi tiếp cuối file | ✅ Tạo mới |
| `"r+"` | Đọc + ghi | ✅ Đọc/ghi từ đầu | ❌ NULL |
| `"w+"` | Đọc + ghi | ❌ Ghi đè | ✅ Tạo mới |
| `"a+"` | Đọc + thêm | ✅ Đọc từ đầu, ghi cuối | ✅ Tạo mới |

## 4. Pattern chuẩn — Luôn kiểm tra NULL!

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    
    fp = fopen("data.txt", "r");
    
    // ✅ LUÔN kiểm tra — không thì crash!
    if (fp == NULL) {
        printf("Khong mo duoc file data.txt!\n");
        return 1;
    }
    
    // ... đọc/ghi file ...
    
    fclose(fp);  // Đóng file
    return 0;
}
```

## 5. Ghi file — `fprintf()` và `fputs()`

### 5.1 `fprintf()` — Ghi có định dạng
```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("sinhVien.txt", "w");
    
    if (fp == NULL) {
        printf("Loi mo file!\n");
        return 1;
    }
    
    fprintf(fp, "%-10s %-20s %5s\n", "Ma SV", "Ho ten", "Diem");
    fprintf(fp, "%-10s %-20s %5.2f\n", "SE001", "Nguyen Van A", 8.5);
    fprintf(fp, "%-10s %-20s %5.2f\n", "SE002", "Tran Van B", 7.2);
    fprintf(fp, "%-10s %-20s %5.2f\n", "SE003", "Le Thi C", 9.1);
    
    fclose(fp);
    printf("Da ghi file thanh cong!\n");
    
    return 0;
}
```

### 5.2 `fputs()` — Ghi chuỗi
```c
FILE *fp = fopen("notes.txt", "w");
if (fp != NULL) {
    fputs("Dong thu nhat\n", fp);
    fputs("Dong thu hai\n", fp);
    fclose(fp);
}
```

## 6. Đọc file — `fscanf()` và `fgets()`

### 6.1 `fscanf()` — Đọc có định dạng
```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("sinhVien.txt", "r");
    
    if (fp == NULL) {
        printf("Khong mo duoc file!\n");
        return 1;
    }
    
    char maSV[20], hoTen[50];
    float diem;
    
    // Đọc từng dòng
    while (fscanf(fp, "%s %s %f", maSV, hoTen, &diem) == 3) {
        printf("Ma: %s, Ten: %s, Diem: %.2f\n", maSV, hoTen, diem);
    }
    
    fclose(fp);
    return 0;
}
```

> ⚠️ `fscanf` dừng ở khoảng trắng — không đọc được họ tên có dấu cách!

### 6.2 `fgets()` — Đọc từng dòng ✅ KHUYÊN DÙNG
```c
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("data.txt", "r");
    
    if (fp == NULL) {
        printf("Khong mo duoc file!\n");
        return 1;
    }
    
    char dong[256];
    
    // Đọc từng dòng cho đến cuối file
    while (fgets(dong, sizeof(dong), fp) != NULL) {
        dong[strcspn(dong, "\n")] = '\0';  // Bỏ '\n' ở cuối
        printf(">>> %s\n", dong);
    }
    
    fclose(fp);
    return 0;
}
```

## 7. Đọc file dùng `feof()` — End of File

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) return 1;
    
    char c;
    
    // Đọc từng ký tự đến cuối file
    while (!feof(fp)) {
        c = fgetc(fp);
        if (c != EOF) {
            putchar(c);
        }
    }
    
    fclose(fp);
    return 0;
}
```

## 8. Đọc/ghi file nhị phân — `fread()` và `fwrite()`

```c
#include <stdio.h>

typedef struct {
    int ma;
    char ten[50];
    float diem;
} SinhVien;

int main() {
    SinhVien sv = {1, "Nguyen Van A", 8.5};
    
    // Ghi binary
    FILE *fp = fopen("data.bin", "wb");
    if (fp != NULL) {
        fwrite(&sv, sizeof(SinhVien), 1, fp);
        fclose(fp);
    }
    
    // Đọc binary
    SinhVien svDoc;
    fp = fopen("data.bin", "rb");
    if (fp != NULL) {
        fread(&svDoc, sizeof(SinhVien), 1, fp);
        printf("Ma: %d, Ten: %s, Diem: %.2f\n",
               svDoc.ma, svDoc.ten, svDoc.diem);
        fclose(fp);
    }
    
    return 0;
}
```

## 9. Ghi mảng struct vào file

```c
#include <stdio.h>

typedef struct {
    char maSV[20];
    char hoTen[50];
    float diem;
} SinhVien;

// Ghi danh sách vào file text
void ghiDanhSach(SinhVien ds[], int n, const char *tenFile) {
    FILE *fp = fopen(tenFile, "w");
    if (fp == NULL) return;
    
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s|%s|%.2f\n",
                ds[i].maSV, ds[i].hoTen, ds[i].diem);
    }
    
    fclose(fp);
    printf("Da ghi %d sinh vien vao %s\n", n, tenFile);
}

// Đọc danh sách từ file text
int docDanhSach(SinhVien ds[], const char *tenFile) {
    FILE *fp = fopen(tenFile, "r");
    if (fp == NULL) return 0;
    
    int n = 0;
    while (fscanf(fp, "%[^|]|%[^|]|%f\n",
                  ds[n].maSV, ds[n].hoTen, &ds[n].diem) == 3) {
        n++;
    }
    
    fclose(fp);
    return n;
}

int main() {
    SinhVien ds[] = {
        {"SE001", "Nguyen Van A", 8.5},
        {"SE002", "Tran Van B", 7.2},
        {"SE003", "Le Thi C", 9.1}
    };
    int n = 3;
    
    // Ghi
    ghiDanhSach(ds, n, "danhSach.txt");
    
    // Đọc lại
    SinhVien dsDoc[100];
    int m = docDanhSach(dsDoc, "danhSach.txt");
    
    for (int i = 0; i < m; i++) {
        printf("%s - %s - %.2f\n",
               dsDoc[i].maSV, dsDoc[i].hoTen, dsDoc[i].diem);
    }
    
    return 0;
}
```

## 10. `fseek()`, `ftell()`, `rewind()` — Truy cập ngẫu nhiên

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) return 1;
    
    // Đọc vị trí hiện tại
    long viTri = ftell(fp);
    printf("Vi tri hien tai: %ld\n", viTri);  // 0
    
    // Di chuyển con trỏ file
    fseek(fp, 5, SEEK_SET);  // Từ đầu file, nhảy 5 byte
    printf("Sau fseek 5: %c\n", fgetc(fp));  // Ký tự thứ 6
    
    fseek(fp, -2, SEEK_END);  // Từ cuối file, lùi 2 byte
    printf("Truoc cuoi 2: %c\n", fgetc(fp));
    
    // Quay lại đầu file
    rewind(fp);
    printf("Sau rewind: %c\n", fgetc(fp));  // Ký tự đầu tiên
    
    fclose(fp);
    return 0;
}
```

## 11. Bảng tổng hợp hàm file

| Hàm | Chức năng | Cú pháp |
|-----|-----------|---------|
| `fopen()` | Mở file | `FILE *fopen(const char *ten, const char *mode)` |
| `fclose()` | Đóng file | `int fclose(FILE *fp)` |
| `fprintf()` | Ghi có định dạng | `int fprintf(FILE *fp, const char *fmt, ...)` |
| `fscanf()` | Đọc có định dạng | `int fscanf(FILE *fp, const char *fmt, ...)` |
| `fputs()` | Ghi chuỗi | `int fputs(const char *s, FILE *fp)` |
| `fgets()` | Đọc chuỗi | `char *fgets(char *s, int n, FILE *fp)` |
| `fgetc()` | Đọc 1 ký tự | `int fgetc(FILE *fp)` |
| `fputc()` | Ghi 1 ký tự | `int fputc(int c, FILE *fp)` |
| `feof()` | Kiểm tra cuối file | `int feof(FILE *fp)` |
| `fread()` | Đọc nhị phân | `size_t fread(void *ptr, size_t size, size_t n, FILE *fp)` |
| `fwrite()` | Ghi nhị phân | `size_t fwrite(const void *ptr, size_t size, size_t n, FILE *fp)` |
| `fseek()` | Di chuyển con trỏ | `int fseek(FILE *fp, long offset, int whence)` |
| `ftell()` | Vị trí con trỏ | `long ftell(FILE *fp)` |
| `rewind()` | Về đầu file | `void rewind(FILE *fp)` |

## 12. Các lỗi thường gặp

### Lỗi 1: Không kiểm tra NULL
```c
FILE *fp = fopen("data.txt", "r");
fscanf(fp, "%d", &n);  // ❌ Crash nếu file không tồn tại!
```

### Lỗi 2: Quên `fclose()`
- Tài nguyên hệ thống bị giữ → không thể xóa/sửa file
- Có thể mất dữ liệu (buffer chưa được ghi xuống đĩa)

### Lỗi 3: Mode sai
```c
FILE *fp = fopen("data.txt", "r");
fprintf(fp, "Hello");  // ❌ Lỗi! Mode "r" không cho ghi!
```

## 13. Bài tập thực hành

### Bài 1: Ghi và đọc số
Viết chương trình:
- Tạo file `so.txt` ghi 10 số nguyên từ 1 đến 10 (mỗi số 1 dòng)
- Đọc file và tính tổng các số
- In tổng ra màn hình

### Bài 2: Quản lý sinh viên bằng file
```c
typedef struct {
    char maSV[20];
    char hoTen[50];
    float diemTB;
} SinhVien;
```
Chức năng:
1. Thêm sinh viên (ghi vào file)
2. In danh sách (đọc từ file)
3. Tìm sinh viên theo mã
4. Thoát

### Bài 3: Sao chép file
Nhập tên file nguồn và file đích. Copy nội dung từ file nguồn sang file đích.

### Bài 4: Đọc file CSV
Cho file `diem.csv` có nội dung:
```
SE001,Nguyen Van A,8.5
SE002,Tran Van B,7.2
SE003,Le Thi C,9.1
```
Đọc file, lưu vào mảng struct, tính điểm TB cả lớp, ghi kết quả vào `ketQua.txt`.

### Bài 5: Thống kê file văn bản
Đọc file văn bản. Đếm và in:
- Số dòng
- Số từ
- Số ký tự (không tính khoảng trắng)

## 📚 Tham khảo thêm

- [GeeksforGeeks — File Handling in C](https://www.geeksforgeeks.org/file-handling-in-c/)
- [Programiz — C File I/O](https://www.programiz.com/c-programming/c-file-input-output)
- [GeeksforGeeks — fseek, ftell, rewind](https://www.geeksforgeeks.org/fseek-ftell-rewind-in-c/)
- [Video: File I/O trong C](https://www.youtube.com/watch?v=EPFgeMh-0kM)
