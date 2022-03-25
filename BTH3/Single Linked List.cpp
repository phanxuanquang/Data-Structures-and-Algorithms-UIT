#include <iostream>
using namespace std;

struct node {
    int number;
    node* link_toNext;
    void get_Newlink(node* x);
    node* import_node(int x);
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
    void print_fromHead();
    void print_fromTail(node* p);
    void import_fromHead(node* x);
    void import_fromTail(node* x);
    void del_Head();
    void del_Tail();
    void del_after(node* p);
    void import_after(node*& pre, node* ins);
};

void call_menu();
void choose();
void import_List_Head(list& l);
void import_List_Tail(list& l);
void quantity(list* x);
void delete_node(list& l);
void insert_node(list& l);
void find_node(list* l);

void main(){
    call_menu();
    choose();
    system("pause");
}

node* node::import_node(int x) {
    node* p = new node;
    if (p == NULL)
        return NULL;
    p->number = x;
    p->link_toNext = NULL;
    return p;
}
void node::get_Newlink(node* x) {
    this->link_toNext = x;
}

void list::print_fromHead() {
    cout << "Danh sach: ";
    for (node* temp = head; temp != NULL; temp = temp->link_toNext)
        cout << temp->number << " ";
    cout << endl;
}
void list::print_fromTail(node* p) {
    if (p != NULL) {
        print_fromTail(p->link_toNext);
        cout << p->number << " ";
    }
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
        cout << "Danh sach khong co phan tu de xoa" << endl;
    else if (head == tail) {
        node* temp = head;
        delete temp;
        head = tail = NULL;
        cout << "Da xoa phan tu dau danh sach" << endl;
    }
    else {
        node* temp = head;
        head = head->link_toNext;
        delete temp;
        cout << "Da xoa phan tu dau danh sach" << endl;
    }
}
void list::del_Tail() {
    if (head == NULL)
        cout << "Danh sach rong, khong co phan tu de xoa" << endl;
    else if (head == tail) {
        delete head;
        head = tail = NULL;
        cout << "Da xoa phan tu cuoi danh sach" << endl;
    }
    else {
        node* temp;
        for (temp = head; (temp->link_toNext)->link_toNext != NULL; temp = temp->link_toNext);
        node* last = tail;
        temp->link_toNext = NULL;
        tail = temp;
        delete last;
        cout << "Da xoa phan tu cuoi danh sach" << endl;
    }
}
void list::del_after(node* p) {
    if (p != NULL && p != tail) {
        node* temp = p->link_toNext;
        p->link_toNext = temp->link_toNext;
        delete temp;
    }
}
void list::import_after(node*& pre, node* ins) {
    if (pre != NULL && pre != tail) {
        ins->link_toNext = pre->link_toNext;
        pre->link_toNext = ins;
    }
}

void call_menu() {
    cout << "_____________________________" << endl << endl;
    cout << "1. Nhap vao danh sach n phan tu bang cach them vao dau danh sach va in ra danh sach vua nhap" << endl;
    cout << "2. Nhap vao danh sach n phan tu bang cach them vao cuoi danh sach va in ra danh sach vua nhap" << endl;
    cout << "3. In ra danh sach theo chieu tu cuoi len dau" << endl;
    cout << "4. Dem so nut co trong danh sach lien ket" << endl;
    cout << "5. Tim mot nut co thanh phan du lieu nhap tu ban phim" << endl;
    cout << "6. Xoa nut dau danh sach" << endl;
    cout << "7. Xoa nut cuoi danh sach" << endl;
    cout << "8. Xoa mot nut co thanh phan du lieu nhap tu ban phim" << endl;
    cout << "9. Chen mot nut co thanh phan du lieu nhap vao tai vi tri n" << endl;
    cout << "_____________________________" << endl << endl;
}
void choose() {
    cout << "Lua chon cua ban la: ";
    int choice;
    cin >> choice;
    system("cls");
    while (choice >= 11 || choice < 1) {
        cout << "Lua chon khong hop le, vui long nhap lai" << endl;
        cout << "Lua chon cua ban la: ";
        cin >> choice;
        system("cls");
    }
    list* l = new list;
    l->create();
    while (choice < 11 && choice >0) {
        switch (choice) {
        case 1:
            system("cls");
            import_List_Head(*l);
            l->print_fromHead();
            call_menu();
            break;
        case 2:
            system("cls");
            import_List_Tail(*l);
            l->print_fromHead();
            call_menu();
            break;
        case 3:
            system("cls");
            cout << "Danh sach dao nguoc: ";
            l->print_fromTail(l->get_Head());
            cout << endl;
            call_menu();
            break;
        case 4:
            system("cls");
            quantity(l);
            call_menu();
            break;
        case 5:
            system("cls");
            find_node(l);
            call_menu();
            break;
        case 6:
            system("cls");
            l->del_Head();
            l->print_fromHead();
            call_menu();
            break;
        case 7:
            system("cls");
            l->del_Tail();
            l->print_fromHead();
            call_menu();
            break;
        case 8:
            system("cls");
            delete_node(*l);
            l->print_fromHead();
            call_menu();
            break;
        case 9:
            system("cls");
            insert_node(*l);
            l->print_fromHead();
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
    cout << "Nhap so phan tu them vao: ";
    cin >> size;
    cout << "Nhap danh sach lien ket" << endl;
    node* temp = new node;
    for (int i = 1; i <= size; i++) {
        temp = new node;
        cout << " Phan tu thu " << i << " la: ";
        int n;
        cin >> n;
        temp = temp->import_node(n);
        l.import_fromHead(temp);
    }
    cout << endl;
}
void import_List_Tail(list& l) {
    int size;
    cout << "Nhap so phan tu them vao: ";
    cin >> size;
    cout << "Nhap danh sach lien ket" << endl;
    node* temp = new node;
    for (int i = 1; i <= size; i++) {
        temp = new node;
        cout << " Phan tu thu " << i << " la: ";
        int n;
        cin >> n;
        temp = temp->import_node(n);
        l.import_fromTail(temp);
    }
    cout << endl;
}
void quantity(list* x) {
    int count = 0;
    for (node* temp = x->get_Head(); temp != NULL; temp = temp->link_toNext)
        count++;
    cout << "So nut cua danh sach la " << count << endl;
}
void delete_node(list& l) {
    int x;
    cout << "Nhap so nguyen can xoa: ";
    cin >> x;
    if (l.get_Head()->number == x) {
        l.del_Head();
        return;
    }
    if (l.get_Tail()->number == x) {
        l.del_Tail();
        return;
    }
    node* p;
    for (p = l.get_Head(); p != NULL && p->link_toNext->number != x; p = p->link_toNext);
    if (p != NULL) {
        l.del_after(p);
        return;
    }
    cout << "Phan tu khong ton tai" << endl;
}
void insert_node(list& l) {
    cout << "So can chen la: ";
    int number;
    cin >> number;
    node* add = new node;
    add = add->import_node(number);
    cout << "Vi tri can chen la ";
    int pos;
    cin >> pos;
    int count = 0;
    node* p = l.get_Head();
    while (p != NULL) {
        if (++count == pos)
            break;
        p = p->link_toNext;
    }
    if (p == NULL) {
        if (pos == 0) {
            l.import_fromHead(add);
            cout << endl;
        }
        else {
            l.import_fromTail(add);
            cout << endl;
        }
    }
    else l.import_after(p, add);
}
void find_node(list* l) {
    cout << "Nhap so can tim: ";
    int x;
    cin >> x;
    for (node* temp = l->get_Head(); temp != NULL; temp = temp->link_toNext)
        if (x == temp->number) {
            cout << "Phan tu " << x << " co ton tai trong danh sach" << endl;
            return;
        }
    cout << "Phan tu " << x << " khong ton tai trong danh sach" << endl;
}