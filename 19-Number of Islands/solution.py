from collections import deque
class Solution:
    def numIslands(self, grid):
        if not grid:
            return 0

        rows, cols = len(grid), len(grid[0])
        vis = set()
        res = 0

        def bfs(r, c):
            queue = deque()
            vis.add((r, c))
            queue.append((r, c))

            while queue:
                row, col = queue.popleft()
                directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

                for x, y in directions:
                    print("CHECKING", (x, y))
                    r, c = row + x, col + y
                    if r in range(rows) and \
                       c in range(cols) and \
                       grid[r][c] == "1" and \
                       (r, c) not in vis:
                        queue.append((r, c))
                        vis.add((r, c))

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1" and (r, c) not in vis:
                    bfs(r, c)
                    res += 1
                    print()

        return res