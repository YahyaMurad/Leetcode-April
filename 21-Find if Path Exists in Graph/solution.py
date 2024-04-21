import collections
from collections import deque

class Solution:
    def validPath(self, n, edges, source, destination):
        graph = collections.defaultdict(list)
        for edge in edges:
            src, dst = edge[0], edge[1]
            graph[src].append(dst)
            graph[dst].append(src)

        q = deque()
        vis = set()
        q.append(source)
        vis.add(source)

        while q:
            curr = q.popleft()
            if curr == destination:
                return True
            for neighbor in graph[curr]:
                if neighbor not in vis:
                    q.append(neighbor)
                    vis.add(neighbor)
        return False