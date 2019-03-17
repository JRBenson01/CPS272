#include <iostream>
#include <fstream>
#include "Votes.h"

using namespace std;

int main()
{
	string ph1, ph2;
	ifstream fin;
	fin.open("results.txt");

	VoteList myVoteList;

	fin >> ph1 >> ph2;
	//cout << ph1 << endl << ph2 << endl;

	while (!fin.eof())
	{
		fin >> myVoteList;
	}
	myVoteList.ProcessVotes();
	cout << myVoteList << endl;
}