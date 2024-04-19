#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> curr(matrix[0].size());
        int res = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '0') curr[j] = 0;
                else curr[j]++;
            }
            res = max(res, func(curr));
        }
        return res;
    }
private:
    int func(const vector<int>& heights) {
        stack<pair<int, int>> stack;
        int max_area = -1;
        int start, index, height;
        for (int i = 0; i < heights.size(); i++) {
            start = i;
            while (!stack.empty() && stack.top().second > heights[i]) {
                pair<int, int> element = stack.top();
                index = element.first;
                height = element.second;
                stack.pop();
                max_area = max(max_area, height * (i - index));
                start = index;
            }
            stack.push(make_pair(start, heights[i]));
        }

        while (!stack.empty()) {
            int i = stack.top().first;
            int h = stack.top().second;
            stack.pop();
            max_area = max(max_area, h * (static_cast<int>(heights.size()) - i));
        }

        return max_area;
    }
};

