/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so]
 * Mon:    PRF192 - Co so Lap trinh
 * Slot:   Slot 40 - Bai 1: Khai bao va su dung struct
 */
#include <stdio.h>
#include <string.h>

// Dinh nghia kieu struct SinhVien
typedef struct {
    char ten[50];
    char mssv[10];
    int tuoi;
    float diemTB;
} SinhVien;

int main() {
    SinhVien sv;

    // Nhap thong tin sinh vien
    printf("Nhap ten: ");
    fgets(sv.ten, sizeof(sv.ten), stdin);
    // Xoa ky tu xuong dong
    sv.ten[strcspn(sv.ten, "\n")] = '\0';

    printf("Nhap MSSV: ");
    fgets(sv.mssv, sizeof(sv.mssv), stdin);
    sv.mssv[strcspn(sv.mssv, "\n")] = '\0';

    printf("Nhap tuoi: ");
    if (scanf("%d", &sv.tuoi) != 1 || sv.tuoi <= 0) {
        printf("Tuoi khong hop le!\n");
        return 1;
    }

    printf("Nhap diem TB: ");
    if (scanf("%f", &sv.diemTB) != 1 || sv.diemTB < 0 || sv.diemTB > 10) {
        printf("Diem khong hop le!\n");
        return 1;
    }

    // In thong tin sinh vien
    printf("\n===== THONG TIN SINH VIEN =====\n");
    printf("Ho ten: %s\n", sv.ten);
    printf("MSSV: %s\n", sv.mssv);
    printf("Tuoi: %d\n", sv.tuoi);
    printf("Diem TB: %.2f\n", sv.diemTB);

    return 0;
}
