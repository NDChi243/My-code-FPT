/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so sinh vien]
 * Mon:    PRF192 - Co so Lap trinh
 * PE Practice Set 01 - Bai 1 (Solution)
 * Ngay:   ___/___/2025
 *
 * ========================= GIAI THICH =========================
 * Bai toan: Phan tich so nguyen n thanh thua so nguyen to
 *
 * Y tuong:
 *  - So nguyen to la so > 1, chi chia het cho 1 va chinh no
 *  - De phan tich thua so: chia n cho cac so nguyen to tu 2 tro len
 *  - Khi n chia het cho i (i la so nguyen to) thi i la thua so
 *  - Tiep tuc chia n cho i den khi khong chia het nua, roi tang i len
 *
 * Vi du: n = 60
 *  60 / 2 = 30  -> thua so 2
 *  30 / 2 = 15  -> thua so 2
 *  15 / 3 = 5   -> thua so 3
 *  5 khong chia het cho 4, chia 5 -> thua so 5
 *  => 60 = 2 * 2 * 3 * 5
 * ========================= HET ================================
 */

#include <stdio.h>   // Thu vien nhap xuat chuan: scanf(), printf()
#include <stdlib.h>  // Thu vien ham dung chung: NULL, malloc,...
#include <math.h>    // Thu vien toan hoc: sqrt() de kiem tra so nguyen to

/* ===== PROTOTYPE ===== */
// Khai bao truoc nguyen mau ham de C biet ten ham, kieu tra ve, tham so
int isPrime(int n);            // Kiem tra n co phai so nguyen to?
void printPrimeFactors(int n); // Phan tich n thanh thua so nguyen to

/* ===== MAIN ===== */
int main() {
    // Khai bao bien n de luu so nguyen can phan tich
    int n;

    // In ra man hinh yeu cau nguoi dung nhap (khong co trong de nhung nen lam)
    printf("Nhap n: ");
    // scanf: doc du lieu tu ban phim
    // "%d" : dinh dang so nguyen (decimal integer)
    // &n   : dia chi cua bien n (de luu gia tri nhap vao)
    scanf("%d", &n);

    // Goi ham printPrimeFactors de phan tich n thanh thua so nguyen to
    // Ham nay se xu ly viec tinh toan va in ket qua
    printPrimeFactors(n);

    return 0; // Ket thuc chuong trinh, tra ve 0 cho he dieu hanh
}

/* ===== IMPLEMENT ===== */

/*
 * Ham: isPrime
 * Cong dung: Kiem tra xem n co phai la so nguyen to hay khong
 *
 * Tham so:
 *  - int n: so nguyen can kiem tra
 *
 * Gia tri tra ve:
 *  - 1 (true)  : neu n la so nguyen to
 *  - 0 (false) : neu n khong phai so nguyen to
 *
 * Giai thuat:
 *  - So nguyen to la so tu nhien > 1, chi chia het cho 1 va chinh no
 *  - Neu n <= 1 -> khong phai so nguyen to
 *  - Duyet i tu 2 den sqrt(n): neu n % i == 0 -> n co uoc khac 1 va n -> khong nguyen to
 *  - Chi can duyet den sqrt(n) vi neu n = a*b va a <= b thi a <= sqrt(n)
 */
int isPrime(int n) {
    // Buoc 1: Loai cac so <= 1 (0, 1, so am) - chung khong phai so nguyen to
    if (n <= 1) {
        return 0; // Tra ve 0 (false) - khong phai so nguyen to
    }

    // Buoc 2: Duyet tu 2 den can bac hai cua n
    // sqrt(n) tra ve kieu double, can ep ve int de so sanh
    // i = 2: bat dau tu so nguyen to dau tien
    // i <= sqrt(n): chi can kiem tra den can bac hai
    // i++: tang i len 1 sau moi vong lap
    for (int i = 2; i <= sqrt(n); i++) {
        // Neu n chia het cho i (n % i == 0)
        // => i la uoc so cua n, va i khac 1 va khac n
        // => n khong phai so nguyen to
        if (n % i == 0) {
            return 0; // Tra ve 0 (false) - khong phai so nguyen to
        }
    }

    // Neu da duyet het ma khong tim thay uoc so nao
    // => n la so nguyen to
    return 1; // Tra ve 1 (true) - la so nguyen to
}

/*
 * Ham: printPrimeFactors
 * Cong dung: Phan tich so n thanh thua so nguyen to va in ra
 *
 * Tham so:
 *  - int n: so nguyen can phan tich
 *
 * Gia tri tra ve: khong co (void)
 *
 * Giai thuat:
 *  - In ra "n = "
 *  - Duyet i tu 2 den n: neu i la so nguyen to va n chia het cho i
 *    -> in i, chia n cho i (n /= i)
 *    -> tiep tuc kiem tra i co con chia duoc nua khong
 *  - Lap lai cho den khi n = 1
 *
 * Vi du: n = 60
 *  i=2: isPrime(2)=true, 60%2=0 -> in "2", n=30
 *  i=2: 30%2=0 -> in " * 2", n=15
 *  i=2: 15%2!=0 -> bo qua
 *  i=3: isPrime(3)=true, 15%3=0 -> in " * 3", n=5
 *  i=3: 5%3!=0 -> bo qua
 *  i=4: isPrime(4)=false -> bo qua
 *  i=5: isPrime(5)=true, 5%5=0 -> in " * 5", n=1
 *  n=1 -> ket thuc
 *  => "60 = 2 * 2 * 3 * 5"
 */
void printPrimeFactors(int n) {
    // In ra phan dau cua dong ket qua: "n = "
    // %d la dinh dang de in so nguyen, thay bang gia tri cua n
    printf("%d = ", n);

    // Dung bien tam m de thao tac, giu nguyen n ban dau
    // (Neu khong, n se bi thay doi va khong in dung "n = ...")
    int m = n;

    // Khai bao bien flag de danh dau thua so dau tien
    // Su dung de in " * " cho cac thua so thu 2 tro di
    // first = 1: thua so tiep theo la thua so dau tien
    int first = 1;

    // Duyet i tu 2 den m de tim thua so nguyen to
    // i <= m: con so can phan tich
    // i++: tang i len 1
    for (int i = 2; i <= m; i++) {
        // Kiem tra: i co phai so nguyen to? VA m co chia het cho i?
        // isPrime(i) goi ham kiem tra so nguyen to da viet o tren
        // m % i == 0 kiem tra m chia het cho i
        if (isPrime(i) && m % i == 0) {
            // Neu i la uoc so nguyen to cua m
            // Vong lap while de chia m cho i nhieu lan (vi du: 60 / 2 / 2)
            while (m % i == 0) {
                // Kiem tra co phai thua so dau tien khong?
                if (first) {
                    // Neu la thua so dau tien: chi in so i
                    printf("%d", i);
                    first = 0; // Danh dau da in thua so dau tien
                } else {
                    // Neu khong phai thua so dau tien: in " * i"
                    // " * " la dau nhan giua cac thua so
                    printf(" * %d", i);
                }
                // Chia m cho i (da lay duoc thua so i)
                // Vi du: m=60, i=2 -> m=30
                // Tiep tuc vong while: m=30, i=2 -> m=15 (dung)
                m = m / i;
            }
        }
    }

    // Xuong dong sau khi in xong
    printf("\n");
}
