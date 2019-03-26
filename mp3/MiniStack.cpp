#include "MiniStack.h"
#include <exception>
#include <iostream>

using namespace std;


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
int MiniStack<T>::Size() const
{
	return counter + 1;
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
		cout << "stack empty" << endl;
	}
	counter--;
}

template <typename T>
T& MiniStack<T>::Top()
{
	if (Empty())
	{
		cout << "stack empty" << endl;
	}
	return ptr[counter];
}

template <typename T>
MiniStack<T>& MiniStack<T>::operator=(const MiniStack<T>& rhs)
{
	if (Empty())
	{
		counter = -1;
	}

	//Delete the data that was previously there
	delete[] ptr;		

	//Allocate the spaces for rhs's data and copy data of its respective members
	length = rhs.length;
	for(int i = 0; i <= counter; i++)
	{
		ptr[i] = rhs.ptr[i];
	}

	return *this;
}