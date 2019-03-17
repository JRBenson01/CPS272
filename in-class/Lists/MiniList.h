#pragma once

#include <iostream>

template <typename T>
class MiniList;

template <typename T>
class ListNode
{
	friend class MiniList<T>;
private:
	T data;
	ListNode<T> *nextPtr;
public:
	ListNode(T info) : data(info), nextPtr(nullptr) {}
	T getData() { return data; }

};

template <typename T>
class MiniList
{
private:
	ListNode<T> *firstPtr;
	ListNode<T> *lastPtr;
public:
	MiniList();
	void insertBack(const T& val);
	void insertFront(const T& val);
	void removeBack();
	void removeFront();
	T getFront();
	T getBack();
	int getSize();
	bool isEmpty();
	void display();
	MiniList<T> operator=(MiniList<T>& rhs);
	bool check();
	void clear();
};

template<typename T>
MiniList<T>::MiniList() : firstPtr(nullptr), lastPtr(nullptr) {}

template<typename T>
void MiniList<T>::insertBack(const T& val)
{
	ListNode<T> *ptr = new ListNode<T>(val);
	if (isEmpty())
	{
		firstPtr = lastPtr = ptr;
	}
	else
	{
		lastPtr->nextPtr = ptr;
		lastPtr = ptr;
	}
}

template<typename T>
void MiniList<T>::insertFront(const T& val)
{
	ListNode<T> *ptr = new ListNode<T>(val);
	if (isEmpty())
	{
		firstPtr = lastPtr = ptr;
	}
	else
	{
		ptr->nextPtr = firstPtr;
		firstPtr = ptr;
	}
}

template<typename T>
bool MiniList<T>::check()
{
	if (isEmpty())
	{
		return true;
	}
	if (firstPtr == lastPtr)
	{
		delete firstPtr;
		firstPtr = lastPtr = nullptr;
		return true;
	}
	return false;
}

template<typename T>
void MiniList<T>::removeBack()
{
	if (!check())
	{
		ListNode<T> *temp = firstPtr;

		while (temp->nextPtr != lastPtr)
		{
			temp = temp->nextPtr;
		}
		delete lastPtr;
		lastPtr = temp;
		temp->nextPtr = nullptr;
	}
}

template<typename T>
void MiniList<T>::removeFront()
{
	if (!check())
	{
		ListNode<T> *temp = firstPtr;
		firstPtr = firstPtr->nextPtr;
		delete temp;
	}
}

template<typename T>
T MiniList<T>::getFront()
{
	if (!isEmpty())
	{
		return firstPtr->data;
	}
	return NULL;
}

template<typename T>
T MiniList<T>::getBack()
{
	if (!isEmpty())
	{
		return lastPtr->data;
	}
	return NULL;
}


template<typename T>
bool MiniList<T>::isEmpty()
{
	return firstPtr == nullptr;
}

template<typename T>
int MiniList<T>::getSize()
{
	int count = 0;
	ListNode<T> *curr = firstPtr;

	while (curr != nullptr)
	{
		count++;
		curr = curr->nextPtr;
	}
	return count;
}

template<typename T>
void MiniList<T>::display()
{
	if (isEmpty())
	{
		cout << "There is nothing to print" << endl;
		return;
	}

	ListNode<T> *curr = firstPtr;
	while (curr != nullptr)
	{
		cout << curr->data << "\t";
		curr = curr->nextPtr;
	}
	cout << endl;
}

template<typename T>
MiniList<T> MiniList<T>::operator=(MiniList<T>& rhs)
{
	if (rhs.isEmpty())
	{
		return MiniList<T>();
	}

	this->clear();

	ListNode<T> *curr = rhs.firstPtr;

	while (curr != nullptr)
	{
		this->insertBack(curr->data);
		curr = curr->nextPtr;
	}
	return *this;
}

template<typename T>
void MiniList<T>::clear()
{
	if (isEmpty())
	{
		return;
	}

	ListNode<T> *curr = firstPtr;

	while (curr != nullptr)
	{
		firstPtr = firstPtr->nextPtr;
		delete curr;
		curr = firstPtr;
	}
	lastPtr = nullptr;
}