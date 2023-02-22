#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        s.insert(a);
    }

    for (int i = 0; i < k; i++)
    {
        if (!s.count(i))
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << k << endl;

    return 0;
}