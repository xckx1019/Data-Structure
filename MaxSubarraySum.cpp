#include <iostream>
#include <cmath>
using namespace std;

int MaxSubarraySum(int list[], int n)
{
    int sum = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        if (sum + list[i] > 0)
        {
            sum += list[i];
        }
        else
        {
            sum = 0;
        }
        ans = max(ans, sum);
    }
    return ans;
}

int main()
{
    int a[] = {1, -3, 2, -5, 7, 6, -1, -4, 11, -23};
    int b = MaxSubarraySum(a, 10);
    cout << b << endl;
    return 0;
}