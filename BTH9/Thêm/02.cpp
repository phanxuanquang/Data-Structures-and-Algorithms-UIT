#include <iostream>
#include <string>
using namespace std;

class student {
	long ID;
	string lastName, firstName;
	double score;
public:
	bool isID();
	bool isScore();
	double getScore() {
		return score;
	}

	void studentImport();
	void studentExport();
};

struct node {
	student value;
	node* leftBranch;
	node* rightBranch;
	node(student element) {
		value = element;
		leftBranch = rightBranch = NULL;
	}
};

void addNode(node*&, student);
void importTree(node*&, int&);
void exportTree(node*);

node* minNode(node*);
void deleteNode(node*&);

void menu();
void choose(node*&, int&);

int main(){
	int n;
	node* tree = NULL;
	choose(tree, n);
}

bool student::isID() {
	if (ID < 0)
		return false;
	return true;
}
bool student::isScore() {
	if (score < 0 || score>10)
		return false;
	return true;
}
void student::studentImport() {
	cout << "Ma sinh vien: ";
	cin >> ID;
	while (!isID()) {
		cout << "Ma sinh vien khong hop le, ma sinh vien moi la: ";
		cin >> ID;
	}
	int temp1 = getchar();
	cout << "Ho cua sinh vien: ";
	getline(cin, firstName);
	cout << "Ten cua sinh vien: ";
	getline(cin, lastName);
	cout << "Diem trung binh cua sinh vien: ";
	cin >> score;
	while (!isScore()) {
		cout << "Diem trung binh khong hop le, diem trung binh moi la: ";
		cin >> score;
	}
}
void student::studentExport() {
	cout << "Ma sinh vien: " << ID << endl;
	cout << "Ho cua sinh vien: " << firstName << endl;
	cout << "Ten cua sinh vien: " << lastName << endl;
	cout << "Diem trung binh cua sinh vien: " << score << endl;
}

void addNode(node*& root, student addElement) {
	if (root == NULL)
		root = new node(addElement);
	else if (root->value.getScore() < addElement.getScore())
		addNode(root->rightBranch, addElement);
	else if (root->value.getScore() > addElement.getScore())
		addNode(root->leftBranch, addElement);
}
void importTree(node*& root, int& size) {
	cout << "So luong sinh vien nhap vao la: ";
	cin >> size;
	student* addElement;
	system("cls");
	for (int i = 0; i < size; i++) {
		cout << "  SINH VIEN THU " << i + 1 << endl;
		addElement = new student;
		addElement->studentImport();
		addNode(root, *addElement);
		system("cls");
	}
}
void exportTree(node* root) {
	if (root == NULL)
		return;
	root->value.studentExport();
	cout << endl;
	exportTree(root->leftBranch);
	exportTree(root->rightBranch);
}

node* minNode(node* root) {
	while (root->leftBranch != NULL)
		root = root->leftBranch;
	return root;
}
void deleteNode(node*& root) {
	if (root == NULL)
		return;
	deleteNode(root->leftBranch);
	deleteNode(root->rightBranch);
	if (root->value.getScore() < 5) {
		if (root->leftBranch == NULL && root->rightBranch == NULL) {
			delete root;
			root = NULL;
		}
		else if (root->leftBranch != NULL && root->rightBranch == NULL) {
			node* temp = root;
			root = root->leftBranch;
			delete temp;
			temp = NULL;
		}
		else if (root->leftBranch == NULL && root->rightBranch != NULL) {
			node* temp = root;
			root = root->rightBranch;
			delete temp;
			temp = NULL;
		}
		else {
			node* temp = minNode(root->rightBranch);
			swap(root->value, temp->value);
			deleteNode(root->rightBranch);
		}
		return;
	}
}

void menu() {
	cout << "====================================================" << endl;
	cout << " (1) Them n sinh vien vao cay" << endl;
	cout << " (2) In ra cay theo thu tu duyet tien tu" << endl;
	cout << " (3) Xoa cac sinh vien co diem trung binh duoi 5" << endl;
	cout << "====================================================" << endl;
}
void choose(node*& root, int& size) {
	int choice;
	menu();
	cout << " Lua chon cua ban la: ";
	cin >> choice;
	switch (choice) {
	case 1:
		system("cls");
		importTree(root, size);
		choose(root, size);
		break;
	case 2:
		system("cls");
		exportTree(root);
		choose(root, size);
		break;
	case 3:
		system("cls");
		deleteNode(root);
		exportTree(root);
		choose(root, size);
		break;
	default:
		system("cls");
		choose(root, size);
		break;
	}
}