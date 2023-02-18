#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<bool> step(1e5 + 5, false);
    step[0] = true;

    int m;
    cin >> m;
    set<int> s;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;

        s.insert(t);
    }

    for (int i = 0; i < 1e5 + 5; i++)
    {

        if (!step[i])
        {
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (i + a[j] < 1e5 + 5 && !(s.count(i + a[j])))
            {
                step[i + a[j]] = true;
            }
        }
    }

    int x;
    cin >> x;
    cout << (step[x] ? "Yes" : "No") << endl;

    return 0;
}