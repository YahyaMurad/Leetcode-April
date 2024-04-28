class Solution:
    def findRotateSteps(self, ring, key):
        dp = [0] * len(ring)

        for k in reversed(range(len(key))):
            next_dp = [float("INF")] * len(ring)
            for r in range(len(ring)):
                for i, c in enumerate(ring):
                    if c == key[k]:
                        minDistance = min(abs(r - i), len(ring) - abs(r - i))
                        next_dp[r] = min(next_dp[r], minDistance + 1 + dp[i])
                
            dp = next_dp

        return dp[0]

sol = Solution()
print(sol.findRotateSteps("godding", "gd"))