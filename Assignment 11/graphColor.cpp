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

bool graphColor(vector<vector<int>> &graph, int n, vector<int> &color, int k)
{
    if (n == color.size())
    {
        return true;
    }
    vector<bool> dp(k, false);
    for (auto x : graph[n])
    {
        if (color[x] != -1)
            dp[color[x]] = true;
    }
    for (int i = 0; i < k; i++)
    {
        if (!dp[i])
        {
            color[n] = i;
            if (graphColor(graph, n + 1, color, k))
            {
                return true;
            }
            color[n] = -1;
        }
    }
    return false;
}

auto solve = []()
{
    int n, k, c;
    cin >> n >> k >> c;
    vector<int> color(n, -1);
    vector<vector<int>> graph(n);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if (graphColor(graph, 0, color, c))
    {
        cout << "Colorings are as follows : " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << " " << color[i] << endl;
        }
    }
    else
    {
        cout << "No coloring possible" << endl;
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