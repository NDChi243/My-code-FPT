# 🔍 Thuật Toán Tìm Kiếm và Sắp Xếp

## 1. Tìm kiếm tuyến tính (Linear Search)

**Ý tưởng:** Duyệt từ đầu đến cuối mảng, so sánh từng phần tử với giá trị cần tìm.

### Đặc điểm
- ⏱ Độ phức tạp: **O(n)** — trung bình n/2 bước
- ✅ Mảng không cần sắp xếp
- ✅ Code đơn giản

### Code
```c
#include <stdio.h>

// Trả về vị trí nếu tìm thấy, -1 nếu không
int timTuyenTinh(int arr[], int n, int giaTri) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == giaTri) {
            return i;  // Tìm thấy tại vị trí i
        }
    }
    return -1;  // Không tìm thấy
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int canTim = 8;
    
    int viTri = timTuyenTinh(arr, n, canTim);
    
    if (viTri != -1) {
        printf("Tim thay %d tai vi tri %d\n", canTim, viTri);
    } else {
        printf("Khong tim thay %d\n", canTim);
    }
    
    return 0;
}
```

## 2. Tìm kiếm nhị phân (Binary Search)

**Ý tưởng:** Chia đôi mảng đã sắp xếp, so sánh phần tử giữa với giá trị cần tìm.

### Điều kiện
- ⚠️ **Mảng phải được sắp xếp** (tăng dần hoặc giảm dần)!
- ⏱ Độ phức tạp: **O(log n)** — rất nhanh

### Cách hoạt động
```
Tìm 7 trong [1, 3, 5, 7, 9, 11, 13]

Bước 1: left=0, right=6, mid=3 → arr[3]=7 == 7 ✅ Tìm thấy!
```

```
Tìm 3 trong [1, 3, 5, 7, 9, 11, 13]

Bước 1: left=0, right=6, mid=3 → arr[3]=7 > 3 → qua trái
Bước 2: left=0, right=2, mid=1 → arr[1]=3 == 3 ✅ Tìm thấy!
```

### Code
```c
#include <stdio.h>

int timNhiPhan(int arr[], int left, int right, int giaTri) {
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Tránh tràn số
        
        if (arr[mid] == giaTri) {
            return mid;        // Tìm thấy
        } else if (arr[mid] < giaTri) {
            left = mid + 1;    // Tìm bên phải
        } else {
            right = mid - 1;   // Tìm bên trái
        }
    }
    return -1;  // Không tìm thấy
}

// Phiên bản đệ quy
int timNhiPhanDeQuy(int arr[], int left, int right, int giaTri) {
    if (left > right) return -1;
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == giaTri) return mid;
    if (arr[mid] < giaTri)
        return timNhiPhanDeQuy(arr, mid + 1, right, giaTri);
    else
        return timNhiPhanDeQuy(arr, left, mid - 1, giaTri);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};  // Đã sắp xếp!
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int viTri = timNhiPhan(arr, 0, n - 1, 7);
    printf("Tim thay 7 tai: %d\n", viTri);  // 3
    
    return 0;
}
```

### So sánh Linear vs Binary

| Tiêu chí | Linear Search | Binary Search |
|----------|--------------|---------------|
| Độ phức tạp | O(n) | O(log n) |
| Mảng cần sort? | ❌ Không | ✅ Có |
| Code | Đơn giản | Phức tạp hơn |
| Dùng khi | Mảng nhỏ, không sort | Mảng lớn, đã sort |

## 3. Selection Sort — Sắp xếp chọn

**Ý tưởng:** Tìm phần tử nhỏ nhất đưa lên đầu, lặp lại với phần còn lại.

### Cách hoạt động
```
[5, 2, 8, 1, 9]  → Tìm min(1) đổi với arr[0]
[1, 2, 8, 5, 9]  → Tìm min(2) đã đúng vị trí
[1, 2, 5, 8, 9]  → Tìm min(5) đổi với arr[2]
[1, 2, 5, 8, 9]  → Tìm min(8) đã đúng
[1, 2, 5, 8, 9]  → Xong!
```

### Code
```c
#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Tìm phần tử nhỏ nhất trong đoạn [i..n-1]
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        // Đổi chỗ nếu cần
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void inMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Truoc: ");
    inMang(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sau:  ");
    inMang(arr, n);
    
    return 0;
}
```

## 4. Bubble Sort — Sắp xếp nổi bọt

**Ý tưởng:** So sánh 2 phần tử liền kề, đổi chỗ nếu sai thứ tự. Phần tử lớn nhất "nổi" lên cuối.

### Code
```c
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int daDoi = 0;  // Tối ưu: kiểm tra đã đổi chỗ chưa
        
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Đổi chỗ
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                daDoi = 1;
            }
        }
        
        // Nếu không cần đổi chỗ → mảng đã sắp xếp xong
        if (daDoi == 0) break;
    }
}
```

## 5. Insertion Sort — Sắp xếp chèn

**Ý tưởng:** Giống cách xếp bài: lấy từng phần tử, chèn vào vị trí đúng trong đoạn đã sắp xếp.

```c
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];      // Phần tử cần chèn
        int j = i - 1;
        
        // Dịch các phần tử lớn hơn key sang phải
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // Chèn key vào vị trí đúng
    }
}
```

## 6. So sánh các thuật toán sắp xếp

| Thuật toán | Tốt nhất | Trung bình | Tệ nhất | Bộ nhớ | Ổn định |
|-----------|---------|-----------|---------|--------|---------|
| **Selection Sort** | O(n²) | O(n²) | O(n²) | O(1) | ❌ Không |
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ Có |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ Có |

> Với n nhỏ (< 1000), chọn Insertion Sort. Với n lớn, cần học Quick Sort, Merge Sort (nâng cao).

## 7. Sắp xếp mảng struct

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char ten[50];
    float diem;
} SinhVien;

// Sắp xếp theo điểm giảm dần
void sapXepTheoDiem(SinhVien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].diem < arr[j].diem) {  // Giảm dần
                SinhVien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Sắp xếp theo tên tăng dần (theo alphabet)
void sapXepTheoTen(SinhVien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i].ten, arr[j].ten) > 0) {  // Tăng dần
                SinhVien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
```

## 8. Bài tập thực hành

### Bài 1: Linear Search
Tạo mảng 20 số ngẫu nhiên 0..99. Nhập x, tìm x trong mảng (trả về vị trí đầu tiên và số lần xuất hiện).

### Bài 2: Binary Search
Tạo mảng đã sắp xếp 100 số. Dùng binary search tìm x. Đếm số bước cần để tìm thấy.

### Bài 3: Selection Sort từng bước
Cài đặt selection sort và in mảng sau mỗi lần lặp:
```
Buoc 0: [64, 25, 12, 22, 11]
Buoc 1: [11, 25, 12, 22, 64]
Buoc 2: [11, 12, 25, 22, 64]
...
```

### Bài 4: Sắp xếp sinh viên
Tạo mảng 5 sinh viên (tên, điểm). Sắp xếp theo:
- Điểm giảm dần
- Tên tăng dần (alphabet)

### Bài 5: Tìm kiếm kết hợp
Sắp xếp mảng rồi dùng binary search để tìm. So sánh thời gian với linear search (dùng `clock()` từ time.h).

## 📚 Tham khảo thêm

- [GeeksforGeeks — Linear Search](https://www.geeksforgeeks.org/linear-search/)
- [GeeksforGeeks — Binary Search](https://www.geeksforgeeks.org/binary-search/)
- [GeeksforGeeks — Selection Sort](https://www.geeksforgeeks.org/selection-sort/)
- [GeeksforGeeks — Bubble Sort](https://www.geeksforgeeks.org/bubble-sort/)
- [Visual Algo — Trực quan hóa thuật toán](https://visualgo.net/en/sorting)
