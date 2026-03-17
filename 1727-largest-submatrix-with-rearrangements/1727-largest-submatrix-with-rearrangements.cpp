class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> presum(2,vector<int>(m,0));
        vector<int> current(m,0);
        int maxarea=0, cnt=0;
        for(int j=0;j<m;j++){
            presum[0][j]=matrix[0][j];
            if(presum[0][j]) cnt++;
        }
        maxarea=max(maxarea,cnt);
        for(int i=1; i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j])
                {
                    presum[1][j]=presum[0][j]+1;
                }
                else presum[1][j]=0;
            }
            current=presum[1];
            sort(current.begin(), current.end());
            for(int k=0; k<m; k++){
                maxarea=max(maxarea,current[k]*(m-k));
            }
            presum[0]=presum[1];
        }
        return maxarea;    
    }
};