#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    map<int, int> mp;
    int cnt2 = 0, cnt4 = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        cnt2 -= mp[num] / 2;
        cnt4 -= mp[num] / 4;
        mp[num] += 1;
        cnt2 += mp[num] / 2;
        cnt4 += mp[num] / 4;
    }
    
    int q;
    cin >> q;
    vector<string> ans(q, "NO");
    for (int i = 0; i < q; i++)
    {
        char label;
        int num;
        cin >> label >> num;

        cnt2 -= mp[num] / 2;
        cnt4 -= mp[num] / 4;
        if (label == '+')
        {
            mp[num] += 1;
        } else {
            mp[num] -= 1;
        }
        cnt2 += mp[num] / 2;
        cnt4 += mp[num] / 4;

        if (cnt4 >= 1 && cnt2 >= 4)
        {
            ans[i] = "YES";
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    slove();

    return 0;
}