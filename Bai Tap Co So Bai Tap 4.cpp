#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>  // Thư viện đo thời gian
using namespace std;
void hoandoi(int& a, int& b)
{
    int tam = a;
    a = b;
    b = tam;
}

// Interchange Sort (sắp xếp đổi chỗ trực tiếp)
void sapxepdoichotructiep(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                hoandoi(arr[i], arr[j]);
        }
    }
}

// Selection Sort (sắp xếp chọn trực tiếp)
void sapxepchontructiep(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int vitrinhonhat = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[vitrinhonhat])
                vitrinhonhat = j;
        }
        hoandoi(arr[i], arr[vitrinhonhat]);
    }
}

// Insertion Sort (sắp xếp chèn trực tiếp)
void sapxepchentructiep(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int giatrichen = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > giatrichen)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = giatrichen;
    }
}

// Bubble Sort (sắp xếp nổi bọt)
void sapxepnoibot(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                hoandoi(arr[j], arr[j + 1]);
        }
    }
}

// Quick Sort (sắp xếp nhanh) 
int chiamang(int arr[], int vitridau, int vitricuoi) // vì nó chia mảng thành 2 phần 
{
    int giatrichot = arr[vitricuoi];    // giá trị chốt để so sánh 
    int i = vitridau - 1;
    for (int j = vitridau; j < vitricuoi; j++)
    {
        if (arr[j] < giatrichot)
            hoandoi(arr[++i], arr[j]);
    }
    hoandoi(arr[i + 1], arr[vitricuoi]);
    return i + 1;
}
void sapxepnhanh(int arr[], int vitridau, int vitricuoi)
{
    if (vitridau < vitricuoi)
    {
        int vt = chiamang(arr, vitridau, vitricuoi); // trả về vị trí chính xác của giá trị chốt trong mảng đã được chia
        sapxepnhanh(arr, vitridau, vt - 1);
        sapxepnhanh(arr, vt + 1, vitricuoi);
    }
}

// Merge Sort (Sắp xếp trộn) 
void tronmang(int a[], int tam[], int dau, int giua, int cuoi)
{
    int i = dau, j = giua + 1, n = 0;

    while (i <= giua && j <= cuoi)
    {
        if (a[i] < a[j])
            tam[n++] = a[i++];

        else
            tam[n++] = a[j++];
    }
    while (i <= giua) tam[n++] = a[i++];
    while (j <= cuoi) tam[n++] = a[j++];
    for (int m = 0; m < n; m++)
        a[dau + m] = tam[m];
}
void trondequy(int a[], int tam[], int dau, int cuoi)
{
    if (dau < cuoi)
    {
        int giua = (dau + cuoi) / 2;
        trondequy(a, tam, dau, giua);
        trondequy(a, tam, giua + 1, cuoi);
        tronmang(a, tam, dau, giua, cuoi);
    }
}
void sapxeptron(int a[], int n)
{
    int* tam = new int[n];  // cấp phát mảng động 
    trondequy(a, tam, 0, n - 1);
    delete[] tam;
}
// Heap Sort (Sắp xếp cây) 
void dinhhinhcayheap(int arr[], int n, int i)
{
    int lonNhat = i;        // Gốc
    int trai = 2 * i + 1;   // Con trái
    int phai = 2 * i + 2;   // Con phải

    // Nếu con trái lớn hơn gốc
    if (trai < n && arr[trai] > arr[lonNhat])
    {
        lonNhat = trai;
    }

    // Nếu con phải lớn hơn gốc
    if (phai < n && arr[phai] > arr[lonNhat])
    {
        lonNhat = phai;
    }

    // Nếu gốc không phải lớn nhất, hoán đổi và tiếp tục vun đống
    if (lonNhat != i)
    {
        hoandoi(arr[i], arr[lonNhat]);
        dinhhinhcayheap(arr, n, lonNhat);
    }
}
void sapxepcay(int arr[], int n)
{
    // Bước 1: Xây dựng max heap (từ dưới lên)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        dinhhinhcayheap(arr, n, i);
    }

    // Bước 2: Trích xuất từng phần tử khỏi heap
    for (int i = n - 1; i > 0; i--)
    {
        hoandoi(arr[0], arr[i]); // Đưa phần tử lớn nhất về cuối
        dinhhinhcayheap(arr, i, 0);
    }
}
// Hàm đọc dữ liệu từ file
void docdulieu(int arr[], int& n, string filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        file >> n;
        for (int i = 0; i < n; i++) file >> arr[i];
        file.close();
    }
    else
    {
        cout << "Khong the mo file " << filename << endl;
    }
}
// Hàm ghi kết quả vào file
void ghiketqua(int arr[], int n, double thoigian, string filename)
{
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "Thoi gian: " << thoigian << " giay" << endl;
        file << "Mang sau khi sap xep: ";
        for (int i = 0; i < n; i++) file << arr[i] << " ";
        file << endl << "--------------------------" << endl;
        file.close();
    }
}
// Đo thời gian chạy của một thuật toán
double dothoigian(void (*sortFunc)(int[], int), int arr[], int n)
{
    double start = clock();  // Ép kiểu double để tránh lỗi
    sortFunc(arr, n);
    double end = clock();
    return (end - start) / CLOCKS_PER_SEC;
}

int main()
{
    int n;
    int arr[30000];

    // Đọc dữ liệu từ file TextFile2.txt
    docdulieu(arr, n, "TextFile2.txt");

    // Ghi kết quả vào file output.txt
    ofstream file("output.txt");
    file << "So luong phan tu: " << n << endl;
    file.close();

    // Đo thời gian của từng thuật toán
    int tempArr[30000];

    // Interchange Sort
    copy(arr, arr + n, tempArr);
    double timeInterchange = dothoigian(sapxepdoichotructiep, tempArr, n);
    ghiketqua(tempArr, n, timeInterchange, "output.txt");

    // Selection Sort
    copy(arr, arr + n, tempArr);
    double timeSelection = dothoigian(sapxepchontructiep, tempArr, n);
    ghiketqua(tempArr, n, timeSelection, "output.txt");

    // Insertion Sort
    copy(arr, arr + n, tempArr);
    double timeInsertion = dothoigian(sapxepchentructiep, tempArr, n);
    ghiketqua(tempArr, n, timeInsertion, "output.txt");

    // Bubble Sort
    copy(arr, arr + n, tempArr);
    double timeBubble = dothoigian(sapxepnoibot, tempArr, n);
    ghiketqua(tempArr, n, timeBubble, "output.txt");

    // Quick Sort
    copy(arr, arr + n, tempArr);
    double startQuick = clock();
    sapxepnhanh(tempArr, 0, n - 1);
    double endQuick = clock();
    double timeQuick = (endQuick - startQuick) / CLOCKS_PER_SEC;
    ghiketqua(tempArr, n, timeQuick, "output.txt");

    // Merge Sort
    copy(arr, arr + n, tempArr);
    double startMerge = clock();
    sapxeptron(tempArr, n);
    double endMerge = clock();
    double timeMerge = (endMerge - startMerge) / CLOCKS_PER_SEC;
    ghiketqua(tempArr, n, timeMerge, "output.txt");
    // Heap Sort
    copy(arr, arr + n, tempArr);
    double timeHeap = dothoigian(sapxepcay, tempArr, n);
    ghiketqua(tempArr, n, timeHeap, "output.txt");
    cout << "Ket qua da duoc ghi vao file output.txt" << endl;
    return 0;
}
