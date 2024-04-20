from collections import deque

class Solution:
    def findFarmland(self, land):
        rows, cols = len(land), len(land[0])
        res = []
        vis = set()

        def bfs(r, c, curr):
            queue = deque()
            vis.add((r, c))
            queue.append((r, c))

            while queue:
                row, col = queue.popleft()
                directions = [(1, 0), (0, 1)]
                cnt = 0

                for x, y in directions:
                    new_r, new_c = row + x, col + y
                    if new_r in range(rows) and new_c in range(cols) and land[new_r][new_c] == 1 and (new_r, new_c) not in vis:
                        queue.append((new_r, new_c))
                        vis.add((new_r, new_c))

                    if (new_r not in range(rows) or new_c not in range(cols)) or land[new_r][new_c] == 0:
                        cnt += 1
                        if cnt == 2:
                            curr.append(row)
                            curr.append(col)
                            return

        for r in range(rows):
            for c in range(cols):
                if land[r][c] == 1 and (r, c) not in vis:
                    curr = [r, c]
                    bfs(r, c, curr)
                    res.append(curr.copy())

        return res

    

sol = Solution()
print(sol.findFarmland([[0]]))