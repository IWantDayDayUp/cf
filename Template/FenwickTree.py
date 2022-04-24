class BIT:
    def __init__(self, n):
        self.n = n
        self.nums = [0] * (n + 1)

    def lowbit(self, x):
        return x & -x

    def update(self, x, k):
        while x <= self.n:
            self.nums[x] += k
            x += self.lowbit(x)

    def query(self, x):
        ans = 0
        while x > 0:
            ans += self.nums[x]
            x -= self.lowbit(x)
        return ans


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        # init BIT
        n = len(nums)
        tree = BIT(n + 1)

        # 单点更新
        tree.update(4, 1)

        # 区间更新
        tree.update(2, 1)
        tree.update(5, -1)

        # 单点查询
        tree.query(4)

        # 区间查询
        tree.query(5)
        tree.query(2)
