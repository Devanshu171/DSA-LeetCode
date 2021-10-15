#include <iostream>
using namespace std;
int BS(int start, int end, int a[], int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
int ans(int a[], int target)
{
    int start = 0;
    int end = 1;
    while (a[end] < target)
    {
        int temp = end + 1;
        end = end + (end - start) * 2;
        start = temp;
    }
    return BS(start, end, a, target);
}
int main()
{
    int a[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int target = 140;
    cout << ans(a, target);
}