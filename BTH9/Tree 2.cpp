#include <iostream>
#include <time.h> 
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

int random(int min, int max);
void add(node*&, int);
void importTree(node*&, int&);

void print_RLN(node*);
void print_NLR(node*);
void print_NRL(node*);
void print_LRN(node*);
void print_LNR(node*);
void print_RNL(node*);
void printTree(node*);

bool isPrime(int x);
void printPrime(node* root);
int maxPrime(node* root);

void printNodes_levelK(node* tree, int level);
void checkNodes_levelK(node* root);

int evenTotal(node* root);

int minValue(node* root);
int maxValue(node* root);

int countNode_belowX(node* root, int x);
void print_nodeAmount(node* root);

int countNode_inRange(node* root, int x, int y);
void printNode_inRange(node* root);

void menu();
void choose(node*& tree, int& size);

int main() {
    node* tree = NULL;
    int n;
    choose(tree, n);
    system("pause");
}

int random(int min, int max) {
    static bool first = true;
    if (first) {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
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
    for (int i = 0; i < size; i++)
        add(TREE, random(10, 99));
    cout << "Cay nhi phan sau khi them cac phan tu la:" << endl;
    printTree(TREE);
    cout << endl;
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
    cout << "  RLN: ";
    print_RLN(root);
    cout << "\n  LRN: ";
    print_LRN(root);
    cout << "\n  NLR: ";
    print_NLR(root);
    cout << "\n  NRL: ";
    print_NRL(root);
    cout << "\n  RNL: ";
    print_RNL(root);
    cout << "\n  LNR: ";
    print_LNR(root);
    cout << endl;
}

bool isPrime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}
void printPrime(node* root) {
    if (root == NULL)
        return;
    if (isPrime(root->value))
        cout << root->value << " ";
    printPrime(root->leftBranch);
    printPrime(root->rightBranch);
}
int maxPrime(node* root) {
    static int result = 0;
    if (root == NULL)
        return 0;
    if ((result = maxPrime(root->rightBranch)) != 0)
        return result;
    if (isPrime(root->value))
        return root->value;
    if ((result = maxPrime(root->leftBranch)) != 0)
        return result;
}

void printNodes_levelK(node* tree, int level) {
    if (tree == NULL)
        return;
    level--;
    if (level == 0)
        cout << tree->value << " ";
    if (tree->leftBranch != NULL)
        printNodes_levelK(tree->leftBranch, level);
    if (tree->rightBranch != NULL)
        printNodes_levelK(tree->rightBranch, level);
}
void checkNodes_levelK(node* root) {
    int k;
    cout << "Muc can in la ";
    cin >> k;
    system("cls");
    printNodes_levelK(root, k + 1);
    cout << endl;
}

int evenTotal(node* root) {
    if (root == NULL)
        return 0;
    int a = evenTotal(root->leftBranch);
    int b = evenTotal(root->rightBranch);
    if (root->value % 2 == 0)
        return root->value + a + b;
    return a + b;
}

int minValue(node* root) {
    if (root->leftBranch == NULL)
        return root->value;
    return minValue(root->leftBranch);
}
int maxValue(node* root) {
    if (root->rightBranch == NULL)
        return root->value;
    return maxValue(root->rightBranch);
}

int countNode_belowX(node* root, int x) {
    if (root == NULL)
        return 0;
    int count = countNode_belowX(root->leftBranch, x) + countNode_belowX(root->rightBranch, x);
    if (root->value < x)
        return count + 1;
    else return count;
}
void print_nodeAmount(node* root) {
    int x;
    cout << "Gia tri x can doi chieu la ";
    cin >> x;
    system("cls");
    cout << "Trong cay co " << countNode_belowX(root, x) << " nut mang gia tri nho hon " << x << endl;
}

int countNode_inRange(node* root, int x, int y) {
    if (root == NULL)
        return 0;
    int count = countNode_inRange(root->leftBranch, x, y) + countNode_inRange(root->rightBranch, x, y);
    if (root->value > x && root->value < y)
        return count + 1;
    else return count;
}
void printNode_inRange(node* root) {
    int x, y;
    cout << "Hai can doi chieu la: " << endl;
    cout << " x = ";
    cin >> x;
    cout << " y = ";
    cin >> y;
    system("cls");
    cout << "Trong cay co " << countNode_inRange(root, x, y) << " nut mang gia tri lon hon " << x << " va nho hon " << y << endl;
}

void menu() {
    cout << "==============================================================" << endl;
    cout << " (1)  Tao day so ngau nhien roi nhap vao cay nhi phan" << endl;
    cout << " (2)  In ra cac so nguyen to tren cay" << endl;
    cout << " (3)  In ra so nguyen to lon nhat tren cay" << endl;
    cout << " (4)  In ra cac nut o muc K" << endl;
    cout << " (5)  Tinh tong cac so chan o cay con trai" << endl;
    cout << " (6)  In ra phan tu nho nhat o cay con phai" << endl;
    cout << " (7)  In ra phan tu lon nhat o cay con trai" << endl;
    cout << " (8)  Dem so nut co gia tri nho hon X" << endl;
    cout << " (9)  Dem so nut co gia tri lon hon X va nho hon Y" << endl;
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
        break;
    case 2:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else if (maxPrime(tree) > 0) {
            cout << "Cac so nguyen to co tren cay la: ";
            printPrime(tree);
            cout << endl;
        }
        else cout << "Khong co so nguyen to tren cay" << endl;
        break;
    case 3:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else {
            if (maxPrime(tree) > 0)
                cout << "So nguyen to lon nhat tren cay la " << maxPrime(tree) << endl;
            else cout << "Khong co so nguyen to tren cay" << endl;
        }
        break;
    case 4:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else checkNodes_levelK(tree);
        break;
    case 5:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else cout << "Tong cac so chan o cay con trai la " << evenTotal(tree->leftBranch) << endl;
        break;
    case 6:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else {
            if (minValue(tree->rightBranch) > 0)
                cout << "Phan tu nho nhat o cay con phai la " << minValue(tree->rightBranch) << endl;
            else cout << "Cay con phan khong co phan tu" << endl;
        }
        break;
    case 7:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else {
            if (maxValue(tree->leftBranch) > 0)
                cout << "Phan tu lon nhat o cay con trai la " << maxValue(tree->leftBranch) << endl;
            else cout << "Cay con trai khong co phan tu" << endl;
        }
        break;
    case 8:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else print_nodeAmount(tree);
        break;
    case 9:
        system("cls");
        if (tree == NULL)
            cout << "Khong co du lieu de thuc hien" << endl;
        else printNode_inRange(tree);
        break;
    default:
        choose(tree, size);
        break;
    }
    system("pause");
    choose(tree, size);
}