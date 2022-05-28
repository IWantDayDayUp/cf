# class Solution:
#     def maximumWhiteTiles(self, tiles: List[List[int]], carpetLen: int) -> int:
#         tiles.sort()
#         n = len(tiles)
        
#         ans = 0
#         for i in range(n):
#             for l in range(tiles[i][0], tiles[i][1] + 1):
#                 cnt = tiles[i][1] - l + 1
#                 # print(i, cnt)
#                 j = i
#                 while j + 1 < n and l + carpetLen - 1 >= tiles[j + 1][0]:
#                     j += 1
#                     cnt += min(l + carpetLen - 1, tiles[j][1]) - tiles[j][0] + 1
#                     # print(i, cnt)
                
#                 ans = max(ans, cnt)
#         return ans
            
# 
# 


# print(16 & 17 & 71 & 62 & 24)
import matplotlib.pyplot as plt
fig = plt.figure(num = 1, figsize = (4, 4))
nums = [[72,98],[62,27],[32,7],[71,4],[25,19],[91,30],[52,73],[10,9],[99,71],[47,22],[19,30],[80,63],[18,15],[48,17],[77,16],[46,27],[66,87],[55,84],[65,38],[30,9],[50,42],[100,60],[75,73],[98,53],[22,80],[41,61],[37,47],[95,8],[51,81],[78,79],[57,95]]
nums.sort()
x = [0] * len(nums)
y = [0] * len(nums)
for i in range(len(nums)):
    x[i] = nums[i][0]
    y[i] = nums[i][1]
plt.plot(x, y)
plt.show()