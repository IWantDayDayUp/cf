#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<string> ans(h);

    for (int i = 0; i < h; i++)
    {
        string s = "";
        for (int j = 0; j < w; j++)
        {
            int a;
            cin >> a;

            if (a == 0)
            {
                s += '.';
            } else {
                s += ('A' + a - 1);
            }
        }

        ans[i] = s;
    }

    for (int i = 0; i < h; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}