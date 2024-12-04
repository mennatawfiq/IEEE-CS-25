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
    int n, t, maxi = INT_MIN, l1 = 0, l2 = 1;
    cin >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (n == 1)
    {
        cout << (t >= v[0] ? 1 : 0);
        return 0;
    }
    int sum = v[0];
    while (l2 < n)
    {
        if (sum + v[l2] <= t)
        {
            sum += v[l2++];
            maxi = max(maxi, l2 - l1);
        }
        else
        {
            sum -= v[l1++];
        }
    }
    if (maxi < 0)
        cout << 0;
    else
        cout << maxi;
    return 0;
}