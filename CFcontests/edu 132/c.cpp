#include <bits/stdc++.h>

using namespace std;

void slove() {
    string s;
    cin >> s;

    int cnt = 0, ques = 0;
    for (auto & c : s)
    {
        if (c == '(')
        {
            cnt += 1;
        } else if (c == ')')
        {
            cnt -= 1;
        } else {
            ques += 1;
        }

        if (cnt + ques == 1)
        {
            cnt = 1;
            ques = 0;
        }
    }

    if (abs(cnt) == ques)
    {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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