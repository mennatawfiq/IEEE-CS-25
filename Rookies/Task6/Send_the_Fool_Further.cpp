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

ll res = 0;

void dfs(int i, ll s, vector<vector<pair<int, int>>> &g, vector<bool> &vis)
{
    if (vis[i])
    {
        return;
    }
    vis[i] = true;
    for (int j = 0; j < sz(g[i]); ++j)
    {
        dfs(g[i][j].first, s + g[i][j].second, g, vis);
        res = max(res, s);
    }
    vis[i] = false;
    return;
}

int main()
{
    int n, u, v, c;
    cin >> n;
    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>(0));
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v >> c;
        if (u > v)
            swap(u, v);
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    vector<bool> vis(n, false);
    dfs(0, 0, g, vis);
    cout << res;
    return 0;
}