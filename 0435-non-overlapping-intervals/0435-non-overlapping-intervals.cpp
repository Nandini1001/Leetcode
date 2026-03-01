class Solution {
public:
    static bool comp(vector<int> val1,vector<int> val2)
    {
        return val1[1]<val2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int nonOverlapping=1, free=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(free<=intervals[i][0]){
                nonOverlapping++;
                free=intervals[i][1];
            }
        }
        return intervals.size()-nonOverlapping;
    }
};