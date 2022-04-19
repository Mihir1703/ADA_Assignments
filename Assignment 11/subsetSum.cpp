#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
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
const int mod = 1e9 + 7;
const ll INF = LONG_LONG_MAX / 2;
const ll NEG_INF = LONG_LONG_MIN / 2;

bool subsetSum(int i, vector<int> &arr, vector<int> &include, int sum)
{
    if (sum == 0)
    {
        return true;
    }
    if (i == arr.size())
    {
        return false;
    }
    else
    {
        bool not_taken = subsetSum(i + 1, arr, include, sum);
        if (not_taken)
        {
            return true;
        }
        if (arr[i] <= sum)
        {
            include[i] = 1;
            bool taken = subsetSum(i + 1, arr, include, sum - arr[i]);
            if (taken)
            {
                return true;
            }
            include[i] = 0;
        }
    }
    return false;
}

auto solve = []()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), ans(n, 0);
    for (auto &x : arr)
        cin >> x;
    bool possible = subsetSum(0, arr, ans, k);
    if (possible)
        for (int i = 0; i < n; i++)
        {
            if (ans[i])
            {
                cout << arr[i] << " ";
            }
        }
    else
        cout << "No Such Subset Exists" << endl;
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