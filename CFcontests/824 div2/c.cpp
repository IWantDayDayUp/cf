#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;

    string ans;

    int pre[26], nxt[26];
    memset(pre, -1, sizeof pre);
    memset(nxt, -1, sizeof nxt);

    auto check = [&](int a, int b){
        if (pre[b] != -1) return pre[b] == a;
        if (nxt[a] != -1) return nxt[a] == b;
        int t = a, cnt = 0;
        while(pre[t] != -1) t = pre[t], cnt++;
        if (t == b && cnt != 25) return false;
        pre[b] = a, nxt[a] = b;
        return true;
    };

    for(auto c : s){
        for(int j = 0; j < 26; j++){
            if (check(c - 'a', j)){
                ans += char('a' + j);
                break;
            }
        }
    }
    
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}