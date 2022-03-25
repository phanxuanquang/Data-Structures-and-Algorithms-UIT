#include <iostream>
using namespace std;
struct Customer
{
	string name;
	int seatNumber;
	Customer *pNext;
};

struct ListCustomer
{
	Customer *pHead;
	Customer *pTail;
};

struct Seat
{
	int number;
	Seat *pNext;
};
struct ListSeat
{
	int quantity;
	Seat *pHead;
	Seat *pTail;
};

struct SoThuTu
{
	int stt;
	SoThuTu *pNext;
};
struct List
{
	SoThuTu *pHead;
	SoThuTu *pTail;
};

int luaChonMenu();

//A Danh sach ghe
void addSeat(ListSeat &listSeat, Seat *seat);
void init(ListSeat &);
Seat *CreateSeat(int x);
void output(ListSeat);
int demSoPT(ListSeat listSeat);
void deleteSeat(ListSeat &listSeat);
bool deleteX(ListSeat &listSeat, int x);
bool deleteAfter(ListSeat &listSeat, Seat *seat);
bool isEmpty(ListSeat);

//B Hang doi chua so thu tu cua khach
void init(List &);
SoThuTu *CreateSoThuTu(int x);
void EnQueue(List &queue);
int DeQueue(List &queue);
void output(List);
bool isEmpty(List queue);

//C Danh sach  chua thong tin khac da mua ve
void init(ListCustomer &);
Customer *CreateCustomer();
void addCustomer(ListCustomer &listCustomer, Customer *);
void output(ListCustomer);
void deleteCustomer(ListCustomer &listCustomer);
bool deleteX(ListCustomer &listCustomer, int x);
bool deleteAfter(ListCustomer &listCustomer, Customer *);

int main()
{
	ListSeat listSeat;
	List queue;
	ListCustomer listCustomer;
	init(queue);
	init(listSeat);
	init(listCustomer);

	int lua_chon;
	bool flag = true;
	while (flag != false)
	{
		lua_chon = luaChonMenu();
		switch (lua_chon)
		{
		case 1:
		{
			EnQueue(queue);
			output(queue);
			cout << "\n";
			break;
		}
		case 2:
		{
			if (!isEmpty(queue))
			{
				if (!isEmpty(listSeat))
				{
					DeQueue(queue);
					cout << "Danh sach ghe con trong: ";
					output(listSeat);
					Customer *cust = CreateCustomer();
					addCustomer(listCustomer,cust);
					deleteX(listSeat, cust->seatNumber);
				}
				else
				{
					cout << "\nKhong co ghe nao trong";
				}
			}
			else
			{
				cout << "\nKhong co khach hang nao xep hang!";
			}

			break;
		}
		case 3:{
			
			break;
		}
		case 4:
		{
			cout<<"Danh sach khang hang da dat ve:\n";
			output(listCustomer);
			break;
		}
		case 0:
		{
			flag = false;
			break;
		}
		default:
			cout << "Lua chon nhap khong dung! Vui long nhap lai: ";
			cin >> lua_chon;
			break;
		}
	}
	return 0;
}

int luaChonMenu()
{
	int lua_chon;
	cout << "\n \n ================================ \n";
	cout << "\n Vui long chon chuc nang tuong ung.";
	cout << "\n 1. Lay so xep hang.";
	cout
		<< "\n 2. Mua ve.";
	cout
		<< "\n 3. Huy ve.";
	cout << "\n 4. Hien thi thong tin nhung ve da ban.";
	cout << "\n 0. Thoat chuong trinh";
	cout << "\n ================================";
	cout << "\n Lua chon cua ban: ";
	cin >> lua_chon;
	return lua_chon;
}
//Danh sach ghe A
void init(ListSeat &listSeat)
{
	listSeat.pHead = listSeat.pTail = NULL;
	cout << "Nhap so ghe :";
	cin >> listSeat.quantity;
	for (int i = 0; i < listSeat.quantity; i++)
	{
		Seat *seat = CreateSeat(i + 1);
		addSeat(listSeat, seat);
	}
}
Seat *CreateSeat(int x)
{
	Seat *seat = new Seat;
	if (seat == NULL)
	{
		return NULL;
	}
	seat->number = x;
	seat->pNext = NULL;
	return seat;
}
void addSeat(ListSeat &listSeat, Seat *seat)
{
	if (listSeat.pHead == NULL)
	{
		listSeat.pHead = listSeat.pTail = seat;
	}
	else
	{
		listSeat.pTail->pNext = seat;
		listSeat.pTail = seat;
	}
}
void deleteSeat(ListSeat &listSeat)
{
	if (listSeat.pHead == NULL)
	{
		return;
	}
	Seat *p = listSeat.pHead;
	listSeat.pHead = p->pNext;
	if (listSeat.pHead == NULL)
	{
		listSeat.pTail = NULL;
	}
	delete p;
	p = NULL;
}

int demSoPT(ListSeat listSeat)
{
	int dem = 0;
	Seat *p = listSeat.pHead;
	while (p != NULL)
	{
		dem++;
		p = p->pNext;
	}
	return dem;
}
void output(ListSeat listSeat)
{
	Seat *p = listSeat.pHead;
	while (p != NULL)
	{
		cout << p->number << " ";
		p = p->pNext;
	}
}
bool deleteX(ListSeat &listSeat, int x)
{
	Seat *p = listSeat.pHead;
	Seat *prev = NULL;
	while (true)
	{
		if (p == NULL)
		{
			cout << "Khong co thanh phan du lieu can xoa trong danh sach\n";
			return false;
		}

		if (p->number == x)
		{
			if (prev == NULL)
			{
				deleteSeat(listSeat);
			}
			else
			{
				deleteAfter(listSeat, prev);
			}
			return true;
		}
		prev = p;
		p = p->pNext;
	}
}
bool deleteAfter(ListSeat &listSeat, Seat *seat)
{
	if (seat != NULL)
	{
		Seat *p = seat->pNext;

		if (p != NULL)
		{
			seat->pNext = p->pNext;
			if (p == listSeat.pTail)
			{
				listSeat.pTail = seat;
			}
			delete p;
			p = NULL;
		}
		return true;
	}
	return false;
}
bool isEmpty(ListSeat listSeat)
{
	if (listSeat.pHead == NULL)
	{
		return true;
	}
	return false;
}

//Hang doi B
void init(List &queue)
{
	queue.pHead = queue.pTail = NULL;
}

SoThuTu *CreateSoThuTu(int x)
{
	SoThuTu *soThuTu = new SoThuTu;
	if (soThuTu == NULL)
	{
		return NULL;
	}
	soThuTu->stt = x;
	soThuTu->pNext = NULL;
	return soThuTu;
}
void EnQueue(List &queue)
{
	if (isEmpty(queue))
	{
		SoThuTu *soThuTu = CreateSoThuTu(1);
		queue.pHead = queue.pTail = soThuTu;
	}
	else
	{
		int x = queue.pTail->stt;
		SoThuTu *soThuTu = CreateSoThuTu(x + 1);
		queue.pTail->pNext = soThuTu;
		queue.pTail = soThuTu;
	}
}

bool isEmpty(List queue)
{
	if (queue.pHead == NULL)
	{
		return true;
	}
	return false;
}

int DeQueue(List &queue)
{
	if (!isEmpty(queue))
	{
		SoThuTu *p = queue.pHead;
		queue.pHead = p->pNext;
		if (queue.pHead == NULL)
		{
			queue.pTail = NULL;
		}
		delete p;
		p = NULL;
		return 1;
	}
	else
	{
		cout << "Queue is empty!";
	}

	return 0;
}
void output(List queue)
{
	SoThuTu *p = queue.pHead;
	while (p != NULL)
	{
		cout << p->stt << " ";
		p = p->pNext;
	}
}

// Danh sach C chua thong tin khac dat ve
void init(ListCustomer &listCustomer)
{
	listCustomer.pHead = listCustomer.pTail = NULL;
}
Customer *CreateCustomer()
{
	Customer *cust = new Customer;

	if (cust == NULL)
	{
		return NULL;
	}
	cout << "\nNhap so ghe khach muon chon: ";
	cin >> cust->seatNumber;
	cout << "\nNhap ten khach hang: ";
	cin.ignore();
	getline(cin, cust->name);
	cust->pNext = NULL;
	return cust;
}

void addCustomer(ListCustomer &listCustomer, Customer *cust)
{
	if (listCustomer.pHead == NULL)
	{
		listCustomer.pHead = listCustomer.pTail = cust;
	}
	else
	{
		listCustomer.pTail->pNext = cust;
		listCustomer.pTail = cust;
	}
}
void deleteCustomer(ListCustomer &listCustomer)
{
	if (listCustomer.pHead == NULL)
	{
		return;
	}
	Customer *p = listCustomer.pHead;
	listCustomer.pHead = p->pNext;
	if (listCustomer.pHead == NULL)
	{
		listCustomer.pTail = NULL;
	}
	delete p;
	p = NULL;
}
void output(ListCustomer listCustomer)
{
	Customer *p = listCustomer.pHead;
	while (p != NULL)
	{
		cout <<"So ghe: "<< p->seatNumber << " Name:" << p->name << endl;
		p = p->pNext;
	}
}
bool deleteX(ListCustomer &listCustomer, int x)
{
	Customer *p = listCustomer.pHead;
	Customer *prev = NULL;
	while (true)
	{
		if (p == NULL)
		{
			cout << "Khong co thanh phan du lieu can xoa trong danh sach\n";
			return false;
		}

		if (p->seatNumber == x)
		{
			if (prev == NULL)
			{
				deleteCustomer(listCustomer);
			}
			else
			{
				deleteAfter(listCustomer, prev);
			}
			return true;
		}
		prev = p;
		p = p->pNext;
	}
}
bool deleteAfter(ListCustomer &listCustomer, Customer *cust)
{
	if (cust != NULL)
	{
		Customer *p = cust->pNext;

		if (p != NULL)
		{
			cust->pNext = p->pNext;
			if (p == listCustomer.pTail)
			{
				listCustomer.pTail = cust;
			}
			delete p;
			p = NULL;
		}
		return true;
	}
	return false;
}
