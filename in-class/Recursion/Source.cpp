/*
Justin Benson - CPS 272
Recursion, Linked List, Doubly Linked List, Circular Linked List
3-5-2019
*/

#include <iostream>
#include "LinkedList.h"

using namespace std;

int fact(int n)
{
	if (n <= 1)		//Base case stops recursion
		return 1;
	return n * fact(n - 1);	//General case reduces down to base case
}

void cvtDec2Bin(int num)
{
	if (num > 0)
	{
		cvtDec2Bin(num / 2);
		cout << num % 2;
	}
}

/*
void ReversePrint(node * curr)
{
	if (curr != nullptr)
	{
		reversePrint(curr->next);
		cout << curr->info << " ";
	}
}
*/

class NQueenPuzzle
{
private:
	int num;
	int queens;
	int *qRow;
public:
	NQueenPuzzle(int q = 8);
	bool CanPlace(int r, int c);
	void QueenConfig(int k);
	void PrintConfig();
	int NumOfSolutions();
};

NQueenPuzzle::NQueenPuzzle(int q)
{
	queens = q;
	qRow = new int[queens];
	int num = 0;
}

bool NQueenPuzzle::CanPlace(int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		if ((qRow[i] == c) || abs(qRow[i] - c) == abs(i - r))
		{
			return false;
		}
	}
	return true;
}

void NQueenPuzzle::QueenConfig(int k)
{
	for (int i = 0; i < queens; i++)
	{
		if (CanPlace(k, i))
		{
			qRow[k] = i;			// place kth queen in column i
			if (k == queens - 1)	// if all queens are placed:
				PrintConfig();		// print all the queens
			else
				QueenConfig(k + 1);	//determine place for next queen
		}
	}
}

void NQueenPuzzle::PrintConfig()
{
	for (int i = 0; i < queens - 1; i++)
	{
		cout << qRow[i] << ", ";
	}
	cout << qRow[queens - 1] << endl;
}

int NQueenPuzzle::NumOfSolutions()
{
	return num;
}

int main()
{
	CircularLinkedList<int> grades;
	grades.initialize();

	grades.insert(78);
	grades.insert(56);
	grades.insert(69);
	grades.insert(77);
	grades.insert(92);
	grades.insert(70);

	cout << "Printing..." << endl;
	grades.print();

	cout << "Printing in reverse using recursion..." << endl;
	grades.reversePrint(0);

	cout << "Printing in reverse without recursion..." << endl;
	grades.reversePrint();

	cout << "Printing using the iterator" << endl;
	CircularLinkedListIterator<int> it;
	for (it = grades.begin(); it != grades.end(); it++)
	{
		cout << *it << '\t';
	}
	cout << endl;




	//NQueenPuzzle puzzle;
	//puzzle.QueenConfig(0);

	//cout << fact(5) << endl;
	//cvtDec2Bin(28);
	//cout << endl;

	return 0;
}

//Is there a delayed return command?