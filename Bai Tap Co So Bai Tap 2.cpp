#include <iostream>
using namespace std;

void HoanDoi(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Sắp xếp nhanh (Quick Sort)
int PhanHoach(int a[], int trai, int phai)
{
    int chot = a[phai]; // Chọn phần tử cuối làm pivot
    int i = trai - 1;
    for (int j = trai; j < phai; j++)
    {
        if (a[j] <= chot)
        {
            i++;
            HoanDoi(a[i], a[j]);
        }
    }
    HoanDoi(a[i + 1], a[phai]);
    return i + 1;
}

void SapXepNhanh(int a[], int trai, int phai)
{
    if (trai < phai)
    {
        int chot = PhanHoach(a, trai, phai);
        SapXepNhanh(a, trai, chot - 1);
        SapXepNhanh(a, chot + 1, phai);
    }
}

// Sắp xếp trộn (Merge Sort)
void Tron(int a[], int trai, int giua, int phai)
{
    int n1 = giua - trai + 1;
    int n2 = phai - giua;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = a[trai + i];
    for (int i = 0; i < n2; i++) R[i] = a[giua + 1 + i];

    int i = 0, j = 0, k = trai;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void SapXepTron(int a[], int trai, int phai)
{
    if (trai < phai)
    {
        int giua = trai + (phai - trai) / 2;
        SapXepTron(a, trai, giua);
        SapXepTron(a, giua + 1, phai);
        Tron(a, trai, giua, phai);
    }
}

// Sắp xếp cây (Heap Sort)
void CayXuoi(int a[], int n, int i)
{
    int lonNhat = i;
    int trai = 2 * i + 1;
    int phai = 2 * i + 2;
    if (trai < n && a[trai] > a[lonNhat]) lonNhat = trai;
    if (phai < n && a[phai] > a[lonNhat]) lonNhat = phai;
    if (lonNhat != i)
    {
        HoanDoi(a[i], a[lonNhat]);
        CayXuoi(a, n, lonNhat);
    }
}

void SapXepCay(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) CayXuoi(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        HoanDoi(a[0], a[i]);
        CayXuoi(a, i, 0);
    }
}

// HÀM NHẬP & XUẤT MẢNG 
void NhapMang(int a[], int& n)
{
    cout << "Nhập số lượng phần tử của mảng: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Phần tử thứ " << i + 1 << ": ";
        cin >> a[i];
    }
}

void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int a[100], b[100], c[100], n;
    NhapMang(a, n);
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
        c[i] = a[i];
    }

    SapXepNhanh(a, 0, n - 1);
    cout << "Mảng sau sắp xếp nhanh: ";
    XuatMang(a, n);

    SapXepTron(b, 0, n - 1);
    cout << "Mảng sau sắp xếp trộn: ";
    XuatMang(b, n);

    SapXepCay(c, n);
    cout << "Mảng sau sắp xếp cây: ";
    XuatMang(c, n);
    return 0;
}