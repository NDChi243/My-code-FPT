/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so]
 * Mon:    PRF192 - Co so Lap trinh
 * Slot:   Slot 30 - Bai 1: Hoan doi dung cach (dung con tro)
 */
#include <stdio.h>

// Prototype: nhan vao 2 con tro int
void hoanVi(int *a, int *b);

int main() {
    int x, y;

    printf("Nhap x: ");
    if (scanf("%d", &x) != 1) {
        printf("Du lieu khong hop le!\n");
        return 1;
    }
    printf("Nhap y: ");
    if (scanf("%d", &y) != 1) {
        printf("Du lieu khong hop le!\n");
        return 1;
    }

    printf("Truoc khi hoan doi: x = %d, y = %d\n", x, y);

    // Truyen dia chi cua x va y
    hoanVi(&x, &y);

    printf("Sau khi hoan doi:  x = %d, y = %d\n", x, y);

    /* Giai thich:
     * O slot20, ham hoanVi(int a, int b) nhan ban copy cua x, y
     * nen thay doi trong ham khong anh huong ben ngoai.
     * O day, ham nhan dia chi (&x, &y) qua con tro int *a, int *b,
     * va thay doi gia tri tai dia chi do bang *a, *b,
     * nen ben ngoai bi thay doi theo.
     */
    return 0;
}

// Dinh nghia ham hoan vi dung con tro
void hoanVi(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
