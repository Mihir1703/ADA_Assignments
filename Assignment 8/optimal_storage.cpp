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

auto solve = []()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    vector<int> tape[k];
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        tape[i % k].push_back(arr[i]);
    }
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<ld> timeElapsed = chrono::duration_cast<chrono::duration<ld>>(end - start);
    for (int i = 0; i < k; i++)
    {
        cout<<"Tape "<<i+1<<endl;
        int sum = 0, ans = 0;
        for (auto x : tape[i])
        {
            cout << x << " ";
            sum += x;
            ans += sum;
        }
        cout << endl;
        cout << "Average access time : " << (ld)ans / (ld)tape[i].size() << endl;
    }
    cout << "Time elapsed : " << ld(timeElapsed.count() * 1e6) << endl;
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