#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    string t = "";
    for (auto & c : s)
    {
        if (c != '.')
        {
            t += c;
        }
    }

    cout << (t == "|*|" ? "in" : "out") << endl;

    return 0;
}