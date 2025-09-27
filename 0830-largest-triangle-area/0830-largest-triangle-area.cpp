class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxi=INT_MIN;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                for(int k=j+1;k<points.size();k++){
                    double x1=points[i][0], y1=points[i][1];
                    double x2=points[j][0], y2=points[j][1];
                    double x3=points[k][0], y3=points[k][1];
                    double area=0.5*fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
                    maxi=max(maxi,area);
                }
            }
        }
        return maxi;
    }
};