#include <iostream>
#define max 10
using namespace std;
struct Stack
{
    int s[max];
    int top;
};
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
//Menu
int luaChonMenu();
int ChooseAorL();
void StackList(List stack);
void StackArr(Stack stack);

//List
void CreateStack(List &);
Node *CreateNode(int x);
void push(List &stack, int);
int pop(List &stack, int &);
bool deleteAfter(List &stack, Node *node);
bool isEmpty(List stack);
void output(List);
void deleteStack(List &stack);
int demSoPT(List stack);

//Array
void CreatStack(Stack &);
int pop(Stack &, int &x);
int push(Stack &, int x);
bool isEmpty(Stack);
int demSoPT(Stack);
void deleteStack(Stack &);
void output(Stack);
int main()
{
    List stackL;
    Stack stackA;
    bool flag = true;
    int chosen;
    while (flag != false)
    {
        chosen = ChooseAorL();
        switch (chosen)
        {
        case 1:
        {
            StackArr(stackA);
            break;
        }
        case 2:
        {

            StackList(stackL);
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
void StackArr(Stack stack)
{
    CreatStack(stack);
    cout << "BAN DANG LAM THAO TAC VOI STACK LA MANG";
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
            cout << "Nhap gia tri can them vao STACK: ";
            cin >> x;
            push(stack, x);
            cout << "Cac phan tu cua STACK sau khi PUSH: ";
            output(stack);
            break;
        }
        case 2:
            if (pop(stack, x))
            {
                cout << "Gia tri lay duoc khi POP la: " << x << endl;
                cout
                    << "Cac phan tu cua STACK sau khi POP: ";
                output(stack);
            }
            break;
        case 3:
        {
            if (isEmpty(stack))
            {
                cout << "STACK is empty!\n";
            }
            else
            {
                cout << "STACK co phan tu!\n";
            }

            break;
        }
        case 4:
            cout << "So luong phan tu trong STACK: " << demSoPT(stack);
            break;
        case 5:
            deleteStack(stack);
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
void StackList(List stack)
{
    CreateStack(stack);
    cout << "BAN DANG LAM THAO TAC VOI STACK LA LIST";
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
            cout << "Nhap gia tri can them vao STACK: ";
            cin >> x;
            push(stack, x);
            cout << "Cac phan tu cua STACK sau khi PUSH: ";
            output(stack);
            break;
        }
        case 2:
            if (pop(stack, x))
            {
                cout << "Gia tri lay duoc khi POP la: " << x << endl;
                cout
                    << "Cac phan tu cua STACK sau khi POP: ";
                output(stack);
            }
            break;
        case 3:
        {
            if (isEmpty(stack))
            {
                cout << "STACK is empty!\n";
            }
            else
            {
                cout << "STACK co phan tu!\n";
            }

            break;
        }
        case 4:
            cout << "So luong phan tu trong STACK: " << demSoPT(stack);
            break;
        case 5:
            deleteStack(stack);
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
    cout << "\nVui long chon chuc nang tuong ung";
    cout << "\n1. PUSH ";
    cout << "\n2. POP";
    cout << "\n3. Kiem tra Stack co rong hay khong";
    cout << "\n4. Dem so phan tu trong Stack";
    cout << "\n5. Xoa cac phan tu trong Stack";
    cout << "\n0. Thoat chuong trinh";
    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> lua_chon;
    return lua_chon;
}

// ARRAY
void CreatStack(Stack &stack)
{
    stack.top = -1;
}
void output(Stack stack)
{
    for (int i = 0; i <= stack.top; i++)
    {
        cout << stack.s[i] << " ";
    }
}
int demSoPT(Stack stack)
{
    if (stack.top == -1)
    {
        return 0;
    }

    return stack.top + 1;
}
int pop(Stack &stack, int &x)
{
    if (!isEmpty(stack))
    {
        x = stack.s[stack.top];
        stack.top--;
        return 1;
    }
    else
    {
        cout << "Stack rong";
        return 0;
    }
}
int push(Stack &stack, int x)
{
    if (stack.top == max - 1)
    {
        cout << "STACK is full!" << endl;
        return 0;
    }
    else
    {
        stack.s[++stack.top] = x;
    }
    return 1;
}
void deleteStack(Stack &stack)
{
    stack.top = -1;
}
bool isEmpty(Stack stack)
{
    if (stack.top == -1)
    {
        return true;
    }
    return false;
}

//List
void CreateStack(List &stack)
{
    stack.pHead = stack.pTail = NULL;
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
void push(List &stack, int x)
{
    Node *node = CreateNode(x);
    if (stack.pHead == NULL)
    {
        stack.pHead = stack.pTail = node;
    }
    else
    {
        stack.pTail->pNext = node;
        stack.pTail = node;
    }
}
int pop(List &stack, int &x)
{
    Node *p = stack.pHead;
    if (p == NULL)
    {
        cout << "Stack is empty! You can't pop";
        return 0;
    }
    if (p->pNext == NULL)
    {
        stack.pHead = stack.pTail = NULL;
        delete p;
        p = NULL;
        return 1;
    }

    while (true)
    {
        if (p->pNext == stack.pTail)
        {
            deleteAfter(stack, p);
            return 1;
        }
        p = p->pNext;
    }
    return 0;
}
bool deleteAfter(List &stack, Node *node)
{
    if (node != NULL)
    {
        Node *p = node->pNext;

        if (p != NULL)
        {
            node->pNext = p->pNext;
            if (p == stack.pTail)
            {
                stack.pTail = node;
            }
            delete p;
            p = NULL;
        }
        return true;
    }
    return false;
}
int demSoPT(List stack)
{
    int dem = 0;
    Node *p = stack.pHead;
    while (p != NULL)
    {
        dem++;
        p = p->pNext;
    }
    return dem;
}
bool isEmpty(List stack)
{
    if (stack.pHead == NULL)
    {
        return true;
    }
    return false;
}
void deleteStack(List &stack)
{
    Node *p = stack.pHead;
    while (p != NULL)
    {
        Node *temp = p;
        p = p->pNext;
        delete temp;
        temp = NULL;
    }
    stack.pHead = stack.pTail = NULL;
    cout << "Stack is deleted!\n";
}
void output(List stack)
{
    Node *p = stack.pHead;
    while (p != NULL)
    {
        cout << p->infor << " ";
        p = p->pNext;
    }
}