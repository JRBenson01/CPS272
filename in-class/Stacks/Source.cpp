/*
Justin Benson | CPS 272
2-12-2019
Stacks
*/

#include <iostream>
#include <stack>
#include <string>
#include "MiniStack.h"

using namespace std;

class A
{
private:
	int n1, n2;
public:
	A(int x = 10, int y = 20) : n1(x), n2(y) {}
	void display()
	{
		cout << n1 << '\t' << n2 << endl;
	}
};

class PostFix
{
private:
	string postExpr;
	MiniStack<int> opStack;
public:
	PostFix() : postExpr("") {}
	void Set(string ex) { postExpr = ex; }
	string Get() { return postExpr; }
	int Evaluate();
	int Compute(int lhs, int rhs, char opr);
	bool isOperator(char ch);
};

bool PostFix::isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int PostFix::Compute(int lhs, int rhs, char opr)
{
	switch (opr)
	{
	case '+': return lhs + rhs;
	case '-': return lhs - rhs;
	case '*': return lhs * rhs;
	case '/': return lhs / rhs;
	}
	return 0;
}

int PostFix::Evaluate() 
{
	char ch = ' ';
	int l = 0, r = 0;
	for (string::size_type i = 0; i < postExpr.size(); i++)
	{
		ch = postExpr[i];
		if (isdigit(ch))
		{
			opStack.Push(ch - '0');
		}
		else if (isOperator(ch))
		{
			r = opStack.Top();
			opStack.Pop();

			l = opStack.Top();
			opStack.Pop();

			opStack.Push(Compute(l, r, ch));
		}
	}
	return opStack.Top();
}

int main()
{
	stack<int> grades;
	stack<A> letterStack;

	PostFix quickMaths;

	quickMaths.Set("1 2 +");
	cout << quickMaths.Evaluate() << endl;

	quickMaths.Set("1 2 3 / +");
	cout << quickMaths.Evaluate() << endl;



	letterStack.emplace(59, 20);
	letterStack.emplace(65, 100);

	letterStack.top().display();
	letterStack.pop();
	letterStack.push(30);
	letterStack.top().display();

	if (!grades.empty())
	{
		grades.pop();
	}

	grades.push(73);
	grades.push(80);
	grades.push(66);
	grades.push(92);

	cout << "Size: " << grades.size() << endl;
	cout << "Top grade: " << grades.top() << endl;

	while (!grades.empty())
	{
		cout << "Deleting: " << grades.top() << endl;
		grades.pop();
	}

	return 0;
}