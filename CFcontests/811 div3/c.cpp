#include <bits/stdc++.h>

using namespace std;

void slove() {
    int s;
    cin >> s;
    
    string ans;

    for (int j = 9; j >= 1; j--) 
    {
        if (s >= j){
            ans += (char) ('0' + j);
            s -= j;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}