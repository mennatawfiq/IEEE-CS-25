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
    int n, m, h, dist = 0;
    cin >> n >> m;
    vector<int> a(n);
    set<int> st;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        cin >> h;
        st.insert(h);
    }
    vector<int> b(st.begin(), st.end());
    m = sz(b);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j + 1 < m && abs(a[i] - b[j]) > abs(a[i] - b[j + 1]))
            j++;
        dist = max(dist, abs(a[i] - b[j]));
    }
    cout << dist;
    return 0;
}