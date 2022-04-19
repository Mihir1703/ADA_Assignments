#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define FileIO                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define endl '\n'
typedef long long ll;
const ll mod = 1e9 + 7;

void swap(vector<ll> &arr, ll i, ll j)
{
    ll temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

ll partition(vector<ll> &arr, ll l, ll r, ll pivot)
{
    ll i = l + 1;
    ll j = r - 2;
    while (i < j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(arr, i, j);
    }
    swap(arr, i, r - 1);
    return i;
}

void small_sort(vector<ll> &arr, ll l, ll r)
{
    ll size = r - l + 1;
    if (size <= 1)
        return;
    if (size == 2)
    {
        if (arr[r] < arr[l])
            swap(arr, l, r);
        return;
    }
    else
    {
        if (arr[r - 1] < arr[l])
            swap(arr, r - 1, l);
        if (arr[r] < arr[l])
            swap(arr, r, l);
        if (arr[r - 1] > arr[r])
            swap(arr, r - 1, r);
    }
}

ll medianof3(vector<ll> &arr, ll l, ll r)
{
    ll mid = (l + r) / 2;
    if (arr[mid] < arr[l])
        swap(arr, mid, l);
    if (arr[r] < arr[l])
        swap(arr, r, l);
    if (arr[mid] > arr[r])
        swap(arr, mid, r);
    return mid;
}

void quickSort(vector<ll> &arr, ll l, ll r)
{
    ll sks = r - l + 1;
    if (sks <= 3)
    {
        small_sort(arr, l, r);
    }
    else
    {
        ll pivot = medianof3(arr, l, r);
        ll p_index = partition(arr, l, r, pivot);
        quickSort(arr, l, p_index - 1);
        quickSort(arr, p_index + 1, r);
    }
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &x : arr)
        cin >> x;
    quickSort(arr, 0, n - 1);
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}