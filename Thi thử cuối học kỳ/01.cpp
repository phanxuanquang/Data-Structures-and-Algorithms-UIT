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

void add(node*&, int);
void importTree(node*&, int&);
void print_RNL(node*);

bool isAvailable(node* tree, int x);
void findParent(node* tree, int val, int parent);
void findNode(node* tree);

int level(node* tree, int data);
void printLevel(node* root, node* tree);

int rankOf(node* tree);
void rank_ofLevel(node* BST, node* root, int level);
void printRank(node* tree);

void menu();
void choose(node*& tree);

int main() {
    node* tree = NULL;
    choose(tree);
}

void add(node*& root, int value) {
    if (root == NULL)
        root = new node(value);
    else if (value < root->value)
        add(root->leftBranch, value);
    else if (root->value < value)
        add(root->rightBranch, value);
}
void importTree(node*& TREE) {
    int addValue = 1;
    while (addValue > 0) {
        cout << "Phan tu them vao la: ";
        cin >> addValue;
        add(TREE, addValue);
        system("cls");
    }
    cout << "Cay nhi phan sau khi them cac phan tu la: ";
    print_RNL(TREE);
    cout << endl;
}

void print_RNL(node* root) {
    if (root) {
        print_RNL(root->rightBranch);
        cout << root->value << " ";
        print_RNL(root->leftBranch);
    }
}

bool isAvailable(node* tree, int x) {
    if (tree == NULL)
        return false;
    if (tree->value == x)
        return true;
    return isAvailable(tree->leftBranch, x) || isAvailable(tree->rightBranch, x);
}
void findParent(node* tree, int val, int parent) {
    if (tree == NULL)
        return;
    if (tree->value == val)
        cout << parent << endl;
    else {
        findParent(tree->leftBranch, val, tree->value);
        findParent(tree->rightBranch, val, tree->value);
    }
}
void findNode(node* tree) {
    int x;
    cout << "Gia tri cua nut con la: ";
    cin >> x;
    system("cls");
    if (tree == NULL)
        cout << "Gia tri cua nut cha la: " << 0 << endl;
    else {
        cout << "Gia tri cua nut cha la: ";
        if (tree->value == x)
            cout << 1 << endl;
        else if (!isAvailable(tree, x))
            cout << 0 << endl;
        else findParent(tree, x, 0);
    }
}

int level(node* tree, int data) {
    if (tree != NULL && tree->value != data) {
        if (tree->value > data)
            return 1 + level(tree->leftBranch, data);
        else return 1 + level(tree->rightBranch, data);
    }
    return 0;
}
void printLevel(node* tree, node *root) {
    if (tree == NULL)
        return;
    printLevel(tree->leftBranch, root);
    cout << level(root, tree->value) << " ";
    printLevel(tree->rightBranch, root);
}

int rankOf(node* tree) {
    if (tree != NULL) {
        if (tree->leftBranch != NULL) {
            if (tree->rightBranch != NULL)
                return 2;
            return 1;
        }
        else if (tree->rightBranch != NULL) {
            return 1;
        }
        else return 0;
    }
    return -1;
} 
void rank_ofLevel(node* BST, node* root, int levelX) {
    if (BST != NULL) {
        rank_ofLevel(BST->rightBranch, root, levelX);
        if (level(root, BST->value) == levelX + 1)
            cout << rankOf(BST) << " ";
        rank_ofLevel(BST->leftBranch, root, levelX);
    }
}
void printRank(node *tree) {
    int l;
    cout << "L = ";
    cin >> l;
    system("cls");
    rank_ofLevel(tree, tree, l);
}

void menu() {
    cout << "==============================================================" << endl;
    cout << " (1)  Nhap vao mang so nguyen duong" << endl;
    cout << " (2)  In ra gia tri nut cha cua X" << endl;
    cout << " (3)  In ra bac cua cac nut theo thu tu tang dan" << endl;
    cout << " (4)  In ra bac cua cac nut co muc L+1 theo thu tu giam dan" << endl;
    cout << "==============================================================" << endl;
}
void choose(node*& tree) {
    int choice;
    menu();
    cout << " Lua chon cua ban la: ";
    cin >> choice;
    switch (choice) {
    case 1:
        system("cls");
        importTree(tree);
        choose(tree);
        break;
    case 2:
        system("cls");
        findNode(tree);
        choose(tree);
        break;
    case 3:
        system("cls");
        printLevel(tree, tree);
        cout << endl;
        choose(tree);
        break;
    case 4:
        system("cls");
        printRank(tree);
        cout << endl;
        choose(tree);
        break;
    default:
        choose(tree);
        break;
    }
}