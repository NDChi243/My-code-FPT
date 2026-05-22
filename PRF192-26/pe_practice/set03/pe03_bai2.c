/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so sinh vien]
 * Mon:    PRF192 - Co so Lap trinh
 * PE Practice Set 03 - Bai 2
 * Ngay:   ___/___/2025
 *
 * ========================= DE BAI =========================
 * Viet chuong trinh quan ly san pham su dung struct va file.
 *
 * 1.  Khai bao struct Product gom:
 *     - code:     char[10]    (ma san pham)
 *     - name:     char[50]    (ten san pham)
 *     - quantity: int         (so luong)
 *     - price:    double      (don gia)
 *
 * 2.  Viet cac ham sau:
 *
 *     a) void inputProduct(Product *p, int index)
 *        - Nhap thong tin cho san pham thu index+1
 *        - Doc ma, ten (co khoang trang), so luong (>=0),
 *          don gia (>0)
 *
 *     b) void displayProducts(Product arr[], int n)
 *        - In danh sach dang bang:
 *          "|---|----------|---------------------|----------|----------|"
 *          "|STT|  Ma SP   |   Ten san pham      | So luong | Don gia  |"
 *          "|---|----------|---------------------|----------|----------|"
 *          "| 1 |  SP001   |  Laptop Dell        |   10     | 15000.00 |"
 *          "|---|----------|---------------------|----------|----------|"
 *
 *     c) void saveToFile(Product arr[], int n, char filename[])
 *        - Ghi danh sach san pham vao file nhi phan "products.dat"
 *        - Dung fwrite de ghi
 *
 *     d) int loadFromFile(Product arr[], char filename[])
 *        - Doc danh sach san pham tu file "products.dat"
 *        - Tra ve so luong san pham doc duoc
 *        - Dung fread de doc
 *
 *     e) void searchByPrice(Product arr[], int n,
 *                           double minPrice, double maxPrice)
 *        - Tim va in cac san pham co don gia trong doan
 *          [minPrice, maxPrice]
 *        - Neu khong co, in "Khong tim thay san pham phu hop."
 *
 *     f) double totalInventoryValue(Product arr[], int n)
 *        - Tinh tong gia tri ton kho (so luong * don gia)
 *        - Tra ve tong gia tri
 *
 * 3.  Trong ham main():
 *     - Nhap so luong san pham n (1 <= n <= 50)
 *     - Nhap thong tin n san pham
 *     - In danh sach vua nhap
 *     - Luu danh sach vao file "products.dat"
 *     - Doc lai tu file va in ra de xac nhan
 *     - Nhap khoang gia min, max de tim kiem
 *     - In ra tong gia tri ton kho
 *
 * ================ INPUT MAU & OUTPUT MAU =================
 * Input:
 *   3
 *   SP001
 *   Laptop Dell
 *   10
 *   15000.00
 *   SP002
 *   Chuot Logitech
 *   50
 *   250.00
 *   SP003
 *   Ban phim co
 *   30
 *   850.00
 *   200 1000
 *
 * Output:
 *   === Danh sach san pham ===
 *   |---|----------|---------------------|----------|----------|
 *   |STT|  Ma SP   |   Ten san pham      | So luong | Don gia  |
 *   |---|----------|---------------------|----------|----------|
 *   | 1 |  SP001   |  Laptop Dell        |   10     | 15000.00 |
 *   | 2 |  SP002   |  Chuot Logitech     |   50     | 250.00   |
 *   | 3 |  SP003   |  Ban phim co        |   30     | 850.00   |
 *   |---|----------|---------------------|----------|----------|
 *
 *   === Da luu vao file 'products.dat' ===
 *   === Doc lai tu file ===
 *   (In lai giong bang tren)
 *
 *   === San pham co don gia tu 200.00 den 1000.00 ===
 *   |---|----------|---------------------|----------|----------|
 *   |STT|  Ma SP   |   Ten san pham      | So luong | Don gia  |
 *   |---|----------|---------------------|----------|----------|
 *   | 1 |  SP002   |  Chuot Logitech     |   50     | 250.00   |
 *   | 2 |  SP003   |  Ban phim co        |   30     | 850.00   |
 *   |---|----------|---------------------|----------|----------|
 *
 *   Tong gia tri ton kho: 188500.00
 * ========================= END ===========================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ===== PROTOTYPE ===== */


/* ===== MAIN ===== */
int main() {

    return 0;
}

/* ===== IMPLEMENT ===== */
