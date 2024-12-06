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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    sort(all(v));
    int l1 = 0, l2 = 1, maxi = 0;
    while (l2 < n)
    {
        while (v[l2] - v[l1] > 5)
            l1++;
        maxi = max(maxi, l2 - l1 + 1);
        l2++;
    }
    cout << maxi << endl;
    return 0;
}