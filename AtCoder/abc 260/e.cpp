#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<vector<int>> inv(M + 1);
    for (int i = 0; i < N; i++) {
        inv[A[i]].push_back(i);
        inv[B[i]].push_back(i);
    }

    vector<int> cnt(N), ans(M + 3);
    
    // 表示没有被区间 [i, j] 包围的区间 [a, b]的数量(a与b都不出现在区间[i, j]内)
    int cnt_zero = N;

    for (int i = 1, j = 1; i <= M;) {
        // 不断扩展右边界 `j`
        while (j <= M and cnt_zero != 0) {
            // 新的区间右边界 `j` 可以将下标集合inv[j]中的左右集合都覆盖
            for (auto & x : inv[j]) {
                // 如果是第一次覆盖, 没有被覆盖的区间数量减一
                if (cnt[x] == 0) cnt_zero--;

                // 表示区间x被覆盖
                cnt[x]++;
            }
            j++;
        }

        // 区间[i, j]不能把所有区间全部覆盖, 失败
        if (cnt_zero != 0) 
        {
            break;
        }

        // 差分数组
        ans[j - i]++;
        ans[M + 1 - i + 1]--;

        // 左边界 `i` 向右移一格
        for (auto & x : inv[i]) {
            // 把区间左边界 `i` 能覆盖的区间全部移除
            cnt[x]--;

            // 此时区间x不能被区间[i, j]覆盖
            if (cnt[x] == 0) cnt_zero++;
        }

        i++;
    }

    for (int i = 1; i <= M; i++) {
        ans[i] += ans[i - 1];
        cout << ans[i] << " \n"[i == M];
    }
}