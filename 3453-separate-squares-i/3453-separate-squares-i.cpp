class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double mod=1e-5;
        double low=INT_MAX, high=INT_MIN;
        for(int i=0;i<squares.size();i++){
            low=min(low,(double)squares[i][1]);
            high=max(high,(double)(squares[i][1]+squares[i][2]));
        }
        double sum=0;
        for(int i=0;i<squares.size();i++){
            sum+=(double)squares[i][2]*squares[i][2];
        }
        while(high-low>mod){
            double mid=(high+low)/2.0;
            if(findbelowarea(squares,mid)<sum/2.0) low=mid;
            else  high=mid;
        }
        return low;
    }
    double findbelowarea(vector<vector<int>>& squares, double y){
        double area=0.0;
        for(int i=0;i<squares.size();i++){
            if(squares[i][1]<y){
                double Y=(squares[i][1]+squares[i][2]<=y?squares[i][2]:y-squares[i][1]);
                area+=(squares[i][2]*Y);
            }
        }
        return area;
    }
};