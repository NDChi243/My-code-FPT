/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so]
 * Mon:    PRF192 - Co so Lap trinh
 * Slot:   Slot 10 - Bai 2: So nguyen to
 */
#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    int laNguyenTo = 1; // 1: dung, 0: sai

    // Nhap va kiem tra
    printf("Nhap n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Du lieu khong hop le!\n");
        return 1;
    }

    // Kiem tra so nguyen to
    if (n < 2) {
        laNguyenTo = 0;
    } else {
        for (i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                laNguyenTo = 0;
                break;
            }
        }
    }

    // In ket qua
    if (laNguyenTo) {
        printf("%d la so nguyen to\n", n);
    } else {
        printf("%d khong phai la so nguyen to\n", n);
    }

    return 0;
}
