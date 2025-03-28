class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<k;i++)
            sum+=cardPoints[i];
        int maxsum=sum;
        int rind=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--)
        {
            sum-=cardPoints[i];
            sum+=cardPoints[rind--];
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};