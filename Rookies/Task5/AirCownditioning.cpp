#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define endl "\n"

int n, m, res = INT_MAX;
vector<int> temp(101);
vector<pair<pair<int, int>, int>> vp;
vector<int> price;
bool flag;

void cownditioning(int i, int sum)
{
    if (i == m)
    {
        flag = true;
        for (int j : temp)
        {
            if (j > 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            res = min(res, sum);
        return;
    }
    cownditioning(i + 1, sum);
    for (int j = vp[i].first.first; j <= vp[i].first.second; j++)
    {
        if (j < 101)
            temp[j] -= vp[i].second;
    }
    cownditioning(i + 1, sum + price[i]);
    for (int j = vp[i].first.first; j <= vp[i].first.second; j++)
    {
        if (j < 101)
            temp[j] += vp[i].second;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int a, b, t;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> t;
        for (int j = a; j <= b; j++)
            temp[j] += t;
    }
    int c;
    vp.resize(m);
    price.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> t >> c;
        vp[i] = make_pair(make_pair(a, b), t);
        price[i] = c;
    }
    cownditioning(0, 0);
    cout << res;
    return 0;
}