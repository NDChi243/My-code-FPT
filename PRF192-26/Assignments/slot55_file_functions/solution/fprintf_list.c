/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so]
 * Mon:    PRF192 - Co so Lap trinh
 * Slot:   Slot 55 - Bai 1: Ghi danh sach dung fprintf
 */
#include <stdio.h>
#include <string.h>

typedef struct {
    char ten[50];
    char mssv[10];
    float diem;
} SinhVien;

int main() {
    int n, i;
    SinhVien ds[100];
    FILE *fp;

    // Nhap so luong sinh vien
    printf("Nhap so sinh vien: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Du lieu khong hop le!\n");
        return 1;
    }
    getchar(); // Xoa bo nho dem

    // Nhap thong tin tung sinh vien
    for (i = 0; i < n; i++) {
        printf("\nSinh vien %d:\n", i + 1);
        printf("  Ho ten: ");
        fgets(ds[i].ten, sizeof(ds[i].ten), stdin);
        ds[i].ten[strcspn(ds[i].ten, "\n")] = '\0';

        printf("  MSSV: ");
        fgets(ds[i].mssv, sizeof(ds[i].mssv), stdin);
        ds[i].mssv[strcspn(ds[i].mssv, "\n")] = '\0';

        printf("  Diem: ");
        if (scanf("%f", &ds[i].diem) != 1 || ds[i].diem < 0 || ds[i].diem > 10) {
            printf("Diem khong hop le!\n");
            return 1;
        }
        getchar();
    }

    // Ghi vao file
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Khong the mo file de ghi!\n");
        return 1;
    }

    fprintf(fp, "STT | Ho ten          | MSSV   | Diem\n");
    fprintf(fp, "----+-----------------+--------+------\n");
    for (i = 0; i < n; i++) {
        fprintf(fp, "%-3d | %-15s | %-6s | %.2f\n",
                i + 1, ds[i].ten, ds[i].mssv, ds[i].diem);
    }

    fclose(fp);
    printf("\nDa ghi danh sach vao file output.txt thanh cong!\n");

    return 0;
}
