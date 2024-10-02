class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size(),beam=0;
        int count[1000][1]={0};
        int m=bank[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(bank[i][j]=='1')
                    //bank[i][0]+=1;
                    count[i][0]++;
            }
        }
        /*for(int i=0;i<n;i++)
            cout<<bank[i][0]<<" ";
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(bank[i][0]!='0' && bank[j][0]!='0')
                {    
                    beam=beam+bank[i][0]*bank[j][0];
                    break;
                }
            }
        }*/
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(count[i][0]!=0 && count[j][0]!=0)
                {    
                    beam=beam+count[i][0]*count[j][0];
                    break;
                }
            }
        }
        return beam;
    }
};