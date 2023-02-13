#include <iostream>
using namespace std;

void input(int[], int);
void ouput(int[], int);

void deleteElementAtPositionK(int[], int&);
void getMaxValue(int[], int);
void getMinValue(int[], int);

void getMinusCount(int[], int);

void getMaxMinusValue(int[], int);
void getMinPositiveValue(int[], int);

void findValuesEqualToX(int[], int&);
void countValuesEqualToX(int[], int);

void printMenu();
void choose(int[], int&);

int main()
{
	int arrSize;
	cout << "n = ";
	cin >> arrSize;
	system("cls");

	int* arr = new int[arrSize];

	input(arr, arrSize);
	system("cls");

	choose(arr, arrSize);
}

void printMenu() {
	cout << "\n--------------------------------------------------" << endl;
	cout << "1. Xuat mang" << endl;
	cout << "2. Xoa phan tu tai vi tri x trong mang" << endl;
	cout << "3. Liet ke nhung phan tu co gia tri lon nhat trong mang" << endl;
	cout << "4. Liet ke nhung phan tu co gia tri nho nhat trong mang" << endl;
	cout << "5. Dem so phan tu co gia tri am trong mang" << endl;
	cout << "6. Cho biet gia tri am lon nhat trong mang" << endl;
	cout << "7. Cho biet gia tri duong nho nhat trong mang" << endl;
	cout << "8. Tim phan tu co gia tri bang x co hay khong trong mang" << endl;
	cout << "9. Dem so phan tu co gia tri bang x trong mang" << endl;
	cout << "--------------------------------------------------" << endl;
}
void choose(int arr[], int& arrSize) {
	printMenu();
	int choice;
	cout << "Nhap tuy chon: ";
	cin >> choice;
	system("cls");

	while (choice != 0)
	{
		switch (choice) {
		case 1:
			ouput(arr, arrSize);
			break;
		case 2:
			deleteElementAtPositionK(arr, arrSize);
			break;
		case 3:
			getMaxValue(arr, arrSize);
			break;
		case 4:
			getMinValue(arr, arrSize);
			break;
		case 5:
			getMinusCount(arr, arrSize);
			break;
		case 6:
			getMaxMinusValue(arr, arrSize);
			break;
		case 7:
			getMaxMinusValue(arr, arrSize);
			break;
		case 8:
			findValuesEqualToX(arr, arrSize);
			break;
		case 9:
			countValuesEqualToX(arr, arrSize);
			break;
		default:
			cout << "Khong ton tai lua chon" << endl;
			break;
		}
		choose(arr, arrSize);
	}
}

void input(int arr[], int arrSize) {
	cout << "Nhap mang co " << arrSize << " phan tu: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> arr[i];
	}
}
void ouput(int arr[], int arrSize) {
	cout << "Mang nhap vao la: ";
	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << " ";
}

void deleteElementAtPositionK(int arr[], int& arrSize) {
	cout << "k = ";
	int k;
	cin >> k;
	system("cls");
	cout << "Mang sau khi xoa phan tu tai vi tri thu " << k << " la: ";
	if (arrSize <= 0) {
		return;
	}
	if (k < 0)
		k = 0;
	else if (k >= arrSize)
		k = arrSize - 1;
	for (int i = k; i < arrSize - 1; i++)
		arr[i] = arr[i + 1];
	--arrSize;
	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << " ";
}

void getMaxValue(int arr[], int arrSize) {
	int temp = arr[0];
	for (int i = 1; i < arrSize; i++)
		if (arr[i] >= temp)
			temp = arr[i];
	cout << "Cac phan tu co gia tri lon nhat trong mang tai vi tri ";
	for (int i = 0; i < arrSize; i++)
		if (arr[i] == temp)
			cout << i << " ";
}

void getMinValue(int arr[], int arrSize) {
	int temp = arr[0];
	for (int i = 1; i < arrSize; i++)
		if (arr[i] < temp)
			temp = arr[i];
	cout << "Cac phan tu co gia tri nho nhat trong mang tai vi tri ";
	for (int i = 0; i < arrSize; i++)
		if (arr[i] == temp)
			cout << i << " ";
}

void getMinusCount(int arr[], int arrSize) {
	int temp = 0;
	for (int i = 0; i < arrSize; i++)
		if (arr[i] < 0)
			temp++;
	cout << "So phan tu am trong mang la " << temp;
}

void getMaxMinusValue(int arr[], int arrSize) {
	cout << "Phan tu am lon nhat trong mang la ";
	int temp = arr[0];
	for (int i = 0; i < arrSize; i++)
		if (arr[i] > temp && arr[i] < 0)
			temp = arr[i];
	cout << temp;
}

void getMinPositiveValue(int arr[], int arrSize) {
	cout << "Phan tu dương nho nhat trong mang la ";
	int temp = arr[0];
	for (int i = 1; i < arrSize; i++)
		if (arr[i] < temp && arr[i]>0)
			temp = arr[i];
	cout << temp;
}

void findValuesEqualToX(int arr[], int& arrSize) {
	cout << "x = ";
	int x;
	cin >> x;
	system("cls");
	for (int i = 0; i < arrSize; i++)
		if (arr[i] == x)
		{
			cout << "Phan tu co gia tri " << x << " co trong mang";
			cout << endl << endl;
			return;
		}
	cout << "Phan tu co gia tri " << x << " khong co trong mang";
}

void countValuesEqualToX(int arr[], int arrSize) {
	cout << "x = ";
	int x;
	cin >> x;
	system("cls");
	int temp = 0;
	for (int i = 0; i < arrSize; i++)
		if (arr[i] == x)
			temp++;
	if (temp > 0)
		cout << "So phan tu co gia tri " << x << " co trong mang la " << temp;
	else cout << "Phan tu co gia tri " << x << " khong co trong mang";
}
