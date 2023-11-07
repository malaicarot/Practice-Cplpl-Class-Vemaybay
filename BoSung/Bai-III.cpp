#include <iostream>
#include <string>
#include <stack>

using namespace std;

string deletedCharDuplicate();

int main()
{
    cout << deletedCharDuplicate();

    system("pause");
    return 0;
}

string deletedCharDuplicate()
{
    stack<char> notRepeatStack;
    string ipString;
    string opString = "";
    getline(cin, ipString);
    int i = 0;
    while (i < ipString.length())
    {
        char c = ipString[i];
        if (c >= 97 && c <= 122)
        {
            if (notRepeatStack.empty())
            {
                notRepeatStack.push(c);
            }
            else
            {
                if (c != notRepeatStack.top())
                {
                   opString += notRepeatStack.top();
                   notRepeatStack.pop();
                   notRepeatStack.push(c);
                }
                else
                {
                    notRepeatStack.pop();
                    notRepeatStack.push(c);
                }
            }
        }
        i++;
    }

    while (!notRepeatStack.empty())
    {
        opString += notRepeatStack.top();
        notRepeatStack.pop();
    }

    return opString;
}