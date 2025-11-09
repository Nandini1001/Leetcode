class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < nums.size(); i++)
            pos[nums[i]].push_back(i);

        int ans=INT_MAX;
        for(auto it:pos){
            vector<int> arr=it.second;
            if(arr.size()>=3){
                for(int i=0;i+2<arr.size();i++){
                    ans=min(ans,arr[i+2]-arr[i]);
                }
            }
        }
        return ans==INT_MAX?-1:2*ans;
    }
};


//my code prev chatgpt
//time and space complexity is O(N);