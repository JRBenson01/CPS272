#include "Votes.h"

using namespace std;

void Candidate::SetVotes(int newVotes)
{
	votes = newVotes;
}

int Candidate::GetVotes()
{
	return votes;
}

string Candidate::GetName()
{
	return name;
}
