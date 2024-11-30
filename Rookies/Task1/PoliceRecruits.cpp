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
    int n, m, p = 0, c = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        if (m > 0)
        {
            p += m;
        }
        else
        {
            if (p > 0)
                p += m;
            else
                c -= m;
        }
    }
    cout << c << endl;
    return 0;
}