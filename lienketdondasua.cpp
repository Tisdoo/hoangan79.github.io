#include <iostream>
using namespace std;

typedef struct node// khai báo cấu trúc dữ liệu node
{
    int info;// lưu giá trị nguyên
    struct node* next;//khai báo con trỏ dùng để trỏ đến node tieeoops theo
} Node;

Node* pHead = NULL;// khởi tạo mảng rỗng

bool isEmpty(Node* pHead)// kiểm tra danh sách có rỗng hay không
{
    return (pHead == NULL);
}


void init(Node*& pHead)// tạo danh sách pHead chứa NULL
{
    pHead = NULL;
}


Node* createNode(int x) //hàm tạo danh sách
{
    Node* p = new Node;//cấp phát động một node vào con trỏ p
    p->info = x;
    p->next = NULL;
    return p;
}



void ShowList(Node* pHead)// in ra danh sách NULL đã tạo
{
    if (pHead == NULL)//Nếu pHead trỏ tới NULL thì là rỗng
        printf("Danh sach rong\n");
    else
    {
        Node* p = pHead;
        while (p != NULL)// chạy cho đến khi gặp NULL kết thúc hết phần tử
        {
            printf("%d ", p->info);
            p = p->next;
        }
    }
}




void ShowList1(Node* pHead) {
    if (pHead == NULL)
        printf("Danh sach rong\n");
    else {
        for (Node* p = pHead; p != NULL; p = p->next) // dùng lệnh for thay vì while chức năng 2 hàm tương tự nhau
        {
            printf("%d ", p->info);
        }
    }
}




void insertFirst(Node*& pHead, int x)// hàm chèn node vào đầu danh sách
{
    Node* p = createNode(x);//tạo một node mơi vào con trỏ p
    p->next = pHead;//trỏ p->next đến pHead
    pHead = p;// gán con trỏ p vào vị trí phead
}





void insertAfter(Node* p, int x) //chèn vào 1 một node ở cuối danh sách
{
    if (p != NULL) // kiểm tra có phải là danh sách rỗng không
    {
        Node* q = createNode(x);// khỏi tạo 1 node mới vào con trỏ p
        q->next = p->next;//trỏ q->next đến phần tử p->next rồi
        p->next = q;//gán giá trị của con trỏ p đến con trỏ mới cấp phát q
    }
}






void insertOrder(Node*& pHead, int x)//thêm node vào danh sách theo thứ tự
{
    Node* tp = NULL;
    Node* p = pHead;
    bool flag = true;//bật cờ
    while ((p != NULL) && flag)// xét điều kiện duỵt các phần tử danh sách không rỗng
    {
        if (p->info < x)//nếu phần tử ở node nhỏ hơn x thì 
        {
            tp = p;
            p = p->next;//p sẽ trỏ đến giá trị kế tiếp
        }
        else flag = false;// nếu gặp giá trị lớn hơn x thì gán flag false thoát vòng lặp
    }
    if (p == pHead)// nếu giá trị gán nhỏ nhất thì gắn đầu danh sách 
        insertFirst(pHead, x);
    else
        insertAfter(tp, x);//ngược lại thì gán sau giá trị nhỏ hơn
}






Node* find(Node* pHead, int x) // hàm tìm kiếm giá trị trong danh sách 
{
    bool flag = false;//gắn cờ kiểm soát vòng lặp
    Node* p = pHead;//khởi tạo phần tử đầu dnnh sách
    while ((p != NULL) && !flag)// xét từng phần tử 
    { 
        if (p->info == x)// gặp phần tử cần tìm thì gán true thoát khỏi vòng lặp nếu không thì tiếp tục xét phần tử tiếp theo
            flag = true;
        else
            p = p->next;
    }
    if (!flag)//nếu không tìm thấy phần tử cần tìm thì tra về NULL
        p = NULL;
    return p;
}






void clearList(Node*& pHead) //xóa toàn bộ danh sách liên kết
{
    Node* p;
    while (pHead != NULL)// cho đến khi thành danh sách rỗng
    {
        p = pHead;// lưu con trỏ ở nút hiện tại
        pHead = pHead->next;//trỏ pHead đến nút tiếp theo r xóa p
        delete p;
    }
}





void selectionSort(Node* pHead)
{
    Node* p, * q, * pmin;
    int vmin;
    for (p = pHead; p->next != NULL; p = p->next)
    {
        vmin = p->info;
        pmin = p;
        for (q = p->next; q != NULL; q = q->next)
        {
            if (q->info < vmin) 
            {
                vmin = q->info;
                pmin = q;
            }
        }
        pmin->info = p->info;
        p->info = vmin;
    }
}
void test()
{
    init(pHead);

    // Test insertFirst
    insertFirst(pHead, 5);
    insertFirst(pHead, 10);
    insertFirst(pHead, 3);
    cout << "Danh sach sau khi chen dau: ";
    ShowList(pHead); cout << "\n";

    // Test insertOrder
    insertOrder(pHead, 7);
    insertOrder(pHead, 1);
    insertOrder(pHead, 9);
    cout << "Danh sach sau khi chen theo thu tu: ";
    ShowList(pHead); cout << "\n";

    // Test find
    int j = 7;
    Node* timnode = find(pHead, j);
    if (timnode)
        cout << "Tim thay gia tri " << j << " trong danh sach.\n";
    else
        cout << "Khong tim thay gia tri " << j << " trong danh sach.\n";

    // Test selectionSort
    selectionSort(pHead);
    cout << "Danh sach sau khi sap xep: ";
    ShowList(pHead); cout << "\n";

    // Test clearList
    clearList(pHead);
    cout << "Danh sach sau khi xoa: ";
    ShowList(pHead); cout << "\n";
}







int main()
{
    test();
    return 0;
}