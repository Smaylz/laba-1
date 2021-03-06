

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

struct Taska1 {
	int num;
	char seat[30];
	int houro;
	int houri;
	int minuteo;
	int minutei;
};
/*class Tasks1() {
	int num;
	string seat;
	Time time;
public:
	int setNum(int a) { this.num = a };
	string setSeat(string a) { this.seat = a };
	Time setTime(int a,int b,int c,int d) {
		this.time.houro = a;
		this.time.houri = b;
		this.time.minuteo = c;
		this.time.minutei = d;
	};
	void fileOpen() {
		LPCTSTR fn = "File_New.dat";
		HANDLE myFile = CreateFile(fn,
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			NULL,
			CREATE_NEW,
			FILE_ATTRIBUTE_NORMAL,
			NULL);
		if (myFile == INVALID_HANDLE_VALUE)
			cout << "Error";
		else  cout << " File is created";
		CloseHandle (myFile);
		cin.get();
	};
}*/
int setX();
int menu();
HANDLE createOrOpen();
void read(HANDLE);
void write(HANDLE);

int main()
{
	menu();
	return 0;
}

int setX() {
	int x;
	cout << "\n 1-write\n 2-read\n 3-resScreen\n 4-resFile\n 5-Exit";
	cin >> x;
	return x;
}

HANDLE createOrOpen() {
	LPCTSTR fn = L"File_New.dat";
	HANDLE myFile = CreateFile(fn,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (myFile == INVALID_HANDLE_VALUE)
		cout << "Error";
	else  cout << " File is created";
	return myFile;
}

void read(HANDLE mf) {
	int k;
	DWORD n;
	while (ReadFile(mf, &k, sizeof(k), &n, NULL) && n != 0) 
		cout << k;
}

void write(HANDLE mf) {
	DWORD n;
	Taska1 p;
	cout << "Enter num=";
	cin >> p.num;
	cout << "Enter seat=";
	cin >> p.seat;
	cout << "Enter timeout(hour,minute)=";
	cin >> p.houro>>p.minuteo;
	cout << "Enter timein(hour,minute)=";
	cin >> p.houri >> p.minutei;
	WriteFile(mf, &p.num, sizeof(p.houri), &n, NULL);
	WriteFile(mf, &p.seat, sizeof(p.houri), &n, NULL);
	WriteFile(mf, &p.houri, sizeof(p.houri), &n, NULL);
	WriteFile(mf, &p.houro, sizeof(p.houri), &n, NULL);
	WriteFile(mf, &p.minutei, sizeof(p.houri), &n, NULL);
	WriteFile(mf, &p.minuteo, sizeof(p.houri), &n, NULL);
	FlushFileBuffers(mf);
}

int menu() {
	int x;
	HANDLE myFile = createOrOpen();
	while (true) {
		x = setX();
		switch (x)
		{
		case 1:
			write(myFile);
			break;
		case 2:
			read(myFile);
			break;
		
		case 5:
			CloseHandle(myFile);
			exit(0);
			break;
		default:
			break;
		}
	}
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
