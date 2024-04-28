from collections import defaultdict, deque

class Solution:
    def sumOfDistancesInTree(self, n, edges):
        graph = defaultdict(list)
        for edge in edges:
            src, dst = edge[0], edge[1]
            graph[src].append(dst)
            graph[dst].append(src)

        res = [0] * n
        count = [1] * n
        self.root = 0

        def countPopulating(curr, parent, depth):
            o = 1
            for neighbor in graph[curr]:
                if neighbor != parent:
                    o += countPopulating(neighbor, curr, depth + 1)
                    self.root += depth + 1
                
            count[curr] = o
            return o
        
        countPopulating(0, -1, 0)

        def dfs(curr, parent, current_count):
            res[curr] = current_count

            for neighbor in graph[curr]:
                if neighbor != parent:
                    dfs(neighbor, curr, current_count + n - count[neighbor] - count[neighbor])


        dfs(0, -1, self.root)
        return res
