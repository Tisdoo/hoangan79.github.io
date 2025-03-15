#include <iostream>  
#include<fstream>
using namespace std;  


struct SinhVien {  
    int maSo;  
    char hoDem[20];  
    char ten[40];  
    int ngaySinh, thangSinh, namSinh;  
    char phai[4]; // "Nam" or "Nu"  
    float diemTB;  
};  

// Hàm nh?p thông tin sinh viên  
void nhapSinhVien(SinhVien sv[],int &n) { 
     cout<<"nhap sl sinh vien ";
    cin>>n;
    /*while(n<10)
    {
    cout<<"nhap sl sinh vien ";
    cin>>n;
    }*/
    for(int i=0;i<n;i++)
    {
    cout<<"nhap thong tin sinh vien thu "<<i+1;
    cout << "Nhap ma so: ";  
    cin >> sv[i].maSo;  
    cout << "Nhap ho va dem: ";  
    cin.ignore(); //loai bo cac khoang trang
    cin.getline(sv[i].hoDem, 20);  
    cout << "Nhap ten: ";  
    cin.getline(sv[i].ten, 40);  
    cout << "Nhap ngay sinh: ";  
    cin >> sv[i].ngaySinh;  
    cout << "Nhap thang sinh: ";  
    cin >> sv[i].thangSinh;  
    cout << "Nhap nam sinh: ";  
    cin >> sv[i].namSinh;  
    cout << "Nhap phai (Nam/Nu): ";  
    cin >> sv[i].phai;  
    cout << "Nhap diem trung binh: ";  
    cin >> sv[i].diemTB;  
}  
}
// Hàm nhap thông tin sinh viên  
void xuatSinhVien(SinhVien sv[], int n) {  
    for(int i=0;i<n;i++)
    {
    cout<<"thong tin sv thu "<<i+1<<endl;
    cout << "Ma so: " << sv[i].maSo << endl;  
    cout << "Ho va dem: " << sv[i].hoDem << endl;  
    cout << "Ten: " << sv[i].ten << endl;  
    cout << "Ngay sinh: " << sv[i].ngaySinh << "/" << sv[i].thangSinh << "/" << sv[i].namSinh << endl;  
    cout << "Phai: " << sv[i].phai << endl;  
    cout << "Diem trung binh: " << sv[i].diemTB << endl<<endl;  
}  
}
void selectiontheodiem( SinhVien sv[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(sv[j].diemTB < sv[min_index].diemTB)
             min_index=j;
        }
        SinhVien temp = sv[i];  
                sv[i]=sv[min_index] ;  
                sv[min_index] = temp;
    }
}
void testcaseselectiontheodiem()
{
	 // khoi tao mang sinh vien
    SinhVien sv[5] = {  
        {12, "Nguyen", "An", 15, 12, 2000, "Nam", 7.5},  
        {21, "Tran", "Binh", 12, 9, 2001, "Nam", 8.5},  
        {13, "Le", "Lan", 20, 1, 1999, "Nu", 6.7},  
        {4, "Pham", "Mai", 5, 8, 2000, "Nu", 9.0},  
        {25, "Hoang", "Minh", 25, 10, 1998, "Nam", 7.0}  
    }; 
    selectiontheodiem(sv,5);
    xuatSinhVien(sv,5);
}
void selectiontheoma( SinhVien sv[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(sv[j].maSo < sv[min_index].maSo)
             min_index=j;
        }
        SinhVien temp = sv[i];  
                sv[i]=sv[min_index] ;  
                sv[min_index] = temp;
    }
}
void testcaseselectiontheoma()
{
	 // khoi tao mang sinh vien
    SinhVien sv[5] = {  
        {12, "Nguyen", "An", 15, 12, 2000, "Nam", 7.5},  
        {21, "Tran", "Binh", 12, 9, 2001, "Nam", 8.5},  
        {13, "Le", "Lan", 20, 1, 1999, "Nu", 6.7},  
        {4, "Pham", "Mai", 5, 8, 2000, "Nu", 9.0},  
        {25, "Hoang", "Minh", 25, 10, 1998, "Nam", 7.0}  
    }; 
    selectiontheoma(sv,5);
    xuatSinhVien(sv,5);
}
int main()
{
	
    int n;
    SinhVien ds[100];
    //testcaseselectiontheodiem();
	//testcaseselectiontheoma();
    nhapSinhVien(ds,n);
    selectiontheodiem(ds,n);
    //ghi file theo ma
    ofstream file;
	file.open("C:\\Users\\Admin\\Desktop\\SINHVIEN.DAT"); 
    for(int i=0;i<n;i++)
    {
    file << "thong tin sv thu "<<i+1<<endl;
    file << "Ma so: " << ds[i].maSo << endl;  
    file << "Ho va dem: " << ds[i].hoDem << endl;  
    file << "Ten: " << ds[i].ten << endl;  
    file << "Ngay sinh: " << ds[i].ngaySinh << "/" << ds[i].thangSinh << "/" << ds[i].namSinh << endl;  
    file << "Phai: " << ds[i].phai << endl;  
    file << "Diem trung binh: " << ds[i].diemTB << endl<<endl;
}   
	selectiontheoma(ds,n);
	for(int i=0;i<n;i++)
    {
    file << "thong tin sv thu "<<i+1<<endl;
    file << "Ma so: " << ds[i].maSo << endl;  
    file << "Ho va dem: " << ds[i].hoDem << endl;  
    file << "Ten: " << ds[i].ten << endl;  
    file << "Ngay sinh: " << ds[i].ngaySinh << "/" << ds[i].thangSinh << "/" << ds[i].namSinh << endl;  
    file << "Phai: " << ds[i].phai << endl;  
    file << "Diem trung binh: " << ds[i].diemTB << endl<<endl;
}   
    file.close();  

    
    return 0;
}
