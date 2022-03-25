#include <iostream>
using namespace std;

void import(int x[], int y);
void print(int x[], int y);

void k_delete(int x[], int& y);
void max(int x[], int y);
void min(int x[], int y);

void minus_count(int x[], int y);

void negative_max(int x[], int y);
void positive_min(int x[], int y);

void x_find(int x[], int& y);
void find_x(int x[], int y);

int main()
{
	int n, x;
	cout << "n = ";
	cin >> n;
	int* a = new int[n];
	import(a, n);

	cout << endl;
	cout << "1. Xuat mang" << endl;
	cout << "2. Xoa phan tu tai vi tri x trong mang" << endl;
	cout << "3. Liet ke nhung phan tu co gia tri lon nhat trong mang" << endl;
	cout << "4. Liet ke nhung phan tu co gia tri nho nhat trong mang" << endl;
	cout << "5. Dem so phan tu co gia tri am trong mang" << endl;
	cout << "6. Cho biet gia tri am lon nhat trong mang" << endl;
	cout << "7. Cho biet gia tri duong nho nhat trong mang" << endl;
	cout << "8. Tim phan tu co gia tri bang x co hay khong trong mang" << endl;
	cout << "9. Dem so phan tu co gia tri bang x trong mang" << endl;
	cout << endl;

	cout << "Nhap tuy chon: ";
	cin >> x;
	cout << endl;

	while (x != 0)
	{
		switch (x) {
		case 1:
			print(a,n);
			break;
		case 2:
			k_delete(a, n);
			break;
		case 3:
			max(a,n);
			break;
		case 4:
			min(a,n);
			break;
		case 5:
			minus_count(a, n);
			break;
		case 6:
			negative_max(a,n);
			break;
		case 7:
			negative_max(a, n);
			break;
		case 8:
			x_find(a, n);
			break;
		case 9:
			find_x(a, n);
			break;
		default:
			cout << "Khong ton tai lua chon" << endl << endl;
			break;
		}
		cout << "Nhap tuy chon: ";
		cin >> x;
		cout << endl;
	}
}

void import(int x[], int y) {
	cout << "Nhap mang co " << y << " phan tu: " << endl;
	for (int i = 0; i < y; i++)
		cin >> x[i];
}

void print(int x[], int y) {
	cout << "Mang nhap vao la: ";
	for (int i = 0; i < y; i++)
		cout << x[i] << " ";
	cout << endl << endl;
}

void k_delete(int x[], int& y) {
	cout << "k = ";
	int k;
	cin >> k;
	cout << "Mang sau khi xoa phan tu tai vi tri thu " << k << " la: ";
	if (y <= 0) {
		return;
	}
	if (k < 0)
		k = 0;
	else if (k >= y)
		k = y - 1;
	for (int i = k; i < y - 1; i++)
		x[i] = x[i + 1];
	--y;
	for (int i = 0; i < y; i++)
		cout << x[i] << " ";
	cout << endl << endl;
}

void max(int x[], int y) {
	int temp = x[0];
	for (int i = 1; i < y; i++)
		if (x[i] >= temp)
			temp = x[i];
	cout << "Cac phan tu co gia tri lon nhat trong mang tai vi tri ";
	for (int i = 0; i < y; i++)
		if (x[i] == temp)
			cout << i << " ";
	cout << endl << endl;
}

void min(int x[], int y) {
	int temp = x[0];
	for (int i = 1; i < y; i++)
		if (x[i] < temp)
			temp = x[i];
	cout << "Cac phan tu co gia tri nho nhat trong mang tai vi tri ";
	for (int i = 0; i < y; i++)
		if (x[i] == temp)
			cout << i << " ";
	cout << endl << endl;
}

void minus_count(int x[], int y) {
	int temp = 0;
	for (int i = 0; i < y; i++)
		if (x[i] < 0)
			temp++;
	cout << "So phan tu am trong mang la " << temp;
	cout << endl << endl;
}

void negative_max(int x[], int y) {
	cout << "Phan tu am lon nhat trong mang la ";
	int temp = x[0];
	for (int i = 0; i < y; i++)
		if (x[i] > temp && x[i] < 0)
			temp = x[i];
	cout << temp;
	cout << endl << endl;
}

void positive_min(int x[], int y) {
	cout << "Phan tu dương nho nhat trong mang la ";
	int temp = x[0];
	for (int i = 1; i < y; i++)
		if (x[i] < temp && x[i]>0)
			temp = x[i];
	cout << temp;
	cout << endl << endl;
}

void x_find(int x[], int& y) {
	cout << "x = ";
	int k;
	cin >> k;
	for (int i = 0; i < y; i++)
		if (x[i] == k)
		{
			cout << "Phan tu co gia tri " << k << " co trong mang";
			cout << endl << endl;
			return;
		}
	cout << "Phan tu co gia tri " << k << " khong co trong mang";
	cout << endl << endl;
}

void find_x(int x[], int y) {
	cout << "x = ";
	int k;
	cin >> k;
	int temp = 0;
	for (int i = 0; i < y; i++)
		if (x[i] == k)
			temp++;
	if (temp > 0)
		cout << "So phan tu co gia tri " << k << " co trong mang la " << temp;
	else cout << "Phan tu co gia tri " << k << " khong co trong mang";
	cout << endl << endl;
}
