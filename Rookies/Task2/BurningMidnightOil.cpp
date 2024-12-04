#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define endl "\n"

int n, k;
bool can(int mid)
{
    int p = k, sum = mid;
    while (mid / p > 0)
    {
        sum += (mid / p);
        p *= k;
    }
    return sum >= n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    int l = 0, r = n, mid, res = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (can(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << res;
    return 0;
}