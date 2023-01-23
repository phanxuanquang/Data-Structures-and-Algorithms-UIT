#include <iostream>
using namespace std;

class yourClass {
	int yourVariable;

public:
	void input();
};

void printMenu();
void choose(yourClass& yourObject);

int main() {
	yourClass yourObject;
	yourObject.input();

	choose(yourObject);
}

void yourClass::input() {
	cout << "Value of your variable is ";
	cin >> yourVariable;
}

void printMenu() {
	cout << "-----------------------------" << endl;
	cout << " (0) Exit." << endl;
	cout << " (1) Do something usefull." << endl;
	cout << " (2) Do something usefull." << endl;
	cout << " (3) Do something usefull." << endl;
	cout << "-----------------------------" << endl;
}
void choose(yourClass& yourObject) {
	printMenu();

	int choice;
	cout << "Your choice: ";
	cin >> choice;
	system("cls");

	switch (choice)
	{
	case 0:
		return;
	case 1:
		// Call the function for selection (1)
		break;
	case 2:
		// Call the function for selection (2)
		break;
	case 3:
		// Call the function for selection (3)
		break;
	default:
		cout << "Invalid choice. Please try again!" << endl;
		break;
	}

	choose(yourObject);
}