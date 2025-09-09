class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int maxsum=sum;
        int rt=cardPoints.size()-1;
        int left=k-1;
        while(left>=0){
            sum-=cardPoints[left--];
            sum+=cardPoints[rt--];
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};