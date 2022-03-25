#include <iostream>
#include<time.h> 
using namespace std;

int random(int, int);
int* generator_random(int);

void array_Generate(int[], int);
void array_Generate_Increase(int[], int);
void array_Export(int[], int);
void GenerateArray_and_Find();
void GenerateArray_and_Search();
void print_pair(int[], int);

int maxValue(int[], int);
int indexOf_maxValue(int[], int);
void indexesOf_maxValue(int[], int);

int IndexOf_X(int[], int, int);
int IndexOf_X_Improved(int[], int, int);
void IndexesOf_X(int[], int, int);
void find_IndexOf_X(int[], int, int);
void find_IndexOf_X_improved(int[], int, int);
void find_IndexsOf_X(int[], int, int);

int InterPolationSearch(int [], int, int);
void find_IndexOf_X_with_InterPolationSearch(int[], int, int);
void find_IndexsOf_X_with_InterPolationSearch(int[], int, int);

void Interchange_Sort(int[], int);
void Selection_Sort(int[], int);

void choose(int[], int);

int main(){
	int n;
	cout << "So luong phan tu la ";
	cin >> n;
	int* array = new int[n];
	array_Generate(array, n);
	choose(array, n);
}

void choose(int arr[], int size) {
	cout << "_______________________________" << endl;
	cout << "Nhap lua chon tuong ung theo de bai trong LAB 5" << endl;
	cout << "Lua chon cua ban la: ";
	int choice, x;
	cin >> choice;
	switch (choice) {
	case 1:
		system("cls");
		array_Export(arr, size);
		choose(arr, size);
		break;
	case 2:
		system("cls");
		array_Export(arr, size);
		cout << "Gia tri lon nhat trong mang la " << maxValue(arr, size) << endl;
		choose(arr, size);
		break;
	case 3:
		system("cls");
		array_Export(arr, size);
		cout << "Vi tri chua gia tri lon nhat trong mang la " << indexOf_maxValue(arr, size) << endl;
		choose(arr, size);
		break;
	case 4:
		system("cls");
		array_Export(arr, size);
		indexesOf_maxValue(arr, size);
		choose(arr, size);
		break;
	case 5:
		system("cls");
		array_Export(arr, size);
		cout << "Gia tri X can tim la ";
		cin >> x;
		find_IndexOf_X(arr, size, x);
		choose(arr, size);
		break;
	case 6:
		system("cls");
		array_Export(arr, size);
		cout << "Gia tri X can tim la ";
		cin >> x;
		find_IndexOf_X_improved(arr, size, x);
		choose(arr, size);
		break;
	case 7:
		system("cls");
		array_Export(arr, size);
		cout << "Gia tri X can tim la ";
		cin >> x;
		find_IndexsOf_X(arr, size, x);
		choose(arr, size);
		break;
	case 8:
		system("cls");
		GenerateArray_and_Find();
		choose(arr, size);
		break;
	case 9:
		system("cls");
		GenerateArray_and_Search();
		choose(arr, size);
		break;
	case 10:
		system("cls");
		print_pair(arr, size);
		choose(arr, size);
		break;
	case 11:
		system("cls");
		Interchange_Sort(arr, size);
		choose(arr, size);
		break;
	case 12:
		system("cls");
		Selection_Sort(arr, size);
		choose(arr, size);
		break;
	default:
		system("cls");
		cout << "Lua chon khong hop le, hay nhap lai" << endl;
		choose(arr, size);
		break;
	}
}

int random(int min, int max) {
	static bool first = true;
	if (first) {
		srand(time(NULL));
		first = false;
	}
	return min + rand() % ((max + 1) - min);
}
int* generator_random(int n) {
	int* arr = new int[n];
	if (arr != NULL)
		for (int i = 0; i < n; i++)
			*(arr + i) = random(-1000, 1000);
	return arr;
}

void array_Generate(int arr[], int size) {
	for (int i = 0; i < size; i++)
		arr[i] = random(-10000, 10000);
}
void array_Generate_Increase(int arr[], int size) {
	srand(time(NULL));
	int i = 0;
	if (size > 0) {
		arr[i] = rand() % 100;
		for (int i = 1; i < size; i++)
			arr[i] = arr[i - 1] + rand() % 100;
	}
}
void array_Export(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "_______________________________" << endl;
}
void GenerateArray_and_Find() {
	int n;
	cout << "So luong phan tu la ";
	cin >> n;
	int* array = new int[n];
	array_Generate_Increase(array, n);
	system("cls");
	array_Export(array, n);
	int x;
	cout << "Gia tri x can tim la ";
	cin >> x;
	cout << "Tim kiem tuyen tinh: " << endl << "  ";
	find_IndexOf_X(array, n, x);
	cout << "_______" << endl;
	cout << "Tim kiem tuyen tinh cai tien: " << endl << "  ";
	find_IndexOf_X_improved(array, n, x);
	cout << "_______" << endl;
	cout << "Tim tat ca cac vi tri cua x: " << endl << "  ";
	find_IndexsOf_X(array, n, x);

}
void GenerateArray_and_Search() {
	int n;
	cout << "So luong phan tu la ";
	cin >> n;
	int* array = new int[n];
	array_Generate_Increase(array, n);
	system("cls");
	array_Export(array, n);
	int x;
	cout << "Gia tri x can tim la ";
	cin >> x;
	InterPolationSearch(array, n, x);
	cout << "_______" << endl;
	find_IndexOf_X_with_InterPolationSearch(array, n, x);
	cout << "_______" << endl;
	find_IndexsOf_X_with_InterPolationSearch(array, n, x);
}
void print_pair(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++)
			cout << "(" << arr[i] << "," << arr[j] << ") ";
		cout << endl;
	}
}

int maxValue(int arr[], int size) {
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
int indexOf_maxValue(int arr[], int size) {
	for (int i = 0; i < size; i++)
		if (arr[i] == maxValue(arr, size))
			return i;
}
void indexesOf_maxValue(int arr[], int size) {
	system("cls");
	cout << "Cac vi tri chua gia tri lon nhat gom: ";
	for (int i = 0; i < size; i++)
		if (arr[i] == maxValue(arr, size))
			cout << i << " ";
	cout << endl;
}

int IndexOf_X(int arr[], int size, int key) {
	for (int i = 0; i < size; i++)
		if (arr[i] == key)
			return i;
	return -1;
}
int IndexOf_X_Improved(int arr[], int size, int key) {
	arr[size] = key;
	int i;
	for (i = 0; arr[i] != key; i++);
	if (i < size)
		return i;
	return -1;
}
void IndexesOf_X(int arr[], int size, int key) {
	for (int i = 0; i < size; i++)
		if (arr[i] == key)
			cout << i << " ";
}
void find_IndexOf_X(int arr[], int size, int key) {
	clock_t begin, end;
	begin = clock();
	if (IndexOf_X(arr, size, key) == -1)
		cout << "Gia tri " << key << " khong ton tai trong mang" << endl;
	else cout << "Gia tri x nam tai vi tri " << IndexOf_X(arr, size, key) << endl;
	end = clock();
	cout << "Tong thoi gian thuc hien la " << (double)(end - begin) / CLOCKS_PER_SEC << " giay" << endl;
}
void find_IndexOf_X_improved(int arr[], int size, int key) {
	clock_t begin, end;
	begin = clock();
	if (IndexOf_X_Improved(arr, size, key) == -1)
		cout << "Gia tri " << key << " khong ton tai trong mang" << endl;
	else cout << "Gia tri x nam tai vi tri " << IndexOf_X_Improved(arr, size, key) << endl;
	end = clock();
	cout << "Tong thoi gian thuc hien la " << (double)(end - begin) / CLOCKS_PER_SEC << " giay" << endl;
}
void find_IndexsOf_X(int arr[], int size, int key) {
	if (IndexOf_X(arr, size, key) == -1)
		cout << "Gia tri x khong ton tai trong mang" << endl;
	else {
		cout << "Gia tri x nam tai vi tri ";
		IndexesOf_X(arr, size, key);
		cout << endl;
	}
}

int InterPolationSearch(int arr[], int size, int key) {
	int left = 0, right = size - 1;
	while (left <= right && key >= arr[left] && key <= arr[right]) {
		double mid1 = (double)(key - arr[left]) / (arr[right] - arr[left]);
		int mid2 = (right - left);
		int search_index = left + mid1 * mid2;
		if (arr[search_index] == key)
			return search_index;
		if (arr[search_index] < key)
			left = search_index + 1;
		else right = search_index - 1;
	}
	return -1;
}
void find_IndexOf_X_with_InterPolationSearch(int arr[], int size, int key) {
	clock_t begin, end;
	begin = clock();
	if (InterPolationSearch(arr, size, key) == -1)
		cout << "Gia tri " << key << " khong ton tai trong mang" << endl;
	else cout << "Gia tri x nam tai vi tri " << InterPolationSearch(arr, size, key) << endl;
	end = clock();
	cout << "Tong thoi gian thuc hien la " << (double)(end - begin) / CLOCKS_PER_SEC << " giay" << endl;
};
void find_IndexsOf_X_with_InterPolationSearch(int arr[], int size, int key) {
	if (InterPolationSearch(arr, size, key) == -1)
		cout << "Gia tri x khong ton tai trong mang" << endl;
	else {
		cout << "Gia tri x nam tai vi tri ";
		IndexesOf_X(arr, size, key);
		cout << endl;
	}
}

void Interchange_Sort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) 
		for (int j = i + 1; j < size; j++)
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	cout << "Mang sau khi sap xep la: ";
	array_Export(arr, size);
}
void Selection_Sort(int arr[], int size) {
	int i, j, min_index;
	for (i = 0; i < size - 1; i++){
		min_index = i;
		for (j = i + 1; j < size; j++)
			if (arr[j] < arr[min_index])
				min_index = j;
		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
	cout << "Mang sau khi sap xep la: ";
	array_Export(arr, size);
}