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
    int n;
    string s;
    cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    bool right = false, flag = false;
    int mini = INT_MAX, minindx = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
        {
            right = true;
            minindx = i;
        }
        else
        {
            if (right)
            {
                mini = min(mini, v[i] - ((v[minindx] + v[i]) / 2));
                right = false;
                flag = true;
            }
        }
    }
    if (flag)
        cout << mini;
    else
        cout << -1;
    return 0;
}