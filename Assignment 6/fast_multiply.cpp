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

auto numberLength(ll value) -> ll
{
    ll counter = 0;
    while (value != 0)
    {
        counter++;
        value /= 10;
    }
    return counter;
}

auto large_multiply(ll a, ll b) -> ll
{
    ll x = numberLength(a);
    ll y = numberLength(b);
    ll n = max(x, y);
    n = n / 2 + (n & 1);
    if (max(x, y) < 3)
    {
        return (a * b);
    }
    ll factor = pow(10, n);
    ll a1 = a / factor, a0 = a % factor;
    ll b1 = b / factor, b0 = b % factor;
    ll c2 = large_multiply(a1, b1);
    ll c0 = large_multiply(a0, b0);
    ll c1 = large_multiply(a1 + a0, b1 + b0) - c0 - c2;
    cout<<c1<<" "<<c2<<" "<<c0<<endl;
    return ((c2 * factor * factor) + (c1 * factor) + c0);
};

auto solve = []()
{
    ll a, b;
    cin >> a >> b;
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    ll algo = large_multiply(a, b);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<ld> alg = chrono::duration_cast<chrono::duration<ld>>(end - start);
    cout << algo << " " << a * b << endl;
    cout << "Time elapsed for fast approach : " << (alg.count() * 1e6) << endl;
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


/*
    4 4 4 6 4
*/