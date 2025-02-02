class Solution {
public:
    int mySqrt(int x) {
        int low=1,high=x;
        while(low<=high)
        {
            int mid=(long(low)+high)/2;
            if((long)mid*mid<=x)
                low=mid+1;
            else
                high=mid-1;
        }
        return high;
    }
};