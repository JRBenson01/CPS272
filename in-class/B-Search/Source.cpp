/*
Justin Benson - CPS 272
Binary Trees and B-Trees
3-12-2019
*/

#include <iostream>

using namespace std;

struct NodeType
{
	int info;
	NodeType *lLink;
	NodeType *rLink;
};

class BinaryTreeType		//Abstract class
{
protected:
	NodeType * root;
public:
	BinaryTreeType();
	virtual void Insert(const int& item) = 0;
	virtual void Delete(const int& item) = 0;
	bool IsEmpty();
	void PreOrderTraversal();
	void PostOrderTraversal();
	void InOrderTraversal();
private:
	void PreOrder(NodeType *p);
	void PostOrder(NodeType *p);
	void InOrder(NodeType *p);
};

class BST : public BinaryTreeType
{
public:
	void Insert(const int& item);
	void Delete(const int& item);
private:
	void DeleteFromTree(NodeType *&p);
};

void BST::Insert(const int& item)
{
	NodeType *currPtr, *trailPtr = nullptr;
	NodeType *newNode = new NodeType;
	newNode->info = item;
	newNode->lLink = nullptr;
	newNode->rLink = nullptr;

	if (IsEmpty())
	{
		root = newNode;
	}
	else
	{
		currPtr = root;
		while (currPtr != nullptr)
		{
			trailPtr = currPtr;
			if (currPtr->info == item)
				return;
			if (currPtr->info > item)
				currPtr = currPtr->lLink;
			else
				currPtr = currPtr->rLink;
		}
		if (trailPtr->info > item)
			trailPtr->lLink = newNode;
		else
			trailPtr->rLink = newNode;
	}
}

void BST::Delete(const int& item)
{
	NodeType *currPtr, *trailPtr;
	bool found = false;

	if (IsEmpty())
		cout << "Nothing to delete" << endl;

	else
	{
		currPtr = root;
		trailPtr = nullptr;

		while (currPtr != nullptr && !found)
		{
			if (currPtr->info == item)
				found = true;
			else
			{
				trailPtr = currPtr;
				if (currPtr->info > item)
					currPtr = currPtr->lLink;
				else
					currPtr = currPtr->rLink;
			}
		}
		if (!found)
			cout << "Item not found" << endl;
		else
		{
			if (currPtr == root)
			{
				cout << "Deleting the root..." << endl;
				DeleteFromTree(root);
			}
			else if (trailPtr->info > item)
				DeleteFromTree(trailPtr->lLink);
			else
				DeleteFromTree(trailPtr->rLink);
		}
	}
}

void BST::DeleteFromTree(NodeType *& p)
{
	NodeType *currPtr, *trailPtr, *tempPtr;
	if (p->lLink == nullptr && p->rLink == nullptr)
	{
		tempPtr = p;
		p = nullptr;
		delete tempPtr;
	}
	else if (p->lLink == nullptr)
	{
		tempPtr = p;
		p = tempPtr->rLink;
		delete tempPtr;
	}
	else if (p->rLink == nullptr)
	{
		tempPtr = p;
		p = tempPtr->lLink;
		delete tempPtr;
	}
	else
	{
		currPtr = p->lLink;
		trailPtr = nullptr;
		while (currPtr->rLink != nullptr)
		{
			trailPtr = currPtr;
			currPtr = currPtr->rLink;
		}
		p->info = currPtr->info;
		if (trailPtr == nullptr)
			p->lLink = currPtr->lLink;
		else
			trailPtr->rLink = currPtr->lLink;
		delete currPtr;
	}
}

BinaryTreeType::BinaryTreeType()
{
	root = nullptr;
}

bool BinaryTreeType::IsEmpty()
{
	return root == nullptr;
}

void BinaryTreeType::PreOrderTraversal()
{
	PreOrder(root);
}

void BinaryTreeType::PreOrder(NodeType *p)
{
	if (p != nullptr)
	{
		cout << p->info << " ";
		PreOrder(p->lLink);
		PreOrder(p->rLink);
	}
}

void BinaryTreeType::PostOrderTraversal()
{
	PostOrder(root);
}

void BinaryTreeType::PostOrder(NodeType *p)
{
	if (p != nullptr)
	{
		PostOrder(p->lLink);
		PostOrder(p->rLink);
		cout << p->info << " ";
	}
}

void BinaryTreeType::InOrderTraversal()
{
	InOrder(root);
}

void BinaryTreeType::InOrder(NodeType *p)
{
	if (p != nullptr)
	{
		InOrder(p->lLink);
		cout << p->info << " ";
		InOrder(p->rLink);
	}
}

int main()
{
	BST numbersTree;

	numbersTree.Insert(35);
	numbersTree.Insert(15);
	numbersTree.Insert(45);
	numbersTree.Insert(46);
	numbersTree.Insert(75);
	numbersTree.Insert(70);
	numbersTree.Insert(65);
	numbersTree.Insert(40);
	numbersTree.Insert(15);
	numbersTree.Insert(50);

	numbersTree.InOrderTraversal();
	cout << endl;

	numbersTree.PreOrderTraversal();
	cout << endl;

	numbersTree.PostOrderTraversal();
	cout << endl;

	numbersTree.Delete(45);
	numbersTree.Delete(75);

	numbersTree.InOrderTraversal();
	cout << endl;

	return 0;
}