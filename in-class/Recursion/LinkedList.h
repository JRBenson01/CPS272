#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct NodeType
{
	T info;
	NodeType<T> *nextPtr;
	NodeType<T> *prevPtr;
};

template <typename T>
class CircularLinkedListIterator
{
private:
	NodeType<T> *curr;
public:
	CircularLinkedListIterator() { curr = nullptr; }
	CircularLinkedListIterator(NodeType<T> *ptr) { curr = ptr; }
	bool operator !=(const CircularLinkedListIterator<T>& rhs) {return curr != rhs.curr;}
	CircularLinkedListIterator<T> operator++()
	{
		curr = curr->nextPtr;
		return *this;
	}
	CircularLinkedListIterator<T> operator++(int i)
	{
		CircularLinkedListIterator<T> temp = *this;
		curr = curr->nextPtr;
		return temp;
	}
	T operator*() { return curr->info; }
};

template <typename T>
class CircularLinkedList
{
private:
	NodeType<T> *frontPtr;
	NodeType<T> *lastPtr;
	int count;
public:
	CircularLinkedList();
	CircularLinkedListIterator<T> begin();
	CircularLinkedListIterator<T> end();
	void initialize();
	void destroy();
	void print();
	bool isEmpty();
	void reversePrint();
	void reversePrint(int i);	//prints using recursion
	void recursivePrint(NodeType<T> * curr);
	void insert(const T& item);
};

template <typename T>
CircularLinkedList<T>::CircularLinkedList()
{
	frontPtr = lastPtr = nullptr;
	count = 0;
}

template <typename T>
CircularLinkedListIterator<T> CircularLinkedList<T>::begin()
{
	return frontPtr;
}

template <typename T>
CircularLinkedListIterator<T> CircularLinkedList<T>::end()
{
	return nullptr;
}

template <typename T>
void CircularLinkedList<T>::initialize()
{
	destroy();
}

template <typename T>
void CircularLinkedList<T>::destroy()
{
	NodeType<T> *temp;
	while (frontPtr != nullptr)
	{
		temp = frontPtr;
		frontPtr = frontPtr->nextPtr;
		delete temp;
	}
	lastPtr = nullptr;
	count = 0;
}

template <typename T>
bool CircularLinkedList<T>::isEmpty()
{
	return frontPtr == nullptr;
}

template <typename T>
void CircularLinkedList<T>::print()
{
	NodeType<T> *temp = frontPtr;
	while (temp != nullptr)
	{
		cout << temp->info << ", ";
		temp = temp->nextPtr;
	}
	cout << endl;
}

template <typename T>
void CircularLinkedList<T>::reversePrint()
{
	NodeType<T> *curr = lastPtr;
	while (curr != nullptr)
	{
		cout << curr->info << ", ";
		curr = curr->prevPtr;
	}
	cout << endl;
}

template <typename T>
void CircularLinkedList<T>::reversePrint(int i)
{
	recursivePrint(frontPtr);
	cout << endl;
}

template <typename T>
void CircularLinkedList<T>::recursivePrint(NodeType<T> *curr)
{
	if (curr != nullptr)
	{
		recursivePrint(curr->nextPtr);
		cout << curr->info << ", ";
	}

}

template <typename T>
void CircularLinkedList<T>::insert(const T& item)
{
	//create node
	NodeType<T> *n = new NodeType<T>;
	n->info = item;
	n->nextPtr = nullptr;
	n->prevPtr = nullptr;

	//check if empty
	if (isEmpty())
	{
		frontPtr = n;
		lastPtr = n;
		count++;
		return;
	}

	//search where to insert the item
	NodeType<T> *curr = frontPtr;
	while (curr != nullptr)
	{
		if (curr->info >= item)
			break;
		curr = curr->nextPtr;
	}

	if (curr == frontPtr)
	{
		//insert before first
		n->nextPtr = frontPtr;
		frontPtr->prevPtr = n;
		frontPtr = n;
	}
	else
	{
		//insert in the middle
		if (curr != nullptr)
		{
			n->nextPtr = curr;
			n->prevPtr = curr->prevPtr;
			curr->prevPtr = n;
			n->prevPtr->nextPtr = n;
		}
		else
		{
			//insert at the end
			n->prevPtr = lastPtr;
			lastPtr->nextPtr = n;
			lastPtr = n;
		}
	}
	count++;
}

template <typename T>
class CircularLinkedListIterator
{
private:
	NodeType<T> *curr;
public:
	CircularLinkedListIterator() { curr = nullptr; }
	CircularLinkedListIterator(NodeType<T> *ptr) { curr = ptr; }
	bool operator !=(const CircularLinkedListIterator<T>& rhs) { return curr != rhs.curr; }
	CircularLinkedListIterator<T> operator++()
	{
		curr = curr->nextPtr;
		return *this;
	}
	CircularLinkedListIterator<T> operator++(int i)
	{
		CircularLinkedListIterator<T> temp = *this;
		curr = curr->nextPtr;
		return temp;
	}
	T operator*() { return curr->info; }
};

template <typename T>
class CircularLinkedList
{
private:
	NodeType<T> *frontPtr;
	NodeType<T> *lastPtr;
	int count;
public:
	CircularLinkedList();
	CircularLinkedListIterator<T> front();
	CircularLinkedListIterator<T> back();
	void initialize();
	void destroy();
	void print();
	bool isEmpty();
	void reversePrint();
	void reversePrint(int i);	//prints using recursion
	void recursivePrint(NodeType<T> * curr);
	void insert(const T& item);
};

template <typename T>
CircularLinkedList<T>::CircularLinkedList()
{
	frontPtr = lastPtr = nullptr;
	count = 0;
}

template <typename T>
CircularLinkedListIterator<T> CircularLinkedList<T>::front()
{
	return frontPtr;
}

template <typename T>
CircularLinkedListIterator<T> CircularLinkedList<T>::back()
{
	return nullptr;
}

template <typename T>
void CircularLinkedList<T>::initialize()
{
	destroy();
}

template <typename T>
void CircularLinkedList<T>::destroy()
{
	NodeType<T> *temp;
	while (frontPtr != nullptr)
	{
		temp = frontPtr;
		frontPtr = frontPtr->nextPtr;
		delete temp;
	}
	lastPtr = nullptr;
	count = 0;
}

template <typename T>
bool CircularLinkedList<T>::isEmpty()
{
	return frontPtr == nullptr;
}

template <typename T>
void CircularLinkedList<T>::print()
{
	NodeType<T> *temp = frontPtr;
	while (temp != nullptr)
	{
		cout << temp->info << ", ";
		temp = temp->nextPtr;
	}
	cout << endl;
}

template <typename T>
void CircularLinkedList<T>::reversePrint()
{
	NodeType<T> *curr = lastPtr;
	while (curr != nullptr)
	{
		cout << curr->info << ", ";
		curr = curr->prevPtr;
	}
	cout << endl;
}

template <typename T>
void CircularLinkedList<T>::reversePrint(int i)
{
	recursivePrint(frontPtr);
	cout << endl;
}

template <typename T>
void CircularLinkedList<T>::recursivePrint(NodeType<T> *curr)
{
	if (curr != nullptr)
	{
		recursivePrint(curr->nextPtr);
		cout << curr->info << ", ";
	}

}

template <typename T>
void CircularLinkedList<T>::insert(const T& item)
{
	//create node
	NodeType<T> *n = new NodeType<T>;
	n->info = item;
	n->nextPtr = nullptr;
	n->prevPtr = nullptr;

	//check if empty
	if (isEmpty())
	{
		frontPtr = n;
		lastPtr = n;
		count++;
		return;
	}

	//search where to insert the item
	NodeType<T> *curr = frontPtr;
	while (curr != nullptr)
	{
		if (curr->info >= item)
			break;
		curr = curr->nextPtr;
	}

	if (curr == frontPtr)
	{
		//insert before first
		n->nextPtr = frontPtr;
		frontPtr->prevPtr = n;
		frontPtr = n;
	}
	else
	{
		//insert in the middle
		if (curr != nullptr)
		{
			n->nextPtr = curr;
			n->prevPtr = curr->prevPtr;
			curr->prevPtr = n;
			n->prevPtr->nextPtr = n;
		}
		else
		{
			//insert at the end
			n->prevPtr = lastPtr;
			lastPtr->nextPtr = n;
			lastPtr = n;
		}
	}
	count++;
}