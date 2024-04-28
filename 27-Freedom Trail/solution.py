class Solution:
    def findRotateSteps(self, ring, key):
        memo = {}
        def helper(r, k):
            if k == len(key):
                return 0
            
            if (r, k) in memo:
                return memo[(r, k)]
            
            res = float("INF")

            for i, c in enumerate(ring):
                if c == key[k]:
                    minDistance = min(abs(r - i), len(ring) - abs(r - i))
                    res = min(res, minDistance + 1 + helper(i, k + 1))
            
            memo[(r, k)] = res
            return res
        
        return helper(0, 0)

sol = Solution()
print(sol.findRotateSteps("godding", "gd"))