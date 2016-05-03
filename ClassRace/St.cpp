#include <iostream>
#include "Race.h"

using namespace std;

Race InitRace();
Race* InitArray(int);
void DisplayArray(Race*, int);
void EnterArray(int*, int);
void DisplayChoise(Race*, int, char*, double, double);
void SortcarModel(Race*, int);
void Swap(Race&, Race&);

int main()
{
	int n;
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

void DisplayChoise(Race* array, int dimension, char* carryingTag, double lowMark, double upperMark)
{
	for (int i = 0; i < dimension; i++)
	if (!strcmp(array[i].Getcarrying(), carryingTag) && array[i].GetTotalÑost()
		<= upperMark  &&  array[i].GetTotalÑost() >= lowMark)
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
