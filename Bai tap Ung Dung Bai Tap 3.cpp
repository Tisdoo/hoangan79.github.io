#include <iostream>
using namespace std;

struct Phongthi {
    int phong;
    char nha;
    int succhua;
};


void nhapdanhsach(Phongthi*& danhsach, int& n) {
    cout << "Nhap so luong phong thi: ";
    cin >> n;
    danhsach = new Phongthi[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap nha, so phong, suc chua thu " << i + 1 << ": ";
        cin >> danhsach[i].nha >> danhsach[i].phong >> danhsach[i].succhua;
    }
}


void swap(Phongthi& a, Phongthi& b) {
    Phongthi temp = a;
    a = b;
    b = temp;
}

// Câu A: Sắp xếp giảm dần theo sức chứa
void cauA(Phongthi danhsach[], int n) {
    int k = n - 1, i;
    bool flag = true;
    while (flag) {
        flag = false;
        i = 0;
        for (int j = 0; j < k; j++) {
            if (danhsach[j].succhua < danhsach[j + 1].succhua) {
                swap(danhsach[j], danhsach[j + 1]);
                flag = true;
                i = j;
            }
        }
        k = i;
    }
}

// Câu B: Sắp xếp tăng dần theo nhà, nếu cùng nhà thì sắp xếp phòng tăng dần
void cauB(Phongthi danhsach[], int n) {
    int k = n - 1, i;
    bool flag = true;
    while (flag) {
        flag = false;
        i = 0;
        for (int j = 0; j < k; j++) {
            if (danhsach[j].nha > danhsach[j + 1].nha ||
                (danhsach[j].nha == danhsach[j + 1].nha && danhsach[j].phong > danhsach[j + 1].phong)) {
                swap(danhsach[j], danhsach[j + 1]);
                flag = true;
                i = j;
            }
        }
        k = i;
    }
}

// Câu C: Sắp xếp tăng dần theo nhà, nếu cùng nhà thì sắp xếp phòng giảm dần
void cauC(Phongthi danhsach[], int n) {
    int k = n - 1, i;
    bool flag = true;
    while (flag) {
        flag = false;
        i = 0;
        for (int j = 0; j < k; j++) {
            if (danhsach[j].nha > danhsach[j + 1].nha ||
                (danhsach[j].nha == danhsach[j + 1].nha && danhsach[j].phong < danhsach[j + 1].phong)) {
                swap(danhsach[j], danhsach[j + 1]);
                flag = true;
                i = j;
            }
        }
        k = i;
    }
}

void hienthi(Phongthi danhsach[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nha: " << danhsach[i].nha
            << " | So phong: " << danhsach[i].phong
            << " | Suc chua: " << danhsach[i].succhua << endl;
    }
    cout << "-------------------------\n";
}

//  Trường hợp xấu nhất 
void testWorstCaseA() {
    cout << "test xau nhat" << endl;
    Phongthi danhsach[] = {
        {5, 'C', 50}, {4, 'B', 40}, {3, 'A', 30}, {2, 'C', 20}, {1, 'B', 10}
    };
    int n = 5;

  

    cout << "sau khi sap xep" << endl;

    cout << "cau A" << endl;
    cauA(danhsach, n);
    hienthi(danhsach, n);

    cout << "cau B" << endl;
    cauB(danhsach, n);
    hienthi(danhsach, n);

    cout << "cau C" << endl;
    cauC(danhsach, n);
    hienthi(danhsach, n);

}

//  Trường hợp tốt nhất 
void testBestCaseA() {
    cout << " Truong hop tot nhat" << endl;
    Phongthi danhsach[] = {
        {1, 'A', 10}, {2, 'B', 20}, {3, 'C', 30}, {4, 'A', 40}, {5, 'B', 50}
    };
    int n = 5;

   

    cout << "sau khi sap xep" << endl;

    cout << "cau A" << endl;
    cauA(danhsach, n);
    hienthi(danhsach, n);

    cout << "cau B" << endl;
    cauB(danhsach, n);
    hienthi(danhsach, n);

    cout << "cau C" << endl;
    cauC(danhsach, n);
    hienthi(danhsach, n);
}

//  Trường hợp ngẫu nhiên 
void testRandomCaseA() {
    cout << "test binh thuong"<<endl;
    Phongthi danhsach[] = {
        {4, 'B', 40}, {1, 'C', 10}, {3, 'A', 30}, {2, 'B', 20}, {5, 'C', 50}
    };
    int n = 5;
    cout << "sau khi sap xep" << endl;

    cout << "cau A" << endl;
    cauA(danhsach, n);
    hienthi(danhsach, n);

    cout << "cau B" << endl;
    cauB(danhsach, n);
    hienthi(danhsach, n);

    cout << "cau C" << endl;
    cauC(danhsach, n);
    hienthi(danhsach, n);
}

int main() {
    
        testWorstCaseA();
        testBestCaseA();
        testRandomCaseA();
    return 0;
}
