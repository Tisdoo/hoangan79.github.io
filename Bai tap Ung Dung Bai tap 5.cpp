#include<iostream>
using namespace std;

// hàm tính tổng các dòng
void tinhtong(int A[][100], int n, int m, int tongmang[]) {
    for (int i = 0; i < n; i++) {
        tongmang[i] = 0; // tạo tổng của dòng i
        for (int j = 0; j < m; j++) {
            tongmang[i] += A[i][j];
        }
    }
}

// câu A
void cauA(int A[][100], int n, int m,int tongmang[]) {
 
    tinhtong(A, n, m, tongmang); 

    int dongmax = 0; // biến chỉ số dòng có tổng lớn nhất
    for (int i = 1; i < n; i++) {
        if (tongmang[i] > tongmang[dongmax]) {
            dongmax = i;
        }
    }

    //In ra kết quả
    cout << "Dong co tong lon nhat la " << dongmax << " voi tong = " << tongmang[dongmax] << endl;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b; b = temp;



}
void cauB(int A[][100], int n, int m)
{
    int tongmang[100]; // Mảng lưu tổng của các dòng
    tinhtong(A, n, m, tongmang);
    int k = n - 1, i;// dùng bubble sort để hoán đổi
    bool flag = true;
    while (flag == true)
    {
        flag = false;
        i = 0;
        for (int j = 0; j < k; j++)
        {
            if (tongmang[j] < tongmang[j + 1])// so sánh tổng các dòng với nhau
            {
                flag = true;
                swap(tongmang[j], tongmang[j + 1]);
                for (int t = 0; t < m; t++)
                {
                    swap(A[j][t], A[j + 1][t]);// hoán đổi dòng có tổng lớn hơn
                }i = j;

            }
        }k = i;




    }
}
void testtotnhat()
{
    int n = 3; int m = 3; 
    
        int A[100][100] = {
            {7, 8, 9},  
            {4, 5, 6},  
            {1, 2, 3}   
        };
        int tongmang[3];
        cout << "Test tot nhat:\n";
        cauA(A, 3, 3, tongmang);
        cauB(A, 3, 3);

        // In ra kết quả sau sắp xếp
        cout << "Mang sau khi sap xep:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << A[i][j] << " ";
            }
            cout << "| Tong = " << tongmang[i] << endl;
        }
    }

void testxaunhat() {
    int A[100][100] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int tongmang[3];
    cout << "Test xau nhat:\n";
    cauA(A, 3, 3, tongmang);
    cauB(A, 3, 3);

   
    cout << "Mang sau khi sap xep " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int chon = 0; cout << " chon cach nhap " << endl << " chon 0 dung testcase" << endl << "nhap 1 nhap thu cong" << endl; 
    cin >> chon; cout << "---------------------------" << endl;
    int n, m;
    if (chon == 1) {
        cout << "Nhap so dong "; cin >> n;
    cout << "Nhap so cot "; cin >> m;
    int tongmang[100];
    int A[100][100]; 
   
        //Nhập mảng 2 chiều
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << "Nhap A[" << i << "][" << j << "] ";
                cin >> A[i][j];
            }
        }

        cauA(A, n, m, tongmang);
        cauB(A, n, m);
    }

    else if (chon == 0)
    {
        cout << "Mang truoc khi sap xep   " << endl;
        cout << "A ={1, 2, 3}" << endl;
            cout << "   {4, 5, 6}" << endl;
            cout << "   {7, 8, 9}" << endl;
        
          
        testtotnhat();
        cout << "........................" << endl;
        cout << "Mang truoc khi sap xep   " << endl;
        cout << "A ={7, 8, 9}" << endl;
        cout << "   {4, 5, 6}" << endl;
        cout << "   {1, 2, 3}" << endl;
        testxaunhat();


    }
    else
        cout << " loi he thong " << endl;

    return 0;
}
