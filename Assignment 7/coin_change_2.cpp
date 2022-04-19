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
typedef long double ld;
const int mod = 1e9 + 7;

void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(vector<int> &arr, int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}

void quickSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);

        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

auto solve = []()
{
    int n, change;
    cin >> n >> change;
    vector<int> coins(n);
    vector<pair<int, int>> ans;
    for (auto &x : coins)
        cin >> x;
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    quickSort(coins, 0, n - 1);
    for (int i = n - 1; i >= 0; i--)
    {
        int coin = change / coins[i];
        change = change - coin * coins[i];
        if (coin != 0)
            ans.push_back({coins[i], coin});
        if (change <= 0)
            break;
    }
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<ld> alg = chrono::duration_cast<chrono::duration<ld>>(end - start);
    cout << "Time elapsed for above approach : " << (alg.count() * 1e6) << endl;
    for (auto x : ans)
    {
        cout << "Required " << x.second << " coins of value " << x.first << "." << endl;
    }
};

int main()
{
    FastIO int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}