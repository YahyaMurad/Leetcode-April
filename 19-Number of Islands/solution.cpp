#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int res = 0;

        function<void(int, int)> bfs = [&](int row, int col) {
            queue<pair<int, int>> q;
            q.push({row, col});
            vis[row][col] = true;

            while (!q.empty()) {
                int r, c;
                r = q.front().first;
                c = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1' && !vis[nr][nc]) {
                        q.push({nr, nc});
                        vis[nr][nc] = true;
                    } 
                }

            } 
        };

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1' && !vis[r][c]) {
                    bfs(r, c);
                    res += 1;
                }
            }
        }

        return res;
    }
};