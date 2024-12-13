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

void simulate(ll i)
{
    cout << i << " ";
    if (i == 1)
    {
        return;
    }
    if (i % 2 != 0)
    {
        simulate(i * 3 + 1);
    }
    else
    {
        simulate(i / 2);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    simulate(n);

    return 0;
}