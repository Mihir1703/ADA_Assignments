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
const ll INF = LONG_LONG_MAX / 2;
const ll NEG_INF = LONG_LONG_MIN / 2;

ll multiStageGraph(vector<vector<ll>> &graph)
{
    ll n = graph.size();
    vector<ll> cost(n, INF);
    cost[n - 1] = 0;
    for (int i = n - 2; i > 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (graph[i][j] != INF)
            {
                cost[i] = min(cost[i], graph[i][j] + cost[j]);
            }
        }
    }
    return cost[1];
}

auto solve = []()
{
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> graph(n + 1, vector<ll>(n + 1, INF));
    for (ll i = 0; i < k; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    cout << multiStageGraph(graph);
};

int main()
{
    int tc = 1;
    while (tc--)
    {
        solve();
    }
    return 0;
}

/*
Sample Test Case

7 11
1 2 3
1 5 7
5 7 5
6 7 2
3 6 6
1 3 8
2 4 5
4 5 5
4 6 12
4 3 4
1 4 2

*/