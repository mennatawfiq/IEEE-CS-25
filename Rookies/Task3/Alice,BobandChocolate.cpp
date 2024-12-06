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
        cout << 1 << " " << 0 << endl;
        return 0;
    }
    int l1 = 0, l2 = n - 1, s1 = 0, s2 = 0;
    while (l1 <= l2)
    {
        if (s1 <= s2)
            s1 += v[l1++];
        else
            s2 += v[l2--];
    }
    cout << l1 << " " << n - l1;
    return 0;
}