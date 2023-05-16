#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int cnt1 = 0, cnt2 = 0;
    string ans;
    for (auto & c : s)
    {
        cnt1 += c == 'A';
        cnt2 += c == 'T';

        if (cnt1 > cnt2)
        {
            ans = "A";
        } else if (cnt1 < cnt2)
        {
            ans = "T";
        }
    }

    cout << ans << endl;

    return 0;
}