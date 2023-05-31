#include <bits/stdc++.h>

using namespace std;

class LFUCache {
    public:
        map<int, int> freq;
        map<int, list<pair<int, int>>> lfu;
        map<int, list<pair<int, int>>::iterator> pos;

        int capacity;

    public:
        LFUCache(int capacity)
        {
            this -> capacity = capacity;
        }

        int get(int key)
        {
            int value;
            auto it = pos.find(key);
            if (it != pos.end())
            {
                value = it -> second -> second;
                int cnt = freq[key];
                freq[key] += 1;
                lfu[cnt].erase(it -> second);

                if (lfu[cnt].empty())
                {
                    lfu.erase(cnt);
                }

                auto newIter = lfu[cnt + 1].insert(lfu[cnt + 1].begin(), {key, value});
                pos[key] = newIter;
            } else {
                value = -1;
            }

            return value;
        }

        void put(int key, int value)
        {
            if (capacity == 0)
            {
                return ;
            }

            auto it = pos.find(key);
            if (freq.size() == capacity)
            {
                if ((it == pos.end()))
                {
                    auto it2 = lfu.begin() -> second.rbegin();
                    int delkey = it2 -> first;

                    cout << delkey << ' ';

                    int cnt = freq[delkey];
                    freq.erase(delkey);
                    pos.erase(delkey);
                    lfu[cnt].pop_back();
                    if (lfu[cnt].empty())
                    {
                        lfu.erase(cnt);
                    }
                    freq[key] = 1;
                } else {
                    lfu[freq[key]].erase(it -> second);
                    if (lfu[freq[key]].empty())
                    {
                        lfu.erase(freq[key]);
                    }
                    freq[key] += 1;
                }
            } else {
                if (it == pos.end())
                {
                    freq[key] = 1;
                } else {
                    lfu[freq[key]].erase(it -> second);
                    if (lfu[freq[key]].empty())
                    {
                        lfu.erase(freq[key]);
                    }
                    freq[key] += 1;
                }
            }

            auto newIter = lfu[freq[key]].insert(lfu[freq[key]].begin(), {key, value});
            pos[key] = newIter;
        }
};

void solve() {
    int n;
    cin >> n;

    LFUCache lfu = LFUCache(n + 1);

    int num;
    while (cin >> num)
    {
        lfu.put(num, num);
    }
    lfu.put(-1, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}