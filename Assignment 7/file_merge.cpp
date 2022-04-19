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

bool comp(int a, int b)
{
    return (a > b);
}

int optimalMerge2(vector<int> &arr, int n)
{
    Heap<int, comp> heap(n);
    for (auto x : arr)
    {
        heap.insert(x);
    }
    int ans = 0;
    while (heap.filled > 1)
    {
        int f = heap.top();
        heap.deleteRoot();
        int s = heap.top();
        heap.deleteRoot();
        ans += (f + s);
        cout << f << " " << s << " " << ans << endl;
        heap.insert(f + s);
    }
    return ans;
}

int optimalMerge3(vector<int> &arr, int n)
{
    Heap<int, comp> heap(n);
    for (auto x : arr)
    {
        heap.insert(x);
    }
    int ans = 0;
    while (heap.filled > 2)
    {
        int f = heap.top();
        heap.deleteRoot();
        int s = heap.top();
        heap.deleteRoot();
        int t = heap.top();
        heap.deleteRoot();
        ans += (f + s + t);
        heap.insert(f + s + t);
    }
    if (heap.filled == 2)
    {
        ans += (heap.heap[0] + heap.heap[1]);
    }
    return ans;
}

auto solve = []()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    int k2 = optimalMerge2(arr, n);
    int k3 = optimalMerge3(arr, n);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<ld> alg = chrono::duration_cast<chrono::duration<ld>>(end - start);
    cout << "Time elapsed for above approach : " << (alg.count() * 1e6) << endl;
    cout << "Binary merge pattern : " << k2 << " Ternary merge pattern : " << k3 << endl;
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