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
    int n, maxi = 0, mini = 101, indxmin, indxmax;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] > maxi)
        {
            maxi = v[i];
            indxmax = i;
        }
        if (v[i] <= mini)
        {
            mini = v[i];
            indxmin = i;
        }
    }
    int res = n - 1 - indxmin + indxmax;
    if (indxmax > indxmin)
        res--;
    cout << res << endl;
    return 0;
}
