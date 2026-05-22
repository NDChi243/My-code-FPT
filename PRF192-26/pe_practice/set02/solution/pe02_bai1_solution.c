/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so sinh vien]
 * Mon:    PRF192 - Co so Lap trinh
 * PE Practice Set 02 - Bai 1 (Solution)
 * Ngay:   ___/___/2025
 *
 * ========================= GIAI THICH =========================
 * Bai toan: Thao tac tren mang so nguyen
 *
 * Cac ky nang:
 *  1. isPerfect(): Kiem tra so hoan hao
 *     - So hoan hao = tong cac uoc thuc su (khong tinh chinh no)
 *     - VD: 6 = 1 + 2 + 3
 *  2. sumOfDigits(): Tinh tong cac chu so
 *     - VD: 1234 -> 1+2+3+4 = 10
 *  3. processArray(): Xu ly mang
 *     - Dem so hoan hao, tinh tong
 *     - Tim phan tu co tong chu so lon nhat
 *     - Bubble Sort tang dan
 * ========================= HET ================================
 */

#include <stdio.h>   // Thu vien nhap xuat: printf(), scanf()
#include <stdlib.h>  // Thu vien ham dung chung
#include <math.h>    // Thu vien toan hoc (khong dung truc tiep nhung co the can)

/* ===== PROTOTYPE ===== */
// Khai bao truoc cac ham
int isPerfect(int n);           // Kiem tra so hoan hao
int sumOfDigits(int n);         // Tinh tong chu so
void processArray(int arr[], int n); // Xu ly mang

/* ===== MAIN ===== */
int main() {
    int n; // Bien luu so luong phan tu

    // Nhap so luong phan tu
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n); // %d: doc so nguyen, &n: luu vao bien n

    // Khai bao mang arr co toi da 100 phan tu (n <= 100)
    int arr[100];

    // Nhap cac phan tu cua mang
    printf("Nhap %d phan tu: ", n);
    for (int i = 0; i < n; i++) {
        // scanf("%d", &arr[i]): doc so nguyen, luu vao arr[i]
        scanf("%d", &arr[i]);
    }

    // Goi ham processArray de thuc hien cac yeu cau
    processArray(arr, n);

    return 0; // Ket thuc chuong trinh
}

/* ===== IMPLEMENT ===== */

/*
 * Ham: isPerfect
 * Cong dung: Kiem tra n co phai la so hoan hao khong
 *
 * Tham so: int n - so can kiem tra
 * Tra ve: 1 (true) neu la so hoan hao, 0 (false) neu khong
 *
 * So hoan hao: so nguyen duong bang tong cac uoc thuc su cua no
 * Uoc thuc su = uoc so khong tinh chinh so do
 * VD: 6 co cac uoc: 1, 2, 3 -> 1+2+3 = 6 -> 6 la so hoan hao
 *     12 co cac uoc: 1,2,3,4,6 -> 1+2+3+4+6 = 16 != 12 -> khong
 *
 * Giai thuat: Duyet i tu 1 den n/2, neu n%i==0 thi cong vao tong
 * Chi can duyet den n/2 vi uoc lon nhat (khong tinh n) <= n/2
 */
int isPerfect(int n) {
    // So hoan hao phai la so duong
    if (n <= 0) {
        return 0; // Tra ve 0 - khong phai so hoan hao
    }

    int sum = 0; // Bien luu tong cac uoc, khoi tao bang 0

    // Duyet i tu 1 den n/2 de tim uoc so
    // i = 1: bat dau tu 1 (uoc so nho nhat)
    // i <= n/2: chi can duyet den nua cua n
    // i++: tang i len 1
    for (int i = 1; i <= n / 2; i++) {
        // Neu n chia het cho i (i la uoc so cua n)
        if (n % i == 0) {
            sum += i; // sum = sum + i: cong uoc i vao tong
        }
    }

    // Neu tong cac uoc bang n -> n la so hoan hao
    if (sum == n) {
        return 1; // Tra ve 1 (true)
    } else {
        return 0; // Tra ve 0 (false)
    }
}

/*
 * Ham: sumOfDigits
 * Cong dung: Tinh tong cac chu so cua so nguyen n
 *
 * Tham so: int n - so can tinh tong chu so
 * Tra ve: int - tong cac chu so
 *
 * VD: n = 1234
 *   n % 10 = 4 -> sum = 4, n = 1234 / 10 = 123
 *   n % 10 = 3 -> sum = 7, n = 123 / 10 = 12
 *   n % 10 = 2 -> sum = 9, n = 12 / 10 = 1
 *   n % 10 = 1 -> sum = 10, n = 1 / 10 = 0 (dung)
 *   => sum = 10
 *
 * Giai thuat: Lay chu so cuoi (n%10), cong vao sum, loai chu so cuoi (n/10)
 */
int sumOfDigits(int n) {
    int sum = 0; // Bien luu tong, khoi tao bang 0

    // Xu ly truong hop n am: lay gia tri tuyet doi
    // abs(n) tra ve gia tri tuyet doi cua n
    // Neu khong lam buoc nay, VD n = -123 se tinh sai
    if (n < 0) {
        n = -n; // Lay so doi (duong)
    }

    // Vong lap tach tung chu so
    // while (n > 0): lap khi n con > 0
    // Khi n = 0 thi ket thuc (da tach het chu so)
    while (n > 0) {
        // n % 10: lay chu so hang don vi (cuoi cung)
        // VD: 1234 % 10 = 4
        sum += n % 10; // Cong chu so vao tong: sum = sum + (n % 10)

        // n / 10: loai bo chu so cuoi cung (chia nguyen)
        // VD: 1234 / 10 = 123
        n = n / 10;
    }

    return sum; // Tra ve tong cac chu so
}

/*
 * Ham: processArray
 * Cong dung: Thuc hien cac thao tac tren mang
 *   a) Dem va tinh tong cac so hoan hao
 *   b) Tim phan tu co tong chu so lon nhat
 *   c) Sap xep mang tang dan bang Bubble Sort
 *
 * Tham so:
 *  - int arr[]: mang so nguyen can xu ly
 *  - int n: so luong phan tu
 */
void processArray(int arr[], int n) {
    // === Phan a: Dem va tinh tong so hoan hao ===
    int countPerfect = 0;  // Bien dem so luong so hoan hao
    int sumPerfect = 0;    // Bien tinh tong cac so hoan hao

    // Duyet qua tung phan tu cua mang
    for (int i = 0; i < n; i++) {
        // Kiem tra phan tu arr[i] co phai so hoan hao?
        // Goi ham isPerfect(arr[i])
        if (isPerfect(arr[i])) {
            // Neu la so hoan hao: tang bien dem len 1
            countPerfect++;
            // Cong gia tri arr[i] vao tong
            sumPerfect += arr[i];
        }
    }

    // In ket qua phan a
    if (countPerfect > 0) {
        // Neu co it nhat 1 so hoan hao: in ra cac so
        printf("Cac so hoan hao: ");

        // Duyet lai mang de in tung so hoan hao
        for (int i = 0; i < n; i++) {
            if (isPerfect(arr[i])) {
                printf("%d ", arr[i]); // In so hoan hao, cach nhau bang khoang trang
            }
        }
        printf("\n"); // Xuong dong

        // In tong cac so hoan hao
        printf("Tong cac so hoan hao: %d\n", sumPerfect);
    } else {
        // Neu khong co so hoan hao nao
        printf("Khong co so hoan hao.\n");
    }

    // === Phan b: Tim phan tu co tong chu so lon nhat ===
    int maxSumDigits = -1; // Bien luu gia tri tong chu so lon nhat (khoi tao bang -1)
    int maxValue = 0;      // Bien luu gia tri cua phan tu tim duoc
    int maxIndex = -1;     // Bien luu vi tri cua phan tu tim duoc

    // Duyet qua tung phan tu cua mang
    for (int i = 0; i < n; i++) {
        // Tinh tong chu so cua arr[i]
        int currentSum = sumOfDigits(arr[i]); // Goi ham sumOfDigits

        // So sanh: neu currentSum > maxSumDigits thi cap nhat
        // (> thay vi >= de lay phan tu dau tien neu bang nhau)
        if (currentSum > maxSumDigits) {
            maxSumDigits = currentSum; // Cap nhat tong chu so lon nhat
            maxValue = arr[i];         // Cap nhat gia tri phan tu
            maxIndex = i;              // Cap nhat vi tri phan tu
        }
    }

    // In ket qua phan b
    printf("Phan tu co tong chu so lon nhat: %d (tong chu so = %d)\n",
           maxValue, maxSumDigits);

    // === Phan c: Sap xep mang tang dan (Bubble Sort) ===
    // Bubble Sort: So sanh 2 phan tu canh nhau, doi cho neu sai thu tu

    // Vong lap ngoai: i tu 0 den n-2 (n-1 luot)
    for (int i = 0; i < n - 1; i++) {
        // Vong lap trong: j tu 0 den n-1-i
        // Moi luot, phan tu lon nhat "noi" ve cuoi mang
        for (int j = 0; j < n - 1 - i; j++) {
            // Neu arr[j] > arr[j+1]: can doi cho (sap xep tang dan)
            if (arr[j] > arr[j+1]) {
                // Hoan doi (swap) arr[j] va arr[j+1] bang bien tam
                int temp = arr[j];    // Luu arr[j] vao bien tam
                arr[j] = arr[j+1];    // Gan arr[j+1] cho arr[j]
                arr[j+1] = temp;      // Gan temp (arr[j] cu) cho arr[j+1]
            }
        }
    }

    // In mang sau khi sap xep
    printf("Mang sau khi sap xep: ");

    // Duyet mang da sap xep va in tung phan tu
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // In phan tu thu i, cach nhau bang khoang trang
    }
    printf("\n"); // Xuong dong
}
