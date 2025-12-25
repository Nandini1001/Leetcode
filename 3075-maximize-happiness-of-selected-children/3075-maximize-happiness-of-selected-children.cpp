class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum=0, sub=0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for(int i=0;i<k;i++){
            sum+=happiness[i];
            sub+=i>happiness[i]?happiness[i]:i;
        }
        return sum-sub;
    }
};