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

vector<pair<int, pair<int, char>>> directions = {
    {0, {1, 'R'}},
    {0, {-1, 'L'}},
    {1, {0, 'D'}},
    {-1, {0, 'U'}}};

int n, m;

bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char>(m));
    pair<int, int> start, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 'A')
                start = {i, j};
            if (adj[i][j] == 'B')
                end = {i, j};
        }
    }
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    map<pair<int, int>, pair<pair<int, int>, char>> parent;
    q.push(start);
    bool found = false;
    vis[start.first][start.second] = true;
    int nx, ny;
    char dir;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, d] : directions)
        {
            nx = x + dx;
            ny = y + d.first;
            dir = d.second;
            if (valid(nx, ny) && adj[nx][ny] != '#' && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                q.push({nx, ny});
                parent[{nx, ny}] = {{x, y}, dir};
                if (adj[nx][ny] == 'B')
                {
                    end = {nx, ny};
                    found = true;
                    break;
                }
            }
        }
        if (found)
            break;
    }

    if (!found)
    {
        cout << "NO" << endl;
    }
    else
    {
        string path;
        auto [cx, cy] = end;
        while (make_pair(cx, cy) != start)
        {
            auto [px, dir] = parent[{cx, cy}];
            path += dir;
            cx = px.first;
            cy = px.second;
        }
        reverse(path.begin(), path.end());
        cout << "YES" << endl << path.length() << endl << path << endl;
    }
    return 0;
}
