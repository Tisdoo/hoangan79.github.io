#include<iostream>
#include<math.h>
using namespace std;
void nhapmang(int A[][100], int n, int m)// hàm nhập mảng
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) 
		{
			cout << "Nhap A[" << i << "][" << j << "] ";
			cin >> A[i][j];


		}

	}
}
int maxsnt(int B[], int n) // hàm trả về giá trị số nguyên tố lớn nhất trong mảng
{
	int max = B[0]; 
	for (int i = 1; i < n; i++) {
		if (B[i] > max) {
			max = B[i]; 
		}
	}
	return max;
}




int ktrasnt(int n)// hàm kiểm tra SNT
{
	if (n < 2)return 0;
	else
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)return 0;
		}return 1;
}
void cauA(int A[][100], int n, int m, int &dem)//Hàm biểu diễn yêu cầu câu a tham chiếu dem để kiểm tra
{
	
	int B[100];
	for (int i = 0; i < n; i++)// duyệt kiểm tra các phần tử là SNT trong mảng A 
	{
		for (int j = 0; j < m; j++)
		{
			if (ktrasnt(A[i][j]) == 1)
			{
				B[dem] = A[i][j]; dem++;// nếu là số nguyên tố thì nhập vào mảng B
			}

		}

	}if (dem != 0)
		cout << "so nguyen to lon nhat mang " << maxsnt(B, dem) << endl;//in ra số nguyên tố lớn nhất
	else
		cout << " khong co SNT nao";

}
void cauB(int A[][100], int n, int m,int dem)
{
	if (dem == 0)cout<< "khong co so nguyen trong mang ";
	else
	{
		cout << "Cac dong co so nguyen to " << endl;
		for (int i = 0; i < n; i++)
		{
			bool flag = false;// bật cờ 
			for (int j = 0; j < m; j++)
			{
				if (ktrasnt(A[i][j]) == 1) //nếu là số nguyên tố thì
				{
					flag = true;// bật cờ dùng break thoát khỏi vòng lặp
					break;
				}

			}
			if (flag == true) //cờ bật thì dòng đó có SNT in ra dòng thứ i
			{
				cout << "Dong " << i << endl;
			}
		}
	}
}
void cauC(int A[][100], int n, int m,  int dem)// Chạy giống câu B nhưng 
{
	if (dem == 0)cout << "khong co so nguyen trong mang ";
	else
	{
		cout << "Cac dong tat ca là so nguyen to " << endl;
		for (int i = 0; i < n; i++)
		{
			bool flag = true;
			for (int j = 0; j < m; j++)
			{
				if (ktrasnt(A[i][j]) == 0)
				{
					flag = false; break;// nếu gặp không phải số nguyên tố thì tắt cờ thoát vòng lặp
				}

			}
			if (flag == true)
			{
				cout << "Dong " << i << endl;
			}
		}
	}
}
void test1() 
{
	int A[100][100] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{11, 13, 17, 19}
	};
	int n = 3, m = 4, dem = 0;

	cout << " Truong hop ngau nhien"<<endl ;
	cauA(A, n, m, dem); cout << endl;
	cauB(A, n, m, dem); cout << endl;
	cauC(A, n, m, dem); cout << endl;
	cout << "--------------------------"<<endl;
}

void test2()
{
	int A[100][100] =
	{
		{4, 6, 8},
		{10, 12, 14},
		{16, 18, 20}
	};
	int n = 3, m = 3, dem = 0;

	cout << " Khong chua so nguyen to"<<endl;
	cauA(A, n, m, dem); cout << endl;
	cauB(A, n, m, dem); cout << endl;
	cauC(A, n, m, dem); cout << endl;
	cout << "++++++++++++++++++++++"<<endl;
}
void test3()
{
	int A[100][100] =
	{
		{2, 3, 5},
		{7, 11, 13}
	};
	int n = 2, m = 3, dem = 0;

	cout << " Tat ca co so nguyen to"<<endl;
	cauA(A, n, m, dem); cout << endl;
	cauB(A, n, m, dem); cout << endl;
	cauC(A, n, m, dem); cout << endl;
	cout << "**************************"<<endl;
}
int main()
{
	int chon = 0; cout << " chon cach nhap " << endl << " chon 0 dung testcase" << endl << "nhap 1 nhap thu cong" << endl;
	cin >> chon; cout << "---------------------------" << endl;
	if (chon == 1) {
		int n, m; int dem = 0;// dùng biến đếm để kiểm tra xem trong mảng có SNT ko
		cout << "Nhap so dong "; cin >> n;
		cout << "Nhap so cot "; cin >> m;
		int A[100][100];
		nhapmang(A, n, m);
		cauA(A, n, m, dem);
		cauB(A, n, m, dem);
		cauC(A, n, m, dem);
	}
	else if (chon == 0)
	{
		test1();
		test2();
		test3();

	}
	else cout << "loi he thong";
	return 0;
}