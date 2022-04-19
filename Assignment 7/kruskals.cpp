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

class DSU
{
    int *parent;
    int *size;

public:
    DSU(int n)
    {
        parent = new int[n];
        size = new int[n];
    }
    void create_set(int n)
    {
        parent[n] = n;
        size[n] = 1;
    }
    int find(int n)
    {
        if (parent[n] == n)
        {
            return n;
        }
        parent[n] = find(parent[n]);
        return parent[n];
    }
    void union_DSU(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u != v)
        {
            if (size[u] > size[v])
                swap(size[v], size[u]);
            parent[v] = u;
            size[v] += size[u];
        }
    }
};

auto solve = []()
{
    int n, k;
    cin >> n >> k;
    DSU d(n);
    vector<vector<int>> graph;
    for (int i = 0; i < n; i++)
    {
        d.create_set(i);
    }
    for (int i = 0; i < k; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({u, v, w});
    }
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    sort(graph.begin(), graph.end(), [](vector<int> &a, vector<int> &b)
         { return (a[2] < b[2]); });
    int cost = 0;
    vector<vector<int>> spanning_tree;
    for (auto x : graph)
    {
        int u = x[0], v = x[1];
        int w = x[2];
        int a = d.find(u);
        int b = d.find(v);
        if (a != b)
        {
            spanning_tree.push_back({u, v, w});
            cost = cost + w;
            d.union_DSU(u, v);
        }
    }
    cout << cost << endl;
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<ld> alg = chrono::duration_cast<chrono::duration<ld>>(end - start);
    cout << "Time elapsed for above approach : " << (alg.count() * 1e6) << endl;
    for (auto x : spanning_tree)
    {
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}