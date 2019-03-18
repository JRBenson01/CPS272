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
    bool poundFound = false;

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

    for(int i = 0; i < stringStackFront.Size(); i++)
    {
        cout << stringStackFront.Top() << '\t';
        stringStackFront.Pop();
    }
    cout << endl;
    
    
    return 0;
}