# 📝 Chuỗi Ký Tự (String) trong C

## 1. String trong C là gì?

Trong C, **string** là mảng các ký tự `char` kết thúc bằng ký tự **null terminator** `'\0'` (mã ASCII 0).

```
char s[6] = "Hello";
Trong bộ nhớ:
Index:  0  1  2  3  4  5
       [H][e][l][l][o][\0]
                        ↑
                 Null terminator — báo hiệu kết thúc chuỗi
```

> ⚠️ **Mảng char phải đủ lớn** để chứa cả `'\0'`! `"Hello"` cần 6 ký tự (5 + 1).

## 2. Khai báo và khởi tạo

```c
#include <stdio.h>

int main() {
    // Cách 1: Dùng mảng char
    char s1[20] = "Hello";        // {'H','e','l','l','o','\0'}
    char s2[20] = {'H','i','\0'}; // Khởi tạo từng ký tự
    
    // Cách 2: Không cần kích thước
    char s3[] = "Xin chao";       // Tự động = 9 (8 + 1)
    
    // Cách 3: Con trỏ char
    char *s4 = "FPT University";  // Hằng chuỗi — không thể sửa!
    
    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
    printf("s3 = %s\n", s3);
    printf("s4 = %s\n", s4);
    
    return 0;
}
```

### Mảng char vs con trỏ char

```c
char arr[] = "Hello";   // Mảng — có thể sửa nội dung
char *ptr = "Hello";    // Con trỏ — trỏ đến hằng, KHÔNG thể sửa

arr[0] = 'M';  // ✅ OK → "Mello"
// ptr[0] = 'M';  // ❌ LỖI! Hằng không thể sửa
```

## 3. Nhập chuỗi

### 3.1 `scanf("%s", ...)` — Chỉ đọc 1 từ
```c
#include <stdio.h>

int main() {
    char ten[50];
    
    printf("Nhap ten: ");
    scanf("%s", ten);  // Không cần & vì tên mảng đã là địa chỉ
    
    printf("Xin chao %s\n", ten);
    // Nhập "Nguyen Van A" → chỉ đọc "Nguyen"
    
    return 0;
}
```

### 3.2 `fgets()` — Đọc cả dòng ✅ KHUYÊN DÙNG
```c
#include <stdio.h>
#include <string.h>  // strcspn

int main() {
    char hoTen[100];
    
    printf("Nhap ho ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    
    // Loại bỏ ký tự '\n' ở cuối (nếu có)
    hoTen[strcspn(hoTen, "\n")] = '\0';
    
    printf("Xin chao %s!\n", hoTen);
    // Nhập "Nguyen Van A" → đọc cả dòng
    
    return 0;
}
```

### 3.3 Xử lý buffer khi kết hợp scanf và fgets
```c
#include <stdio.h>
#include <string.h>

int main() {
    int tuoi;
    char ten[100];
    
    printf("Nhap tuoi: ");
    scanf("%d", &tuoi);
    getchar();  // Đọc bỏ '\n' còn trong buffer
    
    printf("Nhap ten: ");
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = '\0';
    
    printf("%s, %d tuoi\n", ten, tuoi);
    
    return 0;
}
```

## 4. Xuất chuỗi

```c
#include <stdio.h>

int main() {
    char s[] = "Hello World";
    
    printf("%s\n", s);      // Hello World
    puts(s);                 // Hello World + '\n' tự động
    printf("%.5s\n", s);    // Hello (5 ký tự đầu)
    printf("%10s\n", s);    // Can phải 10 ký tự
    printf("%-10s\n", s);   // Can trái 10 ký tự
    
    // In từng ký tự
    for (int i = 0; s[i] != '\0'; i++) {
        putchar(s[i]);
    }
    putchar('\n');
    
    return 0;
}
```

## 5. Duyệt chuỗi và đếm ký tự

```c
#include <stdio.h>

int main() {
    char s[] = "Hello World";
    int doDai = 0;
    int chuCai = 0, chuSo = 0, khoangTrang = 0;
    
    // Tính độ dài (không dùng strlen)
    for (int i = 0; s[i] != '\0'; i++) {
        doDai++;
        
        if (isalpha(s[i])) chuCai++;
        else if (isdigit(s[i])) chuSo++;
        else if (isspace(s[i])) khoangTrang++;
    }
    
    printf("Chuoi: '%s'\n", s);
    printf("Do dai: %d\n", doDai);
    printf("Chu cai: %d, chu so: %d, khoang trang: %d\n",
           chuCai, chuSo, khoangTrang);
    
    return 0;
}
```

## 6. Đảo ngược chuỗi

```c
#include <stdio.h>
#include <string.h>

void daoNguocChuoi(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

int main() {
    char s[] = "Hello";
    
    printf("Truoc: %s\n", s);
    daoNguocChuoi(s);
    printf("Sau: %s\n", s);  // olleH
    
    return 0;
}
```

## 7. Mảng chuỗi (mảng 2 chiều)

```c
#include <stdio.h>

int main() {
    // Mảng 5 chuỗi, mỗi chuỗi tối đa 50 ký tự
    char danhSach[5][50] = {
        "Nguyen Van A",
        "Tran Van B",
        "Le Thi C",
        "Pham Van D",
        "Hoang Thi E"
    };
    
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, danhSach[i]);
    }
    
    return 0;
}
```

## 8. Xử lý chuỗi thủ công (không dùng string.h)

### 8.1 Tính độ dài
```c
int doDaiChuoi(char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}
```

### 8.2 Sao chép chuỗi
```c
void saoChepChuoi(char dich[], char nguon[]) {
    int i = 0;
    while (nguon[i] != '\0') {
        dich[i] = nguon[i];
        i++;
    }
    dich[i] = '\0';  // Kết thúc chuỗi đích
}
```

### 8.3 So sánh chuỗi
```c
int soSanhChuoi(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') return 0;
    return (s1[i] == '\0') ? -1 : 1;
}
```

## 9. Bài tập thực hành

### Bài 1: Đếm ký tự
Nhập chuỗi. Đếm và in:
- Số ký tự chữ hoa
- Số ký tự chữ thường
- Số chữ số
- Số khoảng trắng
- Số ký tự đặc biệt

### Bài 2: Kiểm tra Palindrome
Nhập chuỗi, kiểm tra có đối xứng không (viết hoa/thường không phân biệt).
```
"radar" → Palindrome
"Hello" → Không
"A man a plan a canal Panama" → Palindrome (bỏ khoảng trắng)
```

### Bài 3: Đếm từ
Nhập một câu, đếm số từ (các từ cách nhau bởi khoảng trắng).
```
"Ngon ngu lap trinh C" → 4 từ
```

### Bài 4: Viết hoa chữ đầu mỗi từ
Nhập chuỗi, viết hoa chữ cái đầu tiên của mỗi từ.
```
"ngon ngu lap trinh C" → "Ngon Ngu Lap Trinh C"
```

### Bài 5: Mã hóa Caesar
Dịch mỗi ký tự đi k vị trí trong bảng chữ cái.
```
"ABC" với k=3 → "DEF"
"XYZ" với k=3 → "ABC"
```

## 📚 Tham khảo thêm

- [GeeksforGeeks — Strings in C](https://www.geeksforgeeks.org/strings-in-c/)
- [Programiz — C Strings](https://www.programiz.com/c-programming/c-strings)
- [GeeksforGeeks — fgets vs scanf for string](https://www.geeksforgeeks.org/fgets-and-gets-in-c/)
