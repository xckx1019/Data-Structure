#include <iostream>
using namespace std;

int FindRotatedCount(int list[], int len)
{
    int low = 0;
    int high = len - 1;
    while (low <= high)
    {

        if (list[low] < list[high])
        {
            return low;
        }
        int mid = (low + high) / 2;
        int prev = (mid + len - 1) % len;
        int next = (mid + 1) % len;

        if (list[prev] >= list[mid] && list[next] >= list[mid])
        {
            return mid;
        }
        //right sorted
        else if (list[mid] <= list[high])
        {
            high = mid - 1;
            return high;
        }
        //left sorted
        else if (list[mid] >= list[low])
        {
            low = mid + 1;
            return low;
        }
    }
    return -1;
}

int main()
{
    int a[] = {14, 15, 16, 2, 4, 6, 8, 10, 11};
    cout << FindRotatedCount(a, 9) << endl;
    return 0;
}