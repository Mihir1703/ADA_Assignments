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
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> job(n); /* job -> first -> first == deadline, job -> first -> second == profit job -> second == job id*/
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        job[i].first = {a, b};
        job[i].second = i + 1;
    }
    vector<bool> occupied(1e5, false);
    vector<vector<int>> scheduled;
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    sort(job.begin(), job.end(), [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
         { return (a.first.second > b.first.second); });
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        int dead = job[i].first.first;
        while (occupied[dead] and dead > 0)
        {
            dead--;
        }
        if (dead > 0)
        {
            occupied[dead] = true;
            profit += job[i].first.second;
            scheduled.push_back({job[i].second, dead});
        }
    }
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<ld> timeElapsed = chrono::duration_cast<chrono::duration<ld>>(end - start);
    for (auto x : scheduled)
    {
        cout << "Job with ID " << x[0] << " is scheduled from " << x[1] - 1 << " to " << x[1] << endl;
    }
    cout << "Net Profit : " << profit << endl;
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