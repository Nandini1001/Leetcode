class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low=*min_element(workerTimes.begin(), workerTimes.end());
        long long high=(*max_element(workerTimes.begin(),workerTimes.end()))*((1LL*mountainHeight*(mountainHeight+1))/2);
        while(low<=high){
            long long mid=(low+high)/2;
            if(helper(mid,workerTimes)>=mountainHeight) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
    int helper(long long maxsec, vector<int>& workerTimes){
        int ht=0;
        for(int work:workerTimes){
            ht+=floor(((sqrt(1+((8*maxsec)/work)))-1)/2);
        }
        return ht;
    }
};