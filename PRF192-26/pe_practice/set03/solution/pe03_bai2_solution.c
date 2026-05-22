/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so sinh vien]
 * Mon:    PRF192 - Co so Lap trinh
 * PE Practice Set 03 - Bai 2 (Solution)
 * Ngay:   ___/___/2025
 *
 * ========================= GIAI THICH =========================
 * Bai toan: Quan ly san pham su dung struct va file
 *
 * Kien thuc moi - FILE I/O:
 *  1. FILE *fp: con tro file
 *  2. fopen(filename, "wb"): mo file de ghi nhi phan
 *     "wb" = write binary
 *  3. fopen(filename, "rb"): mo file de doc nhi phan
 *     "rb" = read binary
 *  4. fwrite(&data, size, count, fp): ghi count phan tu,
 *     moi phan tu size byte, tu dia chi &data vao file fp
 *  5. fread(&data, size, count, fp): doc count phan tu,
 *     moi phan tu size byte, tu file fp vao dia chi &data
 *  6. fclose(fp): dong file
 *
 * fwrite voi mang struct:
 *   fwrite(arr, sizeof(Product), n, fp)
 *   - arr: dia chi dau mang
 *   - sizeof(Product): kich thuoc 1 struct Product
 *   - n: so luong phan tu can ghi
 *   - fp: con tro file
 *
 * fread voi mang struct:
 *   int count = fread(arr, sizeof(Product), 50, fp)
 *   Tra ve so phan tu thuc te da doc duoc
 * ========================= HET ================================
 */

#include <stdio.h>   // Thu vien nhap xuat: printf(), scanf(), fgets(), FILE,...
#include <stdlib.h>  // Thu vien ham dung chung
#include <string.h>  // Thu vien xu ly chuoi: strcpy(), strcspn()

/* ===== KHAI BAO STRUCT ===== */

/*
 * Dinh nghia kieu du lieu Product (san pham)
 * typedef: tu khoa dat ten cho kieu du lieu moi
 * struct: kieu du lieu co cau truc
 * Product: ten kieu du lieu (thay vi "struct Product")
 */
typedef struct {
    char code[10];     // Ma san pham: VD "SP001", "SP002"
    char name[50];     // Ten san pham: VD "Laptop Dell", "Chuot Logitech"
    int quantity;      // So luong: so nguyen (>= 0)
    double price;      // Don gia: so thuc (> 0)
} Product;

/* ===== PROTOTYPE ===== */
// Khai bao cac ham
void inputProduct(Product *p, int index);                              // Nhap san pham
void displayProducts(Product arr[], int n);                            // In danh sach
void saveToFile(Product arr[], int n, char filename[]);                // Ghi file
int loadFromFile(Product arr[], char filename[]);                      // Doc file
void searchByPrice(Product arr[], int n, double minPrice, double maxPrice); // Tim theo gia
double totalInventoryValue(Product arr[], int n);                      // Tong gia tri ton kho

/* ===== MAIN ===== */
int main() {
    int n; // Bien luu so luong san pham

    // Nhap so luong san pham
    printf("Nhap so luong san pham: ");
    scanf("%d", &n); // %d: doc so nguyen, &n: luu vao n

    // Khai bao mang arr Product toi da 50 phan tu
    Product arr[50];

    // Xoa bo nho dem sau scanf (de fgets khong bi loi)
    fflush(stdin); // Windows: xoa bo dem nhap

    // Vong lap nhap thong tin n san pham
    for (int i = 0; i < n; i++) {
        printf("\n--- Nhap san pham thu %d ---\n", i + 1);
        // Goi ham inputProduct, truyen dia chi cua arr[i]
        // &arr[i]: dia chi phan tu thu i
        // i: so thu tu (0-index)
        inputProduct(&arr[i], i);
    }

    // In danh sach san pham vua nhap
    printf("\n=== Danh sach san pham ===\n");
    displayProducts(arr, n);

    // Luu danh sach vao file nhi phan
    // "products.dat": ten file se tao ra
    saveToFile(arr, n, "products.dat");
    printf("\n=== Da luu vao file 'products.dat' ===\n");

    // Doc lai tu file de xac nhan
    Product loaded[50]; // Mang de luu du lieu doc tu file
    int loadedCount = loadFromFile(loaded, "products.dat"); // Doc file

    // In lai danh sach tu file
    printf("\n=== Doc lai tu file ===\n");
    displayProducts(loaded, loadedCount);

    // Tim kiem san pham theo khoang gia
    double minPrice, maxPrice; // Bien luu khoang gia can tim
    printf("\nNhap khoang gia (min max): ");
    scanf("%lf %lf", &minPrice, &maxPrice); // %lf: doc so thuc kieu double

    printf("\n=== San pham co don gia tu %.2f den %.2f ===\n",
           minPrice, maxPrice);
    searchByPrice(arr, n, minPrice, maxPrice); // Goi ham tim kiem

    // Tinh va in tong gia tri ton kho
    double total = totalInventoryValue(arr, n); // Goi ham tinh tong
    printf("\nTong gia tri ton kho: %.2f\n", total); // In voi 2 chu so thap phan

    return 0; // Ket thuc chuong trinh
}

/* ===== IMPLEMENT ===== */

/*
 * Ham: inputProduct
 * Cong dung: Nhap thong tin cho mot san pham
 *
 * Tham so:
 *  - Product *p: CON TRO toi Product can nhap
 *  - int index: so thu tu (bat dau tu 0)
 *
 * Su dung con tro *p de thay doi truc tiep struct ben ngoai ham
 * fgets: doc chuoi co khoang trang (ten san pham)
 * scanf: doc so nguyen (quantity) va so thuc (price)
 */
void inputProduct(Product *p, int index) {
    // Nhap ma san pham
    printf("  Ma SP: ");
    // fgets doc ca dong, bao gom ca khoang trang
    // p->code: truy cap thanh phan code cua struct thong qua con tro p
    // 10: kich thuoc toi da, stdin: ban phim
    fgets(p->code, 10, stdin);
    // Xoa ky tu '\n' o cuoi chuoi (do fgets giu lai)
    // strcspn(p->code, "\n"): tim vi tri cua '\n'
    p->code[strcspn(p->code, "\n")] = '\0';

    // Nhap ten san pham
    printf("  Ten san pham: ");
    fgets(p->name, 50, stdin); // Doc chuoi (co khoang trang)
    p->name[strcspn(p->name, "\n")] = '\0'; // Xoa '\n'

    // Nhap so luong
    printf("  So luong: ");
    // %d: doc so nguyen, &p->quantity: dia chi cua quantity
    scanf("%d", &p->quantity);

    // Nhap don gia
    printf("  Don gia: ");
    // %lf: doc so thuc double, &p->price: dia chi cua price
    scanf("%lf", &p->price);

    // Xoa bo nho dem sau scanf (cho lan fgets tiep theo)
    fflush(stdin);
}

/*
 * Ham: displayProducts
 * Cong dung: In danh sach san pham dang bang can le
 *
 * Tham so:
 *  - Product arr[]: mang san pham can in
 *  - int n: so luong san pham
 *
 * Dinh dang printf:
 *  - %-10s: chuoi can trai, do rong 10
 *  - %8d: so nguyen can phai, do rong 8
 *  - %10.2f: so thuc can phai, do rong 10, 2 so thap phan
 */
void displayProducts(Product arr[], int n) {
    // In duong ke tren bang
    // Cac dau "|---" tao duong ke ngang
    printf("|---|----------|---------------------|----------|----------|\n");

    // In tieu de cot
    // %-5s: STT (can trai, rong 5)
    // %-10s: Ma SP (can trai, rong 10)
    // %-20s: Ten san pham (can trai, rong 20)
    // %-10s: So luong (can trai, rong 10)
    // %-10s: Don gia (can trai, rong 10)
    printf("| %-3s | %-8s | %-19s | %-8s | %-8s |\n",
           "STT", "Ma SP", "Ten san pham", "So luong", "Don gia");

    // In duong ke
    printf("|---|----------|---------------------|----------|----------|\n");

    // Vong lap in tung san pham
    for (int i = 0; i < n; i++) {
        // In mot dong san pham
        // %-3d: STT can trai, rong 3
        // %-8s: ma SP can trai, rong 8
        // %-19s: ten can trai, rong 19
        // %8d: so luong can PHAI, rong 8
        // %8.2f: don gia can PHAI, rong 8, 2 so thap phan
        printf("| %-3d | %-8s | %-19s | %8d | %8.2f |\n",
               i + 1,            // STT (tu 1)
               arr[i].code,      // Ma san pham
               arr[i].name,      // Ten san pham
               arr[i].quantity,  // So luong
               arr[i].price      // Don gia
        );
    }

    // In duong ke cuoi
    printf("|---|----------|---------------------|----------|----------|\n");
}

/*
 * Ham: saveToFile
 * Cong dung: Ghi danh sach san pham vao file nhi phan
 *
 * Tham so:
 *  - Product arr[]: mang san pham can ghi
 *  - int n: so luong san pham
 *  - char filename[]: ten file (vd "products.dat")
 *
 * fwrite(addr, size, count, fp):
 *  - addr: dia chi bat dau ghi
 *  - size: kich thuoc 1 phan tu (byte)
 *  - count: so phan tu can ghi
 *  - fp: con tro file
 *
 * "wb": write binary - mo file de ghi nhi phan
 */
void saveToFile(Product arr[], int n, char filename[]) {
    // Mo file de ghi nhi phan
    // fopen: mo file, tra ve con tro FILE*
    // "wb": write binary (ghi nhi phan)
    // filename: ten file can mo
    FILE *fp = fopen(filename, "wb");

    // Kiem tra mo file co thanh cong khong
    if (fp == NULL) {
        // fopen tra ve NULL neu that bai
        printf("Loi mo file %s de ghi!\n", filename);
        return; // Thoat ham
    }

    // Ghi mang struct vao file
    // fwrite( arr, sizeof(Product), n, fp )
    // - arr: dia chi mang (dau tien)
    // - sizeof(Product): kich thuoc 1 Product (byte)
    // - n: so luong Product can ghi
    // - fp: con tro file
    fwrite(arr, sizeof(Product), n, fp);

    // Dong file
    // fclose(fp): dong file, dam bao du lieu duoc ghi het
    fclose(fp);
}

/*
 * Ham: loadFromFile
 * Cong dung: Doc danh sach san pham tu file nhi phan
 *
 * Tham so:
 *  - Product arr[]: mang de luu du lieu doc duoc
 *  - char filename[]: ten file can doc
 *
 * Tra ve: int - so luong san pham doc duoc
 *
 * fread(addr, size, maxCount, fp):
 *  - addr: dia chi bat dau luu
 *  - size: kich thuoc 1 phan tu
 *  - maxCount: so phan tu toi da can doc
 *  - fp: con tro file
 *  - Tra ve: so phan tu THUC TE doc duoc
 *
 * "rb": read binary - mo file de doc nhi phan
 */
int loadFromFile(Product arr[], char filename[]) {
    // Mo file de doc nhi phan
    // "rb": read binary (doc nhi phan)
    FILE *fp = fopen(filename, "rb");

    // Kiem tra mo file co thanh cong khong
    if (fp == NULL) {
        printf("Loi mo file %s de doc!\n", filename);
        return 0; // Tra ve 0 (khong doc duoc san pham nao)
    }

    // Doc du lieu tu file vao mang
    // fread tra ve so phan tu thuc te da doc
    // - arr: mang de luu du lieu
    // - sizeof(Product): kich thuoc 1 Product
    // - 50: so phan tu toi da (kich thuoc mang)
    // - fp: con tro file
    int count = fread(arr, sizeof(Product), 50, fp);

    // Dong file
    fclose(fp);

    // Tra ve so luong san pham da doc
    return count;
}

/*
 * Ham: searchByPrice
 * Cong dung: Tim va in cac san pham co don gia trong doan [minPrice, maxPrice]
 *
 * Tham so:
 *  - Product arr[]: mang san pham can tim
 *  - int n: so luong san pham
 *  - double minPrice, maxPrice: khoang gia can tim
 */
void searchByPrice(Product arr[], int n, double minPrice, double maxPrice) {
    // Mang tam de luu ket qua tim duoc
    Product result[50];
    int count = 0; // Dem so san pham tim duoc

    // Duyet qua tung san pham trong mang
    for (int i = 0; i < n; i++) {
        // Kiem tra don gia co nam trong khoang [minPrice, maxPrice]
        // arr[i].price >= minPrice: lon hon hoac bang min
        // arr[i].price <= maxPrice: nho hon hoac bang max
        if (arr[i].price >= minPrice && arr[i].price <= maxPrice) {
            // Tim thay: them vao mang ket qua
            result[count] = arr[i]; // Gan nguyen struct
            count++;                // Tang so dem
        }
    }

    // In ket qua
    if (count > 0) {
        // Neu co it nhat 1 san pham: in bang
        displayProducts(result, count);
    } else {
        // Khong tim thay: in thong bao
        printf("Khong tim thay san pham phu hop.\n");
    }
}

/*
 * Ham: totalInventoryValue
 * Cong dung: Tinh tong gia tri ton kho
 *
 * Tham so:
 *  - Product arr[]: mang san pham
 *  - int n: so luong san pham
 *
 * Tra ve: double - tong gia tri (so_luong * don_gia)
 *
 * Cong thuc: total = SUM(quantity * price) voi moi san pham
 */
double totalInventoryValue(Product arr[], int n) {
    double total = 0.0; // Bien luu tong, khoi tao bang 0

    // Duyet qua tung san pham
    for (int i = 0; i < n; i++) {
        // Cong don: so_luong * don_gia
        // arr[i].quantity: so luong (int)
        // arr[i].price: don gia (double)
        // Ep kieu: quantity tu int thanh double truoc khi nhan
        total += (double)arr[i].quantity * arr[i].price;
    }

    return total; // Tra ve tong gia tri
}
