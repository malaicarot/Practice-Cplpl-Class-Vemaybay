#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;
void printSuperPrimeNums(int n);
bool checkSuperPrime(int n);
bool checkPrime(int n);
int main()
{
    printSuperPrimeNums(30);
    // cout << checkSuperPrime(23);
    // cout << checkPrime(2);

    system("pause");
    return 0;
}

/*Dinh Nghia*/

bool checkPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
bool checkSuperPrime(int n)
{
    if (!checkPrime(n))
    {
        return false;
    }

    while (n != 0)
    {
        if (!checkPrime(n))
        {
            return false;
        }
        n /= 10;
    }
    return true;
}

void printSuperPrimeNums(int n)
{
    queue<int> superPrimeQueue;
    for (int i = 2; i <= n; i++)
    {
        if (checkSuperPrime(i))
        {
            superPrimeQueue.push(i);
        }
    }
    while (!superPrimeQueue.empty())
    {
        cout << superPrimeQueue.front() << " ";
        superPrimeQueue.pop();
    }
}


// vector<int> superPrimeNumber(int n) {
//     vector<int> result;
//     queue<int> q;
//     q.push(2);
//     q.push(3);
//     q.push(5);
//     q.push(7);
//     while (!q.empty()) {
//         int x = q.front();
//         q.pop();
//         if (x <= n && isSuperPrime(x)) {
//             result.push_back(x);
//             for (int i = 1; i <= 9; i += 2) {
//                 int y = x * 10 + i;
//                 if (isPrime(y)) {
//                     q.push(y);
//                 }
//             }
//         }
//     }
//     return result;
// }