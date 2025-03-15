#include<iostream>
#include<cstring>
using namespace std;

// Định nghĩa cấu trúc sinh viên
typedef struct sinhvien
{
    char HoTen[50];    // Họ tên sinh viên
    char diaChi[70];   // Địa chỉ sinh viên
    char lop[10];      // Lớp sinh viên
    int khoa;          // Khóa sinh viên
};

// Định nghĩa cấu trúc node trong danh sách liên kết
typedef struct node
{
    sinhvien info;      // Thông tin sinh viên
    struct node* next;  // Con trỏ trỏ đến node tiếp theo
} Node;

Node* pHead = NULL;     // Khởi tạo con trỏ đầu danh sách

// Hàm kiểm tra danh sách có rỗng hay không
bool isEmpty(Node* pHead)
{
    return (pHead == NULL);
}

// Hàm khởi tạo danh sách liên kết
void init(Node*& pHead)
{
    pHead = NULL;
}

// Hàm tạo một node mới với thông tin sinh viên
Node* createNode(const sinhvien& sv)
{
    Node* p = new Node;
    p->info = sv;       // Gán thông tin sinh viên vào node
    p->next = NULL;     // Khởi tạo con trỏ next là NULL
    return p;
}

// Hàm hiển thị danh sách sinh viên
void showlist(Node* pHead)
{
    if (pHead == NULL)
        cout << "Danh sach rong" << endl;
    else
    {
        // Duyệt qua từng node trong danh sách và hiển thị thông tin
        for (Node* p = pHead; p != NULL; p = p->next)
        {
            cout << "Ho ten: " << p->info.HoTen << endl;
            cout << "Dia chi: " << p->info.diaChi << endl;
            cout << "Lop: " << p->info.lop << endl;
            cout << "Khoa: " << p->info.khoa << endl;
        }
    }
}

// Hàm chèn một node mới vào đầu danh sách
void insertFirst(Node*& pHead, const sinhvien& sv)
{
    Node* p = createNode(sv);
    p->next = pHead;
    pHead = p;
}

// Hàm chèn một node mới vào sau một node cho trước
void insertAfter(Node*& p, const sinhvien& sv)
{
    Node* q = createNode(sv);
    q->next = p->next;
    p->next = q;
}

// Hàm tìm kiếm một node dựa trên họ tên sinh viên
node* find(Node* pHead, const char* Hoten)
{
    for (Node* p = pHead; p != NULL; p = p->next)
    {
        if (strcmp(p->info.HoTen, Hoten) == 0)
            return p;
    }
    return NULL;
}

// Hàm chèn một node mới vào danh sách theo thứ tự tăng dần của họ tên
void insertOrder(Node*& pHead, const sinhvien& sv)
{
    Node* p = createNode(sv);
    if (pHead == NULL)
        pHead = p;
    else
    {
        Node* q = pHead;
        Node* r = NULL;
        while (q != NULL && strcmp(q->info.HoTen, sv.HoTen) < 0)
        {
            r = q;
            q = q->next;
        }
        if (r == NULL)
        {
            p->next = pHead;
            pHead = p;
        }
        else
        {
            p->next = q;
            r->next = p;
        }
    }
}

// Hàm so sánh họ tên của hai sinh viên
int sosanhHoten(const sinhvien& Hoten1, const sinhvien& Hoten2)
{
    return strcmp(Hoten1.HoTen, Hoten2.HoTen);
}

// Hàm so sánh địa chỉ của hai sinh viên
int sosanhdiaChi(const sinhvien& diaChi1, const sinhvien& diaChi2) {
    return strcmp(diaChi1.diaChi, diaChi2.diaChi);
}

// Hàm so sánh lớp của hai sinh viên
int sosanhlop(const sinhvien& lop1, const sinhvien& lop2) {
    return strcmp(lop1.lop, lop2.lop);
}

// Hàm so sánh khóa của hai sinh viên
int sosanhkhoa(const sinhvien& khoa1, const sinhvien& khoa2) {
    return khoa1.khoa - khoa2.khoa;
}

// Hàm xóa một node dựa trên họ tên sinh viên
void xoatheoHoTen(Node*& pHead, const char* Hoten)
{
    Node* p = pHead;
    Node* q = NULL;
    while (p != NULL && strcmp(p->info.HoTen, Hoten) != 0)
    {
        q = p;
        p = p->next;
    }
    if (p != NULL)
    {
        if (q != NULL)
            q->next = p->next;
        else pHead = p->next;
        delete p;
    }
}

// Hàm xóa một node dựa trên địa chỉ sinh viên
void xoatheodiaChi(Node*& pHead, const char* diaChi)
{
    Node* p = pHead;
    Node* q = NULL;
    while (p != NULL && strcmp(p->info.diaChi, diaChi) != 0)
    {
        q = p;
        p = p->next;
    }
    if (p != NULL)
    {
        if (q != NULL)
            q->next = p->next;
        else pHead = p->next;
        delete p;
    }
}

// Hàm sắp xếp danh sách sinh viên bằng thuật toán Selection Sort
void SelectionSort(Node*& pHead, int(*sosanh)(const sinhvien&, const sinhvien&))
{
    if (pHead == NULL) return;

    node* p, * q, * pmin;
    sinhvien vmin;

    for (p = pHead; p->next != NULL; p = p->next)
    {
        pmin = p;
        vmin = p->info;
        for (q = p->next; q != NULL; q = q->next)
        {
            if (sosanh(q->info, vmin) < 0)
            {
                pmin = q;
                vmin = q->info;
            }
        }
        if (pmin != p)
        {
            sinhvien temp = p->info;
            p->info = pmin->info;
            pmin->info = temp;
        }
    }
}
//Hàm test các chương trình
void test1()
{
    init(pHead);

    // Thêm sinh viên vào danh sách
    sinhvien sv1 = { "Nguyen Van A", "123 Le Loi", "CTK45", 2021 };
    sinhvien sv2 = { "Tran Van B", "456 Tran Hung Dao", "CTK44", 2020 };
    sinhvien sv3 = { "Le Thi C", "789 Nguyen Hue", "CTK46", 2022 };

    insertOrder(pHead, sv1);
    insertOrder(pHead, sv2);
    insertOrder(pHead, sv3);

    // Hiển thị danh sách sinh viên sau khi nhập
    cout << "\nDanh sach sinh vien sau khi them:\n";
    showlist(pHead);

    // Tìm sinh viên
    const char* tenTimKiem = "Tran Van B";
    Node* timKiem = find(pHead, tenTimKiem);
    if (timKiem != NULL)
        cout << "\nTim thay sinh vien: " << timKiem->info.HoTen << "\n";
    else
        cout << "\nKhong tim thay sinh vien co ten: " << tenTimKiem << "\n";

    // Xóa sinh viên có tên "Nguyen Van A"
    xoatheoHoTen(pHead, "Nguyen Van A");
    cout << "\nDanh sach sinh vien sau khi xoa 'Nguyen Van A':\n";
    showlist(pHead);

    // Thêm sinh viên mới
    sinhvien svMoi = { "Pham Thi D", "25 Hong Bang", "CTK47", 2023 };
    insertOrder(pHead, svMoi);
    cout << "\nDanh sach sinh vien sau khi them 'Pham Thi D':\n";
    showlist(pHead);

    // Sắp xếp danh sách sinh viên theo họ tên
    SelectionSort(pHead, sosanhHoten);
    cout << "\nDanh sach sinh vien sau khi sap xep theo ho ten:\n";
    showlist(pHead);
}


int main()
{
    test1();
    return 0;
}