#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define endl "\n"

vector<int> parent;
int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void un(int x, int y)
{
    int rx = find(x);
    int ry = find(y);
    if (rx != ry)
    {
        parent[rx] = ry;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        un(i, p[i]);
    }
    unordered_set<int> t;
    for (int i = 1; i <= n; i++)
    {
        t.insert(find(i));
    }
    cout << t.size() << endl;
    return 0;
}