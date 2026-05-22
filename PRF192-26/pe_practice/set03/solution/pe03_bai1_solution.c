/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so sinh vien]
 * Mon:    PRF192 - Co so Lap trinh
 * PE Practice Set 03 - Bai 1 (Solution)
 * Ngay:   ___/___/2025
 *
 * ========================= GIAI THICH =========================
 * Bai toan: Xu ly chuoi ky tu
 *
 * Cac ky nang:
 *  1. Dem nguyen am (a, e, i, o, u, y) khong phan biet hoa thuong
 *  2. Dem phu am (ky tu chu cai khong phai nguyen am)
 *  3. Chuyen chuoi sang chu hoa KHONG DUNG <ctype.h>
 *     - Dung bang ma ASCII:
 *       'a'(97) -> 'A'(65), 'b'(98) -> 'B'(66), ...
 *       'a' - 'A' = 32. Vay: chu_hoa = chu_thuong - 32
 *  4. Kiem tra palindrome bo qua khoang trang, khong phan biet hoa thuong
 *     - Palindrome: doc xuoi doc nguoc deu giong nhau
 *     - VD: "Race car" -> bo qua khoang trang -> "racecar" -> palindrome
 * ========================= HET ================================
 */

#include <stdio.h>   // Thu vien nhap xuat: printf(), fgets()
#include <stdlib.h>  // Thu vien ham dung chung
#include <string.h>  // Thu vien xu ly chuoi: strlen(), strcspn()
#include <ctype.h>   // Thu vien xu ly ky tu: tolower(), toupper()

/* ===== PROTOTYPE ===== */
// Khai bao cac ham xu ly chuoi
int countVowels(char str[]);             // Dem so nguyen am
int countConsonants(char str[]);         // Dem so phu am
void toUpperCase(char str[]);            // Chuyen chuoi sang chu hoa (khong dung <ctype.h>)
int isPalindrome(char str[]);            // Kiem tra palindrome

/* ===== MAIN ===== */
int main() {
    // Khai bao mang str de luu chuoi nhap vao (toi da 200 ky tu)
    char str[201]; // +1 cho ky tu '\0' ket thuc chuoi

    // Nhap chuoi tu ban phim (co the chua khoang trang)
    printf("Nhap chuoi: ");
    // fgets: doc chuoi tu ban phim, giu lai khoang trang
    // str: mang luu chuoi, 201: kich thuoc toi da, stdin: ban phim
    fgets(str, 201, stdin);

    // Loai bo ky tu '\n' o cuoi chuoi (fgets giu lai '\n')
    // strcspn(str, "\n"): tra ve vi tri cua '\n' trong str
    // Thay '\n' bang '\0' (ky tu ket thuc chuoi)
    str[strcspn(str, "\n")] = '\0';

    // In chuoi vua nhap (co dau ngoac kep cho dep)
    printf("Chuoi vua nhap: \"%s\"\n", str);

    // Dem nguyen am: goi ham countVowels(str)
    int vowels = countVowels(str);
    printf("So nguyen am: %d\n", vowels);

    // Dem phu am: goi ham countConsonants(str)
    int consonants = countConsonants(str);
    printf("So phu am: %d\n", consonants);

    // Chuyen chuoi sang chu hoa (khong dung ctype.h)
    // Tao ban sao de khong lam mat chuoi goc
    char upperStr[201];         // Mang tam de luu chuoi in hoa
    strcpy(upperStr, str);      // Copy str vao upperStr
    toUpperCase(upperStr);      // Chuyen upperStr sang chu hoa
    printf("Chuoi in hoa: \"%s\"\n", upperStr);

    // Kiem tra palindrome
    if (isPalindrome(str)) {
        printf("\"%s\" LA palindrome\n", str);
    } else {
        printf("\"%s\" KHONG phai palindrome\n", str);
    }

    return 0; // Ket thuc chuong trinh
}

/* ===== IMPLEMENT ===== */

/*
 * Ham: countVowels
 * Cong dung: Dem so nguyen am trong chuoi
 *
 * Tham so: char str[] - chuoi can dem
 * Tra ve: int - so luong nguyen am
 *
 * Nguyen am: a, e, i, o, u, y (khong phan biet hoa thuong)
 * VD: "Hello World" -> e(1), o(2), o(3) -> 3
 *
 * Giai thuat: Duyet tung ky tu, chuyen ve thuong roi so sanh
 */
int countVowels(char str[]) {
    int count = 0; // Bien dem, khoi tao bang 0

    // Duyet tung ky tu cua chuoi
    // strlen(str): tra ve do dai chuoi (so ky tu)
    for (int i = 0; i < strlen(str); i++) {
        // Lay ky tu thu i va chuyen ve chu thuong
        // tolower(str[i]): chuyen str[i] ve chu thuong (neu la chu hoa)
        char c = tolower(str[i]); // c la ky tu thuong

        // Kiem tra c co phai nguyen am khong
        // So sanh c voi tung nguyen am: a, e, i, o, u, y
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            count++; // Tang bien dem len 1
        }
    }

    return count; // Tra ve so luong nguyen am
}

/*
 * Ham: countConsonants
 * Cong dung: Dem so phu am trong chuoi
 *
 * Tham so: char str[] - chuoi can dem
 * Tra ve: int - so luong phu am
 *
 * Phu am: ky tu chu cai KHONG phai nguyen am
 * VD: "Hello World" -> H(1), l(2), l(3), W(4), r(5), l(6), d(7) -> 7
 *
 * Giai thuat: Kiem tra tung ky tu, neu la chu cai va khong phai nguyen am -> phu am
 * isalpha(c): kiem tra c co phai chu cai khong (co trong <ctype.h>)
 */
int countConsonants(char str[]) {
    int count = 0; // Bien dem, khoi tao bang 0

    // Duyet tung ky tu cua chuoi
    for (int i = 0; i < strlen(str); i++) {
        // Chuyen ky tu ve chu thuong de kiem tra
        char c = tolower(str[i]);

        // Kiem tra: c co phai chu cai khong?
        // isalpha(c): tra ve != 0 neu c la chu cai (a-z, A-Z)
        if (isalpha(c)) {
            // Kiem tra c co phai nguyen am khong
            // Neu KHONG phai nguyen am -> la phu am
            if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')) {
                count++; // Tang bien dem len 1
            }
        }
    }

    return count; // Tra ve so luong phu am
}

/*
 * Ham: toUpperCase
 * Cong dung: Chuyen toan bo chuoi sang chu hoa
 * KHONG dung <ctype.h> (tu viet bang ma ASCII)
 *
 * Tham so: char str[] - chuoi can chuyen (thay doi truc tiep)
 *
 * Bang ma ASCII:
 *   'a' (97) -> 'A' (65): 'A' = 'a' - 32
 *   'b' (98) -> 'B' (66): 'B' = 'b' - 32
 *   ...
 *   'z' (122) -> 'Z' (90): 'Z' = 'z' - 32
 *
 * Vay: chu_hoa = chu_thuong - 32
 *   hoac: chu_hoa = chu_thuong - ('a' - 'A')
 *   ('a' - 'A' = 32)
 *
 * Chi chuyen khi ky tu nam trong 'a'..'z'
 */
void toUpperCase(char str[]) {
    // Duyet tung ky tu cua chuoi
    for (int i = 0; i < strlen(str); i++) {
        // Kiem tra str[i] co phai chu thuong khong
        // 'a' <= str[i] && str[i] <= 'z': ky tu nam trong khoang a-z
        if (str[i] >= 'a' && str[i] <= 'z') {
            // Chuyen sang chu hoa: tru di 32
            // 'a' - 'A' = 97 - 65 = 32
            str[i] = str[i] - ('a' - 'A');
            // Tuong duong: str[i] = str[i] - 32;
            // Tuong duong: str[i] = str[i] - 'a' + 'A';
            // 'a' + 0 = 'a', 'a' + 1 = 'b', ... 
            // str[i] - 'a' = vi tri trong bang chu cai (0-25)
            // + 'A' = ky tu hoa tuong ung
        }
        // Neu khong phai chu thuong: giu nguyen
    }
}

/*
 * Ham: isPalindrome
 * Cong dung: Kiem tra chuoi co doi xung (palindrome) hay khong
 *
 * Tham so: char str[] - chuoi can kiem tra
 * Tra ve: 1 (palindrome) hoac 0 (khong palindrome)
 *
 * Bo qua khoang trang va khong phan biet hoa thuong
 * VD: "Race car" -> bo qua khoang trang -> "racecar" -> palindrome
 *     "A man a plan a canal Panama" -> palindrome
 *
 * Giai thuat:
 *  - Tao chuoi "sach" (chi giu lai chu cai va chu so, bo qua khoang trang)
 *  - Chuyen tat ca ve chu thuong
 *  - Dung 2 con tro: left (dau) va right (cuoi)
 *  - So sanh: neu khong bang nhau -> khong palindrome
 */
int isPalindrome(char str[]) {
    // Buoc 1: Tao chuoi sach (chi giu lai chu cai, bo qua ky tu dac biet)
    char clean[201]; // Mang chua chuoi da loc
    int cleanLen = 0; // Do dai chuoi da loc

    // Duyet tung ky tu cua chuoi goc
    for (int i = 0; i < strlen(str); i++) {
        // isalpha(str[i]): kiem tra co phai chu cai khong
        // isdigit(str[i]): kiem tra co phai chu so khong
        // Neu la chu cai hoac chu so -> giu lai
        if (isalpha(str[i]) || isdigit(str[i])) {
            // Chuyen ve chu thuong va them vao chuoi sach
            clean[cleanLen] = tolower(str[i]); // Ky tu thuong
            cleanLen++; // Tang do dai
        }
        // Neu la khoang trang hoac ky tu dac biet: bo qua
    }
    clean[cleanLen] = '\0'; // Them ky tu ket thuc chuoi

    // Buoc 2: Kiem tra palindrome
    // left: con tro trai (bat dau tu dau chuoi)
    int left = 0;
    // right: con tro phai (bat dau tu cuoi chuoi)
    int right = cleanLen - 1;

    // So sanh cac ky tu tu ngoai vao trong
    // lap khi left < right (con gap nhau o giua)
    while (left < right) {
        // So sanh ky tu o left va right
        if (clean[left] != clean[right]) {
            return 0; // Khong bang nhau -> khong palindrome
        }
        left++;  // Di chuyen left sang phai
        right--; // Di chuyen right sang trai
    }

    // Da duyet het, tat ca deu bang nhau -> palindrome
    return 1; // Tra ve 1 (true)
}
