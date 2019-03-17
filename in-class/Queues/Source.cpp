/*
Justin Benson
2/19/2019
Queues
*/

#include <iostream>
#include "MiniQueue.h"
#include <vector>
#include <queue>
#include <string>
#include <fstream>

using namespace std;




void Distribute(vector<int> v, queue<int> arr[], int p)
{
	for (int i = 0; i < v.size(); i++)
	{
		arr[v[i] / p % 10].push(v[i]);
	}
}

void Collect(queue<int> arr[], vector<int>& v)
{
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		while (!arr[i].empty())
		{
			v[j] = arr[i].front();
			arr[i].pop();
			j++;
		}
	}
}

void RadixSort(vector<int>& v, int d)
{
	queue<int> arrQ[10];
	int power = 1;
	for (int i = 0; i < d; i++)
	{
		Distribute(v, arrQ, power);
		Collect(arrQ, v);
		power *= 10;
	}
}

class JobRequest
{
	friend ostream& operator<<(ostream& os, const JobRequest& j)
	{
		os << j.jobid << '\t' << j.jobtime << '\t' << j.title << endl;
		return os;
	}

	friend istream& operator>>(istream& is, JobRequest& j)
	{
		string t;
		is >> t >> j.jobid >> j.jobtime;
		switch (t[0])
		{
		case 'c': j.title = JobRequest::clerk; break;
		case 'm': j.title = JobRequest::manager; break;
		case 'p': j.title = JobRequest::president; break;
		case 's': j.title = JobRequest::supervisor; break;
		}
		return is;
	}
public:
	enum staff {clerk, supervisor, manager, president};
	JobRequest() {}
	int GetID() { return jobid; }
	int GetTime() { return jobtime; }
	bool operator<(const JobRequest& j) const;
private:
	staff title;
	int jobid;
	int jobtime;
};

bool JobRequest::operator<(const JobRequest& j) const
{
	if (title == j.title)
	{
		if (jobtime > j.jobtime)
		{
			return true;
		}
		else
			return false;
	}
	else if (title < j.title)
		return true;
	else
		return false;
}

int main()
{
	ifstream fin("jobs.txt");
	priority_queue<JobRequest> myJobs;
	JobRequest job;
	while (!fin.eof())
	{
		fin >> job;
		myJobs.push(job);
	}
	fin.close();

	while (!myJobs.empty())
	{
		cout << myJobs.top();
		myJobs.pop();
	}


	MiniQueue<int> grades;
	LQueue<char> letters;
	vector<int> vi;

	vi.push_back(29);
	vi.push_back(50);
	vi.push_back(17);
	vi.push_back(8);
	vi.push_back(11);
	vi.push_back(67);
	vi.push_back(97);

	RadixSort(vi, 2);
	for (int i : vi)
	{
		cout << i << ", ";
	}
	cout << endl;


	letters.Push('B');
	letters.Push('E');
	letters.Push('N');

	if (!letters.Empty())
	{
		letters.Pop();
	}
	letters.Print();

	grades.Push(95);
	grades.Push(80);
	grades.Push(99);
	grades.Push(74);
	grades.Push(55);
	grades.Push(62);
	grades.Push(11);
	grades.Push(22);
	grades.Push(5);
	grades.Push(100);

	cout << "size: " << grades.Size() << endl;
	cout << "front: " << grades.Front() << endl;
	cout << "back: " << grades.Back() << endl;

	if (!grades.Empty()) 
	{
		cout << "deleting..." << grades.Front() << endl;
		grades.Pop();
	}
	cout << "size: " << grades.Size() << endl;

	grades.Push(44);

	grades.Display();

	cout << "size: " << grades.Size() << endl;
	cout << "front: " << grades.Front() << endl;
	cout << "back: " << grades.Back() << endl;

	//grades.Push(2); causes full exception	

	return 0;

}