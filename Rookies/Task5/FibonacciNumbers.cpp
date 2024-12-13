#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define endl "\n"

int n;

ll fib(int i)
{
    if (i < 2)
        return i;
    return fib(i - 1) + fib(i - 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    cout << fib(n);

    return 0;
}