#include <iostream>
#include <algorithm>
using namespace std;

void findMaxAndSecondMax(int a[], int n);
void enterArr(int a[], int n);

int main()
{
    int arr[100], n;
    cin >> n;
    enterArr(arr, n);
    findMaxAndSecondMax(arr, n);
    system("pause");
    return 0;
}

void enterArr(int a[], int n)
{
    int i = 0;
    while (i < n)
    {
        cin >> a[i];
        i++;
    }
}

bool sortZtoA(int i, int j) { return i > j; }
void findMaxAndSecondMax(int a[], int n)
{
    sort(a, a + n, sortZtoA);
    if (a[0] == a[1])
    {
        cout << a[0] << endl;
    }
    else
    {
        cout << a[0] << endl;
        cout << a[1] << endl;
    }
}