#include <iostream>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;
vector<int> exportSuperPrime(int n);
int main()
{
    int n;
    cin >> n;
    vector<int> v = exportSuperPrime(n);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    system("pause");
    return 0;
}

// Ham check SNT
bool isPrime(int n)
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

// Ham check SSNT
bool isSuperPrime(int n)
{
    if (!isPrime(n))
    {
        return false;
    }

    while ((n / 10) > 0)
    {
        n /= 10;
        if (!isPrime(n))
        {
            return false;
        }
    }
    return true;
}

// Ham xuat cac so SSNT <= n
vector<int> exportSuperPrime(int n)
{
    queue<int> superPrimeQueue;
    vector<int> superPrimeArr;

    superPrimeQueue.push(2);
    superPrimeQueue.push(3);
    superPrimeQueue.push(5);
    superPrimeQueue.push(7);

    while (!superPrimeQueue.empty())
    {
        int x = superPrimeQueue.front();
        superPrimeQueue.pop();
        if(x > n){
            break;
        }
        superPrimeArr.push_back(x);
        for (int i = 1; i <= 9; i += 2)
        {
            int y = x * 10 + i;
            if(isSuperPrime(y)){
                superPrimeQueue.push(y);
            }
        }
    }
    return superPrimeArr;
}
