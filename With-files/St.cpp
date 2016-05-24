#include <io.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include "Race.h"

using namespace std;

void InitFile(char*);
void DisplayFile(char*);
void AddToEndFile(char*);
void ChangeFile(char*);
void RemoveFromFile(char*);
void InitNumber(long&);
void SystemFun();
void InitNameFile(char*);
void SortingFile(char*);
int Menu();

Race InitRace();
Race* InitArray(int);
void DisplayArray(Race*, int);
void EnterArray(int*, int);
void DisplayChoise(Race*, int, char*, double, double);
void SortcarModel(Race*, int);
void Swap(Race&, Race&);

int main()
{
	char fileName[N] = "List.bin";
	enum { Init = 1, Create, Display, Add, Change, Remove, Sort, Exit };
	while (true)
	{
		int Key = Menu();
		if (Key == Exit)
			return 0;
		system("cls");
		switch (Key)
		{
		case Init:
			InitNameFile(fileName);
			SystemFun();
			break;
		case Create:
			InitFile(fileName);
			SystemFun();
			break;
		case Display:
			DisplayFile(fileName);
			SystemFun();
			break;
		case Add:
			AddToEndFile(fileName);
			SystemFun();
			break;
		case Change:
			ChangeFile(fileName);
			SystemFun();
			break;
		case Remove:
			RemoveFromFile(fileName);
			SystemFun();
			break;
		case Sort:
			SortingFile(fileName);
			SystemFun();
			break;
		default:
			cout << "\nIncorrect input! Try again!";
			SystemFun();
		}
	}

	
	cout << "\nEnter the number of Races:";
	cin >> n;
	system("cls");
	Race* Races = InitArray(n);
	if (!Races)
	{
		cout << "\nDynamic array doesn't exist!\n";
		system("pause");
		return 0;
	}
	cout << "\nThe list of Races:\n";
	DisplayArray(Races, n);
	char carryingTag[N];
	cout << "\nEnter the carrying-tag:";
	cin >> carryingTag;
	double lowtotalÑost, uppertotalÑost;
	cout << "\nEnter the low boundary of totalÑost:";
	cin >> lowtotalÑost;
	cout << "\nEnter the upper boundary of totalÑost:";
	cin >> uppertotalÑost;
	cout << "\n\nThe list of choise-Races:\n";
	DisplayChoise(Races, n, carryingTag, lowtotalÑost, uppertotalÑost);
	cout << "\n\nThe sorting list of Races: \n";
	SortcarModel(Races, n);
	DisplayArray(Races, n);
	delete[] Races;
	system("pause");
	return 0;
}

Race InitRace()
{
	char carModel[N] = "not", licensePlate[N] = "not", carrying[N] = "not";
	cout << "\nEnter model of car:";
	cin.ignore();
	cin.get(carModel, N, '\n');
	cout << "Enter license plate:";
	cin.ignore();
	cin.get(licensePlate, N, '\n');
	cout << "Enter Carrying:";
	cin.ignore();
	cin.get(carrying, N, '\n');

	cout << "Enter the number of goods:";
	/*const int num;
	cin >> num;
	cout << "Enter array of the unit cost:";*/
	int A[M];
	EnterArray(A, M);
	Race trip;
	trip.SetRace(carModel, licensePlate, carrying, A);
	return trip;
}

Race* InitArray(int n)
{
	Race* array = new Race[n];
	if (!array)
		return NULL;
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter the information about " << (i + 1) << " Race\n";
		array[i] = InitRace();
	}
	return array;
}

void EnterArray(int* array, int n)
{
	for (int i = 0; i < M; i++)
	{
		cout << "enter A[" << (i + 1) << "] = ";
		cin >> array[i];
	}
}


void DisplayArray(Race* array, int n)
{
	for (int i = 0; i < n; i++)
		array[i].DisplayRace();
	cout << endl;
}

void DisplayChoise(Race* array, int dimension, char* carryingTag, double lowUniÑost, double upperUniÑost)
{
	for (int i = 0; i < dimension; i++)
	if (!strcmp(array[i].Getcarrying(), carryingTag) && array[i].GetTotalÑost()
		<= upperUniÑost  &&  array[i].GetTotalÑost() >= lowUniÑost)
		array[i].DisplayRace();
}

void SortcarModel(Race* array, int n)
{
	for (int i = 0; i <= n; i++)
	for (int j = n - 1; j > i; j--)
	if (strcmp(array[j].GetcarModel(), array[j - 1].GetcarModel()) < 0)
		Swap(array[j], array[j - 1]);
}

void Swap(Race &a, Race &b)
{
	Race t = a;
	a = b;
	b = t;
}




void InitFile(char* fileName)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Race);
	//Race* man = new Race;
	Race man;
	char Ok = 'y';
	while (Ok == 'y')
	{
		//man->EnterRace();
		man.EnterRace();//
		//streamOut.write((char*)man,bufSize);
		streamOut.write((char*)&man, bufSize);
		cout << " If do you want to continue, press 'y' :";
		cin >> Ok;
	}
	//delete man;
	streamOut.close();
}

void AddToEndFile(char* fileName)
{
	ofstream streamOut(fileName, ios::app | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "Can't open file to write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Race);
	Race man;
	char Ok = 'y';
	while (Ok == 'y')
	{
		man.EnterRace();
		streamOut.write((char*)&man, bufSize);
		cout << " If do you want to continue, press 'y' : ";
		cin >> Ok;
	}
	streamOut.close();
}

void ChangeFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut)
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Race);
	Race man;
	long Position;
	InitNumber(Position);
	streamInOut.seekp((Position - 1) * bufSize, ios::beg);
	man.EnterRace();
	streamInOut.write((char*)&man, bufSize);
	streamInOut.close();
}

void RemoveFromFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut.is_open())
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	streamInOut.seekp(0, ios::end);//*
	long N = streamInOut.tellp();//*
	int bufSize = sizeof(Race);
	Race man;
	long Position;
	InitNumber(Position);
	streamInOut.seekp(Position * bufSize, ios::beg);
	while (streamInOut.read((char*)&man, bufSize))
	{
		//streamInOut.seekp( (Position - 1 + i ) * bufSize, ios::beg);
		//streamInOut.write((char*)&man, bufSize);
		//streamInOut.seekp( bufSize, ios::cur);
		//i++;
		streamInOut.seekp(-2 * bufSize, ios::cur);
		streamInOut.write((char*)&man, bufSize);
		streamInOut.seekp(bufSize, ios::cur);
	}
	streamInOut.close();
	int DiskriptorFile = open(fileName, 2);//*
	chsize(DiskriptorFile, N - bufSize);//*
	close(DiskriptorFile);//*
}

void SortingFile(char* fileName)
{
	bool flag = true;
	while (flag)
	{
		fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
		if (!streamInOut.is_open())
		{
			cout << "Can't open file to read and write!";
			SystemFun();
			return;
		}
		flag = false;
		Race manOne, manTwo;
		int bufSize = sizeof(Race);
		streamInOut.read((char*)&manOne, bufSize);
		while (streamInOut.read((char*)&manTwo, bufSize))
		{
			if (manTwo.GetTotalÑost() < manOne.GetTotalÑost())
			{
				streamInOut.seekp(-2 * bufSize, ios::cur);
				streamInOut.write((char*)&manTwo, bufSize);
				streamInOut.write((char*)&manOne, bufSize);
				flag = true;
			}
			streamInOut.seekp(-bufSize, ios::cur);
			streamInOut.read((char*)&manOne, bufSize);
		}
		streamInOut.close();
	}
}

void DisplayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Race);
	Race* man = new Race;
	while (streamIn.read((char*)man, bufSize))
	{
		man->DisplayRace();
	}
	streamIn.close();
}

void InitNumber(long& n)
{
	cout << "Enter the number of record:" << endl;
	cin >> n;
	system("cls");
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

void InitNameFile(char* fileName)
{
	cout << "Enter the name of file: " << endl;
	cin.ignore();
	cin.getline(fileName, 256, '\n');
	system("cls");
}

int Menu()
{
	int k;
	cout << "\n Enter the number - the mode of operations with file:"
		"\n 1 - INITIALIZATION THE NAME OF FILE"
		"\n 2 - FORMATION OF THE FILE"
		"\n 3 - VIEWING OF CONTENTS OF THE FILE"
		"\n 4 - ADD AN ELEMENT TO AND OF FILE"
		"\n 5 - CHANGE THE ELEMENT IN THE FILE"
		"\n 6 - REMOVE THE ELEMENT IN THE FILE"
		"\n 7 - SORTING THE ELEMENT IN THE FILE"
		"\n 8 - EXIT\n";
	cin >> k;
	return k;
}
