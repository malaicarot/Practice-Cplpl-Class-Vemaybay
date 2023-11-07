#include <iostream>
#include <algorithm>

using namespace std;
void exportFirstMaxAndSecondMax(int a[], int n);
void enterArr(int a[], int &n);

int main()
{
    int arr[100], n;
    enterArr(arr, n);
    exportFirstMaxAndSecondMax(arr, n);
    system("pause");
    return 0;
}

void enterArr(int a[], int &n)
{
    int i = 0;
    cin >> n;
    while (i < n)
    {
        cin >> a[i];
        i++;
    }
}

// Tim gia tri phan thu lon thu I va thu II
bool SortZtoA(int i, int j) { return i > j; }
void exportFirstMaxAndSecondMax(int a[], int n)
{
    sort(a, a + n, SortZtoA);
    if (a[0] == a[1])
    {
        cout << a[0] << endl;
    }
    else
    {
        cout << a[0] << " " << a[1] << endl;
    }
}