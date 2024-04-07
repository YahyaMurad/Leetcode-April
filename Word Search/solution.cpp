#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, const string& word) {
        int rows = board.size(), cols = board[0].size();
        
        auto isValid = [&](int r, int c) {
            return r >= 0 && c >= 0 && r < rows && c < cols;
        };
        
        function<bool(int, int, int)> dfs = [&](int r, int c, int i) -> bool {
            if (i == word.length()) return true;

            if (!isValid(r, c) || word[i] != board[r][c] || board[r][c] == '#') {
                return false;
            }
            
            char temp = board[r][c];
            board[r][c] = '#';
            
            if (dfs(r + 1, c, i + 1) || dfs(r - 1, c, i + 1) ||
                dfs(r, c + 1, i + 1) || dfs(r, c - 1, i + 1)) {
                return true;
            }
            
            board[r][c] = temp;
            return false;
        };

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(r, c, 0)) return true;
            }
        }
        return false;
    }
};