#include <iostream>
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

void addNode(node*&, int);
void importTree(node*&, int&);

void print_NLR(node*);

void findNode_1branch(node*);

bool isAvailable(node*, int);
void findX(node*);

bool isPrime(int);
void findPrime(node*);

void copyTree_toArray(node*, int[], int&);
void selectionSort(int[], int);
void copySort(node*);

void menu();
void choose(node*& tree);

int main() {
    int n;
    node* tree = NULL;
    importTree(tree, n);
    choose(tree);
}

void addNode(node*& root, int value) {
    if (root == NULL)
        root = new node(value);
    else if (value < root->value)
        addNode(root->leftBranch, value);
    else if (root->value < value)
        addNode(root->rightBranch, value);
}
void importTree(node*& tree, int& size) {
    cout << "So phan tu muon them la ";
    cin >> size;
    system("cls");
    int addElement;
    for (int i = 0; i < size; i++) {
        cout << "Phan tu thu " << i + 1 << " la: ";
        cin >> addElement;
        addNode(tree, addElement);
        system("cls");
    }
}

void print_NLR(node* tree) {
    if (tree == NULL)
        return;
    cout << tree->value << " ";
    print_NLR(tree->leftBranch);
    print_NLR(tree->rightBranch);
}

void findNode_1branch(node* tree) {
    if (tree == NULL)
        return;
    if ((tree->leftBranch == NULL && tree->rightBranch != NULL) || (tree->leftBranch != NULL && tree->rightBranch == NULL))
        cout << tree->value << " ";
    findNode_1branch(tree->leftBranch);
    findNode_1branch(tree->rightBranch);
}

bool isAvailable(node* tree, int x) {
    if (tree == NULL)
        return false;
    if (tree->value == x)
        return true;
    return isAvailable(tree->leftBranch, x) || isAvailable(tree->rightBranch, x);
}
void findX(node* tree) {
    int x;
    cout << "Gia tri can tim la ";
    cin >> x;
    system("cls");
    if (isAvailable(tree, x))
        cout << "Gia tri " << x << " co ton tai tren cay" << endl;
    else cout << "Gia tri " << x << " khong ton tai tren cay" << endl;
}

bool isPrime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}
void findPrime(node* tree) {
    if (tree == NULL)
        return;
    if (isPrime(tree->value))
        cout << tree->value << " ";
    findPrime(tree->leftBranch);
    findPrime(tree->rightBranch);
}

void copyTree_toArray(node* tree, int arr[], int& ArraySize) {
    if (tree == NULL)
        return;
    copyTree_toArray(tree->leftBranch, arr, ArraySize);
    copyTree_toArray(tree->rightBranch, arr, ArraySize);
    arr[ArraySize] = tree->value;
    ArraySize++;
}
void selectionSort(int arr[], int size) {
    int minIndex;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (arr[minIndex] > arr[j])
                minIndex = j;
        swap(arr[minIndex], arr[i]);
    }
}
void copySort(node* tree) {
    int size = 0;
    int arr[1000];
    copyTree_toArray(tree, arr, size);
    selectionSort(arr, size);
    cout << "Mang sau khi duoc sap xep la: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void menu() {
    cout << "================================================================================" << endl;
    cout << " (1) In ra cay theo phep duyet NLR" << endl;
    cout << " (2) In ra gia tri cac nut co mot cay con" << endl;
    cout << " (3) Kiem tra gia tri X co ton tai tren cay khong" << endl;
    cout << " (4) In ra cac so nguyen to tren cay" << endl;
    cout << " (5) Luu cac gia tri tren cay vao mang roi sap xep lai bang Selection Sort" << endl;
    cout << "================================================================================" << endl;
}
void choose(node*& tree) {
    menu();
    int choice;
    cout << "  Lua chon cua ban la: ";
    cin >> choice;
    switch (choice) {
    case 1:
        system("cls");
        cout << "Cay theo phep duyet NLR la: ";
        print_NLR(tree);
        cout << endl;
        choose(tree);
        break;
    case 2:
        system("cls");
        cout << "Cac nut chi co mot cay con la: ";
        findNode_1branch(tree);
        cout << endl;
        choose(tree);
        break;
    case 3:
        system("cls");
        findX(tree);
        choose(tree);
        break;
    case 4:
        system("cls");
        cout << "Cac so nguyen to tren cay la: ";
        findPrime(tree);
        cout << endl;
        choose(tree);
        break;
    case 5:
        system("cls");
        copySort(tree);
        choose(tree);
        break;
    default:
        system("cls");
        cout << " LUA CHON KHONG HOP LE" << endl;
        choose(tree);
        break;
    }
}