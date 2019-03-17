/*
Justin Benson - CPS 272
2-5-2019
Learning Module 3: Lists
*/

#include <iostream>
#include <list>
#include <iterator>
#include "MiniList.h"

using namespace std;

template <typename T>
void display(const list<T>& temp)
{
	typename list<T>::const_iterator cit;
	for (cit = temp.begin(); cit != temp.end(); cit++)
	{
		cout << *cit << "\t";
	}
	cout << endl;
}


bool moreThan70(int temp)
{
	return temp > 70;
}


bool PalendromeChecker(list<char> word)
{
	bool found = false;
	while (word.front() == word.back())
	{
		word.pop_back();
		if (!word.empty())
		{
			word.pop_front();
		}
		if (word.empty())
		{
			found = true;
			break;
		}
	}
	return found;
}

int main()
{
	list<int> grades;
	list<int>::iterator it;

	list<char> word;
	bool found = false;

	word.push_back('m');
	word.push_back('a');
	word.push_back('d');
	word.push_back('d');
	word.push_back('a');
	word.push_back('m');

	list<char> nonp;
	nonp.push_back('h');
	nonp.push_back('e');
	nonp.push_back('l');
	nonp.push_back('l');
	nonp.push_back('o');


	MiniList<double> gpaList;
	gpaList.insertBack(3.92);
	gpaList.insertBack(3.01);
	gpaList.insertFront(3.87);
	gpaList.insertFront(3.99);
	cout << gpaList.getSize() << endl;
	gpaList.display();
	cout << gpaList.getFront() << endl;
	cout << gpaList.getBack() << endl;

	gpaList.removeBack();
	gpaList.removeFront();
	gpaList.display();

	cout << gpaList.getSize();

	MiniList<double> tempList;
	tempList = gpaList;

	tempList.display();

	/**
	while (word.front() == word.back())
	{
		word.pop_back();
		
		if (word.empty())
		{
			found = true;
			break;
		}

		word.pop_front();
	}
	*/

	if (!PalendromeChecker(word))
	{
		cout << "Not ";
	}
	cout << "Palendome." << endl;

	if (!PalendromeChecker(nonp))
	{
		cout << "Not ";
	}
	cout << "Palendome." << endl;


	grades.push_back(90);
	grades.push_back(78);

	grades.push_front(95);
	grades.push_front(60);

	grades.push_back(80);

	
	display(grades);

	it = grades.begin();
	it++;
	grades.insert(next(grades.begin(), 2), 100);
	grades.insert(grades.begin(), 5, 20);

	/*
	display(grades);
	it++;
	grades.erase(it);
	display(grades);

	grades.remove(20);
	display(grades);

	grades.remove_if(moreThan70);


	cout << "The size is: " << grades.size() << endl;
	grades.reverse();
	display(grades);
	


	while (!grades.empty())
	{
		cout << "Deleting..." << grades.front() << endl;
		grades.pop_front();
	}
	*/

	display(grades);

	return 0;
}