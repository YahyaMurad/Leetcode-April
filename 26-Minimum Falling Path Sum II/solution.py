class Solution:
    def minFallingPathSum(self, grid):
        dp = grid[0]

        for i in range(1, len(grid)):
            smallest = dp.index(min(dp))
            secondSmallest = dp.index(min(dp[:smallest] + dp[smallest + 1:]))

            for j in range(len(grid)):
                grid[i][j] += dp[smallest] if j != smallest else dp[secondSmallest]

            dp = grid[i]

        return min(dp)