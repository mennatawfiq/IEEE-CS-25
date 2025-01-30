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

ll dist(pair<int, int> i, pair<int, int> j)
{
    return (ll)abs(i.first - j.first) + (ll)abs(i.second - j.second);
}
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct point
{
    int x, y;
};

int n, m;

bool valid(point p)
{
    return p.x < n && p.x >= 0 && p.y < m && p.y >= 0;
}

ll dfs(vector<vector<int>> &v, vector<vector<bool>> &vis, int i, int j)
{
    if (v[i][j] == 0 || vis[i][j])
        return 0;
    vector<point> nbr(0);
    for (int k = 0; k < 4; k++)
    {
        point p = {i + dx[k], j + dy[k]};
        if (valid(p))
            nbr.push_back(p);
    }
    vis[i][j] = true;
    ll res = v[i][j];
    for (int k = 0; k < nbr.size(); k++)
    {
        if (!vis[nbr[k].x][nbr[k].y])
        {
            res += dfs(v, vis, nbr[k].x, nbr[k].y);
        }
    }
    return res;
}

int main()
{
    int t;
    ll maxi;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        maxi = 0;
        vector<vector<int>> v(n, vector<int>(m));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
                vis[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && v[i][j])
                    maxi = max(maxi, dfs(v, vis, i, j));
            }
        }
        cout << maxi << endl;
    }
    return 0;
}