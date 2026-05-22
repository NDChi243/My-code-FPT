/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so]
 * Mon:    PRF192 - Co so Lap trinh
 * Slot:   Slot 04 - Bai 1: Khai bao nhieu kieu
 */
#include <stdio.h>

int main() {
    // Khai bao bien cac kieu
    int a = 10;
    float b = 3.14f;
    double c = 3.141592;
    char d = 'A';
    char e[] = "PRF192";

    // In gia tri va kich thuoc
    printf("Kieu int:     a = %d, kich thuoc = %d byte\n", a, (int)sizeof(a));
    printf("Kieu float:   b = %.2f, kich thuoc = %d byte\n", b, (int)sizeof(b));
    printf("Kieu double:  c = %f, kich thuoc = %d byte\n", c, (int)sizeof(c));
    printf("Kieu char:    d = '%c', kich thuoc = %d byte\n", d, (int)sizeof(d));
    printf("Kieu chuoi:   e = \"%s\", kich thuoc = %d byte\n", e, (int)sizeof(e));

    return 0;
}
