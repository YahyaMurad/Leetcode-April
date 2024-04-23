import collections

class Solution:
    def findMinHeightTrees(self, n, edges):
        if n == 1 or edges == []:
            return [0]

        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        res = []
        for node, neighbors in graph.items():
            if len(neighbors) ==  1:
                res.append(node)

        while n > 2:
            n -= len(res)
            new_nodes = []

            for leaf_node in res:
                neighbor = graph[leaf_node].pop()
                graph[neighbor].remove(leaf_node)

                if len(graph[neighbor]) == 1:
                    new_nodes.append(neighbor)

            res = new_nodes

        return res