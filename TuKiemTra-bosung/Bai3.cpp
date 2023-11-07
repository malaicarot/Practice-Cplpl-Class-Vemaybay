#include <iostream>
#include <string>
#include <stack>
using namespace std;

string deletedDuplicate();
int main()
{
    cout << deletedDuplicate() << endl;

    system("pause");
    return 0;
}

string deletedDuplicate()
{
    stack<char> unDuplicateStack;
    string inputString;
    string resultString = "";
    getline(cin, inputString);
    for (int i = 0; i < inputString.length(); i++)
    {
        char c = inputString[i];
        if (c >= 97 && c <= 122)
        {
            if (unDuplicateStack.empty())
            {
                unDuplicateStack.push(c);
            }
            else
            {
                if (c != unDuplicateStack.top())
                {
                    resultString += unDuplicateStack.top();
                    unDuplicateStack.pop();
                    unDuplicateStack.push(c);
                }
                else
                {
                    unDuplicateStack.pop();
                    unDuplicateStack.push(c);
                }
            }
        }
    }
    while (!unDuplicateStack.empty())
    {
        resultString += unDuplicateStack.top();
        unDuplicateStack.pop();
    }
    
    return resultString;
}