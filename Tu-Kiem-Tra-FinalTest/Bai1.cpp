#include <iostream>

using namespace std;

void enterArr(int a[], int n);
void sumOfSubmultiple(int a[], int n);

int main()
{
    int arr[100], n;
    cin >> n;
    enterArr(arr, n);
    sumOfSubmultiple(arr, n);

    system("pause");
    return 0;
}
/*Dinh Nghia*/
void enterArr(int a[], int n)
{
    int i = 0;
    while (i < n)
    {
        cin >> a[i];
        i++;
    }
}
int submultiple(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}
void sumOfSubmultiple(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << submultiple(a[i]) << endl;
    }
}