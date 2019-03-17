/*
Containers:
1- Sequence containers
2- Associative containers
3- Adapters
*/

#include <vector>
#include <iostream>
#include <string>
#include "MiniVector.h"

using namespace std;

void PrintVector(vector<int> printingVec)
{
	int vectorSize = printingVec.size();
}

int main()
{
	MiniVector<double> gpas;

	gpas.Push_Back(3.67);
	gpas.Push_Back(3.62);
	gpas.Push_Back(3.90);

	cout << gpas.Front() << endl;
	cout << gpas.Back() << endl;
	cout << gpas.At(1) << endl;
	cout << gpas[1] << endl;
	


	vector<int> grades;		//size is zero | capacity is different
	vector<int> exams;
	vector<int>::iterator i;
	int x = 0;


	grades.push_back(76);
	grades.push_back(62);
	grades.push_back(90);
	grades.push_back(88);
	grades.push_back(70);
	grades.push_back(92);

	cout << "Size of grades: " << grades.size() << endl;
	cout << "Capacity: " << grades.capacity() << endl;

	// insert a 30 after 62
	grades.insert(grades.begin() + 2, 30);

	
	for (i = grades.begin(); i != grades.end(); i++)
	{
		cout << *i << endl;
	}

	x = grades.back();
	grades.pop_back();


	cout << "Last grade been capped." << endl;
	cout << "Size of grades: " << grades.size() << endl;

	exams = grades;				// copy not pointing (deep copy not shallow copy) | 

	while (!grades.empty())
	{
		cout << "Deleting..." << grades.back() << endl;
		grades.pop_back();
	}

	cout << "We have " << exams.size() << " exams." << endl;
}