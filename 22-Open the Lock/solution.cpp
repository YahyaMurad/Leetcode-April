#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis(deadends.begin(), deadends.end());
        if (vis.count("0000")) return -1;
        if (target == "0000") return 0;

        queue<string> q{{"0000"}};
        int res = 0;

        while (!q.empty()) {
            res++;
            for (int sz = q.size(); sz > 0; sz--){
                string word = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    const char cache = word[i];
                    word[i] = word[i] == '9' ? '0' : word[i] + 1;
                    if (word == target) return res;
                    if (!vis.count(word)) {
                        q.push(word);
                        vis.insert(word);
                    }

                    word[i] = cache;
                    word[i] = word[i] == '0' ? '9' : word[i] - 1;
                    if (word == target) return res;
                    if (!vis.count(word)) {
                        q.push(word);
                        vis.insert(word);
                    }
                    word[i] = cache;
                }
            }
        }
        return -1;
    }
};