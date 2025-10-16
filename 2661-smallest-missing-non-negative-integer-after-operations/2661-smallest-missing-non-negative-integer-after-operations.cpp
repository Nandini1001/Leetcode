class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[((nums[i]%value)+value)%value]++;
        }
        int i=0;
        while(1){
            if(freq[i%value]==0) return i;
            if(freq[i%value]==1) freq.erase(i%value);
            else freq[i%value]--;
            i++;
        }
        return i;
    }
};

