#include <iostream>
using namespace std;

int CircularArraySearch(int list[], int data, int len)
{
    int low = 0;
    int high = len - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data == list[mid])
        {
            return mid;
        }

        if (list[mid] <= list[high])
        {
            if (data > list[mid] && data <= list[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
        {
            if (data < list[mid] && data >= list[low])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int a[] = {12, 14, 18, 21, 3, 6, 8, 9};
    cout << CircularArraySearch(a, 12, 8);
    return 0;
}