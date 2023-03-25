#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long L, n1, n2;
    cin >> L >> n1 >> n2;

    vector<long long> v1(n1), l1(n1), v2(n2), l2(n2);
    for (int i = 0; i < n1; i++)
    {
        cin >> v1[i] >> l1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> v2[i] >> l2[i];
    }

    int i = 0, j = 0;
    long long ans = 0;

    while (i < n1)
    {
        auto l = min(l1[i], l2[j]);
        ans += l * (v1[i] == v2[j]);

        l1[i] -= l;
        l2[j] -= l;

        if (!l1[i])
        {
            i++;
        }
        if (!l2[j])
        {
            j++;
        }
    }

    cout << ans << endl;

    return 0;
}