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
int cnt = 0;

int find_sum(vector<int> &arr, int l, int r)
{
    int ans = 0;
    for (int i = l; i <= r; i++)
        ans += arr[i];
    return ans;
}

int defectiveCoin(vector<int> &arr, int l, int r)
{
    int n = (r - l + 1);
    if (n == 1 and (++cnt))
    {
        return l;
    }
    if (n == 2 and (++cnt))
    {
        if (l != 0 and (++cnt))
        {
            if (arr[l - 1] == arr[l] and (++cnt))
            {
                return l + 1;
            }
            else
            {
                return l;
            }
        }
        else
        {
            if (arr[r + 1] == arr[l] and (++cnt))
            {
                return l + 1;
            }
            else
            {
                return l;
            }
        }
    }
    if (n == 3 and (++cnt))
    {
        if (arr[l] == arr[l + 1] and arr[l + 1] != arr[l + 2] and (++cnt))
        {
            return (l + 2);
        }
        else if (arr[l] != arr[l + 1] and arr[l + 1] == arr[l + 2] and (++cnt))
        {
            return l;
        }
        return (l + 1);
    }
    int rem = n % 3;
    vector<int> r_(3), l_(3);
    vector<double> p(3);
    l_[0] = l;
    r_[0] = l + (n / 3) - 1 + ((rem <= 0) ? 0 : 1);
    rem--;
    l_[1] = r_[0] + 1;
    r_[1] = l_[1] + (n / 3) - 1 + ((rem <= 0) ? 0 : 1);
    rem--;
    l_[2] = r_[1] + 1;
    r_[2] = r;
    for (int i = 0; i < 3; i++)
    {
        cnt++;
        p[i] = (double)find_sum(arr, l_[i], r_[i]) / (double)(r_[i] - l_[i] + 1);
    }
    if (p[0] == p[1] and p[1] != p[2] and (++cnt))
    {
        return defectiveCoin(arr, l_[2], r_[2]);
    }
    else if (p[0] != p[1] and p[1] == p[2] and (++cnt))
    {
        return defectiveCoin(arr, l_[0], r_[0]);
    }
    return defectiveCoin(arr, l_[1], r_[1]);
}

auto solve = []()
{
    cnt = 0;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    int idx = defectiveCoin(arr, 0, n - 1);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<ld> alg = chrono::duration_cast<chrono::duration<ld>>(end - start);
    cout << "The index of defective coin " << idx + 1 << " with weight of " << arr[idx] << " with comparison count = " << cnt << endl;
    cout << "Time elapsed for above approach : " << (alg.count() * 1e6) << endl;
};

int main()
{
    FileIO int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
