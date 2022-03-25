#include <iostream>
using namespace std;
class fraction {
public:
	int tuSo, mauSo;
public:
	void import() {
		cout << " Tu so la: ";
		cin >> tuSo;
		cout << " Mau so la: ";
		cin >> mauSo;
		while (mauSo == 0)
		{
			cout << "Mau so phai khac 0.\n Mau so moi la: ";
			cin >> mauSo;
		}
	}
	void simple() {
		for (int i = tuSo; i >= 1; i--)
			if (tuSo % i == 0 && mauSo % i == 0)
			{
				tuSo /= i;
				mauSo /= i;
				break;
			}
	}
	fraction operator+(fraction x) {
		fraction temp;
		temp.tuSo = tuSo * x.mauSo + x.tuSo * mauSo;
		temp.mauSo = x.mauSo * mauSo;
		return temp;
	}
	fraction operator-(fraction x) {
		fraction temp;
		temp.tuSo = tuSo * x.mauSo - x.tuSo * mauSo;
		temp.mauSo = x.mauSo * mauSo;
		return temp;
	}
	fraction operator*(fraction x) {
		fraction temp;
		temp.tuSo = tuSo * x.tuSo;
		temp.mauSo = x.mauSo * mauSo;
		return temp;
	}
	void print() {
		if (tuSo % mauSo == 0)
			cout << tuSo / mauSo;
		else cout << tuSo << "/" << mauSo << " ";
	}
};
void array_import(fraction arr[], int x);
void array_print(fraction arr[], int x);
void sum(fraction arr[], int x);
void multiple(fraction arr[], int x);
void arrange(fraction arr[], int x);
void UCLN(int& x, int& y);
void main()
{
	int n;
	cout << "So phan tu cua mang la: ";
	cin >> n;
	fraction* a = new fraction[n];
	array_import(a, n);
	array_print(a, n);
	sum(a, n);
	multiple(a, n);
	arrange(a, n);
	cout << endl;
	system("pause");
}
void array_import(fraction arr[], int x) {
	for (int i = 0; i < x; i++)
	{
		cout << " Phan tu thu " << i + 1 << " la: " << endl;
		arr[i].import();
		arr[i].simple();
	}
}
void array_print(fraction arr[], int x) {
	cout << "Mang phan so: ";
	for (int i = 0; i < x; i++)
		arr[i].print();
}
void sum(fraction arr[], int x) {
	fraction temp;
	temp.tuSo = 0;
	temp.mauSo = 1;
	for (int i = 0; i < x; i++)
		temp = temp + arr[i];
	cout << endl << "Tong cac phan so trong mang la ";
	temp.simple();
	temp.print();
	cout << endl;
}
void multiple(fraction arr[], int x) {
	fraction temp;
	temp.tuSo = 1;
	temp.mauSo = 1;
	for (int i = 0; i < x; i++)
		temp = temp * arr[i];
	cout << "Tich cac phan so trong mang la ";
	temp.simple();
	temp.print();
	cout << endl;
}
void arrange(fraction arr[], int x) {
	for (int i = 0; i < x-1; i++)
		for (int j = i + 1; j < x; j++)
			if ((arr[i] - arr[j]).tuSo < 0)
			{
				fraction temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	array_print(arr, x);
}