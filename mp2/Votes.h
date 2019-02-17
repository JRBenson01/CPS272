#pragma once
#include <string>
#include <vector>

using namespace std;

class Candidate
{
private:
	int votes;
	string name;
public:
	Candidate(string n = "Doe", int v = 0) : votes(v), name(n) {}
	void SetVotes(int newVotes);
	int GetVotes();
	string GetName();
};

class VoteList
{
private:
	vector<Candidate> candList;
public:
	
};