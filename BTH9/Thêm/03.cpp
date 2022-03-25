#include <iostream>
#include <string>
using namespace std;

class item {
    string word;
    string meaning;
public:
    int getOrder_firstChar();
    string getMeaning();
    string getWord();

    void itemImport();
    void itemExport();

};

struct node {
    item value;
    node* leftBranch;
    node* rightBranch;
    node(item element) {
        value = element;
        leftBranch = rightBranch = NULL;
    }
};

bool isAvailable(node*, string);
void addItem(item, node*&);
void addWord(node*&, int&);

void exportWord(node*);

void getMeaning(node*, string);
void findMeaning(node* y);

node* minNode(node*);
void deleteNode(node*&, string);
void deleteWord(node*&);

void printLNR(node*);

void menu();
void choose(node*, int&);

int main(){
    int n;
    node* dictionary = NULL;
    choose(dictionary, n);
}

int item::getOrder_firstChar() {
    return int(word[0]);
}
string item::getMeaning() {
    return meaning;
}
string item::getWord() {
    return word;
}
void item::itemImport() {
    int temp = getchar();
    cout << "Tu vung: ";
    getline(cin, word);
    cout << "Nghia cua tu: ";
    getline(cin, meaning);
    system("cls");
}
void item::itemExport() {
    cout << "Tu vung: " << word << endl;
    cout << "Nghia cua tu '" << word << "' la: " << meaning << endl;
}

bool isAvailable(node* dictionary, string element) {
    if (dictionary == NULL)
        return false;
    if (dictionary->value.getWord() == element)
        return true;
    return isAvailable(dictionary->leftBranch, element) || isAvailable(dictionary->rightBranch, element);
}
void addItem(item element, node*& dictionary) {
    if (dictionary == NULL)
        dictionary = new node(element);
    else if (element.getOrder_firstChar() > dictionary->value.getOrder_firstChar())
        addItem(element, dictionary->rightBranch);
    else if (element.getOrder_firstChar() < dictionary->value.getOrder_firstChar())
        addItem(element, dictionary->leftBranch);
}
void addWord(node*& dictionary, int& amount) {
    item element;
    element.itemImport();
    addItem(element, dictionary);
    amount++;
}

void exportWord(node* dictionary) {
    if (dictionary == NULL)
        return;
    cout << dictionary->value.getWord() << " is " << dictionary->value.getMeaning() << endl;
    exportWord(dictionary->leftBranch);
    exportWord(dictionary->rightBranch);
}

void getMeaning(node* dictionary, string x) {
    if (dictionary == NULL)
        return;
    if (dictionary->value.getWord() == x)
        cout << dictionary->value.getMeaning();
    getMeaning(dictionary->rightBranch, x);
    getMeaning(dictionary->leftBranch, x);
}
void findMeaning(node* dictionary) {
    string s;
    int temp = getchar();
    cout << "Tu can tim nghia la: ";
    getline(cin, s);
    system("cls");
    if (!isAvailable(dictionary, s))
        cout << "Tu '" << s << "' khong ton tai trong tu dien" << endl;
    else {
        cout << "Nghia cua tu '" << s << "' la: ";
        getMeaning(dictionary, s);
        cout << endl;
    }
}

node* minNode(node* dictionary) {
    if (dictionary == NULL)
        return NULL;
    while (dictionary != NULL)
        dictionary = dictionary->leftBranch;
    return dictionary;
}
void deleteNode(node*& dictionary, string element) {
    if (dictionary == NULL || !isAvailable(dictionary, element))
        return;
    if (dictionary->value.getWord() == element) {
        if (dictionary->leftBranch == NULL && dictionary->rightBranch == NULL) {
            delete dictionary;
            dictionary = NULL;
        }
        else if (dictionary->leftBranch == NULL && dictionary->rightBranch != NULL) {
            node* temp = dictionary;
            dictionary = dictionary->rightBranch;
            delete temp;
            temp = NULL;
        }
        else if (dictionary->leftBranch != NULL && dictionary->rightBranch == NULL) {
            node* temp = dictionary;
            dictionary = dictionary->leftBranch;
            delete temp;
            temp = NULL;
        }
        else {
            node* temp = dictionary;
            dictionary = minNode(dictionary->rightBranch);
            delete temp;
            temp = NULL;
        }
    }
    deleteNode(dictionary->leftBranch, element);
    deleteNode(dictionary->rightBranch, element);
}
void deleteWord(node*& dictionary) {
    string s;
    int temp = getchar();
    cout << "Tu muon xoa khoi tu dien la: ";
    getline(cin, s);
    system("cls");
    if (!isAvailable(dictionary, s))
        cout << "Tu '" << s << "' khong ton tai trong tu dien" << endl;
    else {
        deleteNode(dictionary, s);
        cout << "Da xoa tu '" << s << "' khoi tu dien" << endl;
    }
}

void printLNR(node* dictionary) {
    if (dictionary == NULL)
        return;
    printLNR(dictionary->leftBranch);
    dictionary->value.itemExport();
    cout << endl;
    printLNR(dictionary->rightBranch);
}

void menu() {
    cout << "===================================================" << endl;
    cout << " (1) Them mot item vao tu dien" << endl;
    cout << " (2) Tim nghia cua mot tu nhap vao tu ban phim" << endl;
    cout << " (3) Xoa mot tu khoi tu dien" << endl;
    cout << " (4) In tu dien theo thu tu tang dang cua word" << endl;
    cout << "===================================================" << endl;
}
void choose(node* dictionary, int& n) {
    menu();
    int choice;
    cout << "  Lua chon cua ban la: ";
    cin >> choice;
    switch (choice) {
    case 1:
        system("cls");
        addWord(dictionary, n);
        cout << "Da them" << endl;
        choose(dictionary, n);
        break;
    case 2:
        system("cls");
        findMeaning(dictionary);
        choose(dictionary, n);
        break;
    case 3:
        system("cls");
        deleteWord(dictionary);
        choose(dictionary, n);
        break;
    case 4:
        system("cls");
        printLNR(dictionary);
        choose(dictionary, n);
        break;
    default:
        system("cls");
        choose(dictionary, n);
        break;
    }
}