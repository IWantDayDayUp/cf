#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    priority_queue<int> pa, pb;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pa.emplace(a);
    }
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        pb.emplace(b);
    }

    while (pa.size() > 0)
    {
        if (pa.top() == pb.top())
        {
            pa.pop();
            pb.pop();
        }

        while (pa.top() > pb.top())
        {
            int cur = pa.top();
            pa.pop();

            if (cur % 2 == 0)
            {
                pa.emplace(cur / 2);
            } else {
                cout << "NO" << endl;
                return ;
            }
        }

        while (pa.top() < pb.top())
        {
            int cur = pb.top();
            pb.pop();

            pb.emplace(cur / 2);
        }
    }

    cout << "YES" << endl;
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