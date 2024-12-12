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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, a, b, start = -1;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pair<int, int>> res(0);
    vector<bool> vis(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            q.push(i);
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                for (int u : adj[v])
                {
                    if (!vis[u])
                    {
                        q.push(u);
                        vis[u] = true;
                    }
                }
            }
            if (start != -1)
            {
                res.push_back({start, i});
            }
            start = i;
        }
    }
    cout << res.size() << endl;
    for (pair<int, int> p : res)
        cout << p.first << " " << p.second << endl;
    return 0;
}