#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        deque<int> q;
        for (int i = 0; i < deck.size(); ++i) {
            q.push_back(i);
        }

        vector<int> res(deck.size(), 0);
        for (int i = 0; i < deck.size(); ++i) {
            res[q.front()] = deck[i];
            q.pop_front();
            if (!q.empty()) {
                q.push_back(q.front());
                q.pop_front();
            }
        }

        return res;
    }
};
