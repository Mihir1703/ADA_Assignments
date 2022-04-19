#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &a, int target)
{
    int l = 0, r = a.size() - 1, count = 0;
    while (l <= r)
    {
        count++;
        int mid = l + (r - l) / 2;
        count++;
        if (a[mid] == target)
        {
            return count;
        }
        count++;
        if (a[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return (count + 1);
};

auto ternarySearch(vector<int> &a, int target)
{
    int l = 0, r = a.size() - 1, count = 0;
    while (l <= r)
    {
        count++;
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        count++;
        if (a[mid1] == target)
        {
            return count;
        }
        count++;
        if (a[mid2] == target)
        {
            return count;
        }
        count++;
        if (target < a[mid1])
        {
            r = mid1 - 1;
            continue;
        }
        count++;
        if (target > a[mid2])
        {
            l = mid2 + 1;
        }
        else
        {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return (count + 1);
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int b = binarySearch(a, a[i]);
        int t = ternarySearch(a, a[i]);
        cout << "to search " << a[i] << " Comparison : Binary = " << b << " Ternary : " << t << endl;
    }
    return 0;
}