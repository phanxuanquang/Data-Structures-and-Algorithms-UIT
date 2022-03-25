#include <iostream>
#define max 10
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
struct QueueA
{
    int a[max];
    int Front; 
    int Rear;  
};
void CreateQueue(QueueA &queue);
void init(List &);

Node *CreateNode(int x);
void EnQueue(List &queue, int x);
int DeQueue(List &queue, int &x);
int DeQueue(QueueA &queue, int &x);
int EnQueue(QueueA &queue, int x);
void output(List);
void output(QueueA queue);
bool isEmpty(List &queue);
bool isEmpty(QueueA queue);
int demSoPT(QueueA queue);
int demSoPT(List queue);
void deleteQueue(List &queue);
void deleteQueue(QueueA &queue);
int luaChonMenu();
int ChooseAorL();
void QueueList(List queue);
void QueueArr(QueueA);
int main()
{
    List queueL;
    QueueA queueA;
    bool flag = true;
    int chosen;
    while (flag != false)
    {
        chosen = ChooseAorL();
        switch (chosen)
        {
        case 1:
        {
            QueueArr(queueA);
            break;
        }
        case 2:
        {

            QueueList(queueL);
            break;
        }
        case 0:
        {
            cout << "BYE! \n";
            flag = false;
            break;
        }
        default:
        {
            cout << "Lua chon khong hop le. VUi long chon lai: ";
            break;
        }
        }
    }
    system("pause");

    return 0;
}

void QueueArr(QueueA queue)
{
    CreateQueue(queue);
    cout << "BAN DANG LAM THAO TAC VOI QUEUE LA MANG";
    int lua_chon;
    bool flag = true;
    while (flag != false)
    {
        int x;
        lua_chon = luaChonMenu();
        switch (lua_chon)
        {
        case 1:
        {
            cout << "Nhap gia tri can them vao queue: ";
            cin >> x;
            EnQueue(queue, x);
            cout << "Cac phan tu cua Queue sau khi EnQueue: ";
            output(queue);
            break;
        }
        case 2:
            if (DeQueue(queue, x))
            {
                cout << "Gia tri lay duoc khi dequeue la: " << x << endl;
                cout
                    << "Cac phan tu cua Queue sau khi DeQueue: ";
                if (queue.Front != -1)
                {
                    output(queue);
                }
            }
            break;
        case 3:
        {
            if (isEmpty(queue))
            {
                cout << "Queue rong!\n";
            }
            else
            {
                cout << "Queue co phan tu!\n";
            }

            break;
        }
        case 4:
            cout << "So luong phan tu trong queue: " << demSoPT(queue);
            break;
        case 5:
            deleteQueue(queue);
            cout << "Queue is deleted!";
            break;
        case 0:
            flag = false;
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.\n";
            cin >> lua_chon;
            break;
        }
    }
}
void QueueList(List queue)
{
    cout << "BAN DANG LAM THAO TAC VOI QUEUE LA LIST";
    init(queue);
    int lua_chon;
    bool flag = true;
    while (flag != false)
    {
        int x;
        lua_chon = luaChonMenu();
        switch (lua_chon)
        {
        case 1:
        {
            cout << "Nhap gia tri can them vao queue: ";
            cin >> x;
            EnQueue(queue, x);
            cout << "Cac phan tu cua Queue sau khi EnQueue: ";
            output(queue);
            break;
        }
        case 2:
            if (DeQueue(queue, x))
            {
                cout << "Gia tri lay duoc khi dequeue la: " << x << endl;
                cout
                    << "Cac phan tu cua Queue sau khi DeQueue: ";
                output(queue);
            }
            break;
        case 3:
        {
            if (isEmpty(queue))
            {
                cout << "Queue rong!\n";
            }
            else
            {
                cout << "Queue co phan tu!\n";
            }

            break;
        }
        case 4:
            cout << "So luong phan tu trong queue: " << demSoPT(queue);
            break;
        case 5:
            deleteQueue(queue);
            cout << "Queue is deleted!";
            break;
        case 0:
            flag = false;
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.\n";
            cin >> lua_chon;
            break;
        }
    }
}
int ChooseAorL()
{
    int chosen;
    cout << "\n \n ================================ \n";
    cout << "\n Ban muon lam viec voi MANG hay DSLK ? ";
    cout << "\n 1. MANG ";
    cout << "\n 2. Danh sach lien ket ";
    cout << "\n 0. Thoat chuong trinh ";
    cout << "\nMoi ban nhap thao tac can thuc hien: ";
    cin >> chosen;
    return chosen;
}
int luaChonMenu()
{
    int lua_chon;
    cout << "\n \n ================================ \n";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n1. Enqueue ";
    cout
        << "\n2. Dequeue ";
    cout << "\n3. Kiem tra Queue co rong hay khong";
    cout << "\n4. Dem so phan tu trong Queue";
    cout << "\n5. Xoa cac phan tu trong Queue";
    cout << "\n0. Thoat chuong trinh";
    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> lua_chon;
    return lua_chon;
}

void CreateQueue(QueueA &queue)
{
    queue.Front = -1;
    queue.Rear = -1;
}
void init(List &queue)
{
    queue.pHead = queue.pTail = NULL;
}

void deleteQueue(List &queue)
{
    Node *p = queue.pHead;
    while (p != NULL)
    {
        Node *temp = p;
        p = p->pNext;
        delete temp;
        temp = NULL;
    }
    queue.pHead = queue.pTail = NULL;
}
void deleteQueue(QueueA &queue)
{
    queue.Front = -1;
    queue.Rear = -1;
}
Node *CreateNode(int x)
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
void EnQueue(List &queue, int x)
{
    Node *node = CreateNode(x);
    if (queue.pHead == NULL)
    {
        queue.pHead = queue.pTail = node;
    }
    else
    {
        queue.pTail->pNext = node;
        queue.pTail = node;
    }
}
int EnQueue(QueueA &queue, int x)
{
    if (queue.Rear - queue.Front + 1 == max)
    {
        cout << "Queue is full!" << endl;
        return 0;
    }
    else
    {
        if (isEmpty(queue)) // queue rong~
        {
            queue.Front = 0;
        }

        if (queue.Rear == max - 1)
        {
            int f = queue.Front;
            int r = queue.Rear;
            for (int i = f; i <= r; i++)
            {
                queue.a[i - f] = queue.a[f];
            }
            queue.Front = 0;
            queue.Rear = r - f;
        }

        queue.Rear++;
        queue.a[queue.Rear] = x;
    }
    return 1;
}
bool isEmpty(List &queue)
{
    if (queue.pHead == NULL)
    {
        return true;
    }
    return false;
}
bool isEmpty(QueueA queue)
{
    if (queue.Front == -1)
    {
        return true;
    }
    return false;
}

int DeQueue(QueueA &queue, int &x)
{
    if (!isEmpty(queue))
    {
        x = queue.a[queue.Front];
        queue.Front++;
        if (queue.Front > queue.Rear) //truong hop co mot phan tu
        {
            queue.Front = -1;
            queue.Rear = -1;
        }
        return 1;
    }
    else
    {
        cout << "QueueA rong";
        return 0;
    }
}
int DeQueue(List &queue, int &x)
{
    if (!isEmpty(queue))
    {
        Node *p = queue.pHead;
        x = p->infor;
        queue.pHead = p->pNext;
        if (queue.pHead == NULL)
        {
            queue.pTail = NULL;
        }
        delete p;
        p = NULL;
        return 1;
    }
    else
    {
        cout << "Queue is empty!";
    }

    return 0;
}

int demSoPT(QueueA queue)
{
    if (queue.Front == -1)
    {
        return 0;
    }

    return queue.Rear - queue.Front + 1;
}
int demSoPT(List queue)
{
    int dem = 0;
    Node *p = queue.pHead;
    while (p != NULL)
    {
        dem++;
        p = p->pNext;
    }
    return dem;
}
void output(QueueA queue)
{
    for (int i = queue.Front; i < queue.Rear + 1; i++)
    {
        cout << queue.a[i] << " ";
    }
}
void output(List queue)
{
    Node *p = queue.pHead;
    while (p != NULL)
    {
        cout << p->infor << " ";
        p = p->pNext;
    }
}
