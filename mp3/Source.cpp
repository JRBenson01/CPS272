#include <iostream>
#include <sstream>
#include <string>
#include "MiniStack.h"


using namespace std;

int main()
{
    MiniStack<char> stringStackFront, stringStackBack;
    string inputString;
    stringstream inputStream;
    bool poundFound = false, same = true;

    getline(cin, inputString);
    inputStream << inputString;

    while (!poundFound)
    {
        char tempChar;
        inputStream >> tempChar;
        if (tempChar == '#')
        {
            poundFound = true;
        }
        else
        {
            stringStackFront.Push(tempChar);
        }
    }

	while (same)
	{
		char tempChar;
		inputStream >> tempChar;

		if (inputStream.eof())
		{
			break;
		}

		cout << tempChar << "  " << stringStackFront.Top() << endl;

		if (tempChar == stringStackFront.Top())
		{
			stringStackFront.Pop();
		}
		else
		{
			same = false;
			cout << "Strings are not the same" << endl;
		}
	}
	if (same)
	{
		cout << "Strings are the same" << endl;
	}
    cout << endl;


    
    
    return 0;
}