#include "Votes.h"
#include <string>
#include <iostream>

using namespace std;

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
void VoteList::AddCandidate(Candidate candToAdd)
{
	candList.push_back(candToAdd);
	totalVotes += candToAdd.GetVotes();
}

void VoteList::CalcVoteShare()
{
	for(int i = 0; i < candList.size; i++)
	{
		double tempVoteS = candList[i].GetVoteShare()/totalVotes;
		candList[i].SetVoteShare(tempVoteS);
	}
}

void VoteList::SortCands()
{
	
}

void VoteList::ProcessVotes()
{
	CalcVoteShare();
	SortCands();
}