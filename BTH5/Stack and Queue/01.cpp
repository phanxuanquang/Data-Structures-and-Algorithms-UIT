#include <iostream>
using namespace std;
struct Node
{
    int infor;
    Node *pNext;
};
struct List
{
    Node *pHead;
    Node *pTail;
};


Node *createNode(int x);
void push(List &list, Node *node);
int pop(List &list, int &x);
void init(List &l);
void Xuat(List list);

void ChuyenNhiPhan(int n, List &list);
bool isEmpty(List list);
int main()
{
    List list;
    init(list);
    cout << "Nhap so can chuyen tu co so 10 sang co so 2:";
    int n;
    cin >> n;
    ChuyenNhiPhan(n, list);
    cout << endl;
    while (!isEmpty(list))
    {
        int x;
        pop(list, x);
        cout << x << " ";
    }

    return 0;
}
Node *createNode(int x)
{
    Node *node = new Node;
    if (node == NULL)
    {
        return NULL;
    }

    node->infor = x;
    node->pNext = NULL;
    return node;
}
void push(List &list, Node *node)
{
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = node;
        return;
    }
    node->pNext = list.pHead;
    list.pHead = node;
}
int pop(List &list, int &x)
{
    if (list.pHead == NULL)
    {
        return 0;
    }

    Node *p = list.pHead;
    x = p->infor;
    list.pHead = p->pNext;
    if (list.pHead == NULL)
    {
        list.pTail = NULL;
    }
    delete p;
    p = NULL;
    return 1;
}
void init(List &l)
{
    l.pHead = l.pTail = NULL;
}
void Xuat(List list)
{
    Node *p = list.pHead;
    while (p != NULL)
    {
        cout << p->infor << " ";
        p = p->pNext;
    }
}

void ChuyenNhiPhan(int n, List &list)
{
    while (n != 0)
    {
        Node *p = createNode(n % 2);
        push(list, p);
        n /= 2;
    }
}
bool isEmpty(List list)
{
    if (list.pHead == NULL)
    {
        return true;
    }
    return false;
}