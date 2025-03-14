#include <iostream>
#include <cmath>
using namespace std;
// Định nghĩa cấu trúc dữ liệu cho một số hạng trong dãy thức bậc n
struct Sohang 
{
    double heso;  // Hệ số (số thực)
    int bac;      // Bậc (số nguyên từ 0 đến 100)
};

// Hoán đổi hai số hạng trong mảng
void hoandoi(Sohang& a, Sohang& b) 
{
    Sohang tam = a;
    a = b;
    b = tam;
}
// Sắp xếp các số hạng theo thứ tự tăng dần của bậc (dùng Interchange Sort)
void sapxep(Sohang arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i].bac > arr[j].bac) 
                hoandoi(arr[i], arr[j]);
        }
    }
}
// Hàm hiển thị dãy thức bậc n
void hienthi(Sohang arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i].heso << "x^" << arr[i].bac;
        if (i < n - 1) cout << " + ";
    }
    cout << endl;
}
int main() 
{
    int n;
    cout << "Nhap so luong so hang: ";
    cin >> n;
    Sohang daThuc[100]; 
    // Nhập hệ số và bậc cho từng số hạng
    for (int i = 0; i < n; i++) 
    {
        cout << "Nhap he so va bac cua so hang thu " << i + 1 << " (vd: 3.5 2): ";
        cin >> daThuc[i].heso >> daThuc[i].bac;
    }
    // Sắp xếp theo thứ tự tăng dần của bậc
    sapxep(daThuc, n);
    // Hiển thị kết quả sau khi sắp xếp
    cout << "\nDa thuc sau khi sap xep: ";
    hienthi(daThuc, n);
    return 0;
}
