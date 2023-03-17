#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n, -1);
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        p--;

        if (a[i] == -1)
        {
            a[p] = 1;
            st.insert(p);
        }
    }

    cout << n - st.size() << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
        {
            cout << i + 1 << ' ';
        }
    }
    cout << endl;

    return 0;
}