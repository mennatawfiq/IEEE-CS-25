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
    char c;
    string s, t = "qwertyuiopasdfghjkl;zxcvbnm,./";
    map<char, char> right, left;
    for (int i = 1; i < sz(t); i++)
    {
        right.insert({t[i], t[i - 1]});
    }
    for (int i = 0; i < sz(t) - 1; i++)
    {
        left.insert({t[i], t[i + 1]});
    }
    cin >> c >> s;
    if (c == 'R')
    {
        for (char h : s)
        {
            cout << right[h];
        }
    }
    else
    {
        for (char h : s)
        {
            cout << left[h];
        }
    }
    return 0;
}