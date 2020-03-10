#include <iostream>
#include <ctime>
using namespace std;
struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};
struct Worker
{
	char F[56];
	char I[32];
	char O[32];
	Date birthday;
	int salary;
	char position[56];
};
bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	return result;
	}
}
struct shop
{
public:
	char name[56];
	char seller[56];
	int year;
	int quantity;
	float price;
};

struct Name
{
	char F[56];
	char I[32];
	char O[32];
};

struct NOTE1
{
	Name user;
	float TELE;
	Date birthday;
};


bool isCorrect(int year)
{
	return year > 2020 ? false : true;
};


void task() {
	const int n = 3;
	shop group[n];
	for (int i = 0; i < n; i++)
	{
		cout << "\nYear: " << group[i].year;
	}
}


int main()
{
	///////////////// 1 lvl(5var)
	int sum = 0;
	const int n = 1;
	shop group[n];

	for (int i = 0; i < n; i++)
	{
		cout << "\nInput Name: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].name, 56);

		cout << "\nInput Seller: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].seller, 32);
		do
		{
			cout << "\nInput Year: ";
			cin >> group[i].year;
		} while (!isCorrect(group[i].year));

		cout << "\nInput Price: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].price;
		cout << "\nInput Quantity: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].quantity;
		cout << "\nName: " << group[i].name;
		cout << "\nSeller: " << group[i].seller;
		cout << "\nPrice: " << group[i].price;
		cout << "\nQuantity: " << group[i].quantity;
		cout << "\nYear: " << group[i].year;
	}
	for (size_t i = 0; i < n; i++)
	{
		if (group[i].year == 2020)
			sum += group[i].price * group[i].quantity;
	}
	cout << "\nWhole price = " << sum;

	/////////////// 2 lvl(5var)

	const int N = 3;
	Worker member[N];
	for (int i = 0; i < N; i++)
	{
		cout << "\nInput F: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(member[i].F, 56);
		cout << "\nIinput I: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(member[i].I, 32);
		cout << "\nInput O: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(member[i].O, 32);
		cout << "\nInput position: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(member[i].position, 56);
		cout << "\nInput Salary: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> member[i].salary;
		do
		{
			cout << "\nInput birthday: ";
			cin >> member[i].birthday.day >> member[i].birthday.month >> member[i].birthday.year;
		} while (!member[i].birthday.isCorrect());
	}
	for (int i = 0; i < N; i++) {
		if (member[i].birthday.month == 5) {
			cout << "\nFIO: " << member[i].F << " " << member[i].I << " " << member[i].O;
			cout << "\nBirthday:" << member[i].birthday.day << " . " << member[i].birthday.month << " . " << member[i].birthday.year;
			cout << "\nPosition: " << member[i].position;
			cout << "\nSalary: " << member[i].salary;
		}
	}
	///////////// 3 lvl(5var)
	const int m = 9;
	NOTE1 BLOCK[m];
	for (int i = 0; i < m; i++)
	{
		cout << "\nInput F: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(BLOCK[i].user.F, 56);
		cout << "\nIinput I: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(BLOCK[i].user.I, 32);
		cout << "\nInput O: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(BLOCK[i].user.O, 32);
		cout << "\nInput Phone number: ";
		cin >> BLOCK[i].TELE;
		do
		{
			cout << "\nInput birthday: ";
			cin >> BLOCK[i].birthday.day >> BLOCK[i].birthday.month >> BLOCK[i].birthday.year;
		} while (!BLOCK[i].birthday.isCorrect());
	}
	NOTE1 temp;
	for (size_t i = 0; i < m - 1; i++)
	{
		if (int(BLOCK[i].user.F[0]) > int(BLOCK[i + 1].user.F[0]))
		{
			temp.birthday = BLOCK[i].birthday;
			temp.TELE = BLOCK[i].TELE;
			temp.user = BLOCK[i].user;

			BLOCK[i].birthday = BLOCK[i + 1].birthday;
			BLOCK[i].TELE = BLOCK[i + 1].TELE;
			BLOCK[i].user = BLOCK[i + 1].user;

			BLOCK[i + 1].birthday = temp.birthday;
			BLOCK[i + 1].TELE = temp.TELE;
			BLOCK[i + 1].user = temp.user;
		}

	}
	int usermonth;
	cout << "\nInput Month: ";
	cin >> usermonth;
	for (size_t i = 0; i < m; i++)
	{
		if (usermonth == BLOCK[i].birthday.month)
		{
			cout << "\nFIO: " << BLOCK[i].user.F << " " << BLOCK[i].user.I << " " << BLOCK[i].user.O;
			cout << "\nBirthday:" << BLOCK[i].birthday.day << " . " << BLOCK[i].birthday.month << " . " << BLOCK[i].birthday.year;
			cout << "\nPhone number: " << BLOCK[i].TELE;

		}
		else
		{
			cout << "\nInput another number";
		}
	}
	return 0;
}
