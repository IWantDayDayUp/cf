#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    for (auto & c : s)
    {
        if (isupper(c))
        {
            c += 32;
        } else {
            c -= 32;
        }
    }

    cout << s << endl;

    return 0;
}