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
const ll INF = LONG_LONG_MAX / 2;
const ll NEG_INF = LONG_LONG_MIN / 2;
const ll mod = 1e9 + 7;

vector<vector<ll>> floydWarshall(vector<vector<pair<ll, ll>>> graph)
{
    ll n = graph.size();
    vector<vector<ll>> ans(n, vector<ll>(n, INF));
    for (ll i = 1; i < n; i++)
    {
        ans[i][i] = 0;
    }
    for (ll i = 1; i < n; i++)
    {
        for (auto x : graph[i])
        {
            ans[i][x.first] = x.second;
        }
    }
    for (ll k = 1; k < n; k++)
    {
        for (ll i = 1; i < n; i++)
        {
            for (ll j = 1; j < n; j++)
            {
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return ans;
}

auto solve = []()
{
    ll n, k;
    cin >> n >> k;
    vector<vector<pair<ll, ll>>> graph(n + 1);
    for (ll i = 0; i < k; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    vector<vector<ll>> path(floydWarshall(graph));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (i == j or path[i][j] >= INF)
                continue;
            cout << "Shortest Path from edge " << i << " to " << j << " is " << path[i][j] << "." << endl;
        }
        cout << endl;
    }
};

int main()
{
    FileIO
    ll tc = 1;
    while (tc--)
    {
        solve();
    }
    return 0;
}

/*
Sample TC

4 7
1 2 3
2 1 8
1 4 7
4 1 2
3 1 5
2 3 2
3 4 1

*/