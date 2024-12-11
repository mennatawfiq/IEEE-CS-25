#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define endl "\n"

template <typename T>
istream &operator>>(istream &input, vector<T> &data)
{
    for (T &x : data)
        input >> x;
    return input;
}

template <typename T>
ostream &operator<<(ostream &output, const vector<T> &data)
{

    for (const T &x : data)
        output << x << " ";
    return output;
}

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
int n, m;

bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

vector<int> dx = {0, 1, -1}, dy = {1, -1, 0};

vector<pair<int, int>> gen(pair<int, int> v)
{
    vector<pair<int, int>> vp;
    if (valid(v.first, v.second + 1))
    {
        vp.push_back({v.first, v.second + 1});
    }
    if (valid(v.first, v.second - 1))
    {
        vp.push_back({v.first, v.second - 1});
    }
    if (valid(v.first + 1, v.second))
    {
        vp.push_back({v.first + 1, v.second});
    }
    if (valid(v.first - 1, v.second))
    {
        vp.push_back({v.first - 1, v.second});
    }
    return vp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int res = 0;
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> adj[i][j];
    }
    vector<vector<bool>> vis(n, vector<bool>(m));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj[i][j] == '.' && !vis[i][j])
            {
                res++;
                q.push({i, j});
                while (!q.empty())
                {
                    pair<int, int> v = q.front();
                    q.pop();
                    for (pair<int, int> u : gen(v))
                    {
                        if (adj[u.first][u.second] == '.' && !vis[u.first][u.second])
                        {
                            q.push({u.first, u.second});
                            vis[u.first][u.second] = true;
                        }
                    }
                }
            }
        }
    }
    cout << res;
    return 0;
}