class Solution:
    def minFallingPathSum(self, grid):
        dp = [[float("inf") for _ in range(len(grid[0]))] for _ in range(len(grid))]

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i == 0:
                    dp[i][j] = grid[i][j]
                else:
                    for idx in range(len(grid[0])):
                        if idx != j:
                            dp[i][j] = min(dp[i][j], grid[i][j] + dp[i - 1][idx])

        return min(dp[-1])
