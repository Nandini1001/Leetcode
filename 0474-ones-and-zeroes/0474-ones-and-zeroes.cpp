class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(101,vector<int>(101,0)));
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[0][i][j]=0;
            }
        }
        for(int ind=1;ind<=strs.size();ind++){
            for(int zero=100;zero>=0;zero--){
                for(int one=100;one>=0;one--){
                    int z=0, o=0;
                    for(char i:strs[ind-1]){
                        if(i=='0') z++;
                        else o++;
                    }
                    int take=0;
                    if(zero+z<=m && one+o<=n){
                        take=1+dp[ind-1][zero+z][one+o];
                    }
                    int nottake=dp[ind-1][zero][one];
                    dp[ind][zero][one]=max(take,nottake);
                }
            }
        }

        return dp[strs.size()][0][0];
    }
    
};


//tabulation