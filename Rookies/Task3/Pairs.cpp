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
    int t, n, k, l, r, mid;
    ll res = 0;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        l = i + 1;
        r = n - 1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (v[mid] == (v[i] + k))
            {
                res += mp[v[mid]];
                break;
            }
            else if (v[mid] > (v[i] + k))
            {
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
    }
    cout << res << endl;
    return 0;
}