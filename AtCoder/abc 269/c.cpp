#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long int n;
    cin >> n;


    int cnt = 0;
    vector<long long int> num;
    for (int i = 0; i < 61; i++)
    {
        if ((n >> i) & 1)
        {
            cnt += 1;
            long long int cur = 0;

            if (i > 18)
            {
                cur = 1;
                for (int j = 0; j < i; j++)
                {
                    cur *= 2;
                }
            } else {
                cur = 1 << i;
            }
            num.emplace_back(cur);
        }
    }

    set<long long int> ans;
    for (long long i = 0; i <= (1 << cnt); i++)
    {
        long long int cur = 0;
        for (int j = 0; j < cnt; j++)
        {
            if ((i >> j) & 1)
            {
                cur += num[j];
            }
        }

        ans.insert(cur);
    }

    for (auto num : ans)
    {
        cout << num << endl;
    }

    return 0;
}