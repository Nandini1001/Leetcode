class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> freq;
        for (int p : power) freq[p]++;
        
        vector<int> vals;
        for (auto &it : freq) vals.push_back(it.first);
        sort(vals.begin(), vals.end());
        
        int n = vals.size();
        vector<long long> dp(n);
        
        for (int i = 0; i < n; i++) {
            long long curDamage = vals[i] * freq[vals[i]];
            int j = i - 1;
            // find previous index with gap > 2
            while (j >= 0 && vals[i] - vals[j] <= 2) j--;
            
            dp[i] = max((i ? dp[i-1] : 0LL),
                        curDamage + (j >= 0 ? dp[j] : 0LL));
        }
        
        return dp[n-1];
    }
};
