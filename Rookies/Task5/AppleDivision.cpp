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

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int n;
vector<int> v;
ll mini = INT_MAX;

void min_dif(ll s1, ll s2, int i)
{
    if (i == n)
    {
        mini = min(mini, abs(s1 - s2));
        // cout << s1 << " " << s2 << " " << mini << endl;
        return;
    }
    min_dif(s1 + v[i], s2, i + 1);
    min_dif(s1, s2 + v[i], i + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    v = vector<int>(n);
    cin >> v;
    min_dif(0, 0, 0);
    cout << mini;

    return 0;
}