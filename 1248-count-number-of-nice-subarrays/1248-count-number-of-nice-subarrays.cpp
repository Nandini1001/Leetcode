class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> oddcnt;
        oddcnt[0]=1;
        int odd=0, cnt=0;
        for(auto i:nums){
            if(i%2) odd++;
            int req=odd-k;
            cnt+=oddcnt[req];
            oddcnt[odd]++;
        }
        return cnt;
    }
};