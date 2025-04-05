//3124411021-Nguyễn Hoàng Ấn
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;


void readFile(int*& a, int& n, string& s, string& x, const string& name) {
    ifstream fin(name);


    fin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }


    fin.ignore();


    getline(fin, s);


    getline(fin, x);

    fin.close();
}

int SNT(int num)
{
    if (num < 2) return 0;


    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) return 0;
    }
    return 1;
}


void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


void sort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortdebai(int* a, int n)
{

    int demSNT = 0;
    for (int i = 0; i < n; i++) {
        if (SNT(a[i])) {
            demSNT++;
        }
    }
    int demNotSNT = n - demSNT;  

  
    int* snt = new int[demSNT];
    int* kosnt = new int[demNotSNT];  

    int pos = 0, pos0 = 0;
    for (int i = 0; i < n; i++) {
        if (SNT(a[i])) {
            snt[pos++] = a[i];
        }
        else {
            kosnt[pos0++] = a[i];
        }
    }

    sort(snt, demSNT);
    sort(kosnt, demNotSNT);  

    int poss = 0;
    for (int i = 0; i < demSNT; i++) {
        a[poss++] = snt[i];  
    }
    for (int i = 0; i < demNotSNT; i++) {
        a[poss++] = kosnt[i];
    }

   
    delete[] snt;
    delete[] kosnt;
}



int demchuoi(const string& s, const string& x) {
    int count = 0;
    size_t dodaix = x.length();
    size_t dodais = s.length();

    if (dodaix == 0 || dodais < dodaix) return 0;

    for (size_t i = 0; i <= dodais - dodaix; i++) {
        bool found = true;
        for (size_t j = 0; j < dodaix; j++) {
            if (s[i + j] != x[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            count++;
            i += dodaix - 1; 
        }
    }

    return count;
}




string longest(const string& s) {
    string longestWord;
    string tmp;

    for (char c : s) {
        if (c == ' ') {
            if (tmp.length() > longestWord.length()) {
                longestWord = tmp;
            }
            tmp.clear();
        }
        else {
            tmp += c;
        }
    }

   
    if (tmp.length() > longestWord.length()) {
        longestWord = tmp;
    }

    return longestWord;
}


void writeFile(int* a, int n, int count, const string& longestWord, const string& name) {
    ofstream fout(name);

    // Ghi mảng đã sắp xếp
    for (int i = 0; i < n; i++) {
        fout << a[i];
        if (i < n - 1) fout << " ";
    }
    fout << endl;

   
    fout << count << endl;

   
    fout << longestWord << endl;

    fout.close();
}


int main() {
    int* a = nullptr;
    int n;
    string s, x;

    // 1. Đọc file input và in ra console
    readFile(a, n, s, x, "DE03.INP");
    cout << "Mang doc duoc: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Chuoi s: " << s << endl;
    cout << "Chuoi x: " << x << endl;

    // 2. Sắp xếp mảng theo yêu cầu và in ra
    sortdebai(a, n);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // 3. Đếm số lần xuất hiện của x trong s và in ra
    int dem = demchuoi(s, x);
    cout << "So lan xuat hien cua x trong s: " << dem << endl;

    // 4. Tìm từ dài nhất trong s và in ra
    string Longest = longest(s);
    cout << "Tu dai nhat trong s: " << Longest << endl;  

    // 5. Ghi kết quả ra file
    writeFile(a, n, dem, Longest, "DE03.OUT");


    delete[] a;

    return 0;
}