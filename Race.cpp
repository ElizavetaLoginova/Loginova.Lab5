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

void Race::SetUni—osts(int* A)
{
	for(int i = 0; i < M; i++)
		Uni—osts[i] = A[i];
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

double Race::GetTotal—ost()
{
	return total—ost;
}

void Race::SetTotal—ost()
{
	total—ost = 0;
	for(int i = 0; i < M; i++)
		total—ost += Uni—osts[i];
}

void Race::SetRace(char* s1, char* s2, char* s3, int* a)
{
	Model(s1);
	LicensePlate(s2);
	Carrying(s3);
	SetUni—osts(a);
	SetTotal—ost();
}

void Race::DisplayRace()
{
	cout << endl << carModel << " " << licensePlate << ", \t";
	cout.precision(3);
	cout << total—ost << "  , \t" <<  carrying << ".";
	cout << "\tUni—osts: ";
	for(int i = 0; i < M; i++)
		cout << Uni—osts[i] << "  ";
}

void Race::EnterRace()
{
	const int N = 256;
	char carModel[N] = "", licensePlate[N] = "", carrying[N] = "";
	cout << "Enter the model of car:";
	cin.ignore();
	cin.getline(carModel, N, '\n');
	cout << "Enter the licence plate (π):";
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