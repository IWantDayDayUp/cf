#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n;
    cin >> n;

    vector<vector<int>> a(2, vector<int>(n, 0));
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++) 
        {
            cin >> a[i][j];
        }
    }

    a[0][0] = -1;  //为了防止后面+1, 所以a[0][0] = - 1

    // 当前在(i, j), 一直往后走, 再向上(或下), 再转回来, 所需的最小时间
    vector<vector<int>> b(2, vector<int>(n + 1, 0));
    b[0][n] = b[1][n] = 0;
    
    for (int i = 0; i < 2; i++) {
        for (int j = n - 1; j >= 0; j--) {
            b[i][j] = max(
                {
                    // 需要解锁最后一个格子的最小时间
                    a[i ^ 1][j] + 1,
                    // 当前格子解锁条件, 再加上后面一路畅通无阻时所需要的必要步数
                    a[i][j] + 1 + 2 * (n - j) - 1,
                    // 在前一个目的地的基础上, 再向左运动一次, 即可到达这次的目的地
                    b[i][j + 1] + 1
                }
            );      
        }       
    }

    int ans = int(1e9) + int(1e8);
    int cur = 0;
    for (int j = 0; j < n; j++) {
        int k = j & 1;

        ans = min(ans, max(cur + 2 * (n - j) - 1, b[k][j]));

        // 走到[k][j], 解锁它
        cur = max(cur , a[k][j] + 1);

        // 向上(向下)走, 再解锁另一个
        cur++;
        cur = max(cur, a[k ^ 1][j] + 1);

        // 往下一列运动
        cur++;
    }

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