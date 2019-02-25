#include "Votes.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int NAME_LEN = 20;
const int COUNT_LEN = 10;
const int PERC_LEN = 5;


//=====+ Candidate Class +=====
void Candidate::SetVotes(int newVotes)
{
	votes = newVotes;
}

void Candidate::SetVoteShare(double newVoteShare)
{
	voteShare = newVoteShare;
}

int Candidate::GetVotes()
{
	return votes;
}

string Candidate::GetName()
{
	return name;
}

double Candidate::GetVoteShare()
{
	return voteShare;
}

bool Candidate::operator>(const Candidate& rightSideObj)
{
	return this->votes > rightSideObj.votes;
}

bool Candidate::operator<(const Candidate& rightSideObj)
{
	return this->votes < rightSideObj.votes;
}




//=====+ VoteList class +=====
VoteList::VoteList()
{

}


void VoteList::AddCandidate(Candidate candToAdd)
{
	candList.push_back(candToAdd);
	totalVotes += candToAdd.GetVotes();
}

void VoteList::CalcVoteShare()
{
	for (int i = 0; i < candList.size; i++)
	{
		double tempVoteS = candList[i].GetVoteShare() / totalVotes;
		candList[i].SetVoteShare(tempVoteS);
	}
}

void VoteList::SortCands()
{
	sort(candList.begin(), candList.end());
}

void VoteList::ProcessVotes()
{
	CalcVoteShare();
	SortCands();
}

int VoteList::GetSize()
{
	return candList.size;
}

istream& operator>>(istream& givenStream, VoteList& rightSideObj)
{
	int tempVotes;
	string tempName;
	givenStream >> tempName >> tempVotes;
	Candidate tempCand(tempName, tempVotes);
	rightSideObj.AddCandidate(tempCand);

	return givenStream;
}

ostream& operator<<(ostream& givenStream, const VoteList& rightSideObj) 
{

	for (int i = 0; i < rightSideObj.candList.size; i++)
	{
		Candidate currentCand = rightSideObj.candList[i];
		givenStream << left << setw(NAME_LEN) << currentCand.GetName();
		givenStream << right << setw(COUNT_LEN) << currentCand.GetVotes();
		givenStream << setw(PERC_LEN) << currentCand.GetVoteShare << '%'
					<< endl;
	}

	return givenStream;
}
