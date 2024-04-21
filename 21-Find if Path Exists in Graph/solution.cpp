#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int src = edge[0];
            int dst = edge[1];
            graph[src].push_back(dst);
            graph[dst].push_back(src);
        }

        queue<int> q;
        unordered_set<int> vis;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr == destination) return true;
            for (int neighbor : graph[curr]) {
                if (vis.find(neighbor) == vis.end()) {
                    vis.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};