#include <iostream>
using namespace std;

int BinarySearchFirst(int list[], int num, int data)
{
    int low = 0;
    int high = num - 1;
    int result = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data == list[mid])
        {
            result = mid;
            high = mid - 1;
        }
        else if (data < list[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

int BinarySearchLast(int list[], int num, int data)
{
    int low = 0;
    int high = num - 1;
    int result = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data == list[mid])
        {
            result = mid;
            low = mid + 1;
        }
        else if (data < list[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

int main()
{
    int a[] = {1, 2, 3, 3, 3, 4, 5, 6, 7, 8, 9};
    int first = BinarySearchFirst(a, 11, 3);
    int last = BinarySearchLast(a, 11, 3);
    cout << first << "," << last << "," << last - first + 1 << endl;
    return 0;
}