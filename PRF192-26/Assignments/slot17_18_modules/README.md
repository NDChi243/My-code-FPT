# Slot 17-18 — Bài tập: Module (tiếp)

## Bài 1: Phân tích bài toán Quản lý điểm (grade_manager.c)
Viết chương trình in ra sơ đồ phân rã bài toán "Quản lý điểm sinh viên" gồm các module:
1. Nhập thông tin sinh viên
2. Nhập điểm từng môn
3. Tính điểm trung bình
4. Xếp loại học lực
5. In bảng điểm

**Yêu cầu:** Mỗi module là một hàm riêng. Hàm `main()` chỉ gọi các hàm con.

---

## Bài 2: Cohesion cao - coupling thấp (high_cohesion.c)
Viết chương trình quản lý đơn giản với 3 hàm:
- `nhapMang(int arr[], int *n)`: Nhập số lượng và từng phần tử
- `tinhTong(int arr[], int n)`: Tính tổng mảng
- `inMang(int arr[], int n)`: In mảng ra màn hình

**Yêu cầu:** Mỗi hàm chỉ làm một việc duy nhất. `main()` gọi các hàm theo trình tự.

---

## Bài 3: Kiểm tra số hoàn hảo (perfect_number.c)
Viết chương trình gồm các hàm:
- `int laSoHoanHao(int n)`: Kiểm tra `n` có phải số hoàn hảo? (tổng ước số = `n`, VD: 6=1+2+3)
- `void inSoHoanHaoTrongDoan(int a, int b)`: In các số hoàn hảo trong `[a, b]`

Nhập `a, b` từ bàn phím. Gọi hàm `inSoHoanHaoTrongDoan()`.
