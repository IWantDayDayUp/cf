#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long x, k;
    cin >> x >> k;

    for (int i = 1; i <= k; i++)
    {
        long long base = pow(10, i);

        long long temp = x / base;
        long long diff = abs(x - base * temp);

        // cout << temp << ' ' << diff << endl;
        
        if (abs(x - base * (temp + 1)) <= diff)
        {
            x = base * (temp + 1);
        } else {
            x = base * temp;
        }

        // cout << x << endl;
    }

    cout << x << endl;

    return 0;
}