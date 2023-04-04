#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    set<string> st = {"and", "not", "that", "the", "you"};

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (st.count(s))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}