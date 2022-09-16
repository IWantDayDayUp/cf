#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    if (s.size() == 0)
    {
        cout << "Yes" << endl;
    } else {
        if (s == t.substr(0, s.size()))
        {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}