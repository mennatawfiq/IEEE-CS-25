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
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    cin >> v;
    int j, l, r, mid;
    ll res = 0, m;
    for (int i = 0; i < n - 2; i++)
    {
        j = -1;
        l = i + 2;
        r = n - 1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (abs(v[mid] - v[i]) <= d)
            {
                j = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (j != -1)
        {
            m = j - i - 1;
            res += (m * (m + 1)) / 2;
        }
    }
    cout << res;
    return 0;
}