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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, n, g, h, l, r, mid, mini, maxi;
    ll res;
    cin >> t;
    while (t--)
    {
        res = 0;
        cin >> n >> g >> h;
        vector<int> v(n);
        cin >> v;
        sort(all(v));
        for (int i = 0; i < n; i++)
        {
            l = i + 1;
            r = n - 1;
            mini = -1;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (v[mid] + v[i] >= g)
                {
                    mini = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            l = i + 1;
            r = n - 1;
            maxi = -1;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (v[mid] + v[i] <= h)
                {
                    maxi = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            if (maxi != -1 && mini != -1)
                res += (maxi - mini + 1);
        }
        cout << res << endl;
    }
    return 0;
}