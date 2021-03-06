#include "pch.h"
#include <fstream>
#include <iostream>

#define I 32

using namespace std;

struct people
{
	char owner_surname[I];
	char car_brand[I];
	char car_color[I];
};

void StructPeopleCreate(people *People, int n)
{
	for (int i = 0; i < n; i++)
	{
		people *p = &People[i];
		cout << "Car owner surname:" << endl;
		cin >> p->owner_surname;
		cout << "Car brand name:" << endl;
		cin >> p->car_brand;
		cout << "Car color name:" << endl;
		cin >> p->car_color;
		cout << endl;
	}
	for (int i = 0; i < 100; i++)
		cout << "_";
	cout << endl << endl << endl;
}

void StructPeopleWriteFile(people *People, int n)
{
	ofstream output_file("info.dat");
	if (output_file.fail())
	{
		cerr << "An error occurred during the file (info.dat) opening!" << endl;
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		people *p = &People[i];
		output_file << "Car owner surname : " << p->owner_surname << endl;
		output_file << "   Car brand name : " << p->car_brand << endl;
		output_file << "   Car color name : " << p->car_color << endl;
		output_file << endl;
	}
	output_file.close();
}

void StructPeopleReadFile(people *People, int n)
{
	ifstream input_file("info.dat");
	if (input_file.fail())
	{
		cerr << "An error occurred during the file (info.dat) opening!" << endl;
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		char empty_line[I];
		people *p = &People[i];
		input_file.getline(p->owner_surname, I);
		input_file.getline(p->car_brand, I);
		input_file.getline(p->car_color, I);
		input_file.getline(empty_line, I);
	}
	input_file.close();
}

void StructPeopleWrite(people *People, int n)
{
	char brand[] = "Lada", color[] = "Red";
	for (int i = 0; i < n; i++)
	{
		people *p = &People[i];
		if ((strstr(p->car_brand, brand) != 0) && (strstr(p->car_color, color) != 0))
		{
			cout << p->owner_surname << endl;
			cout << p->car_brand << endl;
			cout << p->car_color << endl;
			cout << endl;
		}
		else
		{
			cout << "----------" << endl;
			cout << endl;
		}
	}
}

int main()
{
	int n;
	cout << "Enter the amount of people : ";
	cin >> n;
	cout << endl;
	if (n > I)
	{
		cout << "The amount of people cannot be higher than " << I << endl;
		return 0;
	}
	people* People = new people[n];
	StructPeopleCreate(People, n);
	StructPeopleWriteFile(People, n);
	StructPeopleReadFile(People, n);
	StructPeopleWrite(People, n);
	return 0;
}