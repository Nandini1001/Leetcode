#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        long long windowSum = 0;
        unordered_map<int,int> cnt;

        // We'll use multiset pairs: (frequency, value)
        multiset<pair<int,int>> top;  // elements contributing to x-sum
        multiset<pair<int,int>> bot;  // the rest

        auto update = [&](int val, int delta) {
            int old = cnt[val];
            if (old > 0) {
                // Remove old pair from either top or bot
                auto p = make_pair(old, val);
                auto itBot = bot.find(p);
                if (itBot != bot.end()) {
                    bot.erase(itBot);
                } else {
                    auto itTop = top.find(p);
                    if (itTop != top.end()) {
                        top.erase(itTop);
                        windowSum -= (long long)old * val;
                    }
                }
            }

            cnt[val] = old + delta;
            int now = cnt[val];
            if (now > 0) {
                bot.insert(make_pair(now, val));
            }
        };

        for (int i = 0; i < n; ++i) {
            update(nums[i], +1);
            if (i >= k) {
                update(nums[i - k], -1);
            }

            if (i >= k - 1) {
                // Now we have a full window [i-k+1 .. i]
                // Rebalance sets: ensure top has at most x items
                while (!bot.empty() && top.size() < (size_t)x) {
                    auto it = prev(bot.end());
                    auto p = *it;
                    bot.erase(it);
                    top.insert(p);
                    windowSum += (long long)p.first * p.second;
                }

                while (!bot.empty() && !top.empty() && *prev(bot.end()) > *top.begin()) {
                    auto pB = *prev(bot.end());
                    auto pT = *top.begin();
                    bot.erase(prev(bot.end()));
                    top.erase(top.begin());
                    bot.insert(pT);
                    top.insert(pB);
                    windowSum += (long long)pB.first * pB.second;
                    windowSum -= (long long)pT.first * pT.second;
                }

                ans.push_back((int)windowSum);
            }
        }

        return ans;
    }
};
