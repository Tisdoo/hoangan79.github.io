#include<iostream>
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
// ham sap xep tang dan nhung cac phan tu 0 thi giu nguyen vi tri ban dau
void selection(int a[], int n)
{
	int flat[n]={0};
	for(int h=0;h<n-1;h++)
	{
		if(a[h]==0) flat[h]=1;
	}
	for(int i=0;i<n-1;i++)
	{
		int min_index=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min_index]&&flat[j]==0)
			min_index=j;
		}
		hv(a[i],a[min_index]);
	}
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
void xuat(int a[], int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}

void chantanglegiam(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]%2!=0)
		a[i]*=-1;
	}
	selection(a,n);
	for(int i=0;i<n;i++)
	{
		if(a[i]%2!=0)
		a[i]*=-1;
	}
}
void testcasechantanglegiam()
{
	int n=10;
	int a[n]={3,6,1,0,0,4,0,2,9,10};
	chantanglegiam(a,n);
	xuat(a,n);
}
int main()
{
	//testcasehv();
	//testcaseselection();
	//testcasechantanglegiam();
	int n;
	cout<<"nhap sl phan tu n";
	cin>>n;
	int *a = new int [n];
	nhap(a,n);
	chantanglegiam(a,n);
	xuat(a,n);
	return 0;
}
