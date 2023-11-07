#include <iostream>
#include <stack>
#include <string>

using namespace std;

string maHoaChuoi();

int main()
{

    cout << maHoaChuoi() << endl;

    system("pause");
    return 0;
}

/*Dinh nghia*/
string maHoaChuoi()
{
    stack<char> myStack; // stack luu ki tu giong nhau
    string chuoiBanDau;
    string chuoiMaHoa;
    getline(cin, chuoiBanDau);
    int i = 0;     // index chuoiBanDau
    int count = 0; // dem so luong ki tu giong nhau
    while (i < chuoiBanDau.length())
    {
        char c = chuoiBanDau[i];
        if (c >= 97 && c <= 122)
        {
            if (myStack.empty() || c == myStack.top()) // neu stack rong hoac c giong ki tu tren dinh stack
            {
                myStack.push(c);
            }
            else // neu gap ki tu khac
            {
                chuoiMaHoa += myStack.top();
                while (!myStack.empty())
                {
                    myStack.pop();
                    count++; // dem so luong ki tu giong nhau
                }
                chuoiMaHoa += to_string(count);
                count = 0;
                myStack.push(c); // push ki tu khac vao sau khi xoa het cac ki tu giong nhau ban dau
            }
        }
        i++;
    }
    // Neu Stack con gia tri
    if (!myStack.empty())
    {
        chuoiMaHoa += myStack.top();
        while (!myStack.empty())
        {
            myStack.pop();
            count++; // dem so luong ki tu giong nhau
        }
        chuoiMaHoa += to_string(count);
    }
    return chuoiMaHoa;
}