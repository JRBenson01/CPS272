#pragma once

using namespace std;

template <typename T>
class MiniStack
{
private:
	T * ptr;
	int counter;
	int length;
public:
	MiniStack(int s = 10);
	bool Empty() const;
	int Size() const;
	void Push(const T& val);
	void Pop();
	T& Top();
	MiniStack<T>& operator=(const MiniStack<T>& rhs);
};





