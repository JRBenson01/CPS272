#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Candidate
{
private:
	int votes;
	string name;
	double voteShare = 1.0;
public:
	Candidate(string n = "Doe", int v = 0) : votes(v), name(n) {}
	void SetVotes(int newVotes);
	void SetVoteShare(double newVoteShare);
	int GetVotes();
	string GetName();
	double GetVoteShare();

	bool operator>(const Candidate& rightSideObj);
	bool operator<(const Candidate& rightSideObj);
};

class VoteList
{
	friend istream& operator>>(istream& givenStream, VoteList& righSideObj);
	friend ostream& operator<<(ostream& givenStream, const VoteList& rightSideObj);
private:
	vector<Candidate> candList;
	int totalVotes = 0;
public:
	VoteList();
	~VoteList();
	void AddCandidate(Candidate candToAdd);
	void CalcVoteShare();
	void SortCands();
	void ProcessVotes();
	int GetSize();
};