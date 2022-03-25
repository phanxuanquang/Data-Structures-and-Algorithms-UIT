#include <iostream>
#include <queue>
using namespace std;

struct node {
    int value;
    node* leftBranch;
    node* rightBranch;
    node(int value) {
        this->value = value;
        leftBranch = rightBranch = NULL;
    }
};

void add(node*&, int);
void importTree(node*&, int&);

void print_RLN(node*);
void print_NLR(node*);
void print_NRL(node*);
void print_LRN(node*);
void print_LNR(node*);
void print_RNL(node*);
void printTree(node*);

bool isAvailable(node*, int);
void findX(node*);

node* minNode(node*);
void deleteNode(node*&, int);
void deleteX(node*&);

int countNode(node*);
int countNode_2branch(node*);
int countNode_1branch(node*);
int countNode_rightBranch(node*);
int countNode_noBranch(node*);

int height(node*);

void find_evenNode(node* root);

int amount_greaterThanX(node*, int);
void find_greaterThanX(node*);

int maxValue(node*);

int maxValue_rightBranch(node*);

void printNode_level(node*);

node* Node(node*, int);
int heightX(node*, int);
void findPath_X(node*);

void menu();
void choose(node*&, int&);

int main() {
	node* tree = NULL;
    int n;
    choose(tree, n);
    system("pause");
}

void add(node*& root, int value) {
    if (root == NULL)
        root = new node(value);
    else if (value < root->value)
        add(root->leftBranch, value);
    else if (root->value < value)
        add(root->rightBranch, value);
}
void importTree(node*& TREE, int& size) {
    cout << "So phan tu muon them la ";
    cin >> size;
    system("cls");
    int addValue;
    for (int i = 0; i < size; i++) {
        cout << "Nhap cac phan tu!" << endl;
        cout << "Phan tu them vao thu " << i + 1 << ": ";
        cin >> addValue;
        add(TREE, addValue);
        system("cls");
    }
}

void print_RLN(node* root) {
    if (root) {
        print_RLN(root->rightBranch);
        print_RLN(root->leftBranch);
        cout << root->value << " ";
    }
}
void print_NLR(node* root) {
    if (root) {
        cout << root->value << " ";
        print_NLR(root->leftBranch);
        print_NLR(root->rightBranch);
    }
}
void print_NRL(node* root) {
    if (root) {
        cout << root->value << " ";
        print_NRL(root->rightBranch);
        print_NRL(root->leftBranch);
    }
}
void print_LRN(node* root) {
    if (root) {
        print_LRN(root->leftBranch);
        print_LRN(root->rightBranch);
        cout << root->value << " ";
    }
}
void print_LNR(node* root) {
    if (root) {
        print_LNR(root->leftBranch);
        cout << root->value << " ";
        print_LNR(root->rightBranch);
    }
}
void print_RNL(node* root) {
    if (root) {
        print_LNR(root->rightBranch);
        cout << root->value << " ";
        print_LNR(root->leftBranch);
    }
}
void printTree(node* root) {
    cout << "RLN: ";
    print_RLN(root);
    cout << "\nLRN: ";
    print_LRN(root);
    cout << "\nNLR: ";
    print_NLR(root);
    cout << "\nNRL: ";
    print_NRL(root);
    cout << "\nRNL: ";
    print_RNL(root);
    cout << "\nLNR: ";
    print_LNR(root);
    cout << endl;
}

bool isAvailable(node* root, int value) {
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;
    if (value < root->value)
        return isAvailable(root->leftBranch, value);
    else if (root->value < value)
        return isAvailable(root->rightBranch, value);
    return false;
}
void findX(node* root) {
    int x;
    cout << "Gia tri can tim la ";
    cin >> x;
    if (isAvailable(root, x))
        cout << "Gia tri " << x << " co ton tai trong cay" << endl;
    else cout << "Gia tri " << x << " khong ton tai trong cay" << endl;
}

node* minNode(node* root) {
    while (root->leftBranch != NULL)
        root = root->leftBranch;
    return root;
}
void deleteNode(node*& root, int value) {
    if (root == NULL || isAvailable(root, value) == false) {
        cout << "Khong ton tai node can xoa" << endl;
        return;
    }
    if (value > root->value)
        deleteNode(root->rightBranch, value);
    else if (value < root->value)
        deleteNode(root->leftBranch, value);
    else {
        if (root->leftBranch == NULL && root->rightBranch == NULL) {
            delete root;
            root = NULL;
            cout << "Xoa thanh cong" << endl;
        }
        else if (root->leftBranch == NULL && root->rightBranch != NULL) {
            node* temp = root;
            root = root->rightBranch;
            delete temp;
            temp = NULL;
        }
        else if (root->rightBranch == NULL && root->leftBranch != NULL) {
            node* temp = root;
            root = root->leftBranch;
            delete temp;
            temp = NULL;
            cout << "Xoa thanh cong" << endl;
        }
        else {
            node* temp = minNode(root->rightBranch);
            swap(root->value, temp->value);
            deleteNode(root->rightBranch, value);
        }
    }
}
void deleteX(node*& root) {
    int x;
    cout << "Gia tri can xoa la ";
    cin >> x;
    deleteNode(root, x);
}

int countNode(node* root) {
    if (root == NULL)
        return 0;
    int a = countNode(root->leftBranch);
    int b = countNode(root->rightBranch);
    return a+ b + 1;
}
int countNode_2branch(node* root) {
    if (root == NULL)
        return 0;
    int a = countNode_2branch(root->leftBranch);
    int b = countNode_2branch(root->rightBranch);
    if (root->leftBranch != NULL && root->rightBranch != NULL)
        return a + b + 1;
    return a + b;
}
int countNode_1branch(node* root) {
    if (root == NULL)
        return 0;
    int a = countNode_1branch(root->leftBranch);
    int b = countNode_1branch(root->rightBranch);
    if ((root->leftBranch != NULL && root->rightBranch == NULL) || (root->leftBranch == NULL && root->rightBranch != NULL))
        return a + b + 1;
    return a + b;
}
int countNode_rightBranch(node* root) {
    if (root == NULL)
        return 0;
    int a = countNode_rightBranch(root->leftBranch);
    int b = countNode_rightBranch(root->rightBranch);
    if (root->leftBranch == NULL && root->rightBranch != NULL)
        return a + b + 1;
    return a + b;
}
int countNode_noBranch(node* root) {
    if (root == NULL)
        return 0;
    int a = countNode_noBranch(root->leftBranch);
    int b = countNode_noBranch(root->rightBranch);
    if (root->leftBranch == NULL && root->rightBranch == NULL)
        return 1;
    return a + b;
}

int height(node* root) {
    if (root == NULL)
        return 0;
    int a = height(root->leftBranch);
    int b = height(root->rightBranch);
    return max(a, b) + 1;
}

void find_evenNode(node* root) {
    if (root != NULL) {
        if (root->value % 2 == 0)
            cout << root->value << " ";
        find_evenNode(root->leftBranch);
        find_evenNode(root->rightBranch);
    }
}

int amount_greaterThanX(node* root, int value) {
    if (root == NULL)
        return 0;
    int a = amount_greaterThanX(root->leftBranch, value);
    int b = amount_greaterThanX(root->rightBranch, value);
    if (root->value > value)
        return a + b + 1;
    return a + b;
}
void find_greaterThanX(node* root) {
    int x;
    cout << "Gia tri X la ";
    cin >> x;
    cout << "So node co gia tri lon hon " << x << " la " << amount_greaterThanX(root, x) << endl;
}

int maxValue(node* root) {
    if (root == NULL)
        return 0;
    int max = root->value;
    int a = maxValue(root->leftBranch);
    int b = maxValue(root->rightBranch);
    if (a > max)
        max = a;
    if (b > max)
        max = b;
    return max;
}

int maxValue_rightBranch(node* root) {
    if (root == NULL)
        return 0;
    int min = root->value;
    int a = maxValue(root->rightBranch);
    if (a < min)
        min = a;
    return min;
}

void printNode_level(node* root) {
    if (root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        int n = size;
        while (n--) {
            node* Node = q.front();
            q.pop();
            if (n == size - 1 || n == 0)
                cout << Node->value << " ";
            if (Node->leftBranch != NULL)
                q.push(Node->leftBranch);
            if (Node->rightBranch != NULL)
                q.push(Node->rightBranch);
        }
        cout << endl;
    }
}

node* Node(node* root, int value) {
    if (root == NULL)
        return NULL;
    if (root->value == value)
        return root;
    if (value < root->value)
        return Node(root->leftBranch, value);
    else if (root->value < value)
        return Node(root->rightBranch, value);
    return NULL;
}
int heightX(node* tree, int data) {
    if (tree != NULL && tree->value != data) {
        if (tree->value > data) {
            return heightX(tree->leftBranch, data) + 1;
        }
        else return heightX(tree->rightBranch, data) + 1;
    }
    return 0;
}
void findPath_X(node* root) {
    int x;
    cout << "Gia tri X la ";
    cin >> x;
    if (Node(root, x))
        cout << "Do dai duong di ngan nhat tu goc den node co gia tri " << x << " la " << heightX(root, x) << endl;
    else cout << "Duong di khong ton tai" << endl;
}

void menu() {
    cout << "==============================================================" << endl;
    cout << " (1)  Nhap vao cay nhi phan va in ra cay theo moi thu tu" << endl;
    cout << " (2)  Tim mot node tren cay" << endl;
    cout << " (3)  Xoa mot node tren cay" << endl;
    cout << " (4)  Tinh tong so node tren cay" << endl;
    cout << " (5)  Tinh tong so node co hai cay con" << endl;
    cout << " (6)  Tinh tong so node co mot cay con" << endl;
    cout << " (7)  Tinh tong so node chi co cay con phai" << endl;
    cout << " (8)  Tinh tong so node la tren cay" << endl;
    cout << " (9)  Tinh chieu cao cua cay" << endl;
    cout << " (10) In ra cac node co gia tri chan" << endl;
    cout << " (11) Tim so node co gia tri lon hon gia tri X nhap tu ban phim" << endl;
    cout << " (12) Tim gia tri cua node co gia tri lon nhat tren cay" << endl;
    cout << " (13) Tim gia tri co key nho nhat cua cay con phai" << endl;
    cout << " (14) In ra cac node tren tung muc cua cay" << endl;
    cout << " (15) Tim do dai duong di tu goc den node co gia tri X" << endl;
    cout << " (16) Thoat chuong trinh" << endl;
    cout << "==============================================================" << endl;
}
void choose(node*& tree, int& size) {
    system("cls");
    int choice;
    menu();
    cout << " Lua chon cua ban la: ";
    cin >> choice;
    switch (choice) {
    case 1:
        system("cls");
        importTree(tree, size);
        system("cls");
        printTree(tree);
        break;
    case 2:
        system("cls");
        findX(tree);
        break;
    case 3:
        system("cls");
        deleteX(tree);
        printTree(tree);
        break;
    case 4:
        system("cls");
        cout << "Tong so node tren cay la " << countNode(tree) << endl;
        break;
    case 5:
        system("cls");
        cout << "Tong so node co day du hai cay con tren cay la " << countNode_2branch(tree) << endl;
        break;
    case 6:
        system("cls");
        cout << "Tong so node chi co mot cay con tren cay la " << countNode_1branch(tree) << endl;
        break;
    case 7:
        system("cls");
        cout << "Tong so node chi co mot cay con phai tren cay la " << countNode_rightBranch(tree) << endl;
        break;
    case 8:
        system("cls");
        cout << "Tong so la tren cay la " << countNode_noBranch(tree) << endl;
        break;
    case 9:
        system("cls");
        cout << "Chieu cao cua cay la " << height(tree) - 1 << endl;
        break;
    case 10:
        system("cls");
        cout << "Cac node mang gia tri chan tren cay la ";
        if (tree == NULL)
            cout << "khong co" << endl;
        else find_evenNode(tree);
        cout << endl;
        break;
    case 11:
        system("cls");
        find_greaterThanX(tree);
        break;
    case 12:
        system("cls");
        cout << "Gia tri lon nhat tren cay la " << maxValue(tree) << endl;
        break;
    case 13:
        system("cls");
        cout << "Gia tri lon nhat tren cay con phai la " << maxValue_rightBranch(tree) << endl;
        break;
    case 14:
        system("cls");
        printNode_level(tree);
        break;
    case 15:
        system("cls");
        findPath_X(tree);
        break;
    case 16:
        return;
    default:
        choose(tree, size);
        break;
    }
    system("pause");
    choose(tree, size);
}