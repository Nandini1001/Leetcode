class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> copymat=mat;
        int n=mat.size(), m=mat[0].size();
        k=k%m;
        for(int i=0;i<n;i++){
            if(i%2) rtshift(mat[i], k,m);
            else leftshift(mat[i], k, m);
        }
        return copymat==mat;
    }
    void rtshift(vector<int>& arr, int k, int m){
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+m-k);
        reverse(arr.begin()+m-k, arr.end());
    }
    void leftshift(vector<int>& arr, int k, int m){
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
    }
};