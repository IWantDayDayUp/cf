#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    set<int> st;
    int mn = 1;

    for (int i = 0; i < q; i++)
    {
        int p, x;
        cin >> p;

        if (p == 1)
        {
            st.insert(mn++);
        } else if (p == 2){
            cin >> x;

            st.erase(x);
        } else {
            cout << *st.begin() << endl;
        }
    }

    return 0;
}