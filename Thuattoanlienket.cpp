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








void test1()
{
    printf("--- Test1 ---\n");

    Node* pHead;
    init(pHead);
    if (isEmpty(pHead))
        printf("List bi rong");
    else
        printf("List co phan tu");
    printf("\n");
}

void test2()
{
    printf("--- Test2 ---\n");
    int a[] = { 2, 5, 4, 2, 1, 8 }, n = 6;
    Node* pHead;
    init(pHead);
    for (int i = 0; i < n; i++)
    {
        insertFirst(pHead, a[i]);
    }
    printf("Noi dung danh sach (insertFirst): ");
    ShowList(pHead);
    printf("\n\n");

    Node* pHead1;
    init(pHead1);
    insertFirst(pHead1, a[0]);
    Node* p = pHead1;
    for (int i = 1; i < n; i++) {
        insertAfter(p, a[i]);
        p = p->next;
    }
    printf("Noi dung danh sach (insertAfter): ");
    ShowList(pHead1);
    printf("\n\n");

    int b[] = { 1, 2, 3, 4, 10, 20, 30 };
    n = 7;
    int x = 8;
    Node* pHead2;
    init(pHead2);
    insertFirst(pHead2, b[0]);
    p = pHead2;
    for (int i = 1; i < n; i++)
    {
        insertAfter(p, b[i]);
        p = p->next;
    }
    printf("Noi dung danh sach truoc (insertOrder): ");
    ShowList(pHead2);
    printf("\n\n");
    insertOrder(pHead2, x);
    printf("Noi dung danh sach (chen 8) (insertOrder): ");
    ShowList(pHead2);
    printf("\n\n");
    insertOrder(pHead2, 40);
    printf("Noi dung danh sach (chen 40) (insertOrder): ");
    ShowList(pHead2);
    printf("\n\n");
}

void test3() {
    printf("--- Test3 ---\n");
    int a[] = { 2, 5, 4, 2, 1, 8 }, n = 6;
    int b[] = { 1, 2, 5, 10, 20, 30 }, m = 6;

    Node* pHead = NULL, * p, * q;
    insertFirst(pHead, a[0]); p = pHead;
    for (int i = 1; i < n; i++) {
        insertAfter(p, a[i]);
        p = p->next;
    }
    printf("Tim danh sach (find): ");
    ShowList(pHead);
    printf("\n");
    q = find(pHead, 1);
    if (q == NULL) {
        printf("--> Khong tim thay\n");
    }
    else {
        printf("--> Tim thay gia tri %d\n", q->info);
    }
    q = find(pHead, 30);
    if (q == NULL) {
        printf("--> Khong tim thay gia tri 30\n");
    }
    else {
        printf("--> Tim thay gia tri %d\n", q->info);
    }
    printf("\n\n");
}

void test4()
{
    printf("--- Test3 ---\n");
    int a[] = { 2, 5, 4, 2, 1, 8 }, n = 6;

    Node* pHead = NULL, * p;
    insertFirst(pHead, a[0]); p = pHead;
    for (int i = 1; i < n; i++) {
        insertAfter(p, a[i]);
        p = p->next;
    }
    printf("Truoc khi sap xep: ");
    ShowList(pHead);
    printf("\n");
    selectionSort(pHead);
    printf("Sau khi sap xep: ");
    ShowList(pHead);
    printf("\n\n");
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}