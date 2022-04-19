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

auto gen_random = []() -> ll
{
    random_device dev;
    mt19937 range(dev());
    uniform_int_distribution<mt19937::result_type> gen(0, 10);
    return gen(range);
};

auto fill_arr = [](ll len, bool fill) -> vector<vector<ll>>
{
    vector<vector<ll>> a(len, vector<ll>(len));
    for (auto &x : a)
    {
        for (auto &y : x)
        {
            y = ((fill) ? 0 : gen_random());
        }
    }
    return a;
};

void add_or_sub(vector<vector<ll>> &first, vector<vector<ll>> &second, int n, vector<vector<ll>> &ans, bool sub)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = first[i][j] + ((ll)((sub) ? -1 : 1) * second[i][j]);
        }
    }
}

void get_multiplication(vector<vector<ll>> &a, vector<vector<ll>> &b, ll n, vector<vector<ll>> &c)
{
    if (n == 2)
    {
        c[0][0] = (a[0][0] * b[0][0]) + (a[0][1] * b[1][0]);
        c[0][1] = (a[0][0] * b[0][1]) + (a[0][1] * b[1][1]);
        c[1][0] = (a[1][0] * b[0][0]) + (a[1][1] * b[1][0]);
        c[1][1] = (a[1][0] * b[0][1]) + (a[1][1] * b[1][1]);
    }
    else
    {
        vector<vector<vector<vector<ll>>>> copy_a(2, vector<vector<vector<ll>>>(2, vector<vector<ll>>(n / 2, vector<ll>(n / 2))));
        vector<vector<vector<vector<ll>>>> copy_b(2, vector<vector<vector<ll>>>(2, vector<vector<ll>>(n / 2, vector<ll>(n / 2))));
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        copy_a[k][l][i][j] = a[i + (k * (n / 2))][j + (l * (n / 2))];
                        copy_b[k][l][i][j] = b[i + (k * (n / 2))][j + (l * (n / 2))];
                    }
                }
            }
        }
        vector<vector<vector<ll>>> p(7, vector<vector<ll>>(n / 2, vector<ll>(n / 2)));
        vector<vector<vector<ll>>> temp(2, vector<vector<ll>>(n / 2, vector<ll>(n / 2)));
        add_or_sub(copy_b[0][1], copy_b[1][1], n / 2, temp[0], true);
        get_multiplication(copy_a[0][0], temp[0], n / 2, p[0]);

        add_or_sub(copy_a[0][0], copy_a[0][1], n / 2, temp[0], false);
        get_multiplication(temp[0], copy_b[1][1], n / 2, p[1]);

        add_or_sub(copy_a[1][0], copy_a[1][1], n / 2, temp[0], false);
        get_multiplication(temp[0], copy_b[0][0], n / 2, p[2]);

        add_or_sub(copy_b[1][0], copy_b[0][0], n / 2, temp[0], true);
        get_multiplication(copy_a[1][1], temp[0], n / 2, p[3]);

        add_or_sub(copy_a[0][0], copy_a[1][1], n / 2, temp[0], false);
        add_or_sub(copy_b[0][0], copy_b[1][1], n / 2, temp[1], false);
        get_multiplication(temp[0], temp[1], n / 2, p[4]);

        add_or_sub(copy_a[0][1], copy_a[1][1], n / 2, temp[0], true);
        add_or_sub(copy_b[1][0], copy_b[1][1], n / 2, temp[1], false);
        get_multiplication(temp[0], temp[1], n / 2, p[5]);

        add_or_sub(copy_a[0][0], copy_a[1][0], n / 2, temp[0], true);
        add_or_sub(copy_b[0][0], copy_b[0][1], n / 2, temp[1], false);
        get_multiplication(temp[0], temp[1], n / 2, p[6]);

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                c[i][j] = p[4][i][j] + p[3][i][j] - p[1][i][j] + p[5][i][j];
                c[i + (n / 2)][j] = p[2][i][j] + p[3][i][j];
                c[i][j + (n / 2)] = p[0][i][j] + p[1][i][j];
                c[i + (n / 2)][j + (n / 2)] = p[0][i][j] + p[4][i][j] - p[2][i][j] - p[6][i][j];
            }
        }
    }
}

auto solve = []() -> void
{
    ll n;
    cin >> n;
    vector<vector<ll>> a, b, c, d;
    a = fill_arr(n, 0), b = fill_arr(n, 0), c = fill_arr(n, 1), d = fill_arr(n, 1);
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                d[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<ld> naive = chrono::duration_cast<chrono::duration<ld>>(end - start);
    start = chrono::high_resolution_clock::now();
    get_multiplication(a, b, n, c);
    end = chrono::high_resolution_clock::now();
    chrono::duration<ld> strassens = chrono::duration_cast<chrono::duration<ld>>(end - start);
    cout << "Matrix A : " << endl;
    for (auto &x : a)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << "Matrix B : " << endl;
    for (auto &x : b)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << "Matrix A x B by Strassen's Method: " << endl;
    for (auto &x : c)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Matrix A x B by Naive Method: " << endl;
    for (auto &x : d)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Time elapsed for naive approach : " << (naive.count() * 1e6) << endl;
    cout << "Time elapsed for strassen's approach : " << (strassens.count() * 1e6) << endl;
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