class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> trailingzeros(n,-1);
        for(int i=0;i<n;i++){
            int j=n-1;
            for(;j>=0;j--){
                if(grid[i][j]) break;
            }
            trailingzeros[i]=n-1-j;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            int req=n-i-1;
            if(trailingzeros[i]>=req) continue;
            for(int j=i+1;j<n;j++){
                if(trailingzeros[j]>=req){
                    int k=j;
                    while(k!=i){
                        swap(trailingzeros[k],trailingzeros[k-1]);
                        cnt++;
                        k--;
                    }
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(trailingzeros[i]<n-i-1) return -1;
        }
        return cnt;
    }
};