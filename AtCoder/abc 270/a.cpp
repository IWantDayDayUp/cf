#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    set<int> st;
    auto check = [&](int x)
    {
        if (x >= 4)
        {
            st.insert(4);
            x -= 4;
        }
        if (x >= 2)
        {
            st.insert(2);
            x -= 2;
        }
        if (x >= 1)
        {
            st.insert(1);
            x -= 1;
        }
    };

    int ans = 0;
    check(a);
    check(b);

    for (auto num : st)
    {
        ans += num;
    }
    
    cout << ans << endl;

    return 0;
}