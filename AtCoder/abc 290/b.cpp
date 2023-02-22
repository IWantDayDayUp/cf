#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o' && k)
        {
            k -= 1;
        } else {
            s[i] = 'x';
        }
    }

    cout << s << endl;

    return 0;
}