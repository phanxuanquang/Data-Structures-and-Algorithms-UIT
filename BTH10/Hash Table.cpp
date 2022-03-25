#include <iostream>
#include <vector>
using namespace std;

class hashTable {
public:
    int tableSize;
    int* table;
    hashTable();

    virtual int valueOf(int);
    virtual void addValue(int);
    virtual int getValue(int);

    void add_manyValue();
    virtual void printTable();
};

class hashLinear : public hashTable {
public:
    int valueOf(int);
    void addValue(int);
    int getValue(int);
};
class hashSquare : public hashTable {
public:
    int valueOf(int);
    void addValue(int);
    int getValue(int);
};

class hashChain : public hashTable {
    vector<int> chain[11];
public:
    virtual int valueOf(int x);
    void addValue(int element);
    int getValue(int element);
    void printTable();
};
class hashChain_f1 : public hashChain {
    int valueOf(int x);
};
class hashChain_f2 : public hashChain {
    int valueOf(int x);
};

void menu();
void choose(hashTable*&);

void menu_hashChain();
void choose_hashChain(hashTable*&);

int main(){
    hashTable *table;
    choose(table);
}

hashTable::hashTable() {
    tableSize = 11;
    table = new int[tableSize];
    for (int i = 0; i < tableSize; i++)
        table[i] = -1;
}
int hashTable::valueOf(int) {
    return 0;
}
void hashTable::addValue(int) {
    cout << "Nothing here";
}
int hashTable::getValue(int) {
    return 0;
}

void hashTable::add_manyValue() {
    addValue(32);
    addValue(15);
    addValue(25);
    addValue(44);
    addValue(36);
    addValue(21);
}
void hashTable::printTable() {
    cout << "    KEY     VALUE" << endl;
    cout << "   ----     -----" << endl;
    for (int i = 0; i < tableSize; i++)
        if (table[i] != -1)
            cout << "    " << table[i] << "        " << getValue(table[i]) << endl;
}

int hashLinear::valueOf(int x) {
    return x % tableSize;
}
void hashLinear::addValue(int element) {
    int index = valueOf(element);
    while (table[index] != -1)
        index = valueOf(index + 1);
    table[index] = element;
}
int hashLinear::getValue(int element) {
    int index = valueOf(element);
    while (table[index] != -1 && table[index] != element)
        index = valueOf(index + 1);
    if (table[index] == element)
        return index;
    else return -1;
}

int hashSquare::valueOf(int x) {
    return x % tableSize;
}
void hashSquare::addValue(int element) {
    int index = valueOf(element);
    int k = 0;
    while (table[index] != -1) {
        k++;
        index = valueOf(valueOf(element) + k * k);
    }
    table[index] = element;
}
int hashSquare::getValue(int element) {
    int index = valueOf(element);
    int k = 0;
    while (table[index] != -1 && table[index] != element) {
        k++;
        index = valueOf(valueOf(element) + k * k);
    }
    if (table[index] == element)
        return index;
    else return -1;
}

int hashChain::valueOf(int x) {
    return x % tableSize;
}
void hashChain::addValue(int element) {
    int index = valueOf(element);
    chain[index].push_back(element);
}
int hashChain::getValue(int element) {
    int index = valueOf(element);
    for (int i = 0; i < tableSize; i++)
        for (auto value : chain[index])
            if (value == element)
                return index;
    return -1;
}
void hashChain::printTable() {
    cout << "    KEY     VALUE" << endl;
    cout << "   ----     -----" << endl;
    for (int i = 0; i < tableSize; i++) {
        size_t j;
        for (j = 0; j < chain[i].size(); j++)
            cout << "   " << chain[i][j];
        if (j != 0) 
            cout << "        " << i << endl;     
    }
}

int hashChain_f1::valueOf(int x) {
    return x % tableSize;
}
int hashChain_f2::valueOf(int x) {
    return (tableSize - 2) - (x % (tableSize - 2));
}

void menu() {
    cout << "=========================================================" << endl;
    cout << " Luu y: Bang bam da duoc them san cac gia tri 32, 15, 25, 44, 36 va 21" << endl;
    cout << "  (1) Tham do tuyen tinh" << endl;
    cout << "  (2) Tham do binh phuong" << endl;
    cout << "  (3) Tham do day chuyen" << endl;
    cout << "=========================================================" << endl;
}
void choose(hashTable*& table) {
    int choice;
    menu();
    cout << "  Lua chon cua ban la: ";
    cin >> choice;
    system("cls");
    switch (choice) {
    case 1:
        system("cls");
        table = new hashLinear;
        table->add_manyValue();
        table->printTable();
        choose(table);
        break;
    case 2:
        system("cls");
        table = new hashSquare;
        table->add_manyValue();
        table->printTable();
        choose(table);
        break;
    case 3:
        system("cls");
        choose_hashChain(table);
        choose(table);
        break;
    default:
        system("cls");
        choose(table);
        break;
    }
}

void menu_hashChain() {
    cout << "===============================================================================" << endl;
    cout << "  (1) Bam theo cong thuc F(key) = key % M'" << endl;
    cout << "  (2) Bam theo cong thuc F(key) = (tableSize - 2) - (x % (tableSize - 2))" << endl;
    cout << "===============================================================================" << endl;
}
void choose_hashChain(hashTable*& table) {
    int choice;
    menu_hashChain();
    cout << "  Lua chon cua ban la: ";
    cin >> choice;
    system("cls");
    switch (choice) {
    case 1:
        system("cls");
        table = new hashChain_f1;
        table->add_manyValue();
        table->printTable();
        choose(table);
        break;
    case 2:
        system("cls");
        table = new hashChain_f2;
        table->add_manyValue();
        table->printTable();
        choose(table);
        break;
    default:
        system("cls");
        choose(table);
        break;
    }
}