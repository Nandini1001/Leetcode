class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxi=0;
        for(int i=0; i<nums.size();i++){
            set<int> even, odd;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2) odd.insert(nums[j]);
                else even.insert(nums[j]);
                if(odd.size()==even.size())
                    maxi=max(maxi,j-i+1); 
            }
        }
        return maxi;
    }
};