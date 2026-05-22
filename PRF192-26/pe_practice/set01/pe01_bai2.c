/*
 * Ho ten: [Ten ban]
 * MSSV:   [Ma so sinh vien]
 * Mon:    PRF192 - Co so Lap trinh
 * PE Practice Set 01 - Bai 2
 * Ngay:   ___/___/2025
 *
 * ========================= DE BAI =========================
 * Viet chuong trinh quan ly danh sach sinh vien.
 *
 * 1.  Khai bao struct Student gom:
 *     - id:     char[10]   (ma sinh vien)
 *     - name:   char[50]   (ho ten)
 *     - score:  float      (diem tong ket)
 *
 * 2.  Viet cac ham sau:
 *     a) void inputStudent(Student *s, int index)
 *        - Nhap thong tin cho sinh vien thu index+1
 *        - Doc ma so, ho ten (co the co khoang trang),
 *          va diem so (0 <= score <= 10)
 *
 *     b) void sortByScore(Student arr[], int n)
 *        - Sap xep mang sinh vien theo diem giam dan
 *          (su dung thuat toan Bubble Sort hoac Selection Sort)
 *
 *     c) void searchByName(Student arr[], int n, char keyword[])
 *        - Tim va in ra sinh vien co ho ten chua keyword
 *        (khong phan biet hoa thuong)
 *        - Neu khong tim thay, in "Khong tim thay sinh vien!"
 *
 *     d) void displayStudents(Student arr[], int n)
 *        - In danh sach sinh vien dang bang, can le:
 *          "|---|----------|--------------------|--------|"
 *          "|STT|  Ma SV   |     Ho ten         |  Diem  |"
 *          "|---|----------|--------------------|--------|"
 *          "| 1 |  SE0001  |  Nguyen Van A      |  9.50  |"
 *          "| 2 |  SE0002  |  Tran Thi B        |  8.75  |"
 *          "|---|----------|--------------------|--------|"
 *
 * 3.  Trong ham main():
 *     - Nhap so luong sinh vien n (1 <= n <= 100)
 *     - Nhap thong tin n sinh vien (ham inputStudent)
 *     - In danh sach vua nhap
 *     - Sap xep theo diem giam dan va in lai
 *     - Nhap mot tu khoa, tim kiem va in ket qua
 *
 * ================ INPUT MAU & OUTPUT MAU =================
 * Input:
 *   3
 *   SE001
 *   Nguyen Van A
 *   9.5
 *   SE002
 *   Tran Thi B
 *   7.8
 *   SE003
 *   Le Van C
 *   8.2
 *   van
 *
 * Output:
 *   === Danh sach sinh vien ===
 *   |---|----------|--------------------|--------|
 *   |STT|  Ma SV   |     Ho ten         |  Diem  |
 *   |---|----------|--------------------|--------|
 *   | 1 |  SE001   |  Nguyen Van A      |  9.50  |
 *   | 2 |  SE002   |  Tran Thi B        |  7.80  |
 *   | 3 |  SE003   |  Le Van C          |  8.20  |
 *   |---|----------|--------------------|--------|
 *
 *   === Sau khi sap xep theo diem giam dan ===
 *   |---|----------|--------------------|--------|
 *   |STT|  Ma SV   |     Ho ten         |  Diem  |
 *   |---|----------|--------------------|--------|
 *   | 1 |  SE001   |  Nguyen Van A      |  9.50  |
 *   | 2 |  SE003   |  Le Van C          |  8.20  |
 *   | 3 |  SE002   |  Tran Thi B        |  7.80  |
 *   |---|----------|--------------------|--------|
 *
 *   === Ket qua tim kiem tu khoa: "van" ===
 *   |---|----------|--------------------|--------|
 *   |STT|  Ma SV   |     Ho ten         |  Diem  |
 *   |---|----------|--------------------|--------|
 *   | 1 |  SE001   |  Nguyen Van A      |  9.50  |
 *   | 2 |  SE003   |  Le Van C          |  8.20  |
 *   |---|----------|--------------------|--------|
 * ========================= END ===========================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ===== PROTOTYPE ===== */


/* ===== MAIN ===== */
int main() {

    return 0;
}

/* ===== IMPLEMENT ===== */
