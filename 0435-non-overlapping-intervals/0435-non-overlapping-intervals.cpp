class Solution {
private:
    static bool comp(vector<int> val1,vector<int> val2)
    {
        return val1[1]<val2[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n=intervals.size(),cnt=1;
        int lastend=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>=lastend)
            {
                cnt++;
                lastend=intervals[i][1];
            }
        }
        return n-cnt;
    }
};