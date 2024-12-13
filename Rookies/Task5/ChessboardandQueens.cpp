// core concept:
// we could have looped on the grid cell by cell and check if the cell is valid to put a queen, but this will give a TLE so we needed an optimization.
// the optimization is to use columns to loop, and then loop for a valid cell in each column. then we'll need to mark the left diagonal, right diagonal and row as attacked
// so that it won't be valid to have a queen in it again.
// the '15' is because we'll have a 15 diagonal from the top right to the left bottom for both right and left. use any three valid positions to proof the 'i+j' and 'i-j+7'.
// ai + bj + c = <diagonal number>

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
