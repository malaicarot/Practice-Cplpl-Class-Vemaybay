#include<iostream>
#include<stack>
#include<string>

using namespace std;


string maHoaChuoi(string chuoiBanDau);

int main(){

    int c = 61;
    string b = to_string(c);
  cout << b;
   
    



    system("pause");
    return 0;
}
string maHoaChuoi()
{
    stack<char> myStack;
    string chuoiBanDau;
    string chuoiMaHoa = "";
    int count = 0; // doc so luong ki tu lien ke giong nhau
    getline(cin, chuoiBanDau);
    int i = 0;
    while (i < chuoiBanDau.length())
    {
        char c = chuoiBanDau.at(i);
        if (c >= 97 && c <= 122)
        {
            if (myStack.empty() || c == myStack.top())
            {
                myStack.push(c);
            }
            else
            {
                chuoiMaHoa += myStack.top();
                while (!myStack.empty())
                {
                    myStack.pop();
                    count++; // dem so luong ki tu giong nhau
                }
                chuoiMaHoa += to_string(count);
                count = 0;
                myStack.push(c); // push ki tu khac vao
            }
        }
        i++;
    }
    if (!myStack.empty()) // neu stack khong rong
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