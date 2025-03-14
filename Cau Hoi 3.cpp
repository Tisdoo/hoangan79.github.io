#include<iostream>
using namespace std;
void swap(int& a, int& b)
{
	int temp = a;
	a = b; b = temp;


}

void bubblesort(int a[], int n)
{
	for (int i = n - 1; i >= 1; i--)
		for (int j = 0; j <= i - 1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);


}
void insertionsort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int x = a[i];
		bool flag = true;
		while ((j >= 0) && flag==true)
			if (a[j] > x)
			{
				a[j + 1] = a[j];
				j--;
			}
			else
				flag = false;
		a[j + 1] = x;
	}
}
void selectionsort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		
		int minval = a[i];
		int kmin = i;
		for (int j = i + 1; j < n; j++)
			if (minval > a[j])
			{
				minval = a[j];
				kmin = j;
			}
	
		swap(a[i], a[kmin]);
	}
}
void maxcha(int a[], int p, int q) {
	int x = a[p];
	int i = p;
	int j = 2 * i + 1;
	bool flag = true;

	while ((j <= q) && flag) {
		if (j < q)
			if (a[j] < a[j + 1])
				j = j + 1;

		if (x < a[j]) {
			a[i] = a[j];
			i = j;
			j = j * 2 + 1;
		}
		else {
			flag = false;
		}
	}
	a[i] = x;
}
void HeapSort(int a[], int n)
{
	
	int k = n / 2 - 1;
	for (int i = k; i >= 0; i--)
		maxcha(a, i, n - 1);
	
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		maxcha(a, 0, i - 1);
	}
}

void chiamang(int a[], int p, int q)
{
	int x = a[(p + q) / 2]; int i = p; int j = q; do {
		while (a[i] < x) i++; while (a[j] > x) j--; if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i > j);
	if (p < j)
		chiamang(a, p, j); if (i < q) chiamang(a, i, q);
}
void Quicksort(int a[], int n)
{
	// Phân hoạch dãy a0 .. an-1
	chiamang(a, 0, n - 1);
}
bool ktra (int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}
void test()
{
	int test1[] = { 5, 2, 9, 1, 5, 6 };
	int n1 = sizeof(test1) / sizeof(test1[0]);
	bubblesort(test1, n1);


	int test2[] = { 5, 2, 9, 1, 5, 6 };
	int n2 = sizeof(test2) / sizeof(test2[0]);
	insertionsort(test2, n2);



	int test3[] = { 5, 2, 9, 1, 5, 6 };
	int n3 = sizeof(test3) / sizeof(test3[0]);
	selectionsort(test3, n3);


	int test4[] = { 5, 2, 9, 1, 5, 6 };
	int n4 = sizeof(test4) / sizeof(test4[0]);
	HeapSort(test4, n4);



	int test5[] = { 5, 2, 9, 1, 5, 6 };
	int n5 = sizeof(test5) / sizeof(test5[0]);
	Quicksort(test5, n5);



	cout << "Test 1: " << (ktra(test1, n1) ? "Passed" : "Failed") << endl;
	cout << "Test 2: " << (ktra(test2, n2) ? "Passed" : "Failed") << endl;
	cout << "Test 3: " << (ktra(test3, n3) ? "Passed" : "Failed") << endl;
	cout << "Test 4: " << (ktra(test4, n4) ? "Passed" : "Failed") << endl;
	cout << "Test 5: " << (ktra(test5, n5) ? "Passed" : "Failed") << endl;

}
int main()
{
	test();
	return 0;


}