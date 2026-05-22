/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so sinh vien]
 * Mon:    PRF192 - Co so Lap trinh
 * PE Practice Set 01 - Bai 2 (Solution)
 * Ngay:   ___/___/2025
 *
 * ========================= GIAI THICH =========================
 * Bai toan: Quan ly danh sach sinh vien
 *
 * Cac kien thuc su dung:
 *  1. struct: Dinh nghia kieu du lieu tu dinh nghia gom nhieu thanh phan
 *  2. Mang struct: Luu nhieu doi tuong sinh vien
 *  3. fgets + strcspn: Doc chuoi co khoang trang, loai bo \n
 *  4. strlwr + strstr: Chuyen chuoi ve chu thuong + tim kiem chuoi con
 *  5. Bubble Sort: Sap xep mang theo diem giam dan
 *  6. Bang in can le: Su dung printf voi do rong truong (%-Ns)
 * ========================= HET ================================
 */

#include <stdio.h>   // Thu vien nhap xuat: printf, scanf, fgets,...
#include <stdlib.h>  // Thu vien ham dung chung
#include <string.h>  // Thu vien xu ly chuoi: strcmp, strcpy, strstr, strlwr,...
#include <ctype.h>   // Thu vien xu ly ky tu: tolower,...

/* ===== KHAI BAO STRUCT ===== */

/*
 * Dinh nghia kieu du lieu Student (sinh vien)
 * struct la tu khoa de dinh nghia kieu du lieu co cau truc
 * Student la ten cua kieu du lieu moi
 * Gom 3 thanh phan (goi la field/member):
 *   - id: ma sinh vien (chuoi toi da 10 ky tu)
 *   - name: ho ten (chuoi toi da 50 ky tu)
 *   - score: diem tong ket (so thuc)
 */
typedef struct {
    char id[10];      // Ma sinh vien: VD "SE001", "SE002",...
    char name[50];    // Ho ten sinh vien: VD "Nguyen Van A"
    float score;      // Diem tong ket: VD 9.5, 8.75
} Student;           // Tu khoa typedef giup ta dung "Student" thay vi "struct Student"

/* ===== PROTOTYPE ===== */
// Khai bao cac ham se viet phan ben duoi
void inputStudent(Student *s, int index);                   // Nhap thong tin sinh vien
void sortByScore(Student arr[], int n);                     // Sap xep theo diem giam dan
void searchByName(Student arr[], int n, char keyword[]);    // Tim kiem theo ten
void displayStudents(Student arr[], int n);                 // In danh sach dang bang

/* ===== MAIN ===== */
int main() {
    int n; // Bien luu so luong sinh vien

    // Nhap so luong sinh vien
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n); // %d: doc so nguyen, &n: luu vao bien n

    // Khai bao mang arr gom n phan tu kieu Student
    // Mang nay luu danh sach sinh vien
    Student arr[100]; // Toi da 100 sinh vien (theo de bai)

    // Dung fflush(stdin) hoac getchar() de xoa bo nho dem sau scanf
    // Vi sau scanf con lai ky tu '\n', gay loi cho fgets
    fflush(stdin); // Xoa bo nho dem (tren Windows)

    // Vong lap nhap thong tin n sinh vien
    // i = 0 -> n-1: tuong ung sinh vien thu 1 -> n
    for (int i = 0; i < n; i++) {
        // In ra so thu tu sinh vien can nhap (i+1 de bat dau tu 1)
        printf("\n--- Nhap sinh vien thu %d ---\n", i + 1);
        // Goi ham inputStudent, truyen dia chi cua phan tu thu i
        // &arr[i]: lay dia chi cua phan tu arr[i] de ham co the thay doi truc tiep
        // i: so thu tu (bat dau tu 0)
        inputStudent(&arr[i], i);
    }

    // In danh sach vua nhap
    printf("\n=== Danh sach sinh vien ===\n");
    displayStudents(arr, n); // Truyen mang va so phan tu

    // Sap xep danh sach theo diem giam dan
    sortByScore(arr, n); // Truyen mang, ham se sap xep truc tiep tren mang

    // In danh sach sau khi sap xep
    printf("\n=== Sau khi sap xep theo diem giam dan ===\n");
    displayStudents(arr, n);

    // Tim kiem sinh vien theo ten
    char keyword[50]; // Bien luu tu khoa can tim
    printf("\nNhap tu khoa tim kiem: ");
    fflush(stdin); // Xoa bo nho dem truoc khi doc chuoi
    fgets(keyword, 50, stdin); // Doc chuoi tu ban phim (co the co khoang trang)

    // fgets lay ca ky tu '\n' o cuoi, can loai bo no
    // strcspn(keyword, "\n") tra ve vi tri cua '\n' trong keyword
    // Thay '\n' bang '\0' (ky tu ket thuc chuoi)
    keyword[strcspn(keyword, "\n")] = '\0';

    // Goi ham tim kiem
    printf("\n=== Ket qua tim kiem tu khoa: \"%s\" ===\n", keyword);
    searchByName(arr, n, keyword);

    return 0; // Ket thuc chuong trinh
}

/* ===== IMPLEMENT ===== */

/*
 * Ham: inputStudent
 * Cong dung: Nhap thong tin cho mot sinh vien
 *
 * Tham so:
 *  - Student *s: CON TRO toi struct Student can nhap
 *    (dung con tro de thay doi truc tiep gia tri cua struct o ben ngoai)
 *  - int index: so thu tu cua sinh vien (bat dau tu 0)
 *
 * Gia tri tra ve: khong co (void)
 *
 * Giai thich: Su dung con tro *s cho phep ham nay
 * thay doi truc tiep bien Student o ben ngoai ham.
 * Neu khong dung con tro, ham chi thao tac tren ban sao.
 */
void inputStudent(Student *s, int index) {
    // Nhap ma sinh vien
    printf("  Ma SV: ");
    // fgets doc chuoi tu ban phim, co the chua khoang trang
    // s->id: truy cap thanh phan id cua struct Student thong qua con tro
    // 10: kich thuoc toi da cua mang id
    // stdin: doc tu ban phim
    fgets(s->id, 10, stdin);
    // Loai bo ky tu '\n' o cuoi chuoi
    // s->id la ten chuoi, strcspn tim vi tri cua '\n'
    s->id[strcspn(s->id, "\n")] = '\0';

    // Nhap ho ten sinh vien
    printf("  Ho ten: ");
    fgets(s->name, 50, stdin); // Doc chuoi co the co khoang trang
    s->name[strcspn(s->name, "\n")] = '\0'; // Xoa bo '\n'

    // Nhap diem so
    printf("  Diem: ");
    // %f: doc so thuc kieu float
    // &s->score: dia chi cua thanh phan score
    scanf("%f", &s->score);
    // Xoa bo nho dem sau scanf (de lan goi fgets tiep theo khong bi loi)
    fflush(stdin);
}

/*
 * Ham: sortByScore
 * Cong dung: Sap xep mang sinh vien theo diem giam dan
 *
 * Tham so:
 *  - Student arr[]: mang cac sinh vien can sap xep
 *  - int n: so luong phan tu trong mang
 *
 * Gia tri tra ve: khong co (void)
 *
 * Giai thuat: Bubble Sort (sap xep noi bot)
 *  - So sanh 2 phan tu canh nhau, neu phan tu truoc < phan tu sau thi doi cho
 *  - Vong lap ngoai: chay n-1 lan (luot)
 *  - Vong lap trong: chay tu 0 den n-1-i
 *  - Sau moi luot, phan tu nho nhat "noi" ve cuoi mang
 */
void sortByScore(Student arr[], int n) {
    // Bien tam de hoan doi (swap) 2 bien Student
    Student temp;

    // Vong lap ngoai: i tu 0 den n-2 (n-1 luot)
    for (int i = 0; i < n - 1; i++) {
        // Vong lap trong: j tu 0 den n-1-i
        // Moi luot i, phan tu cuoi cung da dung vi tri
        for (int j = 0; j < n - 1 - i; j++) {
            // So sanh diem cua arr[j] va arr[j+1]
            // Neu arr[j].score < arr[j+1].score: can doi cho (sap xep giam dan)
            // Dau '.' (dot operator) dung de truy cap thanh phan cua struct
            if (arr[j].score < arr[j+1].score) {
                // Hoan doi (swap) arr[j] va arr[j+1]
                // Dung bien temp de luu tam arr[j]
                temp = arr[j];          // Gan arr[j] vao temp
                arr[j] = arr[j+1];      // Gan arr[j+1] vao arr[j]
                arr[j+1] = temp;        // Gan temp (arr[j] cu) vao arr[j+1]
            }
        }
    }
}

/*
 * Ham: searchByName
 * Cong dung: Tim kiem sinh vien co ho ten chua tu khoa (khong phan biet hoa thuong)
 *
 * Tham so:
 *  - Student arr[]: mang sinh vien can tim
 *  - int n: so luong sinh vien
 *  - char keyword[]: tu khoa can tim
 *
 * Gia tri tra ve: khong co (void)
 *
 * Giai thuat:
 *  - Tao ban sao thuong cua keyword (strlwr)
 *  - Duyet tung sinh vien: tao ban sao thuong cua name
 *  - Dung strstr de kiem tra chuoi name co chua keyword khong
 *  - Neu co: them vao mang ket qua
 *  - Cuoi cung in mang ket qua (hoac thong bao khong tim thay)
 */
void searchByName(Student arr[], int n, char keyword[]) {
    // Mang ket qua tam: luu cac sinh vien tim duoc
    Student result[100];
    int count = 0; // Dem so sinh vien tim duoc

    // Duyet qua tung sinh vien trong mang
    // i tu 0 den n-1
    for (int i = 0; i < n; i++) {
        // Tao ban sao cua ten sinh vien va chuyen ve chu thuong
        // strcpy(s1, s2): copy chuoi s2 vao s1
        char nameLower[50]; // Bien tam chua ten chu thuong
        strcpy(nameLower, arr[i].name); // Copy name vao nameLower

        // Chuyen tung ky tu trong nameLower ve chu thuong
        // strlen(nameLower): tra ve do dai chuoi (so ky tu)
        for (int j = 0; j < strlen(nameLower); j++) {
            // tolower(nameLower[j]): chuyen ky tu thu j ve chu thuong
            // gan lai vao nameLower[j] de thay doi truc tiep
            nameLower[j] = tolower(nameLower[j]);
        }

        // Tao ban sao cua keyword va chuyen ve chu thuong
        char keyLower[50];
        strcpy(keyLower, keyword); // Copy keyword vao keyLower
        for (int j = 0; j < strlen(keyLower); j++) {
            keyLower[j] = tolower(keyLower[j]); // Chuyen tung ky tu ve thuong
        }

        // strstr(s1, s2): tim chuoi s2 trong chuoi s1
        // Tra ve con tro toi vi tri dau tien tim thay
        // Neu khong tim thay, tra ve NULL
        if (strstr(nameLower, keyLower) != NULL) {
            // Tim thay: them sinh vien vao mang ket qua
            result[count] = arr[i]; // Gan nguyen struct
            count++;                // Tang so dem
        }
    }

    // In ket qua
    if (count > 0) {
        // Neu tim thay it nhat 1 sinh vien: in bang
        displayStudents(result, count);
    } else {
        // Khong tim thay: in thong bao
        printf("Khong tim thay sinh vien!\n");
    }
}

/*
 * Ham: displayStudents
 * Cong dung: In danh sach sinh vien dang bang can le
 *
 * Tham so:
 *  - Student arr[]: mang sinh vien can in
 *  - int n: so luong sinh vien
 *
 * Gia tri tra ve: khong co (void)
 *
 * Giai thich dinh dang printf:
 *  - printf("%-5s", "abc"): in "abc  " (can trai, do rong 5)
 *  - printf("%10s", "abc"): in "       abc" (can phai, do rong 10)
 *  - printf("%7.2f", 9.5): in "   9.50" (do rong 7, 2 so thap phan)
 */
void displayStudents(Student arr[], int n) {
    // In duong ke tren bang
    // "|---|----------|--------------------|--------|\n"
    // \n: xuong dong moi
    printf("|---|----------|--------------------|--------|\n");

    // In tieu de cot
    // %-5s: In chuoi can trai, do rong toi thieu 5 ky tu
    // "STT" : So thu tu
    // "Ma SV" : Ma sinh vien (can trai, do rong 10)
    // "Ho ten" : Ho ten (can trai, do rong 20)
    // "Diem" : Diem (can trai, do rong 8)
    printf("| %-3s | %-8s | %-18s | %-6s |\n", "STT", "Ma SV", "Ho ten", "Diem");

    // In duong ke
    printf("|---|----------|--------------------|--------|\n");

    // Vong lap in tung sinh vien
    // i tu 0 den n-1 (index trong mang)
    for (int i = 0; i < n; i++) {
        // In mot dong sinh vien
        // %-3d: In so nguyen can trai, do rong 3 (i+1: so thu tu tu 1)
        // %-8s: In chuoi can trai, do rong 8 (arr[i].id: ma SV)
        // %-18s: In chuoi can trai, do rong 18 (arr[i].name: ho ten)
        // %-6.2f: In so thuc can trai, do rong 6, 2 chu so thap phan (arr[i].score)
        printf("| %-3d | %-8s | %-18s | %-6.2f |\n",
               i + 1,        // So thu tu (bat dau tu 1)
               arr[i].id,    // Ma sinh vien
               arr[i].name,  // Ho ten
               arr[i].score  // Diem
        );
    }

    // In duong ke cuoi bang
    printf("|---|----------|--------------------|--------|\n");
}
