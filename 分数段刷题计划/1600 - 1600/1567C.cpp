#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    string s, s1, s2;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
        {
            s1 += s[i];
        } else {
            s2 += s[i];
        }
    }

    if (s2 == "")
    {
        cout << stoi(s1) - 1 << endl;
    } else {
        cout << (stoi(s1) + 1) * (stoi(s2) + 1) - 2 << endl;
    }
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