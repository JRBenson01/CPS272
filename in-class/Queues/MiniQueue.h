#pragma once
#include <iostream>
#include <list>

using namespace std;

const int SIZE = 10;


template <typename T>
class LQueue : list<T>
{
public:
	void Push(const T& item);
	void Pop();
	bool Empty();
	void Print();
};

template <typename T>
void LQueue<T>::Push(const T& item)
{
	this->push_back(item);
}

template <typename T>
void LQueue<T>::Pop()
{
	this->pop_front();
}

template <typename T>
bool LQueue<T>::Empty()
{
	return this->list<T>::empty();
}

template <typename T>
void LQueue<T>::Print()
{
	for (T item : *this)
	{
		cout << item << "\t";
	}
	cout << endl;
}


template <typename T>
class MiniQueue
{
private:
	T arr[SIZE];
	int first, last, count;
public:
	MiniQueue() : first(0), last(0), count(0) {}
	void Push(const T& val);
	void Pop();
	T& Front();
	T& Back();
	void Display();
	int Size();
	bool Empty();
};

template <typename T>
void MiniQueue<T>::Push(const T& val)
{
	if (count == SIZE)
	{
		throw exception("full");
	}
	arr[last] = val;
	count++;
	last = (last + 1) % SIZE;
}

template <typename T>
void MiniQueue<T>::Pop()
{
	if (Empty())
	{
		throw exception("Empty");
	}
	count--;
	first = (first + 1) % SIZE;
}

template <typename T>
T& MiniQueue<T>::Front()
{
	return arr[first];
}

template <typename T>
T& MiniQueue<T>::Back()
{
	return arr[(last - 1 + SIZE) % SIZE];
}

template<typename T>
bool MiniQueue<T>::Empty()
{
	return count == 0;
}

template <typename T>
int MiniQueue<T>::Size()
{
	return count;
}

template <typename T>
void MiniQueue<T>::Display()
{
	if (count == 0)
	{
		throw exception("empty");
	}
	for (int i = first; i < first + count; i++)
	{
		cout << arr[i % SIZE] << '\t';
	}
	cout << endl;
}