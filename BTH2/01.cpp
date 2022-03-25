#include <iostream>
using namespace std;

void array_import(int arr[], int x);
int even_sum(int arr[], int x);
bool prime_check(int x);
void prime_sum(int arr[], int x);
void arrange(int arr[], int x);
void main()
{
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    int *a = new int[n];
    array_import(a, n);
    cout << "Tong cac phan tu chan trong mang la " << even_sum(a, n) << endl;
    prime_sum(a, n);
    arrange(a, n);
    system("pause");
}
void array_import(int arr[], int x) {
    for (int i = 0; i < x; i++)
    {
        cout << " Phan tu thu " << i + 1 << " la ";
        cin >> arr[i];
    }
}
int even_sum(int arr[], int x) {
    int sum = 0;
    for (int i = 0; i < x; i++)
        if (arr[i] % 2 == 0)
            sum += arr[i];
    return sum;
}
bool prime_check(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i < x; i++)
        if (x % i == 0)
            return false;
    return true;
}
void prime_sum(int arr[], int x) {
    int sum = 0;
    for (int i = 0; i < x; i++)
        if (prime_check(arr[i]))
            sum += arr[i];
    cout << "Tong cac so nguyen to trong mang la " << sum << endl;
}
void arrange(int arr[], int x) {
    for (int i = 0; i < x - 1; i++)
        for (int j = i + 1; j < x; j++)
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    cout << "Mang sau khi sap xep la: ";
    for (int i = 0; i < x; i++)
        cout << arr[i] << " ";
    cout << endl;
}