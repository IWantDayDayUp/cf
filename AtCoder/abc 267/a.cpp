#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    if (s == "Monday")
    {
        cout << 5 << endl;
    } else if (s == "Tuesday")
    {
        cout << 4 << endl;
    } else if (s == "Wednesday")
    {
        cout << 3 << endl;
    } else if (s == "Thursday")
    {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }

    return 0;
}