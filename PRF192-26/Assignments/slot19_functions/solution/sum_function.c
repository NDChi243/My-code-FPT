/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so]
 * Mon:    PRF192 - Co so Lap trinh
 * Slot:   Slot 19 - Bai 1: Ham tinh tong
 */
#include <stdio.h>

// Prototype
int tinhTong(int a, int b);

int main() {
    int x, y;

    printf("Nhap hai so nguyen: ");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Du lieu khong hop le!\n");
        return 1;
    }

    // Goi ham tinh tong
    int ketQua = tinhTong(x, y);
    printf("Tong cua %d va %d la: %d\n", x, y, ketQua);

    return 0;
}

// Dinh nghia ham tinh tong
int tinhTong(int a, int b) {
    return a + b;
}
