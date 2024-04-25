#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        for (char c : s) {
            int curr = c - 'a';
            int longest = 1;
            for (int prev = 0; prev < 26; ++prev) {
                if (abs(curr - prev) <= k) {
                    longest = max(longest, 1 + dp[prev]);
                }
            }
            dp[curr] = max(dp[curr], longest);
        }
        return *max_element(dp.begin(), dp.end());
    }
};