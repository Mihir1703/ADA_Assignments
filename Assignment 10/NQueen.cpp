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
const ll INF = LONG_LONG_MAX / 2;
const ll NEG_INF = LONG_LONG_MIN / 2;

vector<vector<string>> ans;
bool valid(int r, int c, vector<string> &board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        if (board[r][i] == 'Q' or board[i][c] == 'Q')
        {
            return false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (r - i >= 0 and c - i >= 0)
        {
            if (board[r - i][c - i] == 'Q')
            {
                return false;
            }
        }
        if (r - i >= 0 and c + i < n)
        {
            if (board[r - i][c + i] == 'Q')
            {
                return false;
            }
        }
    }
    return true;
}
bool NQueens(vector<string> board, int r)
{
    int n = board.size();
    if (r >= n)
    {
        ans.push_back(board);
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (valid(r, i, board))
        {
            board[r][i] = 'Q';
            if (NQueens(board, r + 1))
            {
                return true;
            }
            board[r][i] = '.';
        }
    }
    return false;
}

auto solve = []()
{
    int n;
    cin >> n;
    vector<string> board;
    for (int i = 0; i < n; i++)
    {
        string s;
        for (int j = 0; j < n; j++)
        {
            s.push_back('.');
        }
        board.push_back(s);
    }
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    NQueens(board, 0);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<ld> time = chrono::duration_cast<chrono::duration<ld>>(end - start);
    for (int i = 0; i < n; i++)
    {
        cout << ans[0][i] << endl;
    }
    cout << endl;
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