#include <iostream>
#include <string>
using namespace std;

class student {
public:
    string name;
    string ID;
    double score;
public:
    void import() {
        cout << "Ten sinh vien: ";
        int temp = getchar();
        getline(cin, name);
        cout << "Ma sinh vien: ";
        getline(cin, ID);
        cout << "Diem trung binh: ";
        cin >> score;
        while (score < 0 || score > 10)
        {
            cout << "Diem trung binh khong hop le, hay nhap lai" << endl;
            cout << "Diem trung binh: ";
            cin >> score;
        }
        cout << endl;
    }
    void infoExport() {
        cout << "Ten sinh vien: ";
        cout << name << endl;
        cout << "Ma sinh vien: ";
        cout << ID << endl;
        cout << "Diem trung binh: ";
        cout << score << endl;
    }
};

void arrayImport(student x[], int& y);
void arrayExport(student x[], int& y);

void maxExport(student x[], int y);

void find_Above5(student x[], int y);
void find_student(student x[], int y);

void detele_student(student x[], int& y);
void add_student(student x[], int& y);

int main()
{
    int n, x;
    cout << "So sinh vien la: ";
    cin >> n;
    student* sinhVien = new student[n];
    arrayImport(sinhVien, n);

    cout << endl;
    cout << "1. In danh sach sinh vien" << endl;
    cout << "2. Liet ke cac sinh vien co diem trung binh cao nhat lop" << endl;
    cout << "3. Cho biet so sinh vien co diem trung binh tu 5 tro len" << endl;
    cout << "4. Tim sinh vien co ten X trong lop" << endl;
    cout << "5. Xoa sinh vien co ma so cho truoc" << endl;
    cout << "6. Them mot sinh vien vao lop hoc" << endl;
    cout << endl;

    cout << "Nhap tuy chon: ";
    cin >> x;
    cout << endl;

    while (x != 0)
    {
        switch (x) {
        case 1:
            arrayExport(sinhVien, n);
            break;
        case 2:
            maxExport(sinhVien, n);
            break;
        case 3:
            find_Above5(sinhVien, n);
            break;
        case 4:
            find_student(sinhVien, n);
            break;
        case 5:
            detele_student(sinhVien, n);
            break;
        case 6:
            add_student(sinhVien, n);
            break;
        default:
            cout << "Khong ton tai lua chon";
            break;
        }
        cout << "Nhap tuy chon: ";
        cin >> x;
        cout << endl;
    }
}

void arrayImport(student x[], int& y) {
    cout << endl << "Nhap danh sach sinh vien: " << endl << endl;
    for (int i = 0; i < y; i++)
    {
        cout << "Sinh vien thu " << i + 1 << ": " << endl;
        x[i].import();
    }
}

void arrayExport(student x[], int& y) {
    cout << "Danh sach sinh vien vua nhap la: " << endl;
    for (int i = 0; i < y; i++)
    {
        x[i].infoExport();
        cout << endl << endl;
    }
}

void maxExport(student x[], int y) {
    cout << "Cac sinh vien co diem trung binh cao nhat la: " << endl;
    double max = x[0].score;
    for (int i = 1; i < y; i++)
        if (x[i].score > max)
            max = x[i].score;
    for (int i = 1; i < y; i++)
        if (x[i].score == max)
            cout << " " << x[i].name << endl;
    cout << endl;
}

void find_Above5(student x[], int y) {
    int temp = 0;
    for (int i = 0; i < y; i++)
        if (x[i].score >= 5)
            temp += 1;
    if (temp > 0)
        cout << "So sinh vien co diem trung binh tu 5 tro len la " << temp << endl << endl;
    else cout << "Khong co sinh vien nao co diem trung binh tu 5 tro len." << endl << endl;
}

void find_student(student x[], int y) {
    string name;
    cout << "Nhap ten sinh vien can tim: ";
    int temp = getchar();
    getline(cin, name);
    for (int i = 0; i < y; i++)
        if (x[i].name == name)
        {
            cout << "Thong tin cua sinh vien can tim la: " << endl;
            x[i].infoExport();
            cout << endl << endl;
            return;
        }
    cout << "Sinh vien khong ton tai" << endl;
    cout << endl << endl;
}

void detele_student(student x[], int& y) {
    string ID;
    cout << "Nhap ma sinh vien can xoa: ";
    int temp = getchar();
    getline(cin, ID);
    for (int i = 0; i < y; i++)
        if (x[i].ID == ID)
        {
            y--;
            cout << "Da xoa sinh vien co ma " << x[i].ID << " khoi danh sach" << endl;
            for (int j = i; j < y; j++)
                x[j] = x[j + 1];
            return;
        }
    cout << "Sinh vien khong ton tai" << endl;
    cout << endl;
}

void add_student(student x[], int& y) {
    cout << "Nhap thong tin sinh vien can them: " << endl;
    y++;
    x[y-1].import();
    for (int i = 0; i < y - 1; i++)
        for (int j = i + 1; j < y; j++)
            if (x[i].ID > x[j].ID)
            {
                student temp;
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
    cout << endl;
}