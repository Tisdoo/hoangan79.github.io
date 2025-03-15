#include <iostream>  
#include<fstream>
using namespace std;  
// ham nhap phan tu trong mang
void nhap(int a[], int n)
{
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
// ham hoan vi 2 so
void hv( int &a, int &b)
{
	int t=a;a=b;b=t;
}
// ham sap xep tang dan
void selection(int a[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min_index=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min_index])
			min_index=j;
		}
		hv(a[i],a[min_index]);
	}
}
//ham suat mang
void xuat(int a[], int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
void testcasehv()
{
	int a=10,b=5;
	cout<<a<<" "<<b<<endl;
	hv(a,b);
	cout<<a<<" "<<b;
}
void testcaseselection()
{
	int a[5]={1,5,2,3,0};
	selection(a,5);
	for(int i=0;i<5;i++)
	cout<<a[i];
}
void chandaulecuoi(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		a[i]*=-1;
	}
	selection(a,n);
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		a[i]*=-1;
	}xuat(a,n);
}
void testcasechandaulecuoi()
{
	int n=10;
	int a[n]={1,2,3,4,5,6,7,8,9,10};
	chandaulecuoi(a,n);
}
int main()
{
	//testcasehv();
	//testcaseselection();
	//testcasechandaulecuoi();
	int n;
	cout<<"nhap sl phan tu n";
	cin>>n;
	int *a = new int [n];
	nhap(a,n);
	chandaulecuoi(a,n);
	
	return 0;
}
