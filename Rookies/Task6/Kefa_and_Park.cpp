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

int m;
ll cnt = 0;

void dfs(int i, int cats, vector<vector<int>> &g, vector<bool> &cat, vector<bool> &vis)
{
    vis[i] = true;
    if (cats > m)
    {
        return;
    }
    bool leaf = true;
    for (int j = 0; j < sz(g[i]); ++j)
    {
        int l = g[i][j];
        if (!vis[l])
        {
            leaf = false;
            if (cat[l])
                dfs(l, cats + cat[l], g, cat, vis);
            else
                dfs(l, 0, g, cat, vis);
        }
    }
    if (leaf)
    {
        cnt++;
    }
    return;
}

int main()
{
    int n, u, v, t;
    cin >> n >> m;
    vector<bool> cat(n + 1), vis(n + 1);
    vector<vector<int>> g(n + 1, vector<int>(0));
    for (int i = 1; i < n + 1; i++)
    {
        cin >> t;
        cat[i] = t;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, cat[1], g, cat, vis);
    cout << cnt;
    return 0;
}