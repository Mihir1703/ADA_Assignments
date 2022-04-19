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

int longestCommonSubsequence(string s1, string s2)
{
    int n = s1.length(), k = s2.length();
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));
    for (int i = 0; i < s1.length(); i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n][k];
}

auto solve = []()
{
    string s1, s2;
    cin >> s1 >> s2;
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    int cls = longestCommonSubsequence(s1, s2);
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
