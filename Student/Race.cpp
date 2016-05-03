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

void Race::SetMarks(int* A)
{
	for(int i = 0; i < M; i++)
		marks[i] = A[i];
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
		totalÑost += marks[i];
}

void Race::SetRace(char* s1, char* s2, char* s3, int* a)
{
	Model(s1);
	LicensePlate(s2);
	Carrying(s3);
	SetMarks(a);
	SetTotalÑost();
}

void Race::DisplayRace()
{
	cout << endl << carModel << " " << licensePlate << ", \t";
	cout.precision(3);
	cout << totalÑost << "  , \t" <<  carrying << ".";
	cout << "\tMarks: ";
	for(int i = 0; i < M; i++)
		cout << marks[i] << "  ";
}