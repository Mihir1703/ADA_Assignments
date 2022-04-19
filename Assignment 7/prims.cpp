#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include "Heap.hpp"
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

bool comp(pair<int, int> a, pair<int, int> b)
{
    return (a.first > b.first);
}

auto spanningTrees = [](vector<vector<int>> &graph, int vertex)
{
    vector<pair<int, int>> spanning_tree(vertex, {0, INT_MAX});
    Heap<pair<int, int>, comp> heap(graph.size());
    vector<int> included(vertex, false);
    heap.insert({0, 0});
    while (heap.filled)
    {
        int u = heap.heap[0].second;
        heap.deleteRoot();
        if (included[u])
        {
            continue;
        }
        included[u] = true;
        for (int i = 0; i < vertex; i++)
        {
            if (graph[u][i] == 0)
            {
                continue;
            }
            if (!included[i] and spanning_tree[i].second > graph[u][i])
            {
                spanning_tree[i].second = graph[u][i];
                heap.insert({graph[u][i], i});
                spanning_tree[i].first = u;
            }
        }
    }
    return spanning_tree;
};
auto solve = []()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < k; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    vector<pair<int, int>> spanning_tree = spanningTrees(graph, n);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<ld> alg = chrono::duration_cast<chrono::duration<ld>>(end - start);
    cout << "Time elapsed for above approach : " << (alg.count() * 1e6) << endl;
    for (int i = 1; i < n; i++)
    {
        cout << i << " " << spanning_tree[i].first << " " << spanning_tree[i].second << endl;
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