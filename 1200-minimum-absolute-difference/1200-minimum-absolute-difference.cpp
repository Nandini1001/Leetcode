class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        vector<vector<int>> ans;
        for(int i=1;i<arr.size();i++){
            if(mini>arr[i]-arr[i-1]){
                mini=arr[i]-arr[i-1];
                ans.clear();
                ans.push_back({arr[i-1],arr[i]});
            }
            else if(mini==arr[i]-arr[i-1]){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};