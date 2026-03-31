class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0, ans;
        for(int i=0; i<k ;i++){
            sum+=cardPoints[i];
        }
        ans=sum;
        int start=k-1, end=cardPoints.size()-1;
        while(start>=0){
            sum-=cardPoints[start--];
            sum+=cardPoints[end--];
            ans=max(ans,sum);
        }
        return ans;
    }
};