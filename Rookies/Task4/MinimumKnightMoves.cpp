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

bool isvalid(string s)
{
    return s[0] >= 'a' && s[0] <= 'h' && s[1] >= '1' && s[1] <= '8';
}

vector<int> dy = {1, -1, -2, 2}, dx = {2, -2, 1, -1};

vector<string> gen_list(string v)
{
    vector<string> gen;
    string s = "";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            s = "";
            s += char('a' + (v[0] - 'a' + dx[i]));
            s += char('0' + (v[1] - '0' + dy[j]));
            if (isvalid(s))
                gen.push_back(s);
        }
    }
    for (int i = 2; i < 4; i++)
    {
        for (int j = 2; j < 4; j++)
        {
            s = "";
            s += char('a' + (v[0] - 'a' + dx[i]));
            s += char('0' + (v[1] - '0' + dy[j]));
            if (isvalid(s))
                gen.push_back(s);
        }
    }
    return gen;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string start, dist, v;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> start >> dist;
        set<string> vis;
        queue<string> q;
        map<string, int> d;
        vis.insert(start);
        q.push(start);
        d[start] = -1;
        while (!q.empty())
        {
            v = q.front();
            q.pop();
            for (string u : gen_list(v))
            {
                if (vis.find(u) == vis.end())
                {
                    q.push(u);
                    vis.insert(u);
                    d[u] = d[v] + 1;
                }
                if (u == dist)
                    break;
            }
        }
        cout << d[dist] + 1 << endl;
    }
    return 0;
}