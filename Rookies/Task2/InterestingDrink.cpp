#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define endl "\n"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q, m, l, r, mid, res;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    cin >> q;
    while (q--)
    {
        cin >> m;
        if (m < v[0])
        {
            cout << 0 << endl;
            continue;
        }
        l = 0, r = n - 1, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (v[mid] <= m)
            {
                res = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cout << res + 1 << endl;
    }
    return 0;
}