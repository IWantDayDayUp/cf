#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    int k;
    cin >> n >> k;

    vector<string> a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }

    while (true)
    {
        string s = to_string(n);

        bool ok = true;
        for (int i = 0; i < k; i++)
        {
            if (s.find(a[i]) != -1)
            {
                ok = false;
            }
        }

        if (ok)
        {
            cout << n << endl;
            break;
        }

        n += 1;
    }

    return 0;
}