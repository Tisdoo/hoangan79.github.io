#include <iostream>
#include <cmath>
using namespace std;
// Hàm tính tổng chữ số của một số nguyên
int tong(int n) 
{
    int s = 0;
    n = abs(n); // Xử lý cả số âm
    while (n > 0) 
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

// Hàm kiểm tra số nguyên tố
int snt(int n) 
{
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) 
    {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Hàm tìm vị trí k phần tử lớn nhất
void timvitriklonnhat(int arr[], int n, int k) 
{
    if (k > n) 
    {
        cout << "k khong duoc lon hon n!" << endl;
        return;
    }
    int* maxgiatri = new int[k];
    int* maxvitri = new int[k];
    // Khởi tạo mảng maxgiatri với giá trị rất nhỏ
    for (int i = 0; i < k; i++) 
    {
        maxgiatri[i] = -1000000000;
        maxvitri[i] = -1;
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < k; j++) 
        {
            if (arr[i] > maxgiatri[j]) 
            {
                // Dịch các giá trị nhỏ hơn sang phải
                for (int l = k - 1; l > j; l--) 
                {
                    maxgiatri[l] = maxgiatri[l - 1];
                    maxvitri[l] = maxvitri[l - 1];
                }
                maxgiatri[j] = arr[i];
                maxvitri[j] = i;
                break;
            }
        }
    }

    cout << "Vi tri cua " << k << " phan tu lon nhat: ";
    for (int i = 0; i < k; i++) 
    {
        cout << maxvitri[i] << " ";
    }
    cout << endl;

    delete[] maxgiatri;  
    delete[] maxvitri;   
}

// Hàm sắp xếp mảng theo tổng chữ số tăng dần (Bubble Sort)
void sapxeptheotongchuso(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (tong(arr[j]) > tong(arr[j + 1])) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Hàm xóa số nguyên tố khỏi mảng
int xoasnt(int arr[], int n) 
{
    int kichthuocmoi = 0;
    for (int i = 0; i < n; i++) 
    {
        if (!snt(arr[i])) 
        {
            arr[kichthuocmoi] = arr[i];
            kichthuocmoi++;
        }
    }
    return kichthuocmoi;
}

int main() 
{
    int n, k;
    cout << "Nhap so phan tu n: ";
    cin >> n;
    int* arr = new int[n];  // Cấp phát động mảng

    cout << "Nhap " << n << " so nguyen"<<endl;
    for (int i = 0; i < n; i++) 
    {
        cout << "Phan tu thu [" << i << "]: ";
        cin >> arr[i];
    }

    // Phần a: Tìm vị trí k phần tử lớn nhất
    cout << "Nhap k: ";
    cin >> k;
    timvitriklonnhat(arr, n, k);

    // Phần b: Sắp xếp theo tổng chữ số
    sapxeptheotongchuso(arr, n);
    cout << "Mang sau khi sap xep theo tong chu so: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Phần c: Xóa số nguyên tố
    n = xoasnt(arr, n);
    cout << "Mang sau khi xoa so nguyen to: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}
/*Bài tập 1. Cho dãy n số nguyên : a0, a1, ..., an - 1
a.Hãy cho biết vị trí của k phần tử có giá trị lớn nhất trong dãy.
b.Sắp xếp các phần tử tăng dần theo tổng các chữ số của từng phần tử.
c.Hãy xóa tất cả các số nguyên tố có trong dãy. */
