#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> f = {0, 1, 1};
    while (f.back() <= 1e18)
    {
        int cnt = f.size();
        f.emplace_back(f[cnt - 2] + f[cnt - 1]);
    }
    // for (int i = 0; i < f.size(); i++)
    // {
    //     cout << f[i] << " \n"[i == f.size() - 1];
    // }

    for (int i = 0; i < n; i++)
    {
        long long cur;
        cin >> cur;

        for (int j = 2; j < f.size(); j++)
        {
            if (f[j - 1] <= cur && cur <= f[j])
            {
                if (abs(f[j - 1] - cur) <= abs(cur - f[j]))
                {
                    cout << j - 1 << endl;
                } else {
                    cout << j << endl;
                }

                break;
            }
        }
    }

    return 0;
}