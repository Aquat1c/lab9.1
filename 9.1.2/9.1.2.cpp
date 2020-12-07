#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;
enum Specialty { IT, IK, CA, KH, KB };
string strSpecialty[] = { "IT", "IK", "CA", "KH", "KB" };
struct Student
{
	string prizv;
	Specialty specialty;
	short unsigned kurs;
	short unsigned physics;
	short unsigned math;
	union
	{
		short unsigned programming;
		short unsigned methods;
		short unsigned pedagogika;
	};
};
void Create(Student* s, const int N);
void Print(Student* s, const int N);
string WorstAverage(Student* s, const int N);
double lessfour(Student* s, const int N);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "Введіть кількість студентів ";
	cin >> N;
	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);
	cout << "| Кількість студентів, середній бал яких менше 4 " << char(34) << ": " << fixed << setw(6) << setprecision(2) << lessfour(s, N) << setw(12) << "|" << endl;
	cout << "| Предмет, середній бал якого найменший: " << fixed << setprecision(2) << WorstAverage(s, N) << setw(29) << "|" << endl;
	cout << "================================================================================" << endl;
	delete[] s;
}
void Create(Student* s, const int N)
{
	int kurs, specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент# " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "  Назва ";
		getline(cin, s[i].prizv);
		cout << "  Курс ";
		cin >> s[i].kurs;
		cout << " Спеціальність (0 - IT, 1 - IK, 2 - CA, 3 - KH, 4 - KB): "; cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		cout << " Оцінка з фізики: "; cin >> s[i].physics;
		cout << "  Оцінка з інформатики: "; cin >> s[i].math;
		switch (specialty)
		{
		case 0:
			cout << "  Оцінка з інформатики: ";
			cin >> s[i].programming;
			break;
		case 3:
			cout << "  Оцінка з чисельних методів"; cin >> s[i].methods;
			break;
		case 1:
		case 2:
		case 4:
			cout << "Оцінка з педагогіки: "; cin >> s[i].pedagogika;
			break;
		}
	}
}void Print(Student* s, const int N)
{
	cout << "================================================================================================================="
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Програмування| Чисельні методи|Педагогіка|"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << "  "
			<< "| " << setw(8) << right << strSpecialty[s[i].specialty] << "      "
			<< "| " << setw(4) << right << s[i].physics << "   "
			<< "| " << setw(6) << right << s[i].math << "     ";
		switch (s[i].specialty)
		{
		case 0:
		cout << "| " << setw(7) << right << s[i].programming << "       |" << setw(18) << "|" << setw(13) << "|" << endl;				break;			case 3:				cout << "| " << setw(15) << "|" << setw(10) << right << s[i].methods << "       |" << setw(13) << "|" << endl;				break;			case 1:			case 2:			case 4:				cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[i].pedagogika << "     |" << endl;				break;
		}
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	}
	cout << "=================================================================================================================" << endl;
}string WorstAverage(Student* s, const int N)
{
	string worst;
	double F;
	double M;
	double I;
	double Meth;
	double Pedag;
	for (int i = 0; i < N; i++)
	{
		switch (s[i].specialty)
		{
		case 0:
			F = (s[i].physics) / N;
			M = (s[i].math) / N;
			I = (s[i].programming) / N;
			Meth = (s[i].methods) / N;
			Pedag = (s[i].pedagogika) / N;
			break;
		case 3:
			F = (s[i].physics) / N;
			M = (s[i].math) / N;
			I = (s[i].programming) / N;
			Meth = (s[i].methods) / N;
			Pedag = (s[i].pedagogika) / N;

			break;
		case 1:
		case 2:
		case 4:
			F = (s[i].physics) / N;
			M = (s[i].math) / N;
			I = (s[i].programming) / N;
			Meth = (s[i].methods) / N;
			Pedag = (s[i].pedagogika) / N;
			break;
		}
		if (F < M && F < I && F < Meth && F < Pedag)
			worst = "Фізика";
		if (M < F && M < I && M > Meth && M < Pedag)
			worst = "Математика";
		if (I < F && I < M && I < Meth && I < Pedag)
			worst = "Програмування";
		if (Meth < M && Meth < I && Meth < F && Meth < Pedag)
			worst = "Чисельні методи";
		if (Pedag < F && Pedag < I && Pedag < Meth && Pedag < M)
			worst = "Педагогіка";
	}
	return worst;
}
double lessfour(Student* s, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)
		if ((s[i].physics + s[i].math + s[i].programming + s[i].methods + s[i].pedagogika) / 5 < 4)
			k++;
	return k;
}

