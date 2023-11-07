#include <iostream>
#include <string>
#include <stack>

using namespace std;
string enCode();
int main()
{
    cout << enCode();

    system("pause");
    return 0;
}

string enCode()
{
    stack<char> myStack;
    string s;
    string enCodeString;
    getline(cin, s);

    int i = 0;
    int count = 0;

    while (i < s.length())
    {
        char c = s[i];
        if (c >= 97 && c <= 122)
        {
            if (myStack.empty() || c == myStack.top())
            {
                myStack.push(c);
            }
            else
            {
                enCodeString += myStack.top();
                while (!myStack.empty())
                {
                    myStack.pop();
                    count++;
                }
                enCodeString += to_string(count);
                count = 0;
                myStack.push(c);
            }
        }
        i++;
    }

    while (!myStack.empty())
    {
        enCodeString += myStack.top();
        while (!myStack.empty())
        {
            myStack.pop();
            count++;
        }
        enCodeString += to_string(count);
    }

    return enCodeString;
}