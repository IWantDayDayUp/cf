#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        mp[num % 10] += 1;
    } 
    bool flag = false;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if ((i + j + k) % 10 == 3)
                {
                    if (i == j && i == k)
                    {
                        if (mp[i] >= 3)
                        {
                            flag = true;
                            break;
                        }
                    } else if (i == j)
                    {
                        if (mp[i] >= 2 && mp[k])
                        {
                            flag = true;
                            break;
                        }
                    } else if (i == k)
                    {
                        if (mp[i] >= 2 && mp[j])
                        {
                            flag = true;
                            break;
                        }
                    } else if (j == k)
                    {
                        if (mp[i] && mp[j] >= 2)
                        {
                            flag = true;
                            break;
                        }
                    } else {
                        if (mp[i] && mp[j] && mp[k])
                        {
                            flag = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << (flag ? "YES" : "NO") << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }

    return 0;
}