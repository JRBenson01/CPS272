#pragma once

#include <iostream>

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
};

template <typename T>
MiniStack<T>::MiniStack(int s)
{
	length = s;
	ptr = new T[length];
	counter = -1;
}

template <typename T>
bool MiniStack<T>::Empty() const
{
	return counter == -1;
}

template <typename T>
void MiniStack<T>::Push(const T& val)
{
	counter++;
	ptr[counter] = val;
}

template <typename T>
void MiniStack<T>::Pop()
{
	if (Empty())
	{
		throw exception("Stack is empty");
	}
	counter--;
}

template <typename T>
T& MiniStack<T>::Top()
{
	if (Empty())
	{
		throw exception("Stack is empty");
	}
	return ptr[counter];
}

template <typename T>
int MiniStack<T>::Size() const
{
	return counter + 1;
}