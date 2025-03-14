#include <iostream>
using namespace std;
void NhapMang(int a[], int& n)
{
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
}
void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
// 1. Sắp xếp nổi bọt 
void Sapxepnoibot(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
// 2. Sắp xếp chèn trực tiếp 
void Sapxepchentructiep(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int k = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > k)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }
}
// 3. Sắp xếp chọn trực tiếp 
void Sapxepchontructiep(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int vitrimin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[vitrimin])
            {
                vitrimin = j;
            }
        }
        swap(a[i], a[vitrimin]);
    }
}
// 4. Sắp xếp đổi chỗ trực tiếp 
void Sapxepdoichotructiep(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}
// Hàm sao chép mảng để tránh thay đổi dữ liệu gốc
void SaoChepMang(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}

int main()
{
    int a[100], b[100], n;
    NhapMang(a, n);

    // Thực hiện Sapxepnoibot
    SaoChepMang(a, b, n);
    Sapxepnoibot(b, n);
    cout << "Mang sau khi sap xep noi bot: ";
    XuatMang(b, n);

    // Thực hiện Sapxepchentructiep
    SaoChepMang(a, b, n);
    Sapxepchentructiep(b, n);
    cout << "Mang sau khi sap xep chen truc tiep: ";
    XuatMang(b, n);

    // Thực hiện Sapxepchontructiep
    SaoChepMang(a, b, n);
    Sapxepchontructiep(b, n);
    cout << "Mang sau khi sap xep chon truc tiep: ";
    XuatMang(b, n);

    // Thực hiện Sapxepdoichotructiep
    SaoChepMang(a, b, n);
    Sapxepdoichotructiep(b, n);
    cout << "Mang sau khi sap xep doi cho truc tiep: ";
    XuatMang(b, n);
    return 0;
}