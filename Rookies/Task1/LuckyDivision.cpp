#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define endl "\n"

bool islucky(int m)
{
    while (m)
    {
        if (m % 10 != 4 && m % 10 != 7)
        {
            return false;
        }
        m /= 10;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    if (n % 4 == 0 || n % 7 == 0 || islucky(n))
        cout << "YES";
    else
    {
        for (int i = 2; i < 1000; i += 2)
        {
            if (n % i == 0)
            {
                if (islucky(n / i))
                {
                    cout << "YES";
                    goto out;
                }
            }
        }
        cout << "NO";
    out:
        cout << endl;
    }
    return 0;
}