#include <iostream>
#include <string.h>
#include "Race.h"
	
using namespace std;

Race::Race(){}

Race::~Race(){}

void Race::Model(char* s)
{
	strcpy(carModel,s);
}

void Race::LicensePlate(char* s)
{
	strcpy(licensePlate,s);
}

void Race::Carrying(char* s)
{
	strcpy(carrying,s);
}

void Race::SetUniÑosts(int* A)
{
	for(int i = 0; i < M; i++)
		UniÑosts[i] = A[i];
}

char* Race::GetcarModel()
{
	return carModel;
}

char* Race::GetlicensePlate()
{
	return licensePlate;
}

char* Race::Getcarrying()
{
	return carrying;
}

double Race::GetTotalÑost()
{
	return totalÑost;
}

void Race::SetTotalÑost()
{
	totalÑost = 0;
	for(int i = 0; i < M; i++)
		totalÑost += UniÑosts[i];
}

void Race::SetRace(char* s1, char* s2, char* s3, int* a)
{
	Model(s1);
	LicensePlate(s2);
	Carrying(s3);
	SetUniÑosts(a);
	SetTotalÑost();
}

void Race::DisplayRace()
{
	cout << endl << carModel << " " << licensePlate << ", \t";
	cout.precision(3);
	cout << totalÑost << "  , \t" <<  carrying << ".";
	cout << "\tUniÑosts: ";
	for(int i = 0; i < M; i++)
		cout << UniÑosts[i] << "  ";
}

void Race::EnterRace()
{
	const int N = 256;
	char carModel[N] = "", licensePlate[N] = "", carrying[N] = "";
	cout << "Enter the model of car:";
	cin.ignore();
	cin.getline(carModel, N, '\n');
	cout << "Enter the licence plate (¹):";
	cin.getline(licensePlate, N, '\n');
	cout << "Enter the carring (in tons):";
	cin.getline(carrying, N, '\n');
	int* cost = new int[M];
	cout << "Enter the costs:" << endl;
	for (int i = 0; i < M; i++)
	{
		cout << "exam[" << (i + 1) << "] = ";
		cin >> cost[i];
	}
	this->SetRace(carModel, licensePlate, carrying, cost);
	delete[] cost;
}
