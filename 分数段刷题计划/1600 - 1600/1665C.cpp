#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int num;
        cin >> num;
        cnt[--num] += 1;
    }

    cnt.emplace_back(1); // 根节点也算一个 
    sort(cnt.begin(), cnt.end(), greater<int>());

    while (cnt.size() > 0 && cnt.back() <= 0)
    {
        cnt.pop_back();
    }

    int l = cnt.size(), r = n;
    while (l < r) {
        int x = (l + r) / 2;
        
        int c = 0;
        for (int i = 0; i < int(cnt.size()); i++) {
            c += max(0, cnt[i] - x + i);
        }
        if (int(cnt.size()) + c <= x) {
            r = x;
        } else {
            l = x + 1;
        }
    }

    cout << l << endl;
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