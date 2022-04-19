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

int get_sum(vector<int> &a, int l, int r)
{
    int sum = 0;
    for (int i = l; i <= r; i++)
        sum += a[i];

    return sum;
}

int find_defective_coin(vector<int> &a, int l, int r)
{

    if (r == l + 1 and (++cnt))
    {
        if (a[l] > a[r] and (++cnt))
        {
            cnt++;
            return l;
        }
        else
            return r;
    }

    int mid = l + (r - l) / 2;

    int x = get_sum(a, l, mid);
    int y = get_sum(a, mid + 1, r);

    int len_X = mid - l + 1, len_Y = r - mid;

    if (len_X == len_Y and (++cnt))
    {
        if (x > y and (++cnt))
        {
            cnt++;
            return find_defective_coin(a, l, mid);
        }
        else
            return find_defective_coin(a, mid + 1, r);
    }
    else
    {
        if (x == y and (++cnt))
        {
            cnt++;
            return find_defective_coin(a, mid + 1, r);
        }
        else
            return find_defective_coin(a, l, mid);
    }
}

auto solve = []()
{
    cnt = 0;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    int idx;
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    idx = find_defective_coin(arr, 0, n - 1);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<ld> alg = chrono::duration_cast<chrono::duration<ld>>(end - start);
    cout << "The index of defective coin " << idx + 1 << " with weight of " << arr[idx] << " with comparison count of " << cnt << endl;
    cout << "Time elapsed for above approach : " << (alg.count() * 1e6) << endl;
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