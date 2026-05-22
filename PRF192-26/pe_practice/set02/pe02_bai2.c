/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so sinh vien]
 * Mon:    PRF192 - Co so Lap trinh
 * PE Practice Set 02 - Bai 2
 * Ngay:   ___/___/2025
 *
 * ========================= DE BAI =========================
 * Viet chuong trinh thao tac tren ma tran (mang 2 chieu)
 * su dung cap phat dong (malloc).
 *
 * 1.  Viet ham int** allocateMatrix(int rows, int cols)
 *     cap phat dong ma tran rows x cols.
 *     Tra ve con tro toi ma tran da cap phat.
 *
 * 2.  Viet ham void freeMatrix(int **matrix, int rows)
 *     giai phong bo nho da cap phat cho ma tran.
 *
 * 3.  Viet ham void inputMatrix(int **matrix, int rows, int cols)
 *     nhap gia tri cac phan tu cua ma tran tu ban phim.
 *
 * 4.  Viet ham void printMatrix(int **matrix, int rows, int cols)
 *     in ma tran ra man hinh, moi hang tren mot dong,
 *     cac phan tu cach nhau boi 1 tab (\t).
 *
 * 5.  Viet ham int** multiplyMatrix(int **a, int r1, int c1,
 *                                    int **b, int r2, int c2)
 *     thuc hien nhan hai ma tran a (r1 x c1) va b (r2 x c2).
 *     Dieu kien: c1 == r2.
 *     Tra ve ma tran ket qua kich thuoc r1 x c2.
 *     Neu khong hop le, tra ve NULL va in thong bao
 *     "Khong the nhan hai ma tran!"
 *
 * 6.  Viet ham int isSymmetric(int **matrix, int n)
 *     kiem tra ma tran vuong n x n co doi xung qua
 *     duong cheo chinh hay khong (a[i][j] == a[j][i]).
 *     Tra ve 1 neu dung, 0 neu sai.
 *
 * 7.  Trong ham main():
 *     - Nhap kich thuoc ma tran A (r1, c1)
 *     - Nhap ma tran A
 *     - Nhap kich thuoc ma tran B (r2, c2)
 *     - Nhap ma tran B
 *     - In ma tran A va B
 *     - Goi ham multiplyMatrix de nhan A voi B,
 *       in ket qua neu hop le
 *     - Neu ma tran A la ma tran vuong, kiem tra
 *       va in "Ma tran A doi xung" hoac
 *       "Ma tran A khong doi xung"
 *
 * ================ INPUT MAU & OUTPUT MAU =================
 * Input:
 *   2 3
 *   1 2 3
 *   4 5 6
 *   3 2
 *   7 8
 *   9 10
 *   11 12
 *
 * Output:
 *   Ma tran A (2x3):
 *   1	2	3
 *   4	5	6
 *
 *   Ma tran B (3x2):
 *   7	8
 *   9	10
 *   11	12
 *
 *   Tich A x B (2x2):
 *   58	64
 *   139	154
 *
 *   Ma tran A khong doi xung (khong phai ma tran vuong)
 *
 * ==================== TEST CASE 2 ========================
 * Input:
 *   3 3
 *   1 2 3
 *   2 5 6
 *   3 6 9
 *   3 3
 *   1 0 0
 *   0 1 0
 *   0 0 1
 *
 * Output:
 *   Ma tran A (3x3):
 *   1	2	3
 *   2	5	6
 *   3	6	9
 *
 *   Ma tran B (3x3):
 *   1	0	0
 *   0	1	0
 *   0	0	1
 *
 *   Tich A x B (3x3):
 *   1	2	3
 *   2	5	6
 *   3	6	9
 *
 *   Ma tran A doi xung
 * ========================= END ===========================
 */
#include <stdio.h>
#include <stdlib.h>

/* ===== PROTOTYPE ===== */


/* ===== MAIN ===== */
int main() {

    return 0;
}

/* ===== IMPLEMENT ===== */
