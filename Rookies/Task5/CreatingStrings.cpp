#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define endl "\n"

int n;
string m;
set<string> st;
vector<pair<char, bool>> t;

void generate(string s)
{
    if (sz(s) == n)
    {
        st.insert(s);
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!t[i].second)
        {
            t[i].second = true;
            generate(s + t[i].first);
            t[i].second = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> m;
    n = sz(m);
    t.resize(n);
    for (int i = 0; i < n; i++)
    {
        t[i] = make_pair(m[i], false);
    }
    generate("");
    cout << st.size() << endl;
    for (string h : st)
        cout << h << endl;

    return 0;
}