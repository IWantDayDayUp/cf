#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (auto & dx : {-1, 0, 1})
            {
                for (auto & dy : {-1, 0, 1})
                {
                    if (dx || dy)
                    {
                        bool ok = true;
                        for (int k = 0; k < 5; k++)
                        {
                            int x = i + dx * k;
                            int y = j + dy * k;

                            if (!(x >= 0 && x < n && y >= 0 && y < m && a[x][y] == "snuke"[k]))
                            {
                                ok = false;
                            }
                        }

                        if (ok)
                        {
                            for (int k = 0; k < 5; k++)
                            {
                                cout << i + dx * k + 1 << ' ' << j + dy * k + 1<< endl;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}