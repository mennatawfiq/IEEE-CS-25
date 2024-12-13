#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define endl "\n"

const int sz = 8;
int res = 0;
vector<vector<char>> grid(sz, vector<char>(sz));
vector<bool> left_di(15), right_di(15), row(sz);

void queen(int j)
{
    if (j == sz)
    {
        res++;
        return;
    }
    for (int i = 0; i < sz; i++)
    {
        if (grid[i][j] == '.' && !left_di[i - j + 7] && !right_di[i + j] && !row[i])
        {
            left_di[i - j + 7] = true;
            right_di[i + j] = true;
            row[i] = true;
            queen(j + 1);
            left_di[i - j + 7] = false;
            right_di[i + j] = false;
            row[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            cin >> grid[i][j];
        }
    }
    queen(0);
    cout << res;
    return 0;
}