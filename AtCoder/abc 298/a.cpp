#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int o = 0, x = 0;
    for (auto & c : s)
    {
        if (c == 'o')
        {
            o += 1;
        } else if (c == 'x')
        {
            x += 1;
        }
    }

    cout << (o > 0 && x == 0 ? "Yes" : "No") << endl;

    return 0;
}