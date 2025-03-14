#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10000 
using namespace std;

void HoanDoi(int& a, int& b)
{
    int tam = a;
    a = b;
    b = tam;
}

void TaoMangNgauNhien(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10000;
    }
}

// 1. Sắp xếp đổi chỗ trực tiếp
void SapXepDoiCho(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                HoanDoi(a[i], a[j]);
            }
        }
    }
}

// 2. Sắp xếp chọn trực tiếp
void SapXepChon(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        HoanDoi(a[i], a[minIndex]);
    }
}

// 3. Sắp xếp chèn trực tiếp
void SapXepChen(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int tam = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > tam)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tam;
    }
}

// 4. Sắp xếp nổi bọt
void SapXepNoiBot(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                HoanDoi(a[j], a[j + 1]);
            }
        }
    }
}

// **5. Sắp xếp nhanh (Quick Sort)**
int ChiaMang(int a[], int trai, int phai)
{
    int chot = a[phai];
    int i = trai - 1;
    for (int j = trai; j < phai; j++)
    {
        if (a[j] < chot)
        {
            i++;
            HoanDoi(a[i], a[j]);
        }
    }
    HoanDoi(a[i + 1], a[phai]);
    return (i + 1);
}

void SapXepNhanh(int a[], int trai, int phai)
{
    if (trai < phai)
    {
        int pi = ChiaMang(a, trai, phai);
        SapXepNhanh(a, trai, pi - 1);
        SapXepNhanh(a, pi + 1, phai);
    }
}

// 6. Sắp xếp trộn trực tiếp (Merge Sort)
void TronMang(int a[], int trai, int giua, int phai)
{
    int n1 = giua - trai + 1;
    int n2 = phai - giua;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[trai + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[giua + 1 + i];
    int i = 0, j = 0, k = trai;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
}

void SapXepTron(int a[], int trai, int phai)
{
    if (trai < phai)
    {
        int giua = trai + (phai - trai) / 2;
        SapXepTron(a, trai, giua);
        SapXepTron(a, giua + 1, phai);
        TronMang(a, trai, giua, phai);
    }
}

// 7. Sắp xếp cây (Heap Sort)
void XuLyHeap(int a[], int n, int i)
{
    int lonNhat = i;
    int trai = 2 * i + 1;
    int phai = 2 * i + 2;
    if (trai < n && a[trai] > a[lonNhat])
        lonNhat = trai;
    if (phai < n && a[phai] > a[lonNhat])
        lonNhat = phai;
    if (lonNhat != i)
    {
        HoanDoi(a[i], a[lonNhat]);
        XuLyHeap(a, n, lonNhat);
    }
}

void SapXepCay(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        XuLyHeap(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        HoanDoi(a[0], a[i]);
        XuLyHeap(a, i, 0);
    }
}

void InMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    srand(time(0));
    int n;
    cout << "Nhập số phần tử của mảng: ";
    cin >> n;
    int a[MAX], tam[MAX];

    TaoMangNgauNhien(a, n);
    copy(a, a + n, tam);
    cout << "Mảng ban đầu: ";
    InMang(a, n);

    copy(tam, tam + n, a);
    SapXepDoiCho(a, n);
    cout << "Sắp xếp đổi chỗ: ";
    InMang(a, n);

    copy(tam, tam + n, a);
    SapXepChon(a, n);
    cout << "Sắp xếp chọn: ";
    InMang(a, n);

    copy(tam, tam + n, a);
    SapXepChen(a, n);
    cout << "Sắp xếp chèn: ";
    InMang(a, n);

    copy(tam, tam + n, a);
    SapXepNoiBot(a, n);
    cout << "Sắp xếp nổi bọt: ";
    InMang(a, n);

    copy(tam, tam + n, a);
    SapXepNhanh(a, 0, n - 1);
    cout << "Sắp xếp nhanh: ";
    InMang(a, n);

    copy(tam, tam + n, a);
    SapXepTron(a, 0, n - 1);
    cout << "Sắp xếp trộn: ";
    InMang(a, n);

    copy(tam, tam + n, a);
    SapXepCay(a, n);
    cout << "Sắp xếp cây: ";
    InMang(a, n);
    return 0;
}