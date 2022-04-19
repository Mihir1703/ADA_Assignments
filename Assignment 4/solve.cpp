#include <bits/stdc++.h>
using namespace std;
vector<int> link(1e6);

int MergeLists(int i, int j, vector<int> &arr)
{
    int head;
    int *ptr = &head;
    while ((i != -1) && (j != -1))
    {
        if (arr[i] <= arr[j])
        {
            *ptr = i;
            ptr = &link[i];
            i = *ptr;
        }
        else
        {
            *ptr = j;
            ptr = &link[j];
            j = *ptr;
        }
    }
    if (i == -1)
        *ptr = j;
    else
        *ptr = i;
    return head;
}

int MergeSort(int low, int end, vector<int> &arr)
{
    int mid, i, j;
    if ((end - low) == 0)
    {
        return low;
    }
    if ((end - low) == 1)
    {
        link[low] = -1;
        return low;
    }
    if (end - low == 2)
    {
        if (arr[low] <= arr[end - 1])
        {
            link[low] = end - 1;
            link[end - 1] = -1;
            return low;
        }
        else
        {
            link[end - 1] = low;
            link[low] = -1;
            return end - 1;
        }
    }
    mid = (low + end) / 2;
    i = MergeSort(low, mid, arr);
    j = MergeSort(mid, end, arr);
    return MergeLists(i, j, arr);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = MergeSort(0, n, arr);
    do
    {
        cout << arr[ans] << " ";
        ans = link[ans];
    } while (ans != -1);
    cout << '\n';
    return 0;
}