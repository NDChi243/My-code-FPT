/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so sinh vien]
 * Mon:    PRF192 - Co so Lap trinh
 * PE Practice Set 02 - Bai 2 (Solution)
 * Ngay:   ___/___/2025
 *
 * ========================= GIAI THICH =========================
 * Bai toan: Thao tac tren ma tran (mang 2 chieu) cap phat dong
 *
 * Kien thuc moi - CAP PHAT DONG (malloc):
 *  - malloc: cap phat bo nho dong (heap) - tra ve con tro void*
 *  - (int**)ep_kieu: ep kieu tu void* sang int**
 *  - free: giai phong bo nho da cap phat
 *  - Con tro **: con tro tro toi con tro (mang 2 chieu dong)
 *
 * Cau truc ma tran cap phat dong:
 *   matrix -> [row0] -> [col0, col1, col2, ...]
 *             [row1] -> [col0, col1, col2, ...]
 *             [row2] -> [col0, col1, col2, ...]
 *
 * Nhan ma tran: A(r1xc1) * B(r2xc2) = C(r1xc2)
 *   Dieu kien: c1 == r2
 *   C[i][j] = SUM(A[i][k] * B[k][j]) voi k = 0..c1-1
 *
 * Ma tran doi xung: a[i][j] == a[j][i] voi moi i, j
 * ========================= HET ================================
 */

#include <stdio.h>   // Thu vien nhap xuat: printf(), scanf()
#include <stdlib.h>  // Thu vien cap phat dong: malloc(), free()

/* ===== PROTOTYPE ===== */
// Khai bao cac ham thao tac tren ma tran cap phat dong
int** allocateMatrix(int rows, int cols);          // Cap phat bo nho cho ma tran
void freeMatrix(int **matrix, int rows);           // Giai phong bo nho ma tran
void inputMatrix(int **matrix, int rows, int cols); // Nhap ma tran
void printMatrix(int **matrix, int rows, int cols); // In ma tran
int** multiplyMatrix(int **a, int r1, int c1,      // Nhan hai ma tran
                     int **b, int r2, int c2);
int isSymmetric(int **matrix, int n);              // Kiem tra ma tran doi xung

/* ===== MAIN ===== */
int main() {
    int r1, c1; // So hang va so cot cua ma tran A
    int r2, c2; // So hang va so cot cua ma tran B

    // === Nhap ma tran A ===
    printf("Nhap kich thuoc ma tran A (r1 c1): ");
    scanf("%d %d", &r1, &c1); // Doc 2 so nguyen: r1 va c1

    // Cap phat bo nho cho ma tran A
    int **A = allocateMatrix(r1, c1); // A la con tro ** tro toi ma tran r1 x c1

    // Nhap gia tri cho ma tran A
    printf("Nhap ma tran A (%dx%d):\n", r1, c1);
    inputMatrix(A, r1, c1); // Truyen ma tran A da cap phat

    // === Nhap ma tran B ===
    printf("Nhap kich thuoc ma tran B (r2 c2): ");
    scanf("%d %d", &r2, &c2); // Doc 2 so nguyen: r2 va c2

    // Cap phat bo nho cho ma tran B
    int **B = allocateMatrix(r2, c2); // B la con tro ** tro toi ma tran r2 x c2

    // Nhap gia tri cho ma tran B
    printf("Nhap ma tran B (%dx%d):\n", r2, c2);
    inputMatrix(B, r2, c2); // Truyen ma tran B da cap phat

    // === In ma tran A va B ===
    printf("\nMa tran A (%dx%d):\n", r1, c1);
    printMatrix(A, r1, c1); // Goi ham in ma tran A

    printf("\nMa tran B (%dx%d):\n", r2, c2);
    printMatrix(B, r2, c2); // Goi ham in ma tran B

    // === Nhan ma tran A voi B ===
    // Goi ham multiplyMatrix: tra ve ma tran tich (hoac NULL neu khong hop le)
    int **C = multiplyMatrix(A, r1, c1, B, r2, c2);

    // Kiem tra ket qua: neu C != NULL thi in, neu NULL thi da co thong bao loi
    if (C != NULL) {
        printf("\nTich A x B (%dx%d):\n", r1, c2);
        printMatrix(C, r1, c2); // In ma tran tich

        // Giai phong bo nho ma tran tich vi khong can dung nua
        freeMatrix(C, r1);
    }

    // === Kiem tra ma tran A co doi xung khong ===
    // Chi kiem tra khi A la ma tran vuong (r1 == c1)
    if (r1 == c1) {
        // Goi ham isSymmetric de kiem tra
        if (isSymmetric(A, r1)) {
            printf("\nMa tran A doi xung\n");
        } else {
            printf("\nMa tran A khong doi xung\n");
        }
    } else {
        // A khong phai ma tran vuong -> khong the doi xung
        printf("\nMa tran A khong doi xung (khong phai ma tran vuong)\n");
    }

    // === Giai phong bo nho ===
    // Giai phong ma tran A va B de tranh ro ri bo nho (memory leak)
    freeMatrix(A, r1); // Giai phong ma tran A
    freeMatrix(B, r2); // Giai phong ma tran B

    return 0; // Ket thuc chuong trinh
}

/* ===== IMPLEMENT ===== */

/*
 * Ham: allocateMatrix
 * Cong dung: Cap phat dong ma tran rows x cols bang malloc
 *
 * Tham so:
 *  - int rows: so hang
 *  - int cols: so cot
 *
 * Tra ve: int** - con tro toi ma tran da cap phat
 *
 * Giai thich:
 *  - Cap phat mang cac con tro (moi con tro la 1 hang)
 *  - Moi con tro hang tro toi 1 mang gom cols so nguyen
 *  - malloc(kich_thuoc): cap phat kich_thuoc byte bo nho
 *  - sizeof(int): kich thuoc cua 1 bien int (thuong 4 byte)
 *  - sizeof(int*): kich thuoc cua 1 con tro int (thuong 4 hoac 8 byte)
 */
int** allocateMatrix(int rows, int cols) {
    // Buoc 1: Cap phat mang rows con tro (moi con tro la 1 hang)
    // rows * sizeof(int*): so byte cho rows con tro int*
    // (int**): ep kieu tu void* (malloc tra ve void*) sang int**
    int **matrix = (int**)malloc(rows * sizeof(int*));

    // Kiem tra malloc co thanh cong khong
    // Neu malloc that bai, tra ve NULL
    if (matrix == NULL) {
        printf("Loi cap phat bo nho!\n");
        return NULL; // Tra ve NULL de bao loi
    }

    // Buoc 2: Cap phat tung hang (moi hang la 1 mang 1 chieu)
    // Duyet tung hang i tu 0 den rows-1
    for (int i = 0; i < rows; i++) {
        // Cap phat mang cols so nguyen cho hang thu i
        // cols * sizeof(int): so byte cho cols bien int
        matrix[i] = (int*)malloc(cols * sizeof(int));

        // Kiem tra malloc co thanh cong khong
        if (matrix[i] == NULL) {
            // Neu that bai: can giai phong cac hang da cap phat truoc do
            printf("Loi cap phat bo nho!\n");
            // Giai phong cac hang tu 0 den i-1
            for (int j = 0; j < i; j++) {
                free(matrix[j]); // free: giai phong bo nho cua hang j
            }
            free(matrix); // Giai phong mang con tro
            return NULL;
        }
    }

    // Tra ve con tro toi ma tran da cap phat
    return matrix;
}

/*
 * Ham: freeMatrix
 * Cong dung: Giai phong bo nho da cap phat cho ma tran
 *
 * Tham so:
 *  - int **matrix: con tro toi ma tran can giai phong
 *  - int rows: so hang cua ma tran
 *
 * Ghi chu: Sau khi goi free, matrix tro toi vung nho khong hop le
 * Rat quan trong de tranh memory leak!
 */
void freeMatrix(int **matrix, int rows) {
    // Giai phong tung hang: duyet i tu 0 den rows-1
    for (int i = 0; i < rows; i++) {
        free(matrix[i]); // Giai phong mang 1 chieu (hang i)
    }

    // Giai phong mang cac con tro (cac hang)
    free(matrix);
}

/*
 * Ham: inputMatrix
 * Cong dung: Nhap gia tri cho ma tran tu ban phim
 *
 * Tham so:
 *  - int **matrix: ma tran can nhap
 *  - int rows, cols: kich thuoc ma tran
 *
 * matrix[i][j]: truy cap phan tu hang i, cot j
 * Tuong duong: *(*(matrix + i) + j)
 */
void inputMatrix(int **matrix, int rows, int cols) {
    // Duyet tung hang i tu 0 den rows-1
    for (int i = 0; i < rows; i++) {
        // Duyet tung cot j tu 0 den cols-1
        for (int j = 0; j < cols; j++) {
            // Nhap gia tri cho phan tu hang i, cot j
            // &matrix[i][j]: dia chi cua phan tu (i,j)
            scanf("%d", &matrix[i][j]);
        }
    }
}

/*
 * Ham: printMatrix
 * Cong dung: In ma tran ra man hinh
 *
 * Tham so:
 *  - int **matrix: ma tran can in
 *  - int rows, cols: kich thuoc ma tran
 *
 * Dinh dang: moi hang tren 1 dong, cac phan tu cach nhau bang tab (\t)
 */
void printMatrix(int **matrix, int rows, int cols) {
    // Duyet tung hang i
    for (int i = 0; i < rows; i++) {
        // Duyet tung cot j
        for (int j = 0; j < cols; j++) {
            // In phan tu (i,j) va 1 tab
            // %d: in so nguyen
            // \t: tab de can le
            printf("%d\t", matrix[i][j]);
        }
        printf("\n"); // Xuong dong sau khi in xong 1 hang
    }
}

/*
 * Ham: multiplyMatrix
 * Cong dung: Nhan hai ma tran
 *
 * Tham so:
 *  - int **a, **b: hai ma tran can nhan
 *  - int r1, c1: kich thuoc ma tran a
 *  - int r2, c2: kich thuoc ma tran b
 *
 * Dieu kien: c1 == r2 (so cot cua a = so hang cua b)
 *
 * Cong thuc:
 *   C[i][j] = SUM(a[i][k] * b[k][j]) voi k = 0..c1-1
 *
 * Tra ve: int** - ma tran tich, hoac NULL neu khong hop le
 */
int** multiplyMatrix(int **a, int r1, int c1,
                     int **b, int r2, int c2) {
    // Kiem tra dieu kien nhan ma tran
    // c1 (so cot cua a) phai bang r2 (so hang cua b)
    if (c1 != r2) {
        // Neu khong hop le: in thong bao va tra ve NULL
        printf("Khong the nhan hai ma tran!\n");
        return NULL;
    }

    // Cap phat ma tran ket qua C kich thuoc r1 x c2
    int **C = allocateMatrix(r1, c2);

    // Kiem tra cap phat co thanh cong khong
    if (C == NULL) {
        return NULL; // Tra ve NULL neu loi
    }

    // Nhan ma tran: 3 vong lap long nhau
    // Vong ngoai: duyet hang cua ma tran A (va ma tran C)
    for (int i = 0; i < r1; i++) {
        // Vong giua: duyet cot cua ma tran B (va ma tran C)
        for (int j = 0; j < c2; j++) {
            // Khoi tao C[i][j] = 0 truoc khi tinh tong
            C[i][j] = 0;

            // Vong trong: tinh tong a[i][k] * b[k][j]
            // k chay tu 0 den c1-1 (c1 = r2)
            for (int k = 0; k < c1; k++) {
                // Cong don tich a[i][k] * b[k][j] vao C[i][j]
                // Day la cong thuc nhan ma tran chuan
                C[i][j] += a[i][k] * b[k][j];
                // Tuong duong: C[i][j] = C[i][j] + a[i][k] * b[k][j]
            }
        }
    }

    // Tra ve ma tran tich
    return C;
}

/*
 * Ham: isSymmetric
 * Cong dung: Kiem tra ma tran vuong co doi xung qua duong cheo chinh khong
 *
 * Tham so:
 *  - int **matrix: ma tran can kiem tra
 *  - int n: kich thuoc ma tran (n x n)
 *
 * Tra ve: 1 (doi xung) hoac 0 (khong doi xung)
 *
 * Dieu kien doi xung: a[i][j] == a[j][i] voi moi i, j
 * Chi can kiem tra nua tren duong cheo (i < j)
 */
int isSymmetric(int **matrix, int n) {
    // Duyet nua tren duong cheo chinh
    // i tu 0 den n-2 (hang)
    // j tu i+1 den n-1 (cot, bat dau tu i+1 de chi lay nua tren)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // So sanh matrix[i][j] va matrix[j][i]
            // Neu khong bang nhau -> khong doi xung
            if (matrix[i][j] != matrix[j][i]) {
                return 0; // Tra ve 0 (false) - khong doi xung
            }
        }
    }

    // Da duyet het, tat ca deu bang nhau -> doi xung
    return 1; // Tra ve 1 (true) - doi xung
}
