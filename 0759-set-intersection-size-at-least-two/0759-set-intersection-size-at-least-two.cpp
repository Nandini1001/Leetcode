class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort intervals by end ascending, start descending
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if (a[1] == b[1]) 
                return a[0] > b[0];
            return a[1] < b[1];
        });
        
        int ans = 0;
        int p1 = -1, p2 = -1;  // the last two selected points
        
        for (auto &in : intervals) {
            int start = in[0], end = in[1];

            bool has_p1 = (p1 >= start);
            bool has_p2 = (p2 >= start);
            
            if (has_p1 && has_p2) {
                // Interval already has two points
                continue;
            }
            else if (has_p2) {
                // We need just 1 more point
                p1 = p2;
                p2 = end;   // pick the largest possible
                ans += 1;
            }
            else {
                // No points inside → need 2 new points
                p1 = end - 1;
                p2 = end;
                ans += 2;
            }
        }
        
        return ans;
    }
};

//chatgpt