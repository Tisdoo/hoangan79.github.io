
#include <iostream>
using namespace std;
void nhap(int a[], int n)
{
	for(int i=0;i<n;i++)
	cin>>a[i];
}
void xuat(int a[], int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
//ham tim mang nghich the
void timmangnghichthe(int a[],int b[], int n)
{
	// gia tri dau tien duoc dem so sanh la 1
	int m=1;
	//quet qua mang A co tim thay m
	for(int i=0;i<n;i++)
    {
    	// gan dem =0 moi lan m tang thi dem lai =0
		int dem=0;
        if(a[i]==m)
        {
            for(int j=0;j<i;j++)
            {
                if(a[j]>a[i])
                dem++; 
            }
            //gan phan tu dem duoc vao mang B
            b[m-1]=dem;
            // dem xong 1 so thi tiep tuc tang m
            m++;
            //va tim m lai tu dau
            i=-1;
            
        }
        // th khi quet qua mang A nhung khong tim thay m
        if(a[i]!=m&&i==n-1) 
		{
			//khi khong thay thi dem =0 va gan vao mang B luon
			dem=0;
			b[m-1]=dem;
			// tiep tuc tang m va tim lai tu dau
			m++;
			i=-1;
		}
		// neu m tang vuot qua sl phan tu thi dung
		if(m>n) break;
    }
}
void testcasetimmangnghichthe()
{
	int a[9]={5,9,1,8,2,6,4,7,3};
    int b[9]={0};
    timmangnghichthe(a,b,9);
    xuat(b,9);
}
int main()
{
	testcasetimmangnghichthe();
	int n;
	cout<<"nhap sl phan tu cua mang ";
	cin>>n;
	int *a=new int [n];
	int *b=new int [n];
	nhap(a,n);
	timmangnghichthe(a,b,n);
	xuat(b,n);
    
	delete[] a;
	delete[] b;
    return 0;
}
