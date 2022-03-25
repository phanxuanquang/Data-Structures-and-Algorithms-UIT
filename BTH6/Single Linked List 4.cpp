#include <iostream>
#include <string>
using namespace std;

class student {
public:
    string name;
    string ID;
    int year_birth;
    double score;
public:
    double return_Score() {
        return score;
    }
    string return_Name() {
        return name;
    }
    int return_Year() {
        return year_birth;
    }
    void student_import();
    void student_export();
};

struct node {
    student sinhVien;
    node* link_toNext;
    double get_Score() {
        return sinhVien.return_Score();
    }
    int get_Year() {
        return sinhVien.return_Year();
    }
    void get_Newlink(node*);
    node* import_node(student);
};

class list {
    node* head;
    node* tail;
public:
    node* get_Head() {
        return head;
    }
    node* get_Tail() {
        return tail;
    }
    void create() {
        head = NULL;
        tail = NULL;
    }
    void print();
    void import_fromHead(node*);
    void import_fromTail(node*);
    void del_Head();
    void del_Tail();
    void del_after(node* p);
};

void call_menu();
void choose();
void import_List_Head(list&);
void import_List_Tail(list&);
void score_belowFive(list);
void delete_2000(list&);
void re_arrange(list&);
void delete_list(list&);

int main() {
    call_menu();
    choose();
    system("pause");
}

void student::student_import() {
    cout << "  Ho va ten sinh vien: ";
    int temp = getchar();
    getline(cin, name);
    cout << "  Ma sinh vien: ";
    int temp1 = getchar();
    getline(cin, ID);
    cout << "  Nam sinh: ";
    cin >> year_birth;
    while (year_birth < 1) {
        cout << "Nam sinh khong hop le, hay nhap lai" << endl;
        cout << "  Nam sinh: ";
        cin >> year_birth;
    }
    cout << "  Diem trung binh: ";
    cin >> score;
    while (score < 0 || score >10) {
        cout << "Diem khong hop le, hay nhap lai" << endl;
        cout << "  Diem trung binh: ";
        cin >> score;
    }
}
void student::student_export() {
    cout << "  Ho va ten sinh vien: ";
    cout << name << endl;
    cout << "  Ma sinh vien: ";
    cout << ID << endl;
    cout << "  Nam sinh: ";
    cout << year_birth << endl;
    cout << "  Diem trung binh: ";
    cout << score << endl;
}

node* node::import_node(student x) {
    node* p = new node;
    if (p == NULL)
        return NULL;
    p->sinhVien = x;
    p->link_toNext = NULL;
    return p;
}
void node::get_Newlink(node* x) {
    this->link_toNext = x;
}

void list::print() {
    cout << "Danh sach: " << endl;
    for (node* temp = head; temp != NULL; temp = temp->link_toNext)
        temp->sinhVien.student_export();
    cout << endl;
}
void list::import_fromHead(node* x) {
    if (head == NULL) {
        head = tail = x;
    }
    else {
        x->link_toNext = head;
        head = x;
    }
}
void list::import_fromTail(node* x) {
    if (head == NULL) {
        head = tail = x;
    }
    else {
        tail->get_Newlink(x);
        tail = x;
    }
}
void list::del_Head() {
    if (head == NULL)
        cout << "Danh sach khong co sinh vien de xoa" << endl;
    else if (head == tail) {
        node* temp = head;
        delete temp;
        head = tail = NULL;
        cout << "Da xoa sinh vien dau danh sach" << endl;
    }
    else {
        node* temp = head;
        head = head->link_toNext;
        delete temp;
        cout << "Da xoa sinh vien dau danh sach" << endl;
    }
}
void list::del_Tail() {
    if (head == NULL)
        cout << "Danh sach rong, khong co sinh vien de xoa" << endl;
    else if (head == tail) {
        delete head;
        head = tail = NULL;
        cout << "Da xoa sinh vien cuoi danh sach" << endl;
    }
    else {
        node* temp;
        for (temp = head; (temp->link_toNext)->link_toNext != NULL; temp = temp->link_toNext);
        node* last = tail;
        temp->link_toNext = NULL;
        tail = temp;
        delete last;
        cout << "Da xoa sinh vien cuoi danh sach" << endl;
    }
}
void list::del_after(node* p) {
    if (p != NULL && p != tail) {
        node* temp = p->link_toNext;
        p->link_toNext = temp->link_toNext;
        delete temp;
    }
}

void call_menu() {
    cout << "_____________________________" << endl << endl;
    cout << "1. Nhap vao danh sach n sinh vien bang cach them vao dau danh sach va in ra danh sach vua nhap" << endl;
    cout << "2. Nhap vao danh sach n sinh vien bang cach them vao cuoi danh sach va in ra danh sach vua nhap" << endl;
    cout << "3. In ra danh sach cac sinh vien co diem trung binh nho hon 5" << endl;
    cout << "4. Xoa cac sinh vien co nam sinh truoc 2000" << endl;
    cout << "5. Sap xep danh sach theo thu tu tang dan diem trung binh" << endl;
    cout << "6. In ra danh sach roi xoa toan bo danh sach" << endl;
    cout << "_____________________________" << endl << endl;
}
void choose() {
    cout << "Lua chon cua ban la: ";
    int choice;
    cin >> choice;
    system("cls");
    while (choice >= 7 || choice < 1) {
        cout << "Lua chon khong hop le, vui long nhap lai" << endl;
        cout << "Lua chon cua ban la: ";
        cin >> choice;
        system("cls");
    }
    list* l = new list;
    l->create();
    while (choice < 7 && choice >0) {
        switch (choice) {
        case 1:
            system("cls");
            import_List_Head(*l);
            l->print();
            call_menu();
            break;
        case 2:
            system("cls");
            import_List_Tail(*l);
            l->print();
            call_menu();
            break;
        case 3:
            system("cls");
            score_belowFive(*l);
            cout << endl;
            call_menu();
            break;
        case 4:
            system("cls");
            delete_2000(*l);
            l->print();
            call_menu();
            break;
        case 5:
            system("cls");
            re_arrange(*l);
            l->print();
            call_menu();
            break;
        case 6:
            system("cls");
            delete_list(*l);
            delete l;
            l = NULL;
            call_menu();
            break;
        default:
            system("cls");
            cout << "Nhan phim bat ky de thoat" << endl;
            system("pause");
            break;
        }
        cout << "Lua chon cua ban la: ";
        cin >> choice;
    }
}
void import_List_Head(list& l) {
    int size;
    cout << "Nhap so sinh vien can them vao: ";
    cin >> size;
    cout << "Nhap danh sach lien ket" << endl;
    node* temp = new node;
    for (int i = 1; i <= size; i++) {
        temp = new node;
        cout << "  Sinh vien thu " << i << ":" << endl;
        student x;
        x.student_import();
        temp = temp->import_node(x);
        l.import_fromHead(temp);
    }
    cout << endl;
}
void import_List_Tail(list& l) {
    int size;
    cout << "Nhap so sinh vien can them vao: ";
    cin >> size;
    cout << "Nhap danh sach lien ket" << endl;
    node* temp = new node;
    for (int i = 1; i <= size; i++) {
        temp = new node;
        cout << " sinh vien thu " << i << ":" << endl;
        student x;
        x.student_import();
        temp = temp->import_node(x);
        l.import_fromTail(temp);
    }
    cout << endl;
}
void score_belowFive(list l) {
    cout << "Danh sach cac sinh vien co diem trung binh duoi 5: ";
    for (node* temp = l.get_Head(); temp != NULL; temp = temp->link_toNext)
        if (temp->get_Score() < 5) {
            cout << temp->sinhVien.return_Name() << endl;
        }
}
void delete_2000(list& l) {
    if (l.get_Head()->get_Year() < 2000) {
        l.del_Head();
        return;
    }
    if (l.get_Tail()->get_Year() < 2000) {
        l.del_Tail();
        return;
    }
    for (node* p = l.get_Head(); p->link_toNext->get_Year() < 2000; p = p->link_toNext) {
        if (p != NULL) {
            l.del_after(p);
            return;
        }
    }
    cout << "Sinh vien khong ton tai" << endl;
}
void re_arrange(list& l) {
    for (node *p = l.get_Head(); p != NULL; p = p->link_toNext)
        for (node *q = p->link_toNext; q!= NULL; q = q->link_toNext) {
            if (p->sinhVien.return_Score() >= q->sinhVien.return_Score()) 
                swap(p->sinhVien, q->sinhVien);
        }
}
void delete_list(list& l) {
    for (node* p = l.get_Head(); p != NULL; p = p->link_toNext) {
        l.del_after(p);
        cout << "Da xoa toan bo danh sach" << endl;
    }
    l.del_Head();
}