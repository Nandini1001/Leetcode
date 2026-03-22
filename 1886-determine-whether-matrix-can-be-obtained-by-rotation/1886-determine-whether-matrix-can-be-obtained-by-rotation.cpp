class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++){
            rotate(mat);
            if(mat==target) return true;
        }
        return false;
    }
    void rotate(vector<vector<int>>& nums) {
        for(int i=0; i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i<j)
                    swap(nums[i][j], nums[j][i]);
            }
        }
        for(int i=0; i<nums.size();i++){
            reverse(nums[i].begin(), nums[i].end());
        }
    }
};