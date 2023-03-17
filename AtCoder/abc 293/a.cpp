#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < s.size() - 1; i += 2)
    {
        swap(s[i], s[i + 1]);
    }

    cout << s << endl;

    return 0;
}