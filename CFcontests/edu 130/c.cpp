#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        cnt1 += s[i] == 'b';
        cnt2 += t[i] == 'b';
    }
    if (cnt1 != cnt2) 
    {
        cout << "NO" << endl;
        return ;
    }

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'b') continue;
        while (j < n && t[j] == 'b')
        {
            j += 1;
        }
        if (s[i] != t[j] || (s[i] == 'a' && i > j) || (s[i] == 'c' && i < j))
        {
            cout << "NO" << endl;
            return ;
        }
        j += 1;
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}