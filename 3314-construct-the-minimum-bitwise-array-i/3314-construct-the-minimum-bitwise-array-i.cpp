class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int no:nums){
            int i=-1,n=no;
            while(no!=0){
                i++;
                if(!(no&(1<<i))) break;
                no=no&(no-1);
            }
            if(!no) i++;
            if(i!=0) ans.push_back(n^(1<<(i-1)));
            else ans.push_back(-1);
        }
        return ans;
    }

};
