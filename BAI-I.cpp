#include <iostream>
using namespace std;

void enterArr(int a[], int &n);
void exportSum(int a[], int n);
int main()
{
    int testCase[100], n;
    cin >> n;
    enterArr(testCase, n);
    exportSum(testCase, n);

    system("pause");
    return 0;
}
/*Dinh Nghia Ham*/
void enterArr(int a[], int &n)
{
    int i = 0;
    while (i < n)
    {
        cin >> a[i];
        i++;
    }
}

int sumOfDivisor(int num)
{
    int sum = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}
void exportSum(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << sumOfDivisor(a[i]) << " ";
    }
}
