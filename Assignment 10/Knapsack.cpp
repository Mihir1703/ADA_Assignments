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
const int mod = 1e9 + 7;
typedef long double ld;
const ll INF = LONG_LONG_MAX / 2;
const ll NEG_INF = LONG_LONG_MIN / 2;

int KnapSackUtil(int cost[], int value[], int n, int k)
{
    vector<int> dp(k + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= 0; j--)
        {
            if (cost[i - 1] <= j)
            {
                dp[j] = max(value[i - 1] + dp[j - cost[i - 1]], dp[j]);
            }
        }
    }
    return dp[k];
}
int knapSack(int W, int wt[], int val[], int n)
{
    return KnapSackUtil(wt, val, n, W);
}

auto solve = []()
{
    int n,W;
    cin>>n>>W;
    int value[n],wt[n];
    for(int i=0;i<n;i++){
        cin>>value[i]>>wt[i];
    }
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    int cls = knapSack(W,wt,value,n);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<ld> time = chrono::duration_cast<chrono::duration<ld>>(end - start);
    cout << cls << endl;
    cout << "Time : " << ld(time.count() * 1e6) << endl;
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