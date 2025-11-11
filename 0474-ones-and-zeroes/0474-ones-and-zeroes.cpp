class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> prev(101,vector<int>(101,0));
        vector<vector<int>> curr(101,vector<int>(101,0));
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
                        take=1+prev[zero+z][one+o];
                    }
                    int nottake=prev[zero][one];
                    curr[zero][one]=max(take,nottake);
                }
            }
            prev=curr;
        }

        return prev[0][0];
    }
    
};


//space optimisation