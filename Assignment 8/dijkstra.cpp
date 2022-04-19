#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include "library/Heap.hpp"
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

bool compare(pair<int, int> a, pair<int, int> b)
{
    return (a.second > b.second);
}

vector<int> shortestPath(vector<vector<pair<int, int>>> &graph, int vertex, int source)
{
    vector<int> path(vertex, INT_MAX);
    Heap<pair<int, int>, compare> heap(vertex);
    heap.insert({source, 0});
    path[source] = 0;
    while (heap.filled)
    {
        int u = heap.top().first;
        heap.deleteRoot();

        for (auto x : graph[u])
        {
            if (path[x.first] > path[u] + x.second)
            {
                path[x.first] = path[u] + x.second;
                heap.insert({x.first, path[x.first]});
            }
        }
    }
    return path;
}

auto solve = [](vector<vector<pair<int, int>>> &graph, int n)
{
    int source;
    cin >> source;
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    vector<int> path(shortestPath(graph, n, source));
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<ld> timeElapsed = chrono::duration_cast<chrono::duration<ld>>(end - start);
    cout << "Shortest Path from source = " << source << " : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << path[i] << endl;
    }
    cout << "Time elapsed : " << ld(timeElapsed.count() * 1e6) << endl;
};

int main()
{
    FastIO int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < k; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve(graph, n);
    }
    return 0;
}